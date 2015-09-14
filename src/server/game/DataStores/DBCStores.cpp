/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "DBCStores.h"
#include "Log.h"
#include "SharedDefines.h"
#include "SpellInfo.h"
#include "DBCfmt.h"
#include "Timer.h"
#include "DB2Stores.h"

#include <map>


struct WMOAreaTableTripple
{
    WMOAreaTableTripple(int32 r, int32 a, int32 g) :  groupId(g), rootId(r), adtId(a)
    {
    }

    bool operator <(const WMOAreaTableTripple& b) const
    {
        return memcmp(this, &b, sizeof(WMOAreaTableTripple))<0;
    }

    // ordered by entropy; that way memcmp will have a minimal medium runtime
    int32 groupId;
    int32 rootId;
    int32 adtId;
};

typedef std::map<uint16, uint32> AreaFlagByAreaID;
typedef std::map<uint32, uint32> AreaFlagByMapID;
typedef std::multimap<uint32, CharSectionsEntry const*> CharSectionsMap;
typedef std::map<uint32, std::vector<uint32>> FactionTeamMap;
typedef std::map<WMOAreaTableTripple, WMOAreaTableEntry const*> WMOAreaInfoByTripple;

DBCStorage<AnimKitEntry>                    sAnimKitStore(AnimKitfmt);
DBCStorage<AreaTableEntry>                  sAreaStore(AreaTablefmt);
static AreaFlagByAreaID                     sAreaFlagByAreaID;
static AreaFlagByMapID                      sAreaFlagByMapID;   // for instances without generated *.map files
DBCStorage<AreaTriggerEntry>                sAreaTriggerStore(AreaTriggerfmt);
DBCStorage<ArmorLocationEntry>              sArmorLocationStore(ArmorLocationfmt);

DBCStorage<BankBagSlotPricesEntry>          sBankBagSlotPricesStore(BankBagSlotPricesfmt);
DBCStorage<BannedAddOnsEntry>               sBannedAddOnsStore(BannedAddOnsfmt);
DBCStorage<BattlemasterListEntry>           sBattlemasterListStore(BattlemasterListfmt);

DBCStorage<CharSectionsEntry>               sCharSectionsStore(CharSectionsfmt);
CharSectionsMap                             sCharSectionMap;
DBCStorage<CharTitlesEntry>                 sCharTitlesStore(CharTitlesfmt);
DBCStorage<ChatChannelsEntry>               sChatChannelsStore(ChatChannelsfmt);
DBCStorage<ChrClassesEntry>                 sChrClassesStore(ChrClassesfmt);
DBCStorage<ChrRacesEntry>                   sChrRacesStore(ChrRacesfmt);
DBCStorage<ChrSpecializationEntry>          sChrSpecializationStore(ChrSpecializationfmt);
ChrSpecializationByIndexArray               sChrSpecializationByIndexStore;
DBCStorage<CreatureDisplayInfoExtraEntry>   sCreatureDisplayInfoExtraStore(CreatureDisplayInfoExtrafmt);
DBCStorage<CreatureFamilyEntry>             sCreatureFamilyStore(CreatureFamilyfmt);
DBCStorage<CreatureModelDataEntry>          sCreatureModelDataStore(CreatureModelDatafmt);

DBCStorage<DifficultyEntry>                 sDifficultyStore(DifficultyFmt);
DBCStorage<DungeonEncounterEntry>           sDungeonEncounterStore(DungeonEncounterfmt);
DBCStorage<DurabilityCostsEntry>            sDurabilityCostsStore(DurabilityCostsfmt);

DBCStorage<EmotesEntry>                     sEmotesStore(Emotesfmt);
DBCStorage<EmotesTextEntry>                 sEmotesTextStore(EmotesTextfmt);

DBCStorage<FactionEntry>                    sFactionStore(Factionfmt);
static FactionTeamMap                       sFactionTeamMap;
DBCStorage<FactionTemplateEntry>            sFactionTemplateStore(FactionTemplatefmt);

DBCStorage<GameObjectDisplayInfoEntry>      sGameObjectDisplayInfoStore(GameObjectDisplayInfofmt);
DBCStorage<GemPropertiesEntry>              sGemPropertiesStore(GemPropertiesfmt);
DBCStorage<GlyphPropertiesEntry>            sGlyphPropertiesStore(GlyphPropertiesfmt);
DBCStorage<GuildColorBackgroundEntry>       sGuildColorBackgroundStore(GuildColorBackgroundfmt);
DBCStorage<GuildColorBorderEntry>           sGuildColorBorderStore(GuildColorBorderfmt);
DBCStorage<GuildColorEmblemEntry>           sGuildColorEmblemStore(GuildColorEmblemfmt);
DBCStorage<ItemArmorQualityEntry>           sItemArmorQualityStore(ItemArmorQualityfmt);
DBCStorage<ItemArmorShieldEntry>            sItemArmorShieldStore(ItemArmorShieldfmt);
DBCStorage<ItemArmorTotalEntry>             sItemArmorTotalStore(ItemArmorTotalfmt);
DBCStorage<ItemBagFamilyEntry>              sItemBagFamilyStore(ItemBagFamilyfmt);
DBCStorage<ItemDamageEntry>                 sItemDamageAmmoStore(ItemDamagefmt);
DBCStorage<ItemDamageEntry>                 sItemDamageOneHandCasterStore(ItemDamagefmt);
DBCStorage<ItemDamageEntry>                 sItemDamageOneHandStore(ItemDamagefmt);
DBCStorage<ItemDamageEntry>                 sItemDamageRangedStore(ItemDamagefmt);
DBCStorage<ItemDamageEntry>                 sItemDamageThrownStore(ItemDamagefmt);
DBCStorage<ItemDamageEntry>                 sItemDamageTwoHandCasterStore(ItemDamagefmt);
DBCStorage<ItemDamageEntry>                 sItemDamageTwoHandStore(ItemDamagefmt);
DBCStorage<ItemDamageEntry>                 sItemDamageWandStore(ItemDamagefmt);
DBCStorage<ItemSetEntry>                    sItemSetStore(ItemSetfmt);
DBCStorage<ItemSetSpellEntry>               sItemSetSpellStore(ItemSetSpellfmt);
ItemSetSpellsStore                          sItemSetSpellsStore;

DBCStorage<LFGDungeonEntry>                 sLFGDungeonStore(LFGDungeonfmt);
DBCStorage<LightEntry>                      sLightStore(Lightfmt);
DBCStorage<LiquidTypeEntry>                 sLiquidTypeStore(LiquidTypefmt);
DBCStorage<LockEntry>                       sLockStore(Lockfmt);

DBCStorage<MapEntry>                        sMapStore(Mapfmt);
DBCStorage<MapDifficultyEntry>              sMapDifficultyStore(MapDifficultyfmt); // only for loading
MapDifficultyMap                            sMapDifficultyMap;
DBCStorage<MovieEntry>                      sMovieStore(Moviefmt);

DBCStorage<PhaseEntry>                      sPhaseStore(Phasefmt);
DBCStorage<PowerDisplayEntry>               sPowerDisplayStore(PowerDisplayfmt);
DBCStorage<PvPDifficultyEntry>              sPvpDifficultyStore(PvpDifficultyfmt);

DBCStorage<QuestFactionRewEntry>            sQuestFactionRewardStore(QuestFactionRewardfmt);

DBCStorage<RandomPropertiesPointsEntry>     sRandomPropertiesPointsStore(RandPropPointsfmt);

DBCStorage<SkillLineAbilityEntry>           sSkillLineAbilityStore(SkillLineAbilityfmt);
DBCStorage<SkillLineEntry>                  sSkillLineStore(SkillLinefmt);
DBCStorage<SkillRaceClassInfoEntry>         sSkillRaceClassInfoStore(SkillRaceClassInfofmt);
SkillRaceClassInfoMap                       SkillRaceClassInfoBySkill;
DBCStorage<SpellAuraOptionsEntry>           sSpellAuraOptionsStore(SpellAuraOptionsfmt);
DBCStorage<SpellCategoriesEntry>            sSpellCategoriesStore(SpellCategoriesfmt);
DBCStorage<SpellCategoryEntry>              sSpellCategoryStore(SpellCategoryfmt);
DBCStorage<SpellCooldownsEntry>             sSpellCooldownsStore(SpellCooldownsfmt);
DBCStorage<SpellEffectEntry>                sSpellEffectStore(SpellEffectfmt);
DBCStorage<SpellEffectScalingEntry>         sSpellEffectScalingStore(SpellEffectScalingfmt);
SpellEffectScallingByEffectId               sSpellEffectScallingByEffectId;
DBCStorage<SpellEntry>                      sSpellStore(Spellfmt);
DBCStorage<SpellEquippedItemsEntry>         sSpellEquippedItemsStore(SpellEquippedItemsfmt);
DBCStorage<SpellFocusObjectEntry>           sSpellFocusObjectStore(SpellFocusObjectfmt);
DBCStorage<SpellInterruptsEntry>            sSpellInterruptsStore(SpellInterruptsfmt);
DBCStorage<SpellItemEnchantmentEntry>       sSpellItemEnchantmentStore(SpellItemEnchantmentfmt);
DBCStorage<SpellLevelsEntry>                sSpellLevelsStore(SpellLevelsfmt);
DBCStorage<SpellScalingEntry>               sSpellScalingStore(SpellScalingfmt);
DBCStorage<SpellShapeshiftEntry>            sSpellShapeshiftStore(SpellShapeshiftfmt);
DBCStorage<SpellShapeshiftFormEntry>        sSpellShapeshiftFormStore(SpellShapeshiftFormfmt);
DBCStorage<SpellTargetRestrictionsEntry>    sSpellTargetRestrictionsStore(SpellTargetRestrictionsfmt);
DBCStorage<SummonPropertiesEntry>           sSummonPropertiesStore(SummonPropertiesfmt);

DBCStorage<TalentEntry>                     sTalentStore(Talentfmt);
TalentsByPosition                           sTalentByPos;

DBCStorage<VehicleEntry>                    sVehicleStore(Vehiclefmt);
DBCStorage<VehicleSeatEntry>                sVehicleSeatStore(VehicleSeatfmt);

DBCStorage<WMOAreaTableEntry>               sWMOAreaTableStore(WMOAreaTablefmt);
static WMOAreaInfoByTripple                 sWMOAreaInfoByTripple;
DBCStorage<WorldMapAreaEntry>               sWorldMapAreaStore(WorldMapAreafmt);
DBCStorage<WorldMapTransformsEntry>         sWorldMapTransformsStore(WorldMapTransformsfmt);
DBCStorage<WorldSafeLocsEntry>              sWorldSafeLocsStore(WorldSafeLocsfmt);

GameTable<GtBarberShopCostBaseEntry>        sGtBarberShopCostBaseStore(GtBarberShopCostBasefmt);
GameTable<GtChanceToMeleeCritBaseEntry>     sGtChanceToMeleeCritBaseStore(GtChanceToMeleeCritBasefmt);
GameTable<GtChanceToMeleeCritEntry>         sGtChanceToMeleeCritStore(GtChanceToMeleeCritfmt);
GameTable<GtChanceToSpellCritBaseEntry>     sGtChanceToSpellCritBaseStore(GtChanceToSpellCritBasefmt);
GameTable<GtChanceToSpellCritEntry>         sGtChanceToSpellCritStore(GtChanceToSpellCritfmt);
GameTable<GtCombatRatingsEntry>             sGtCombatRatingsStore(GtCombatRatingsfmt);
GameTable<GtItemSocketCostPerLevelEntry>    sGtItemSocketCostPerLevelStore(GtItemSocketCostPerLevelfmt);
GameTable<GtNPCManaCostScalerEntry>         sGtNPCManaCostScalerStore(GtNPCManaCostScalerfmt);
GameTable<GtNpcTotalHpEntry>                sGtNpcTotalHpStore(GtNpcTotalHpfmt);
GameTable<GtNpcTotalHpExp1Entry>            sGtNpcTotalHpExp1Store(GtNpcTotalHpExp1fmt);
GameTable<GtNpcTotalHpExp2Entry>            sGtNpcTotalHpExp2Store(GtNpcTotalHpExp2fmt);
GameTable<GtNpcTotalHpExp3Entry>            sGtNpcTotalHpExp3Store(GtNpcTotalHpExp3fmt);
GameTable<GtNpcTotalHpExp4Entry>            sGtNpcTotalHpExp4Store(GtNpcTotalHpExp4fmt);
GameTable<GtNpcTotalHpExp5Entry>            sGtNpcTotalHpExp5Store(GtNpcTotalHpExp5fmt);
GameTable<GtOCTBaseHPByClassEntry>          sGtOCTBaseHPByClassStore(GtOCTBaseHPByClassfmt);
GameTable<GtOCTBaseMPByClassEntry>          sGtOCTBaseMPByClassStore(GtOCTBaseMPByClassfmt);
GameTable<GtOCTHpPerStaminaEntry>           sGtOCTHpPerStaminaStore(GtOCTHpPerStaminafmt);
GameTable<GtOCTLevelExperienceEntry>        sGtOCTLevelExperienceStore(GtOCTLevelExperiencefmt);
GameTable<GtRegenMPPerSptEntry>             sGtRegenMPPerSptStore(GtRegenMPPerSptfmt);
GameTable<GtSpellScalingEntry>              sGtSpellScalingStore(GtSpellScalingfmt);

typedef std::list<std::string> StoreProblemList;

uint32 DBCFileCount = 0;
uint32 GameTableCount = 0;

template<class T>
inline void LoadDBC(uint32& availableDbcLocales, StoreProblemList& errors, DBCStorage<T>& storage, std::string const& dbcPath, std::string const& filename, uint32 defaultLocale, std::string const* customFormat = NULL, std::string const* customIndexName = NULL)
{
    // compatibility format and C++ structure sizes
    ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T),
        "Size of '%s' set by format string (%u) not equal size of C++ structure (%u).",
        filename.c_str(), DBCFileLoader::GetFormatRecordSize(storage.GetFormat()), uint32(sizeof(T)));

    ++DBCFileCount;
    std::string dbcFilename = dbcPath + localeNames[defaultLocale] + '/' + filename;
    SqlDbc * sql = NULL;
    if (customFormat)
        sql = new SqlDbc(&filename, customFormat, customIndexName, storage.GetFormat());

    if (storage.Load(dbcFilename.c_str(), sql))
    {
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (!(availableDbcLocales & (1 << i)))
                continue;

            std::string localizedName(dbcPath);
            localizedName.append(localeNames[i]);
            localizedName.push_back('/');
            localizedName.append(filename);

            if (!storage.LoadStringsFrom(localizedName.c_str()))
                availableDbcLocales &= ~(1<<i);             // mark as not available for speedup next checks
        }
    }
    else
    {
        // sort problematic dbc to (1) non compatible and (2) non-existed
        if (FILE* f = fopen(dbcFilename.c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << dbcFilename << " exists, and has " << storage.GetFieldCount() << " field(s) (expected " << strlen(storage.GetFormat()) << "). Extracted file might be from wrong client version or a database-update has been forgotten.";
            std::string buf = stream.str();
            errors.push_back(buf);
            fclose(f);
        }
        else
            errors.push_back(dbcFilename);
    }

    delete sql;
}

template<class T>
inline void LoadGameTable(StoreProblemList& errors, std::string const& tableName, GameTable<T>& storage, std::string const& dbcPath, std::string const& filename)
{
    // compatibility format and C++ structure sizes
    ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T),
        "Size of '%s' set by format string (%u) not equal size of C++ structure (%u).",
        filename.c_str(), DBCFileLoader::GetFormatRecordSize(storage.GetFormat()), uint32(sizeof(T)));

    ++GameTableCount;
    std::string dbcFilename = dbcPath + filename;

    if (storage.Load(dbcFilename.c_str()))
    {
        bool found = false;
        // Find table definition in GameTables.db2
        for (uint32 i = 0; i < sGameTablesStore.GetNumRows(); ++i)
        {
            GameTablesEntry const* gt = sGameTablesStore.LookupEntry(i);
            if (!gt)
                continue;

            for (uint32 l = 0; l < TOTAL_LOCALES; ++l)
            {
                if (tableName == gt->Name->Str[l])
                {
                    found = true;
                    storage.SetGameTableEntry(gt);
                    break;
                }
            }

            if (found)
                break;
        }

        ASSERT(found, "Game table %s definition not found in GameTables.db2", tableName.c_str());
    }
    else
    {
        // sort problematic dbc to (1) non compatible and (2) non-existed
        if (FILE* f = fopen(dbcFilename.c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << dbcFilename << " exists, and has " << storage.GetFieldCount() << " field(s) (expected " << strlen(storage.GetFormat()) << "). Extracted file might be from wrong client version or a database-update has been forgotten.";
            std::string buf = stream.str();
            errors.push_back(buf);
            fclose(f);
        }
        else
            errors.push_back(dbcFilename);
    }
}

void LoadDBCStores(const std::string& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string dbcPath = dataPath + "dbc/";

    StoreProblemList bad_dbc_files;
    uint32 availableDbcLocales = 0xFFFFFFFF;

#define LOAD_DBC(store, file) LoadDBC(availableDbcLocales, bad_dbc_files, store, dbcPath, file, defaultLocale)

    LOAD_DBC(sAnimKitStore, "AnimKit.dbc");//20444
    LOAD_DBC(sAreaStore, "AreaTable.dbc");//20444
    LOAD_DBC(sAreaTriggerStore, "AreaTrigger.dbc");//20444
    LOAD_DBC(sArmorLocationStore, "ArmorLocation.dbc");//20444
    LOAD_DBC(sBankBagSlotPricesStore, "BankBagSlotPrices.dbc");//20444
    LOAD_DBC(sBannedAddOnsStore, "BannedAddOns.dbc");//20444
    LOAD_DBC(sBattlemasterListStore, "BattlemasterList.dbc");//20444
    LOAD_DBC(sCharSectionsStore, "CharSections.dbc");//20444
    LOAD_DBC(sCharTitlesStore, "CharTitles.dbc");//20444
    LOAD_DBC(sChatChannelsStore, "ChatChannels.dbc");//20444
    LOAD_DBC(sChrClassesStore, "ChrClasses.dbc");//20444
    LOAD_DBC(sChrRacesStore, "ChrRaces.dbc");//20444
    LOAD_DBC(sChrSpecializationStore, "ChrSpecialization.dbc");//20444
    LOAD_DBC(sCreatureDisplayInfoExtraStore, "CreatureDisplayInfoExtra.dbc");//20444
    LOAD_DBC(sCreatureFamilyStore, "CreatureFamily.dbc");//20444
    LOAD_DBC(sCreatureModelDataStore, "CreatureModelData.dbc");//20444
    LOAD_DBC(sDifficultyStore, "Difficulty.dbc");//20444
    LOAD_DBC(sDungeonEncounterStore, "DungeonEncounter.dbc");//20444
    LOAD_DBC(sDurabilityCostsStore, "DurabilityCosts.dbc");//20444
    LOAD_DBC(sEmotesStore, "Emotes.dbc");//20444
    LOAD_DBC(sEmotesTextStore, "EmotesText.dbc");//20444
    LOAD_DBC(sFactionStore, "Faction.dbc");//20444
    LOAD_DBC(sFactionTemplateStore, "FactionTemplate.dbc");//20444
    LOAD_DBC(sGameObjectDisplayInfoStore, "GameObjectDisplayInfo.dbc");//20444
    LOAD_DBC(sGemPropertiesStore, "GemProperties.dbc");//20444
    LOAD_DBC(sGlyphPropertiesStore, "GlyphProperties.dbc");//20444
    LOAD_DBC(sGuildColorBackgroundStore, "GuildColorBackground.dbc");//20444
    LOAD_DBC(sGuildColorBorderStore, "GuildColorBorder.dbc"); //20444
    LOAD_DBC(sGuildColorEmblemStore, "GuildColorEmblem.dbc");//20444
    LOAD_DBC(sItemArmorQualityStore, "ItemArmorQuality.dbc");//20444
    LOAD_DBC(sItemArmorShieldStore, "ItemArmorShield.dbc");//20444
    LOAD_DBC(sItemArmorTotalStore, "ItemArmorTotal.dbc");//20444
    LOAD_DBC(sItemBagFamilyStore, "ItemBagFamily.dbc");//20444
    LOAD_DBC(sItemDamageAmmoStore, "ItemDamageAmmo.dbc");//20444
    LOAD_DBC(sItemDamageOneHandCasterStore, "ItemDamageOneHandCaster.dbc");//20444
    LOAD_DBC(sItemDamageOneHandStore, "ItemDamageOneHand.dbc");//20444
    LOAD_DBC(sItemDamageRangedStore, "ItemDamageRanged.dbc");//20444
    LOAD_DBC(sItemDamageThrownStore, "ItemDamageThrown.dbc");//20444
    LOAD_DBC(sItemDamageTwoHandCasterStore, "ItemDamageTwoHandCaster.dbc");//20444
    LOAD_DBC(sItemDamageTwoHandStore, "ItemDamageTwoHand.dbc");//20444
    LOAD_DBC(sItemDamageWandStore, "ItemDamageWand.dbc");//20444
    LOAD_DBC(sItemSetSpellStore, "ItemSetSpell.dbc");//20444
    LOAD_DBC(sItemSetStore, "ItemSet.dbc");//20444
    LOAD_DBC(sLFGDungeonStore, "LfgDungeons.dbc");//20444
    LOAD_DBC(sLightStore, "Light.dbc"); //20444
    LOAD_DBC(sLiquidTypeStore, "LiquidType.dbc");//20444
    LOAD_DBC(sLockStore, "Lock.dbc");//20444
    LOAD_DBC(sMapDifficultyStore, "MapDifficulty.dbc");//20444
    LOAD_DBC(sMapStore, "Map.dbc");//20444
    LOAD_DBC(sMovieStore, "Movie.dbc");//20444
    LOAD_DBC(sPhaseStore, "Phase.dbc"); // 20444
    LOAD_DBC(sPowerDisplayStore, "PowerDisplay.dbc");//20444
    LOAD_DBC(sPvpDifficultyStore, "PvpDifficulty.dbc");//20444
    LOAD_DBC(sQuestFactionRewardStore, "QuestFactionReward.dbc");//20444
    LOAD_DBC(sRandomPropertiesPointsStore, "RandPropPoints.dbc");//20444
    LOAD_DBC(sSkillLineAbilityStore, "SkillLineAbility.dbc");//20444
    LOAD_DBC(sSkillLineStore, "SkillLine.dbc");//20444
    LOAD_DBC(sSkillRaceClassInfoStore, "SkillRaceClassInfo.dbc");//20444
    LOAD_DBC(sSpellAuraOptionsStore, "SpellAuraOptions.dbc");//20444
    LOAD_DBC(sSpellCategoriesStore, "SpellCategories.dbc");//20444
    LOAD_DBC(sSpellCategoryStore, "SpellCategory.dbc");//20444
    LOAD_DBC(sSpellCooldownsStore, "SpellCooldowns.dbc");//20444
    LOAD_DBC(sSpellEffectScalingStore, "SpellEffectScaling.dbc");//20444
    LOAD_DBC(sSpellEffectStore, "SpellEffect.dbc"/*, &CustomSpellEffectfmt, &CustomSpellEffectEntryIndex*/);//20444
    LOAD_DBC(sSpellEquippedItemsStore, "SpellEquippedItems.dbc");//20444
    LOAD_DBC(sSpellFocusObjectStore, "SpellFocusObject.dbc");//20444
    LOAD_DBC(sSpellInterruptsStore, "SpellInterrupts.dbc");//20444
    LOAD_DBC(sSpellItemEnchantmentStore, "SpellItemEnchantment.dbc");//20444
    LOAD_DBC(sSpellLevelsStore, "SpellLevels.dbc");//20444
    LOAD_DBC(sSpellScalingStore, "SpellScaling.dbc");//20444
    LOAD_DBC(sSpellShapeshiftFormStore, "SpellShapeshiftForm.dbc");//20444
    LOAD_DBC(sSpellShapeshiftStore, "SpellShapeshift.dbc");//20444
    LOAD_DBC(sSpellStore, "Spell.dbc"/*, &CustomSpellfmt, &CustomSpellEntryIndex*/);//20444
    LOAD_DBC(sSpellTargetRestrictionsStore, "SpellTargetRestrictions.dbc");//20444
    LOAD_DBC(sSummonPropertiesStore, "SummonProperties.dbc");//20444
    LOAD_DBC(sTalentStore, "Talent.dbc");//20444
    LOAD_DBC(sVehicleSeatStore, "VehicleSeat.dbc");//20444
    LOAD_DBC(sVehicleStore, "Vehicle.dbc");//20444
    LOAD_DBC(sWMOAreaTableStore, "WMOAreaTable.dbc");//20444
    LOAD_DBC(sWorldMapAreaStore, "WorldMapArea.dbc");//20444
    LOAD_DBC(sWorldMapTransformsStore, "WorldMapTransforms.dbc");//20444
    LOAD_DBC(sWorldSafeLocsStore, "WorldSafeLocs.dbc"); // 20444

#undef LOAD_DBC

    // must be after sAreaStore loading
    for (uint32 i = 0; i < sAreaStore.GetNumRows(); ++i)           // areaflag numbered from 0
    {
        if (AreaTableEntry const* area = sAreaStore.LookupEntry(i))
        {
            // fill AreaId->DBC records
            sAreaFlagByAreaID.insert(AreaFlagByAreaID::value_type(uint16(area->ID), area->AreaBit));

            // fill MapId->DBC records (skip sub zones and continents)
            if (area->ParentAreaID == 0)
                sAreaFlagByMapID.insert(AreaFlagByMapID::value_type(area->MapID, area->AreaBit));
        }
    }

    for (uint32 i = 0; i < sCharSectionsStore.GetNumRows(); ++i)
        if (CharSectionsEntry const* entry = sCharSectionsStore.LookupEntry(i))
            if (entry->Race && ((1 << (entry->Race - 1)) & RACEMASK_ALL_PLAYABLE) != 0) //ignore Nonplayable races
                sCharSectionMap.insert({ entry->GenType | (entry->Gender << 8) | (entry->Race << 16), entry });

    memset(sChrSpecializationByIndexStore, 0, sizeof(sChrSpecializationByIndexStore));
    for (uint32 i = 0; i < sChrSpecializationStore.GetNumRows(); ++i)
        if (ChrSpecializationEntry const* chrSpec = sChrSpecializationStore.LookupEntry(i))
            sChrSpecializationByIndexStore[chrSpec->ClassID][chrSpec->OrderIndex] = chrSpec;

    for (uint32 i = 0; i < sFactionStore.GetNumRows(); ++i)
    {
        FactionEntry const* faction = sFactionStore.LookupEntry(i);
        if (faction && faction->ParentFactionID)
        {
            std::vector<uint32> &flist = sFactionTeamMap[faction->ParentFactionID];
            flist.push_back(i);
        }
    }

    for (uint32 i = 0; i < sGameObjectDisplayInfoStore.GetNumRows(); ++i)
    {
        if (GameObjectDisplayInfoEntry const* info = sGameObjectDisplayInfoStore.LookupEntry(i))
        {
            if (info->GeoBoxMax.X < info->GeoBoxMin.X)
                std::swap(*(float*)(&info->GeoBoxMax.X), *(float*)(&info->GeoBoxMin.X));
            if (info->GeoBoxMax.Y < info->GeoBoxMin.Y)
                std::swap(*(float*)(&info->GeoBoxMax.Y), *(float*)(&info->GeoBoxMin.Y));
            if (info->GeoBoxMax.Z < info->GeoBoxMin.Z)
                std::swap(*(float*)(&info->GeoBoxMax.Z), *(float*)(&info->GeoBoxMin.Z));
        }
    }

    for (ItemSetSpellEntry const* entry : sItemSetSpellStore)
        sItemSetSpellsStore[entry->ItemSetID].push_back(entry);

    // fill data
    for (uint32 i = 0; i < sMapDifficultyStore.GetNumRows(); ++i)
        if (MapDifficultyEntry const* entry = sMapDifficultyStore.LookupEntry(i))
            sMapDifficultyMap[entry->MapID][entry->DifficultyID] = entry;
    sMapDifficultyMap[0][0] = sMapDifficultyMap[1][0]; //map 0 is missing from MapDifficulty.dbc use this till its ported to sql

    for (uint32 i = 0; i < sPvpDifficultyStore.GetNumRows(); ++i)
        if (PvPDifficultyEntry const* entry = sPvpDifficultyStore.LookupEntry(i))
            if (entry->BracketID > MAX_BATTLEGROUND_BRACKETS)
                ASSERT(false && "Need update MAX_BATTLEGROUND_BRACKETS by DBC data");

    for (uint32 i = 0; i < sSkillRaceClassInfoStore.GetNumRows(); ++i)
        if (SkillRaceClassInfoEntry const* entry = sSkillRaceClassInfoStore.LookupEntry(i))
            if (sSkillLineStore.LookupEntry(entry->SkillID))
                SkillRaceClassInfoBySkill.emplace(entry->SkillID, entry);

    for (uint32 j = 0; j < sSpellEffectScalingStore.GetNumRows(); j++)
    {
        SpellEffectScalingEntry const* spellEffectScaling = sSpellEffectScalingStore.LookupEntry(j);
        if (!spellEffectScaling)
            continue;

        sSpellEffectScallingByEffectId.insert(std::make_pair(spellEffectScaling->SpellEffectID, j));
    }

    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        if (TalentEntry const* talentInfo = sTalentStore.LookupEntry(i))
        {
            if (talentInfo->ClassID < MAX_CLASSES && talentInfo->TierID < MAX_TALENT_TIERS && talentInfo->ColumnIndex < MAX_TALENT_COLUMNS)
                sTalentByPos[talentInfo->ClassID][talentInfo->TierID][talentInfo->ColumnIndex].push_back(talentInfo);
            else
                TC_LOG_ERROR("server.loading", "Value of class (found: %u, max allowed %u) or (found: %u, max allowed %u) tier or column (found: %u, max allowed %u) is invalid.",
                    talentInfo->ClassID, MAX_CLASSES, talentInfo->TierID, MAX_TALENT_TIERS, talentInfo->ColumnIndex, MAX_TALENT_COLUMNS);
        }
    }

    for (uint32 i = 0; i < sWMOAreaTableStore.GetNumRows(); ++i)
        if (WMOAreaTableEntry const* entry = sWMOAreaTableStore.LookupEntry(i))
            sWMOAreaInfoByTripple.insert(WMOAreaInfoByTripple::value_type(WMOAreaTableTripple(entry->WMOID, entry->NameSet, entry->WMOGroupID), entry));

    // error checks
    if (bad_dbc_files.size() >= DBCFileCount)
    {
        TC_LOG_ERROR("misc", "Incorrect DataDir value in worldserver.conf or ALL required *.dbc files (%d) not found by path: %sdbc/%s/", DBCFileCount, dataPath.c_str(), localeNames[defaultLocale]);
        exit(1);
    }
    else if (!bad_dbc_files.empty())
    {
        std::string str;
        for (StoreProblemList::iterator i = bad_dbc_files.begin(); i != bad_dbc_files.end(); ++i)
            str += *i + "\n";

        TC_LOG_ERROR("misc", "Some required *.dbc files (%u from %d) not found or not compatible:\n%s", (uint32)bad_dbc_files.size(), DBCFileCount, str.c_str());
        exit(1);
    }

    // Check loaded DBC files proper version
    if (!sAreaStore.LookupEntry(6565)          ||     // last area (areaflag) added in 6.2.2 (20444)
        !sCharTitlesStore.LookupEntry(457)     ||     // last char title added in 6.2.2 (20444)
        !sGemPropertiesStore.LookupEntry(2544) ||     // last gem property added in 6.2.2 (20444)
        !sMapStore.LookupEntry(1497)           ||     // last map added in 6.2.2 (20444)
        !sSpellStore.LookupEntry(197204)       )      // last spell added in 6.2.2 (20444)
    {
        TC_LOG_ERROR("misc", "You have _outdated_ DBC files. Please extract correct versions from current using client.");
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d DBC data stores in %u ms", DBCFileCount, GetMSTimeDiffToNow(oldMSTime));
}

void LoadGameTables(const std::string& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string dbcPath = dataPath + "dbc/" + localeNames[defaultLocale] + '/';

    StoreProblemList bad_dbc_files;

#define LOAD_GT(tableName, store, file) LoadGameTable(bad_dbc_files, tableName, store, dbcPath, file)

    LOAD_GT("BarberShopCostBase", sGtBarberShopCostBaseStore, "gtBarberShopCostBase.dbc");                      // 20444
    LOAD_GT("CombatRatings", sGtCombatRatingsStore, "gtCombatRatings.dbc");                                     // 20444
    LOAD_GT("ChanceToMeleeCritBase", sGtChanceToMeleeCritBaseStore, "gtChanceToMeleeCritBase.dbc");             // 20444
    LOAD_GT("ChanceToMeleeCrit", sGtChanceToMeleeCritStore, "gtChanceToMeleeCrit.dbc");                         // 20444
    LOAD_GT("ChanceToSpellCritBase", sGtChanceToSpellCritBaseStore, "gtChanceToSpellCritBase.dbc");             // 20444
    LOAD_GT("ChanceToSpellCrit", sGtChanceToSpellCritStore, "gtChanceToSpellCrit.dbc");                         // 20444
    LOAD_GT("ItemSocketCostPerLevel", sGtItemSocketCostPerLevelStore, "gtItemSocketCostPerLevel.dbc");          // 20444
    LOAD_GT("NPCManaCostScaler", sGtNPCManaCostScalerStore, "gtNPCManaCostScaler.dbc");                         // 20444
    LOAD_GT("NpcTotalHp", sGtNpcTotalHpStore, "gtNpcTotalHp.dbc");                                              // 20444
    LOAD_GT("NpcTotalHpExp1", sGtNpcTotalHpExp1Store, "gtNpcTotalHpExp1.dbc");                                  // 20444
    LOAD_GT("NpcTotalHpExp2", sGtNpcTotalHpExp2Store, "gtNpcTotalHpExp2.dbc");                                  // 20444
    LOAD_GT("NpcTotalHpExp3", sGtNpcTotalHpExp3Store, "gtNpcTotalHpExp3.dbc");                                  // 20444
    LOAD_GT("NpcTotalHpExp4", sGtNpcTotalHpExp4Store, "gtNpcTotalHpExp4.dbc");                                  // 20444
    LOAD_GT("NpcTotalHpExp5", sGtNpcTotalHpExp5Store, "gtNpcTotalHpExp5.dbc");                                  // 20444
    LOAD_GT("OCTHPPerStamina", sGtOCTHpPerStaminaStore, "gtOCTHpPerStamina.dbc");                               // 20444
    LOAD_GT("OCTLevelExperience", sGtOCTLevelExperienceStore, "gtOCTLevelExperience.dbc");                      // 20444
    LOAD_GT("RegenMPPerSpt", sGtRegenMPPerSptStore, "gtRegenMPPerSpt.dbc");                                     // 20444
    LOAD_GT("SpellScaling", sGtSpellScalingStore, "gtSpellScaling.dbc");                                        // 20444
    LOAD_GT("OCTBaseHPByClass", sGtOCTBaseHPByClassStore, "gtOCTBaseHPByClass.dbc");                            // 20444
    LOAD_GT("OCTBaseMPByClass", sGtOCTBaseMPByClassStore, "gtOCTBaseMPByClass.dbc");                            // 20444

#undef LOAD_GT

    // error checks
    if (bad_dbc_files.size() >= GameTableCount)
    {
        TC_LOG_ERROR("misc", "Incorrect DataDir value in worldserver.conf or ALL required *.dbc GameTable files (%d) not found by path: %sdbc/%s/", DBCFileCount, dataPath.c_str(), localeNames[defaultLocale]);
        exit(1);
    }
    else if (!bad_dbc_files.empty())
    {
        std::string str;
        for (StoreProblemList::iterator i = bad_dbc_files.begin(); i != bad_dbc_files.end(); ++i)
            str += *i + "\n";

        TC_LOG_ERROR("misc", "Some required *.dbc GameTable files (%u from %d) not found or not compatible:\n%s", (uint32)bad_dbc_files.size(), GameTableCount, str.c_str());
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d DBC GameTables data stores in %u ms", GameTableCount, GetMSTimeDiffToNow(oldMSTime));
}

std::vector<uint32> const* GetFactionTeamList(uint32 faction)
{
    FactionTeamMap::const_iterator itr = sFactionTeamMap.find(faction);
    if (itr != sFactionTeamMap.end())
        return &itr->second;

    return NULL;
}

char const* GetCreatureFamilyPetName(uint32 petfamily, uint32 /*locale*/)
{
    if (!petfamily)
        return nullptr;

    CreatureFamilyEntry const* pet_family = sCreatureFamilyStore.LookupEntry(petfamily);
    if (!pet_family)
        return nullptr;

    return pet_family->Name_lang ? pet_family->Name_lang : NULL;
}

int32 GetAreaFlagByAreaID(uint32 area_id)
{
    AreaFlagByAreaID::iterator i = sAreaFlagByAreaID.find(area_id);
    if (i == sAreaFlagByAreaID.end())
        return -1;

    return i->second;
}

WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid)
{
    WMOAreaInfoByTripple::iterator i = sWMOAreaInfoByTripple.find(WMOAreaTableTripple(rootid, adtid, groupid));
        if (i == sWMOAreaInfoByTripple.end())
            return NULL;
        return i->second;
}

AreaTableEntry const* GetAreaEntryByAreaID(uint32 area_id)
{
    int32 areaflag = GetAreaFlagByAreaID(area_id);
    if (areaflag < 0)
        return NULL;

    return sAreaStore.LookupEntry(areaflag);
}

AreaTableEntry const* GetAreaEntryByAreaFlagAndMap(uint32 area_flag, uint32 map_id)
{
    if (area_flag)
        return sAreaStore.LookupEntry(area_flag);

    if (MapEntry const* mapEntry = sMapStore.LookupEntry(map_id))
        return GetAreaEntryByAreaID(mapEntry->AreaTableID);

    return NULL;
}

char const* GetRaceName(uint8 race, uint8 /*locale*/)
{
    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
    return raceEntry ? raceEntry->Name_lang : NULL;
}

char const* GetClassName(uint8 class_, uint8 /*locale*/)
{
    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);
    return classEntry ? classEntry->Name_lang : NULL;
}

uint32 GetAreaFlagByMapId(uint32 mapid)
{
    AreaFlagByMapID::iterator i = sAreaFlagByMapID.find(mapid);
    if (i == sAreaFlagByMapID.end())
        return 0;
    else
        return i->second;
}

uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId)
{
    if (mapid != 530 && mapid != 571 && mapid != 732)   // speed for most cases
        return mapid;

    if (WorldMapAreaEntry const* wma = sWorldMapAreaStore.LookupEntry(zoneId))
        return wma->DisplayMapID >= 0 ? wma->DisplayMapID : wma->MapID;

    return mapid;
}

uint32 GetMaxLevelForExpansion(uint32 expansion)
{
    switch (expansion)
    {
        case EXPANSION_CLASSIC:
            return 60;
        case EXPANSION_THE_BURNING_CRUSADE:
            return 70;
        case EXPANSION_WRATH_OF_THE_LICH_KING:
            return 80;
        case EXPANSION_CATACLYSM:
            return 85;
        case EXPANSION_MISTS_OF_PANDARIA:
            return 90;
        case EXPANSION_WARLORDS_OF_DRAENOR:
            return 100;
        default:
            break;
    }
    return 0;
}

uint32 GetExpansionForLevel(uint32 level)
{
    if (level < 60)
        return EXPANSION_CLASSIC;
    else if (level < 70)
        return EXPANSION_THE_BURNING_CRUSADE;
    else if (level < 80)
        return EXPANSION_WRATH_OF_THE_LICH_KING;
    else if (level < 85)
        return EXPANSION_CATACLYSM;
    else if (level < 90)
        return EXPANSION_MISTS_OF_PANDARIA;
    else
        return CURRENT_EXPANSION;
}

bool IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId)
{
    if (requiredTotemCategoryId == 0)
        return true;
    if (itemTotemCategoryId == 0)
        return false;

    TotemCategoryEntry const* itemEntry = sTotemCategoryStore.LookupEntry(itemTotemCategoryId);
    if (!itemEntry)
        return false;
    TotemCategoryEntry const* reqEntry = sTotemCategoryStore.LookupEntry(requiredTotemCategoryId);
    if (!reqEntry)
        return false;

    if (itemEntry->CategoryType != reqEntry->CategoryType)
        return false;

    return (itemEntry->CategoryMask & reqEntry->CategoryMask) == reqEntry->CategoryMask;
}

void Zone2MapCoordinates(float& x, float& y, uint32 worldMapAreaId)
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(worldMapAreaId);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return;

    std::swap(x, y);                                         // at client map coords swapped
    x = x*((maEntry->LocBottom-maEntry->LocTop)/100)+maEntry->LocTop;
    y = y*((maEntry->LocRight-maEntry->LocLeft)/100)+maEntry->LocLeft;      // client y coord from top to down
}

void Map2ZoneCoordinates(float& x, float& y, uint32 worldMapAreaId)
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(worldMapAreaId);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return;

    x = (x - maEntry->LocTop) / ((maEntry->LocBottom - maEntry->LocTop) / 100);
    y = (y - maEntry->LocLeft) / ((maEntry->LocRight - maEntry->LocLeft) / 100);    // client y coord from top to down
    std::swap(x, y);                                         // client have map coords swapped
}

MapDifficultyEntry const* GetDefaultMapDifficulty(uint32 mapId, Difficulty* difficulty /*= nullptr*/)
{
    auto itr = sMapDifficultyMap.find(mapId);
    if (itr == sMapDifficultyMap.end())
        return nullptr;

    if (itr->second.empty())
        return nullptr;

    for (auto& p : itr->second)
    {
        DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(p.first);
        if (!difficultyEntry)
            continue;

        if (difficultyEntry->Flags & DIFFICULTY_FLAG_DEFAULT)
        {
            if (difficulty)
                *difficulty = Difficulty(p.first);

            return p.second;
        }
    }

    if (difficulty)
        *difficulty = Difficulty(itr->second.begin()->first);

    return itr->second.begin()->second;
}

MapDifficultyEntry const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty)
{
    auto itr = sMapDifficultyMap.find(mapId);
    if (itr == sMapDifficultyMap.end())
        return nullptr;

    auto diffItr = itr->second.find(difficulty);
    if (diffItr == itr->second.end())
        return nullptr;

    return diffItr->second;
}

MapDifficultyEntry const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty)
{
    DifficultyEntry const* diffEntry = sDifficultyStore.LookupEntry(difficulty);
    if (!diffEntry)
        return GetDefaultMapDifficulty(mapId, &difficulty);

    uint32 tmpDiff = difficulty;
    MapDifficultyEntry const* mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff));
    while (!mapDiff)
    {
        tmpDiff = diffEntry->FallbackDifficultyID;
        diffEntry = sDifficultyStore.LookupEntry(tmpDiff);
        if (!diffEntry)
            return GetDefaultMapDifficulty(mapId, &difficulty);

        // pull new data
        mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // we are 10 normal or 25 normal
    }

    difficulty = Difficulty(tmpDiff);
    return mapDiff;
}

PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level)
{
    PvPDifficultyEntry const* maxEntry = NULL;              // used for level > max listed level case
    for (uint32 i = 0; i < sPvpDifficultyStore.GetNumRows(); ++i)
    {
        if (PvPDifficultyEntry const* entry = sPvpDifficultyStore.LookupEntry(i))
        {
            // skip unrelated and too-high brackets
            if (entry->MapID != mapid || entry->MinLevel > level)
                continue;

            // exactly fit
            if (entry->MaxLevel >= level)
                return entry;

            // remember for possible out-of-range case (search higher from existed)
            if (!maxEntry || maxEntry->MaxLevel < entry->MaxLevel)
                maxEntry = entry;
        }
    }

    return maxEntry;
}

PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id)
{
    for (uint32 i = 0; i < sPvpDifficultyStore.GetNumRows(); ++i)
        if (PvPDifficultyEntry const* entry = sPvpDifficultyStore.LookupEntry(i))
            if (entry->MapID == mapid && entry->GetBracketId() == id)
                return entry;

    return NULL;
}

uint32 GetLiquidFlags(uint32 liquidType)
{
    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquidType))
        return 1 << liq->Type;

    return 0;
}

CharSectionsEntry const* GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color)
{
    std::pair<CharSectionsMap::const_iterator, CharSectionsMap::const_iterator> eqr = sCharSectionMap.equal_range(uint32(genType) | uint32(gender << 8) | uint32(race << 16));
    for (CharSectionsMap::const_iterator itr = eqr.first; itr != eqr.second; ++itr)
    {
        if (itr->second->Type == type && itr->second->Color == color)
            return itr->second;
    }

    return NULL;
}

/// Returns LFGDungeonEntry for a specific map and difficulty. Will return first found entry if multiple dungeons use the same map (such as Scarlet Monastery)
LFGDungeonEntry const* GetLFGDungeon(uint32 mapId, Difficulty difficulty)
{
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(i);
        if (!dungeon)
            continue;

        if (dungeon->MapID == int32(mapId) && Difficulty(dungeon->DifficultyID) == difficulty)
            return dungeon;
    }

    return NULL;
}

uint32 GetDefaultMapLight(uint32 mapId)
{
    for (int32 i = sLightStore.GetNumRows(); i >= 0; --i)
    {
        LightEntry const* light = sLightStore.LookupEntry(uint32(i));
        if (!light)
            continue;

        if (light->MapID == mapId && light->Pos.X == 0.0f && light->Pos.Y == 0.0f && light->Pos.Z == 0.0f)
            return light->ID;
    }

    return 0;
}

SkillRaceClassInfoEntry const* GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_)
{
    SkillRaceClassInfoBounds bounds = SkillRaceClassInfoBySkill.equal_range(skill);
    for (SkillRaceClassInfoMap::iterator itr = bounds.first; itr != bounds.second; ++itr)
    {
        if (itr->second->RaceMask && !(itr->second->RaceMask & (1 << (race - 1))))
            continue;
        if (itr->second->ClassMask && !(itr->second->ClassMask & (1 << (class_ - 1))))
            continue;

        return itr->second;
    }

    return NULL;
}
