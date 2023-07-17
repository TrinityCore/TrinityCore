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

#include "DBCStores.h"
#include "Containers.h"
#include "DBCFileLoader.h"
#include "DBCfmt.h"
#include "Errors.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "ObjectDefines.h"
#include "Player.h"
#include "Regex.h"
#include "SharedDefines.h"
#include "SpellMgr.h"
#include "Timer.h"

 // temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

typedef std::map<uint16, uint32> AreaFlagByAreaID;
typedef std::map<uint32, uint32> AreaFlagByMapID;

typedef std::tuple<int16, int8, int32> WMOAreaTableKey;
typedef std::map<WMOAreaTableKey, WMOAreaTableEntry const*> WMOAreaInfoByTripple;
typedef std::multimap<uint32, CharSectionsEntry const*> CharSectionsMap;

DBCStorage <AreaTableEntry> sAreaTableStore(AreaTableEntryfmt);
DBCStorage <AreaGroupEntry> sAreaGroupStore(AreaGroupEntryfmt);
DBCStorage <AreaPOIEntry> sAreaPOIStore(AreaPOIEntryfmt);

static WMOAreaInfoByTripple sWMOAreaInfoByTripple;

DBCStorage <AchievementEntry> sAchievementStore(Achievementfmt);
DBCStorage <AnimKitEntry> sAnimKitStore(AnimKitfmt);
DBCStorage <AchievementCriteriaEntry> sAchievementCriteriaStore(AchievementCriteriafmt);
DBCStorage <AreaTriggerEntry> sAreaTriggerStore(AreaTriggerEntryfmt);
DBCStorage <ArmorLocationEntry> sArmorLocationStore(ArmorLocationfmt);
DBCStorage <AuctionHouseEntry> sAuctionHouseStore(AuctionHouseEntryfmt);
DBCStorage <BankBagSlotPricesEntry> sBankBagSlotPricesStore(BankBagSlotPricesEntryfmt);
DBCStorage <BannedAddOnsEntry> sBannedAddOnsStore(BannedAddOnsfmt);
DBCStorage <BattlemasterListEntry> sBattlemasterListStore(BattlemasterListEntryfmt);
DBCStorage <BarberShopStyleEntry> sBarberShopStyleStore(BarberShopStyleEntryfmt);
DBCStorage <CharStartOutfitEntry> sCharStartOutfitStore(CharStartOutfitEntryfmt);
std::map<uint32, CharStartOutfitEntry const*> sCharStartOutfitMap;
DBCStorage <CharSectionsEntry> sCharSectionsStore(CharSectionsEntryfmt);
CharSectionsMap sCharSectionMap;
DBCStorage <CharTitlesEntry> sCharTitlesStore(CharTitlesEntryfmt);
DBCStorage <ChatChannelsEntry> sChatChannelsStore(ChatChannelsEntryfmt);
DBCStorage <ChrClassesEntry> sChrClassesStore(ChrClassesEntryfmt);
DBCStorage <ChrRacesEntry> sChrRacesStore(ChrRacesEntryfmt);
DBCStorage <ChrPowerTypesEntry> sChrPowerTypesStore(ChrClassesXPowerTypesfmt);
DBCStorage <CinematicCameraEntry> sCinematicCameraStore(CinematicCameraEntryfmt);
DBCStorage <CinematicSequencesEntry> sCinematicSequencesStore(CinematicSequencesEntryfmt);
DBCStorage <CreatureDisplayInfoEntry> sCreatureDisplayInfoStore(CreatureDisplayInfofmt);
DBCStorage <CreatureDisplayInfoExtraEntry> sCreatureDisplayInfoExtraStore(CreatureDisplayInfoExtrafmt);
DBCStorage <CreatureFamilyEntry> sCreatureFamilyStore(CreatureFamilyfmt);
DBCStorage <CreatureModelDataEntry> sCreatureModelDataStore(CreatureModelDatafmt);
DBCStorage <CreatureSpellDataEntry> sCreatureSpellDataStore(CreatureSpellDatafmt);
DBCStorage <CreatureTypeEntry> sCreatureTypeStore(CreatureTypefmt);
DBCStorage <CurrencyTypesEntry> sCurrencyTypesStore(CurrencyTypesfmt);
uint32 PowersByClass[MAX_CLASSES][MAX_POWERS];

DBCStorage <DestructibleModelDataEntry> sDestructibleModelDataStore(DestructibleModelDatafmt);
DBCStorage <DungeonEncounterEntry> sDungeonEncounterStore(DungeonEncounterfmt);
DBCStorage <DurabilityQualityEntry> sDurabilityQualityStore(DurabilityQualityfmt);
DBCStorage <DurabilityCostsEntry> sDurabilityCostsStore(DurabilityCostsfmt);

DBCStorage <EmotesEntry> sEmotesStore(EmotesEntryfmt);
DBCStorage <EmotesTextEntry> sEmotesTextStore(EmotesTextEntryfmt);
typedef std::tuple<uint32, uint32, uint32> EmotesTextSoundKey;
static std::map<EmotesTextSoundKey, EmotesTextSoundEntry const*> sEmotesTextSoundMap;
DBCStorage <EmotesTextSoundEntry> sEmotesTextSoundStore(EmotesTextSoundEntryfmt);

typedef std::map<uint32, SimpleFactionsList> FactionTeamMap;
static FactionTeamMap sFactionTeamMap;
DBCStorage <FactionEntry> sFactionStore(FactionEntryfmt);
DBCStorage <FactionTemplateEntry> sFactionTemplateStore(FactionTemplateEntryfmt);

// Used exclusively for data validation
DBCStorage <GameObjectArtKitEntry> sGameObjectArtKitStore(GameObjectArtKitfmt);

DBCStorage <GameObjectDisplayInfoEntry> sGameObjectDisplayInfoStore(GameObjectDisplayInfofmt);
DBCStorage <GemPropertiesEntry> sGemPropertiesStore(GemPropertiesEntryfmt);
DBCStorage <GlyphPropertiesEntry> sGlyphPropertiesStore(GlyphPropertiesfmt);
DBCStorage <GlyphSlotEntry> sGlyphSlotStore(GlyphSlotfmt);

DBCStorage <GtBarberShopCostBaseEntry>    sGtBarberShopCostBaseStore(GtBarberShopCostBasefmt);
DBCStorage <GtCombatRatingsEntry>         sGtCombatRatingsStore(GtCombatRatingsfmt);
DBCStorage <GtChanceToMeleeCritBaseEntry> sGtChanceToMeleeCritBaseStore(GtChanceToMeleeCritBasefmt);
DBCStorage <GtChanceToMeleeCritEntry>     sGtChanceToMeleeCritStore(GtChanceToMeleeCritfmt);
DBCStorage <GtChanceToSpellCritBaseEntry> sGtChanceToSpellCritBaseStore(GtChanceToSpellCritBasefmt);
DBCStorage <GtChanceToSpellCritEntry>     sGtChanceToSpellCritStore(GtChanceToSpellCritfmt);
DBCStorage <GtNPCManaCostScalerEntry>     sGtNPCManaCostScalerStore(GtNPCManaCostScalerfmt);
DBCStorage <GtOCTClassCombatRatingScalarEntry> sGtOCTClassCombatRatingScalarStore(GtOCTClassCombatRatingScalarfmt);
DBCStorage <GtOCTRegenHPEntry>            sGtOCTRegenHPStore(GtOCTRegenHPfmt);
//DBCStorage <GtOCTRegenMPEntry>            sGtOCTRegenMPStore(GtOCTRegenMPfmt);  -- not used currently
DBCStorage <gtOCTHpPerStaminaEntry>       sGtOCTHpPerStaminaStore(GtOCTHpPerStaminafmt);
DBCStorage <GtRegenMPPerSptEntry>         sGtRegenMPPerSptStore(GtRegenMPPerSptfmt);
DBCStorage <GtSpellScalingEntry>          sGtSpellScalingStore(GtSpellScalingfmt);
DBCStorage <GtOCTBaseHPByClassEntry>      sGtOCTBaseHPByClassStore(GtOCTBaseHPByClassfmt);
DBCStorage <GtOCTBaseMPByClassEntry>      sGtOCTBaseMPByClassStore(GtOCTBaseMPByClassfmt);
DBCStorage <GuildPerkSpellsEntry>         sGuildPerkSpellsStore(GuildPerkSpellsfmt);

DBCStorage <HolidaysEntry>                sHolidaysStore(Holidaysfmt);

DBCStorage <ImportPriceArmorEntry>        sImportPriceArmorStore(ImportPriceArmorfmt);
DBCStorage <ImportPriceQualityEntry>      sImportPriceQualityStore(ImportPriceQualityfmt);
DBCStorage <ImportPriceShieldEntry>       sImportPriceShieldStore(ImportPriceShieldfmt);
DBCStorage <ImportPriceWeaponEntry>       sImportPriceWeaponStore(ImportPriceWeaponfmt);
DBCStorage <ItemPriceBaseEntry>           sItemPriceBaseStore(ItemPriceBasefmt);
DBCStorage <ItemReforgeEntry>             sItemReforgeStore(ItemReforgefmt);
DBCStorage <ItemArmorQualityEntry>        sItemArmorQualityStore(ItemArmorQualityfmt);
DBCStorage <ItemArmorShieldEntry>         sItemArmorShieldStore(ItemArmorShieldfmt);
DBCStorage <ItemArmorTotalEntry>          sItemArmorTotalStore(ItemArmorTotalfmt);
DBCStorage <ItemClassEntry>               sItemClassStore(ItemClassfmt);
DBCStorage <ItemBagFamilyEntry>           sItemBagFamilyStore(ItemBagFamilyfmt);
DBCStorage <ItemDamageEntry>              sItemDamageAmmoStore(ItemDamagefmt);
DBCStorage <ItemDamageEntry>              sItemDamageOneHandStore(ItemDamagefmt);
DBCStorage <ItemDamageEntry>              sItemDamageOneHandCasterStore(ItemDamagefmt);
DBCStorage <ItemDamageEntry>              sItemDamageRangedStore(ItemDamagefmt);
DBCStorage <ItemDamageEntry>              sItemDamageThrownStore(ItemDamagefmt);
DBCStorage <ItemDamageEntry>              sItemDamageTwoHandStore(ItemDamagefmt);
DBCStorage <ItemDamageEntry>              sItemDamageTwoHandCasterStore(ItemDamagefmt);
DBCStorage <ItemDamageEntry>              sItemDamageWandStore(ItemDamagefmt);
DBCStorage <ItemDisenchantLootEntry>      sItemDisenchantLootStore(ItemDisenchantLootfmt);
//DBCStorage <ItemDisplayInfoEntry> sItemDisplayInfoStore(ItemDisplayTemplateEntryfmt); -- not used currently
DBCStorage <ItemLimitCategoryEntry>       sItemLimitCategoryStore(ItemLimitCategoryEntryfmt);
DBCStorage <ItemRandomPropertiesEntry>    sItemRandomPropertiesStore(ItemRandomPropertiesfmt);
DBCStorage <ItemRandomSuffixEntry>        sItemRandomSuffixStore(ItemRandomSuffixfmt);
DBCStorage <ItemSetEntry>                 sItemSetStore(ItemSetEntryfmt);

DBCStorage <LFGDungeonEntry> sLFGDungeonStore(LFGDungeonEntryfmt);
DBCStorage <LFGDungeonsGroupingMapEntry> sLFGDungeonsGroupingMapStore(LFGDungeonsGroupingMapfmt);
DBCStorage <LightEntry> sLightStore(LightEntryfmt);
DBCStorage <LiquidTypeEntry> sLiquidTypeStore(LiquidTypefmt);
DBCStorage <LockEntry> sLockStore(LockEntryfmt);

DBCStorage <MailTemplateEntry> sMailTemplateStore(MailTemplateEntryfmt);
DBCStorage <MapEntry> sMapStore(MapEntryfmt);

MapDifficultyMap sMapDifficultyMap;

DBCStorage <MovieEntry> sMovieStore(MovieEntryfmt);
DBCStorage <MountCapabilityEntry> sMountCapabilityStore(MountCapabilityfmt);
DBCStorage <MountTypeEntry> sMountTypeStore(MountTypefmt);

NameGenVectorArraysMap sGenNameVectoArraysMap;
DBCStorage <NumTalentsAtLevelEntry> sNumTalentsAtLevelStore(NumTalentsAtLevelfmt);

typedef std::array<std::vector<Trinity::wregex>, TOTAL_LOCALES> NameValidationRegexContainer;
NameValidationRegexContainer NamesProfaneValidators;
NameValidationRegexContainer NamesReservedValidators;

DBCStorage <OverrideSpellDataEntry> sOverrideSpellDataStore(OverrideSpellDatafmt);

DBCStorage <PlayerConditionEntry> sPlayerConditionStore(PlayerConditionfmt);
DBCStorage <PowerDisplayEntry> sPowerDisplayStore(PowerDisplayfmt);
DBCStorage <PvPDifficultyEntry> sPvPDifficultyStore(PvPDifficultyfmt);

DBCStorage <QuestSortEntry> sQuestSortStore(QuestSortEntryfmt);
DBCStorage <QuestXPEntry>   sQuestXPStore(QuestXPfmt);
DBCStorage <QuestFactionRewEntry>  sQuestFactionRewardStore(QuestFactionRewardfmt);
DBCStorage <QuestPOIBlobEntry> sQuestPOIBlobStore(QuestPOIBlobfmt);
DBCStorage <QuestPOIPointEntry> sQuestPOIPointStore(QuestPOIPointfmt);
DBCStorage <RandomPropertiesPointsEntry> sRandomPropertiesPointsStore(RandomPropertiesPointsfmt);
DBCStorage <ScalingStatDistributionEntry> sScalingStatDistributionStore(ScalingStatDistributionfmt);
DBCStorage <ScalingStatValuesEntry> sScalingStatValuesStore(ScalingStatValuesfmt);

DBCStorage <SkillLineEntry> sSkillLineStore(SkillLinefmt);
DBCStorage <SkillLineAbilityEntry> sSkillLineAbilityStore(SkillLineAbilityfmt);
DBCStorage <SkillRaceClassInfoEntry> sSkillRaceClassInfoStore(SkillRaceClassInfofmt);
SkillRaceClassInfoMap SkillRaceClassInfoBySkill;
DBCStorage <SkillTiersEntry> sSkillTiersStore(SkillTiersfmt);

DBCStorage <SoundEntriesEntry> sSoundEntriesStore(SoundEntriesfmt);

DBCStorage <SpellItemEnchantmentEntry> sSpellItemEnchantmentStore(SpellItemEnchantmentfmt);
DBCStorage <SpellItemEnchantmentConditionEntry> sSpellItemEnchantmentConditionStore(SpellItemEnchantmentConditionfmt);
DBCStorage <SpellEntry> sSpellStore(SpellEntryfmt);
PetFamilySpellsStore sPetFamilySpellsStore;

DBCStorage <ResearchBranchEntry> sResearchBranchStore(ResearchBranchEntryfmt);
DBCStorage <ResearchFieldEntry>  sResearchFieldStore(ResearchFieldEntryfmt);
DBCStorage <ResearchProjectEntry> sResearchProjectStore(ResearchProjectEntryfmt);
DBCStorage <ResearchSiteEntry>  sResearchSiteStore(ResearchSiteEntryfmt);

DBCStorage <SpellReagentsEntry> sSpellReagentsStore(SpellReagentsEntryfmt);
DBCStorage <SpellScalingEntry> sSpellScalingStore(SpellScalingEntryfmt);
DBCStorage <SpellTotemsEntry> sSpellTotemsStore(SpellTotemsEntryfmt);
DBCStorage <SpellTargetRestrictionsEntry> sSpellTargetRestrictionsStore(SpellTargetRestrictionsEntryfmt);
DBCStorage <SpellPowerEntry> sSpellPowerStore(SpellPowerEntryfmt);
DBCStorage <SpellLevelsEntry> sSpellLevelsStore(SpellLevelsEntryfmt);
DBCStorage <SpellInterruptsEntry> sSpellInterruptsStore(SpellInterruptsEntryfmt);
DBCStorage <SpellEquippedItemsEntry> sSpellEquippedItemsStore(SpellEquippedItemsEntryfmt);
DBCStorage <SpellClassOptionsEntry> sSpellClassOptionsStore(SpellClassOptionsEntryfmt);
DBCStorage <SpellCooldownsEntry> sSpellCooldownsStore(SpellCooldownsEntryfmt);
DBCStorage <SpellAuraOptionsEntry> sSpellAuraOptionsStore(SpellAuraOptionsEntryfmt);
DBCStorage <SpellAuraRestrictionsEntry> sSpellAuraRestrictionsStore(SpellAuraRestrictionsEntryfmt);
DBCStorage <SpellCastingRequirementsEntry> sSpellCastingRequirementsStore(SpellCastingRequirementsEntryfmt);
DBCStorage <SpellCastTimesEntry> sSpellCastTimesStore(SpellCastTimefmt);
DBCStorage <SpellCategoriesEntry> sSpellCategoriesStore(SpellCategoriesEntryfmt);
DBCStorage <SpellCategoryEntry> sSpellCategoryStore(SpellCategoryfmt);
DBCStorage <SpellEffectEntry> sSpellEffectStore(SpellEffectEntryfmt);
DBCStorage <SpellDifficultyEntry> sSpellDifficultyStore(SpellDifficultyfmt);
DBCStorage <SpellDurationEntry> sSpellDurationStore(SpellDurationfmt);
DBCStorage <SpellFocusObjectEntry> sSpellFocusObjectStore(SpellFocusObjectfmt);
DBCStorage <SpellRadiusEntry> sSpellRadiusStore(SpellRadiusfmt);
DBCStorage <SpellRangeEntry> sSpellRangeStore(SpellRangefmt);
DBCStorage <SpellRuneCostEntry> sSpellRuneCostStore(SpellRuneCostfmt);
DBCStorage <SpellShapeshiftEntry> sSpellShapeshiftStore(SpellShapeshiftEntryfmt);
DBCStorage <SpellShapeshiftFormEntry> sSpellShapeshiftFormStore(SpellShapeshiftFormfmt);
DBCStorage <SpellVisualEntry> sSpellVisualStore(SpellVisualfmt);
DBCStorage <SpellVisualKitEntry> sSpellVisualKitStore(SpellVisualKitfmt);
DBCStorage <SummonPropertiesEntry> sSummonPropertiesStore(SummonPropertiesfmt);
DBCStorage <TalentEntry> sTalentStore(TalentEntryfmt);
TalentSpellPosMap sTalentSpellPosMap;
DBCStorage <TalentTabEntry> sTalentTabStore(TalentTabEntryfmt);
typedef std::map<uint32, std::vector<uint32>> TalentTreePrimarySpellsMap;
TalentTreePrimarySpellsMap sTalentTreePrimarySpellsMap;

// store absolute bit position for first rank for talent inspect
static uint32 sTalentTabPages[MAX_CLASSES][3];

DBCStorage <TaxiNodesEntry> sTaxiNodesStore(TaxiNodesEntryfmt);
TaxiMask sTaxiNodesMask;
TaxiMask sOldContinentsNodesMask;
TaxiMask sHordeTaxiNodesMask;
TaxiMask sAllianceTaxiNodesMask;
TaxiMask sDeathKnightTaxiNodesMask;

TaxiPathSetBySource sTaxiPathSetBySource;
DBCStorage <TaxiPathEntry> sTaxiPathStore(TaxiPathEntryfmt);

// DBC used only for initialization sTaxiPathNodeStore at startup.
TaxiPathNodesByPath sTaxiPathNodesByPath;
DBCStorage <TaxiPathNodeEntry> sTaxiPathNodeStore(TaxiPathNodeEntryfmt);

DBCStorage <TotemCategoryEntry> sTotemCategoryStore(TotemCategoryEntryfmt);
DBCStorage <TransportAnimationEntry> sTransportAnimationStore(TransportAnimationfmt);
DBCStorage <TransportRotationEntry> sTransportRotationStore(TransportRotationfmt);
DBCStorage <UnitPowerBarEntry> sUnitPowerBarStore(UnitPowerBarfmt);
DBCStorage <VehicleEntry> sVehicleStore(VehicleEntryfmt);
DBCStorage <VehicleSeatEntry> sVehicleSeatStore(VehicleSeatEntryfmt);
DBCStorage <WMOAreaTableEntry> sWMOAreaTableStore(WMOAreaTableEntryfmt);
DBCStorage <WorldMapAreaEntry> sWorldMapAreaStore(WorldMapAreaEntryfmt);
DBCStorage <WorldMapOverlayEntry> sWorldMapOverlayStore(WorldMapOverlayEntryfmt);
DBCStorage <WorldSafeLocsEntry> sWorldSafeLocsStore(WorldSafeLocsEntryfmt);
DBCStorage <PhaseEntry> sPhaseStore(PhaseEntryfmt);

PhaseGroupContainer sPhasesByGroup;

typedef std::list<std::string> StoreProblemList;

uint32 DBCFileCount = 0;

DBCManager& DBCManager::Instance()
{
    static DBCManager instance;
    return instance;
}

static bool LoadDBC_assert_print(uint32 fsize, uint32 rsize, const std::string& filename)
{
    TC_LOG_ERROR("misc", "Size of '%s' set by format string (%u) not equal size of C++ structure (%u).", filename.c_str(), fsize, rsize);

    // ASSERT must fail after function call
    return false;
}

namespace
{
    std::unordered_map<uint32, std::vector<SkillLineAbilityEntry const*>> _skillLineAbilitiesBySkillupSkill;
}

template<class T>
inline void LoadDBC(uint32& availableDbcLocales, StoreProblemList& errors, DBCStorage<T>& storage, std::string const& dbcPath, std::string const& filename, uint32 defaultLocale, std::string const& customFormat = std::string(), std::string const& customIndexName = std::string())
{
    // compatibility format and C++ structure sizes
    ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T) || LoadDBC_assert_print(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()), sizeof(T), filename));

    ++DBCFileCount;
    std::string dbcFilename = dbcPath + localeNames[defaultLocale] + '/' + filename;

    if (storage.Load(dbcFilename))
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
                availableDbcLocales &= ~(1 << i);             // mark as not available for speedup next checks
        }

        if (!customFormat.empty())
            storage.LoadFromDB(filename, customFormat, customIndexName);
    }
    else
    {
        // sort problematic dbc to (1) non compatible and (2) non-existed
        if (FILE* f = fopen(dbcFilename.c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << dbcFilename << " exists, and has " << storage.GetFieldCount() << " field(s) (expected " << strlen(storage.GetFormat()) << "). Extracted file might be from wrong client version or a database-update has been forgotten. Search on forum for TCE00008 for more info.";
            std::string buf = stream.str();
            errors.push_back(buf);
            fclose(f);
        }
        else
            errors.push_back(dbcFilename);
    }
}

void DBCManager::LoadStores(const std::string& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string dbcPath = dataPath + "dbc/";

    StoreProblemList bad_dbc_files;
    uint32 availableDbcLocales = 0xFFFFFFFF;

    // Local DBCs (used only to load some internal storage)
    DBCStorage<MapDifficultyEntry> sMapDifficultyStore(MapDifficultyEntryfmt);
    DBCStorage<NameGenEntry> sNameGenStore(NameGenfmt);
    DBCStorage<NamesProfanityEntry> sNamesProfanityStore(NamesProfanityEntryfmt);
    DBCStorage<NamesReservedEntry> sNamesReservedStore(NamesReservedEntryfmt);
    DBCStorage<PhaseGroupEntry> sPhaseGroupStore(PhaseGroupfmt);
    DBCStorage<TalentTreePrimarySpellsEntry> sTalentTreePrimarySpellsStore(TalentTreePrimarySpellsfmt);

#define LOAD_DBC(store, file) LoadDBC(availableDbcLocales, bad_dbc_files, store, dbcPath, file, defaultLocale)

    LOAD_DBC(sAreaTableStore,                     "AreaTable.dbc");
    LOAD_DBC(sAnimKitStore,                       "AnimKit.dbc");//15595
    LOAD_DBC(sAchievementCriteriaStore,           "Achievement_Criteria.dbc");//15595
    LOAD_DBC(sAreaTriggerStore,                   "AreaTrigger.dbc");//15595
    LOAD_DBC(sAreaGroupStore,                     "AreaGroup.dbc");//15595
    LOAD_DBC(sAreaPOIStore,                       "AreaPOI.dbc");//15595
    LOAD_DBC(sAuctionHouseStore,                  "AuctionHouse.dbc");//15595
    LOAD_DBC(sArmorLocationStore,                 "ArmorLocation.dbc");//15595
    LOAD_DBC(sBankBagSlotPricesStore,             "BankBagSlotPrices.dbc");//15595
    LOAD_DBC(sBannedAddOnsStore,                  "BannedAddOns.dbc");
    LOAD_DBC(sBattlemasterListStore,              "BattlemasterList.dbc");//15595
    LOAD_DBC(sBarberShopStyleStore,               "BarberShopStyle.dbc");//15595
    LOAD_DBC(sCharStartOutfitStore,               "CharStartOutfit.dbc");//15595
    LOAD_DBC(sCharSectionsStore,                  "CharSections.dbc");
    LOAD_DBC(sCharTitlesStore,                    "CharTitles.dbc");//15595
    LOAD_DBC(sChatChannelsStore,                  "ChatChannels.dbc");//15595
    LOAD_DBC(sChrClassesStore,                    "ChrClasses.dbc");//15595
    LOAD_DBC(sChrRacesStore,                      "ChrRaces.dbc");//15595
    LOAD_DBC(sChrPowerTypesStore,                 "ChrClassesXPowerTypes.dbc");//15595
    LOAD_DBC(sEmotesTextSoundStore,               "EmotesTextSound.dbc");
    LOAD_DBC(sCinematicCameraStore,               "CinematicCamera.dbc");
    LOAD_DBC(sCinematicSequencesStore,            "CinematicSequences.dbc");//15595
    LOAD_DBC(sCreatureDisplayInfoStore,           "CreatureDisplayInfo.dbc");//15595
    LOAD_DBC(sCreatureDisplayInfoExtraStore,      "CreatureDisplayInfoExtra.dbc");//15595
    LOAD_DBC(sCreatureFamilyStore,                "CreatureFamily.dbc");//15595
    LOAD_DBC(sCreatureModelDataStore,             "CreatureModelData.dbc");//15595
    LOAD_DBC(sCreatureSpellDataStore,             "CreatureSpellData.dbc");//15595
    LOAD_DBC(sCreatureTypeStore,                  "CreatureType.dbc");//15595
    LOAD_DBC(sCurrencyTypesStore,                 "CurrencyTypes.dbc");//15595
    LOAD_DBC(sDestructibleModelDataStore,         "DestructibleModelData.dbc");//15595
    LOAD_DBC(sDungeonEncounterStore,              "DungeonEncounter.dbc");//15595
    LOAD_DBC(sDurabilityCostsStore,               "DurabilityCosts.dbc");//15595
    LOAD_DBC(sDurabilityQualityStore,             "DurabilityQuality.dbc");//15595
    LOAD_DBC(sEmotesStore,                        "Emotes.dbc");//15595
    LOAD_DBC(sEmotesTextStore,                    "EmotesText.dbc");//15595
    LOAD_DBC(sFactionStore,                       "Faction.dbc");//15595
    LOAD_DBC(sFactionTemplateStore,               "FactionTemplate.dbc");//15595
    LOAD_DBC(sGameObjectArtKitStore,              "GameObjectArtKit.dbc");//15595
    LOAD_DBC(sGameObjectDisplayInfoStore,         "GameObjectDisplayInfo.dbc");//15595
    LOAD_DBC(sGemPropertiesStore,                 "GemProperties.dbc");//15595
    LOAD_DBC(sGlyphPropertiesStore,               "GlyphProperties.dbc");//15595
    LOAD_DBC(sGlyphSlotStore,                     "GlyphSlot.dbc");//15595
    LOAD_DBC(sGtBarberShopCostBaseStore,          "gtBarberShopCostBase.dbc");//15595
    LOAD_DBC(sGtCombatRatingsStore,               "gtCombatRatings.dbc");//15595
    LOAD_DBC(sGtChanceToMeleeCritBaseStore,       "gtChanceToMeleeCritBase.dbc");//15595
    LOAD_DBC(sGtChanceToMeleeCritStore,           "gtChanceToMeleeCrit.dbc");//15595
    LOAD_DBC(sGtChanceToSpellCritBaseStore,       "gtChanceToSpellCritBase.dbc");//15595
    LOAD_DBC(sGtChanceToSpellCritStore,           "gtChanceToSpellCrit.dbc");//15595
    LOAD_DBC(sGtNPCManaCostScalerStore,           "gtNPCManaCostScaler.dbc");
    LOAD_DBC(sGtOCTClassCombatRatingScalarStore,  "gtOCTClassCombatRatingScalar.dbc");//15595
    //LOAD_DBC(sGtOCTRegenHPStore,                  "gtOCTRegenHP.dbc");//15595
    LOAD_DBC(sGtOCTHpPerStaminaStore,             "gtOCTHpPerStamina.dbc");//15595
    //LOAD_DBC(sGtOCTRegenMPStore,                  "gtOCTRegenMP.dbc");       -- not used currently
    LOAD_DBC(sGtRegenMPPerSptStore,               "gtRegenMPPerSpt.dbc");//15595
    LOAD_DBC(sGtSpellScalingStore,                "gtSpellScaling.dbc");//15595
    LOAD_DBC(sGtOCTBaseHPByClassStore,            "gtOCTBaseHPByClass.dbc");//15595
    LOAD_DBC(sGtOCTBaseMPByClassStore,            "gtOCTBaseMPByClass.dbc");//15595
    LOAD_DBC(sGuildPerkSpellsStore,               "GuildPerkSpells.dbc");//15595
    LOAD_DBC(sHolidaysStore,                      "Holidays.dbc");//15595
    LOAD_DBC(sImportPriceArmorStore,              "ImportPriceArmor.dbc"); // 15595
    LOAD_DBC(sImportPriceQualityStore,            "ImportPriceQuality.dbc"); // 15595
    LOAD_DBC(sImportPriceShieldStore,             "ImportPriceShield.dbc"); // 15595
    LOAD_DBC(sImportPriceWeaponStore,             "ImportPriceWeapon.dbc"); // 15595
    LOAD_DBC(sItemPriceBaseStore,                 "ItemPriceBase.dbc"); // 15595
    LOAD_DBC(sItemReforgeStore,                   "ItemReforge.dbc"); // 15595
    LOAD_DBC(sItemBagFamilyStore,                 "ItemBagFamily.dbc");//15595
    LOAD_DBC(sItemClassStore,                     "ItemClass.dbc"); // 15595
    //LOAD_DBC(sItemDisplayInfoStore,               "ItemDisplayInfo.dbc");     -- not used currently
    LOAD_DBC(sItemLimitCategoryStore,             "ItemLimitCategory.dbc");//15595
    LOAD_DBC(sItemRandomPropertiesStore,          "ItemRandomProperties.dbc");//15595
    LOAD_DBC(sItemRandomSuffixStore,              "ItemRandomSuffix.dbc");//15595
    LOAD_DBC(sItemSetStore,                       "ItemSet.dbc");//15595
    LOAD_DBC(sItemArmorQualityStore,              "ItemArmorQuality.dbc");//15595
    LOAD_DBC(sItemArmorShieldStore,               "ItemArmorShield.dbc");//15595
    LOAD_DBC(sItemArmorTotalStore,                "ItemArmorTotal.dbc");//15595
    LOAD_DBC(sItemDamageAmmoStore,                "ItemDamageAmmo.dbc");//15595
    LOAD_DBC(sItemDamageOneHandStore,             "ItemDamageOneHand.dbc");//15595
    LOAD_DBC(sItemDamageOneHandCasterStore,       "ItemDamageOneHandCaster.dbc");//15595
    LOAD_DBC(sItemDamageRangedStore,              "ItemDamageRanged.dbc");//15595
    LOAD_DBC(sItemDamageThrownStore,              "ItemDamageThrown.dbc");//15595
    LOAD_DBC(sItemDamageTwoHandStore,             "ItemDamageTwoHand.dbc");//15595
    LOAD_DBC(sItemDamageTwoHandCasterStore,       "ItemDamageTwoHandCaster.dbc");//15595
    LOAD_DBC(sItemDamageWandStore,                "ItemDamageWand.dbc");//15595
    LOAD_DBC(sItemDisenchantLootStore,            "ItemDisenchantLoot.dbc");
    LOAD_DBC(sLFGDungeonStore,                    "LFGDungeons.dbc");//15595
    LOAD_DBC(sLFGDungeonsGroupingMapStore,        "LFGDungeonsGroupingmap.dbc");//15595
    LOAD_DBC(sLightStore,                         "Light.dbc"); //15595
    LOAD_DBC(sLiquidTypeStore,                    "LiquidType.dbc");//15595
    LOAD_DBC(sLockStore,                          "Lock.dbc");//15595
    LOAD_DBC(sMailTemplateStore,                  "MailTemplate.dbc");//15595
    LOAD_DBC(sMapStore,                           "Map.dbc");//15595
    LOAD_DBC(sMapDifficultyStore,                 "MapDifficulty.dbc");//15595
    LOAD_DBC(sMountCapabilityStore,               "MountCapability.dbc");//15595
    LOAD_DBC(sMountTypeStore,                     "MountType.dbc");//15595
    LOAD_DBC(sNumTalentsAtLevelStore,             "NumTalentsAtLevel.dbc");//15595
    LOAD_DBC(sMovieStore,                         "Movie.dbc");//15595
    LOAD_DBC(sOverrideSpellDataStore,             "OverrideSpellData.dbc");//15595
    LOAD_DBC(sNamesProfanityStore,                "NamesProfanity.dbc");
    LOAD_DBC(sNamesReservedStore,                 "NamesReserved.dbc");
    LOAD_DBC(sNameGenStore,                       "NameGen.dbc");//15595
    LOAD_DBC(sPhaseStore,                         "Phase.dbc"); // 15595
    LOAD_DBC(sPhaseGroupStore,                    "PhaseXPhaseGroup.dbc"); // 15595
    LOAD_DBC(sPowerDisplayStore,                  "PowerDisplay.dbc");
    LOAD_DBC(sPvPDifficultyStore,                 "PvpDifficulty.dbc");//15595
    LOAD_DBC(sQuestXPStore,                       "QuestXP.dbc");//15595
    LOAD_DBC(sQuestFactionRewardStore,            "QuestFactionReward.dbc");//15595
    LOAD_DBC(sQuestPOIBlobStore,                  "QuestPOIBlob.dbc");//15595
    LOAD_DBC(sQuestPOIPointStore,                 "QuestPOIPoint.dbc");//15595
    LOAD_DBC(sQuestSortStore,                     "QuestSort.dbc");//15595
    LOAD_DBC(sRandomPropertiesPointsStore,        "RandPropPoints.dbc");//15595
    LOAD_DBC(sResearchBranchStore,                "ResearchBranch.dbc");//15595
    LOAD_DBC(sResearchFieldStore,                 "ResearchField.dbc");//15595
    LOAD_DBC(sResearchProjectStore,               "ResearchProject.dbc");//15595
    LOAD_DBC(sResearchSiteStore,                  "ResearchSite.dbc");//15595
    LOAD_DBC(sScalingStatDistributionStore,       "ScalingStatDistribution.dbc");//15595
    LOAD_DBC(sScalingStatValuesStore,             "ScalingStatValues.dbc");//15595
    LOAD_DBC(sSkillLineStore,                     "SkillLine.dbc");//15595
    LOAD_DBC(sSkillLineAbilityStore,              "SkillLineAbility.dbc");//15595
    LOAD_DBC(sSkillRaceClassInfoStore,            "SkillRaceClassInfo.dbc");
    LOAD_DBC(sSkillTiersStore,                    "SkillTiers.dbc");
    LOAD_DBC(sSoundEntriesStore,                  "SoundEntries.dbc");//15595
    LOAD_DBC(sSpellCategoriesStore,               "SpellCategories.dbc");//15595
    LOAD_DBC(sSpellCategoryStore,                 "SpellCategory.dbc");
    LOAD_DBC(sSpellReagentsStore,                 "SpellReagents.dbc");//15595
    LOAD_DBC(sSpellScalingStore,                  "SpellScaling.dbc");//15595
    LOAD_DBC(sSpellTotemsStore,                   "SpellTotems.dbc");//15595
    LOAD_DBC(sSpellTargetRestrictionsStore,       "SpellTargetRestrictions.dbc");//15595
    LOAD_DBC(sSpellPowerStore,                    "SpellPower.dbc");//15595
    LOAD_DBC(sSpellLevelsStore,                   "SpellLevels.dbc");//15595
    LOAD_DBC(sSpellInterruptsStore,               "SpellInterrupts.dbc");//15595
    LOAD_DBC(sSpellEquippedItemsStore,            "SpellEquippedItems.dbc");//15595
    LOAD_DBC(sSpellClassOptionsStore,             "SpellClassOptions.dbc");//15595
    LOAD_DBC(sSpellCooldownsStore,                "SpellCooldowns.dbc");//15595
    LOAD_DBC(sSpellAuraOptionsStore,              "SpellAuraOptions.dbc");//15595
    LOAD_DBC(sSpellAuraRestrictionsStore,         "SpellAuraRestrictions.dbc");//15595
    LOAD_DBC(sSpellCastingRequirementsStore,      "SpellCastingRequirements.dbc");//15595
    LOAD_DBC(sSpellCastTimesStore,                "SpellCastTimes.dbc");//15595
    LOAD_DBC(sSpellDurationStore,                 "SpellDuration.dbc");//15595
    LOAD_DBC(sSpellFocusObjectStore,              "SpellFocusObject.dbc");//15595
    LOAD_DBC(sSpellItemEnchantmentStore,          "SpellItemEnchantment.dbc");//15595
    LOAD_DBC(sSpellItemEnchantmentConditionStore, "SpellItemEnchantmentCondition.dbc");//15595
    LOAD_DBC(sSpellRadiusStore,                   "SpellRadius.dbc");//15595
    LOAD_DBC(sSpellRangeStore,                    "SpellRange.dbc");//15595
    LOAD_DBC(sSpellRuneCostStore,                 "SpellRuneCost.dbc");//15595
    LOAD_DBC(sSpellShapeshiftStore,               "SpellShapeshift.dbc");//15595
    LOAD_DBC(sSpellShapeshiftFormStore,           "SpellShapeshiftForm.dbc");//15595
    LOAD_DBC(sSpellVisualStore,                   "SpellVisual.dbc");//15595
    LOAD_DBC(sSpellVisualKitStore,                "SpellVisualKit.dbc");//15595
    LOAD_DBC(sSummonPropertiesStore,              "SummonProperties.dbc");//15595
    LOAD_DBC(sTalentStore,                        "Talent.dbc");//15595
    LOAD_DBC(sTalentTabStore,                     "TalentTab.dbc");//15595
    LOAD_DBC(sTalentTreePrimarySpellsStore,       "TalentTreePrimarySpells.dbc");
    LOAD_DBC(sTaxiNodesStore,                     "TaxiNodes.dbc");//15595
    LOAD_DBC(sTaxiPathStore,                      "TaxiPath.dbc");//15595
    LOAD_DBC(sTaxiPathNodeStore,                  "TaxiPathNode.dbc");//15595
    //LOAD_DBC(sTeamContributionPointsStore,        "TeamContributionPoints.dbc");
    LOAD_DBC(sTotemCategoryStore,                 "TotemCategory.dbc");//15595
    LOAD_DBC(sTransportAnimationStore,            "TransportAnimation.dbc");
    LOAD_DBC(sTransportRotationStore,             "TransportRotation.dbc");
    LOAD_DBC(sUnitPowerBarStore,                  "UnitPowerBar.dbc");//15595
    LOAD_DBC(sVehicleStore,                       "Vehicle.dbc");//15595
    LOAD_DBC(sVehicleSeatStore,                   "VehicleSeat.dbc");//15595
    LOAD_DBC(sWMOAreaTableStore,                  "WMOAreaTable.dbc");//15595
    LOAD_DBC(sWorldMapAreaStore,                  "WorldMapArea.dbc");//15595
    LOAD_DBC(sWorldMapOverlayStore,               "WorldMapOverlay.dbc");//15595
    LOAD_DBC(sWorldSafeLocsStore,                 "WorldSafeLocs.dbc");//15595

#undef LOAD_DBC

#define LOAD_DBC_EXT(store, file, dbformat, dbpk) LoadDBC(availableDbcLocales, bad_dbc_files, store, dbcPath, file, defaultLocale, dbformat, dbpk)

    LOAD_DBC_EXT(sAchievementStore,     "Achievement.dbc",     CustomAchievementfmt,            CustomAchievementIndex);//15595
    LOAD_DBC_EXT(sSpellStore,           "Spell.dbc",           CustomSpellEntryfmt,             CustomSpellEntryIndex);//15595
    LOAD_DBC_EXT(sSpellEffectStore,     "SpellEffect.dbc",     CustomSpellEffectEntryfmt,       CustomSpellEffectEntryIndex);//15595
    LOAD_DBC_EXT(sSpellDifficultyStore, "SpellDifficulty.dbc", CustomSpellDifficultyfmt,        CustomSpellDifficultyIndex);//15595
    LOAD_DBC_EXT(sPlayerConditionStore, "PlayerCondition.dbc", CustomPlayerConditionEntryfmt,   CustomPlayerConditionEntryIndex);//15595

#undef LOAD_DBC_EXT

    for (CharStartOutfitEntry const* outfit : sCharStartOutfitStore)
        sCharStartOutfitMap[outfit->RaceID | (outfit->ClassID << 8) | (outfit->SexID << 16)] = outfit;

    for (CharSectionsEntry const* entry : sCharSectionsStore)
        if (entry->RaceID && ((1 << (entry->RaceID - 1)) & RACEMASK_ALL_PLAYABLE) != 0) //ignore Nonplayable races
            sCharSectionMap.insert({ entry->BaseSection | (entry->SexID << 8) | (entry->RaceID << 16), entry });

    for (uint32 i = 0; i < MAX_CLASSES; ++i)
        for (uint32 j = 0; j < MAX_POWERS; ++j)
            PowersByClass[i][j] = MAX_POWERS;

    for (uint32 i = 0; i < sChrPowerTypesStore.GetNumRows(); ++i)
    {
        if (ChrPowerTypesEntry const* power = sChrPowerTypesStore.LookupEntry(i))
        {
            uint32 index = 0;
            for (uint32 j = 0; j < MAX_POWERS; ++j)
                if (PowersByClass[power->ClassID][j] != MAX_POWERS)
                    ++index;

            PowersByClass[power->ClassID][power->PowerType] = index;
        }
    }

    for (EmotesTextSoundEntry const* entry : sEmotesTextSoundStore)
        sEmotesTextSoundMap[EmotesTextSoundKey(entry->EmotesTextID, entry->RaceID, entry->SexID)] = entry;

    for (FactionEntry const* faction : sFactionStore)
    {
        if (faction->ParentFactionID)
        {
            SimpleFactionsList& flist = sFactionTeamMap[faction->ParentFactionID];
            flist.push_back(faction->ID);
        }
    }

    for (GameObjectDisplayInfoEntry const* info : sGameObjectDisplayInfoStore)
    {
        if (info->GeoBoxMax.X < info->GeoBoxMin.X)
            std::swap(*(float*)(&info->GeoBoxMax.X), *(float*)(&info->GeoBoxMin.X));
        if (info->GeoBoxMax.Y < info->GeoBoxMin.Y)
            std::swap(*(float*)(&info->GeoBoxMax.Y), *(float*)(&info->GeoBoxMin.Y));
        if (info->GeoBoxMax.Z < info->GeoBoxMin.Z)
            std::swap(*(float*)(&info->GeoBoxMax.Z), *(float*)(&info->GeoBoxMin.Z));
    }

    // fill data
    sMapDifficultyMap[MAKE_PAIR32(0, 0)] = MapDifficulty(0, 0, false); // map 0 is missing from MapDifficulty.dbc use this till its ported to sql
    for (MapDifficultyEntry const* entry : sMapDifficultyStore)
        sMapDifficultyMap[MAKE_PAIR32(entry->MapID, entry->Difficulty)] = MapDifficulty(entry->RaidDuration, entry->MaxPlayers, !std::string(entry->Message).empty());

    sMapDifficultyMap.erase(MAKE_PAIR32(189, 1)); // Scarlet Monastry has a incorrect heroic entry so we drop it

    for (NameGenEntry const* entry : sNameGenStore)
        sGenNameVectoArraysMap[entry->RaceID].stringVectorArray[entry->Sex].push_back(std::string(entry->Name));

    for (NamesProfanityEntry const* namesProfanity : sNamesProfanityStore)
    {
        ASSERT(namesProfanity->Language < TOTAL_LOCALES || namesProfanity->Language == -1);
        std::wstring wname;
        bool conversionResult = Utf8toWStr(namesProfanity->Name, wname);
        ASSERT(conversionResult);

        if (namesProfanity->Language != -1)
            NamesProfaneValidators[namesProfanity->Language].emplace_back(wname, Trinity::regex::icase | Trinity::regex::optimize);
        else
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                NamesProfaneValidators[i].emplace_back(wname, Trinity::regex::icase | Trinity::regex::optimize);
    }

    for (NamesReservedEntry const* namesReserved : sNamesReservedStore)
    {
        ASSERT(namesReserved->Language < TOTAL_LOCALES || namesReserved->Language == -1);
        std::wstring wname;
        bool conversionResult = Utf8toWStr(namesReserved->Name, wname);
        ASSERT(conversionResult);

        if (namesReserved->Language != -1)
            NamesReservedValidators[namesReserved->Language].emplace_back(wname, Trinity::regex::icase | Trinity::regex::optimize);
        else
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                NamesReservedValidators[i].emplace_back(wname, Trinity::regex::icase | Trinity::regex::optimize);
    }

    for (PhaseGroupEntry const* group : sPhaseGroupStore)
        if (PhaseEntry const* phase = sPhaseStore.LookupEntry(group->PhaseID))
            sPhasesByGroup[group->PhaseGroupID].push_back(phase->ID);

    for (PvPDifficultyEntry const* entry : sPvPDifficultyStore)
        if (entry->RangeIndex > MAX_BATTLEGROUND_BRACKETS)
            ASSERT(false && "Need update MAX_BATTLEGROUND_BRACKETS by DBC data");

    for (SkillLineAbilityEntry const* skillLineAbility : sSkillLineAbilityStore)
        _skillLineAbilitiesBySkillupSkill[skillLineAbility->SkillLine].push_back(skillLineAbility);

    for (SkillRaceClassInfoEntry const* entry : sSkillRaceClassInfoStore)
        if (sSkillLineStore.LookupEntry(entry->SkillID))
            SkillRaceClassInfoBySkill.emplace(entry->SkillID, entry);

    // Must be done when sSkillLineAbilityStore, sSpellStore, sSpellLevelsStore and sCreatureFamilyStore are all loaded
    for (SkillLineAbilityEntry const* skillLine : sSkillLineAbilityStore)
    {
        SpellEntry const* spellInfo = sSpellStore.LookupEntry(skillLine->Spell);
        if (!spellInfo)
            continue;

        SpellLevelsEntry const* levels = sSpellLevelsStore.LookupEntry(spellInfo->LevelsID);
        if (spellInfo->LevelsID && (!levels || levels->SpellLevel))
            continue;

        if (spellInfo && spellInfo->Attributes & SPELL_ATTR0_PASSIVE)
        {
            for (CreatureFamilyEntry const* cFamily : sCreatureFamilyStore)
            {
                if (skillLine->SkillLine != cFamily->SkillLine[0] && skillLine->SkillLine != cFamily->SkillLine[1])
                    continue;

                if (skillLine->AcquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                sPetFamilySpellsStore[cFamily->ID].insert(spellInfo->ID);
            }
        }
    }

    // Create Spelldifficulty searcher
    for (SpellDifficultyEntry const* spellDiff : sSpellDifficultyStore)
    {
        SpellDifficultyEntry newEntry;
        memset(newEntry.DifficultySpellID, 0, 4 * sizeof(uint32));
        for (uint32 x = 0; x < MAX_DIFFICULTY; ++x)
        {
            if (spellDiff->DifficultySpellID[x] <= 0 || !sSpellStore.LookupEntry(spellDiff->DifficultySpellID[x]))
            {
                if (spellDiff->DifficultySpellID[x] > 0)//don't show error if spell is <= 0, not all modes have spells and there are unknown negative values
                    TC_LOG_ERROR("sql.sql", "spelldifficulty_dbc: spell %i at field id:%u at spellid%i does not exist in SpellStore (spell.dbc), loaded as 0", spellDiff->DifficultySpellID[x], spellDiff->ID, x);
                newEntry.DifficultySpellID[x] = 0;//spell was <= 0 or invalid, set to 0
            }
            else
                newEntry.DifficultySpellID[x] = spellDiff->DifficultySpellID[x];
        }

        if (newEntry.DifficultySpellID[0] <= 0 || newEntry.DifficultySpellID[1] <= 0)//id0-1 must be always set!
            continue;

        for (uint32 x = 0; x < MAX_DIFFICULTY; ++x)
            if (newEntry.DifficultySpellID[x])
                sSpellMgr->SetSpellDifficultyId(uint32(newEntry.DifficultySpellID[x]), spellDiff->ID);
    }

    // create talent spells set
    for (TalentEntry const* talentInfo : sTalentStore)
    {
        for (uint8 j = 0; j < MAX_TALENT_RANK; ++j)
            if (talentInfo->SpellRank[j])
                sTalentSpellPosMap[talentInfo->SpellRank[j]] = TalentSpellPos(talentInfo->ID, j);
    }

    // prepare fast data access to bit pos of talent ranks for use at inspecting
    {
        // now have all max ranks (and then bit amount used for store talent ranks in inspect)
        for (TalentTabEntry const* talentTabInfo : sTalentTabStore)
        {
            // prevent memory corruption; otherwise cls will become 12 below
            if ((talentTabInfo->ClassMask & CLASSMASK_ALL_PLAYABLE) == 0)
                continue;

            // store class talent tab pages
            for (uint32 cls = 1; cls < MAX_CLASSES; ++cls)
                if (talentTabInfo->ClassMask & (1 << (cls - 1)))
                    sTalentTabPages[cls][talentTabInfo->OrderIndex] = talentTabInfo->ID;
        }
    }

    for (TalentTreePrimarySpellsEntry const* talentSpell : sTalentTreePrimarySpellsStore)
        sTalentTreePrimarySpellsMap[talentSpell->TalentTabID].push_back(talentSpell->SpellID);

    for (TaxiPathEntry const* entry : sTaxiPathStore)
        sTaxiPathSetBySource[entry->FromTaxiNode][entry->ToTaxiNode] = TaxiPathBySourceAndDestination(entry->ID, entry->Cost);

    uint32 pathCount = sTaxiPathStore.GetNumRows();
    // Calculate path nodes count
    std::vector<uint32> pathLength;
    pathLength.resize(pathCount);                           // 0 and some other indexes not used
    for (TaxiPathNodeEntry const* entry : sTaxiPathNodeStore)
    {
        if (pathLength[entry->PathID] < entry->NodeIndex + 1)
            pathLength[entry->PathID] = entry->NodeIndex + 1;
    }

    // Set path length
    sTaxiPathNodesByPath.resize(pathCount);                 // 0 and some other indexes not used
    for (uint32 i = 1; i < sTaxiPathNodesByPath.size(); ++i)
        sTaxiPathNodesByPath[i].resize(pathLength[i]);

    // fill data
    for (TaxiPathNodeEntry const* entry : sTaxiPathNodeStore)
        sTaxiPathNodesByPath[entry->PathID][entry->NodeIndex] = entry;

    // Initialize global taxinodes mask
    // include existed nodes that have at least single not spell base (scripted) path
    {
        std::set<uint32> spellPaths;
        for (SpellEffectEntry const* sInfo : sSpellEffectStore)
            if (sInfo->Effect == SPELL_EFFECT_SEND_TAXI)
                spellPaths.insert(sInfo->EffectMiscValue);

        sTaxiNodesMask.fill(0);
        sOldContinentsNodesMask.fill(0);
        sHordeTaxiNodesMask.fill(0);
        sAllianceTaxiNodesMask.fill(0);
        sDeathKnightTaxiNodesMask.fill(0);
        for (TaxiNodesEntry const* node : sTaxiNodesStore)
        {
            TaxiPathSetBySource::const_iterator src_i = sTaxiPathSetBySource.find(node->ID);
            if (src_i != sTaxiPathSetBySource.end() && !src_i->second.empty())
            {
                bool ok = false;
                for (TaxiPathSetForSource::const_iterator dest_i = src_i->second.begin(); dest_i != src_i->second.end(); ++dest_i)
                {
                    // not spell path
                    if (dest_i->second.price || spellPaths.find(dest_i->second.ID) == spellPaths.end())
                    {
                        ok = true;
                        break;
                    }
                }

                if (!ok)
                    continue;
            }

            // valid taxi network node
            uint8  field = (uint8)((node->ID - 1) / 8);
            uint32 submask = 1 << ((node->ID - 1) % 8);

            sTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[0] && node->MountCreatureID[0] != 32981)
                sHordeTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[1] && node->MountCreatureID[1] != 32981)
                sAllianceTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[0] == 32981 || node->MountCreatureID[1] == 32981)
                sDeathKnightTaxiNodesMask[field] |= submask;

            // old continent node (+ nodes virtually at old continents, check explicitly to avoid loading map files for zone info)
            if (node->ContinentID < 2 || node->ID == 82 || node->ID == 83 || node->ID == 93 || node->ID == 94)
                sOldContinentsNodesMask[field] |= submask;

            // fix DK node at Ebon Hold and Shadow Vault flight master
            if (node->ID == 315 || node->ID == 333)
                const_cast<TaxiNodesEntry*>(node)->MountCreatureID[1] = 32981;
        }
    }

    for (WMOAreaTableEntry const* entry : sWMOAreaTableStore)
        sWMOAreaInfoByTripple[WMOAreaTableKey(entry->WMOID, entry->NameSetID, entry->WMOGroupID)] = entry;

    // error checks
    if (bad_dbc_files.size() >= DBCFileCount)
    {
        TC_LOG_ERROR("misc", "Incorrect DataDir value in worldserver.conf or ALL required *.dbc files (%d) not found by path: %sdbc/%s", DBCFileCount, dataPath.c_str(), localeNames[defaultLocale]);
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
    if (!sAreaTableStore.LookupEntry(5995)     ||     // last area added in 4.3.4 (15595)
        !sCharTitlesStore.LookupEntry(287)     ||     // last char title added in 4.3.4 (15595)
        !sGemPropertiesStore.LookupEntry(2250) ||     // last gem property added in 4.3.4 (15595)
        !sMapStore.LookupEntry(980)            ||     // last map added in 4.3.4 (15595)
        !sSpellStore.LookupEntry(121820)       )      // last spell added in 4.3.4 (15595)
    {
        TC_LOG_ERROR("misc", "You have _outdated_ DBC files. Please extract correct versions from current using client.");
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d DBC data stores in %u ms", DBCFileCount, GetMSTimeDiffToNow(oldMSTime));
}

std::string const& DBCManager::GetRandomCharacterName(uint8 race, uint8 gender)
{
    return Trinity::Containers::SelectRandomContainerElement(sGenNameVectoArraysMap[race].stringVectorArray[gender]);
}

SimpleFactionsList const* DBCManager::GetFactionTeamList(uint32 faction)
{
    FactionTeamMap::const_iterator itr = sFactionTeamMap.find(faction);
    if (itr != sFactionTeamMap.end())
        return &itr->second;

    return nullptr;
}

char const* DBCManager::GetPetName(uint32 petfamily, uint32 /*dbclang*/)
{
    if (!petfamily)
        return nullptr;
    CreatureFamilyEntry const* pet_family = sCreatureFamilyStore.LookupEntry(petfamily);
    if (!pet_family)
        return nullptr;
    return pet_family->Name ? pet_family->Name : nullptr;
}

TalentSpellPos const* DBCManager::GetTalentSpellPos(uint32 spellId)
{
    TalentSpellPosMap::const_iterator itr = sTalentSpellPosMap.find(spellId);
    if (itr == sTalentSpellPosMap.end())
        return nullptr;

    return &itr->second;
}

uint32 DBCManager::GetTalentSpellCost(uint32 spellId)
{
    if (TalentSpellPos const* pos = GetTalentSpellPos(spellId))
        return pos->rank+1;

    return 0;
}

WMOAreaTableEntry const* DBCManager::GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid)
{
    auto i = sWMOAreaInfoByTripple.find(WMOAreaTableKey(int16(rootid), int8(adtid), groupid));
    if (i != sWMOAreaInfoByTripple.end())
        return i->second;

    return nullptr;
}

char const* DBCManager::GetRaceName(uint8 race, uint8 /*locale*/)
{
    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
    return raceEntry ? raceEntry->Name : nullptr;
}

char const* DBCManager::GetClassName(uint8 class_, uint8 /*locale*/)
{
    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);
    return classEntry ? classEntry->Name : nullptr;
}

uint32 DBCManager::GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId)
{
    if (mapid != 530 && mapid != 571 && mapid != 732)   // speed for most cases
        return mapid;

    if (WorldMapAreaEntry const* wma = sWorldMapAreaStore.LookupEntry(zoneId))
        return wma->DisplayMapID >= 0 ? wma->DisplayMapID : wma->MapID;

    return mapid;
}

uint32 DBCManager::GetMaxLevelForExpansion(uint32 expansion)
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
        default:
            break;
    }
    return DEFAULT_MAX_LEVEL;
}

/*
Used only for calculate xp gain by content lvl.
Calculation on Gilneas and group maps of LostIslands calculated as CONTENT_1_60.
*/
ContentLevels DBCManager::GetContentLevelsForMapAndZone(uint32 mapid, uint32 zoneId)
{
    mapid = GetVirtualMapForMapAndZone(mapid, zoneId);
    if (mapid < 2)
        return CONTENT_1_60;

    MapEntry const* mapEntry = sMapStore.LookupEntry(mapid);
    if (!mapEntry)
        return CONTENT_1_60;

    // no need enum all maps from phasing
    if (mapEntry->ParentMapID >= 0)
        mapid = mapEntry->ParentMapID;

    switch (mapid)
    {
        case 648:   //LostIslands
        case 654:   //Gilneas
            return CONTENT_1_60;
        default:
            return ContentLevels(mapEntry->Expansion());
    }
}

bool DBCManager::IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId)
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

    if (itemEntry->TotemCategoryType != reqEntry->TotemCategoryType)
        return false;

    return (itemEntry->TotemCategoryMask & reqEntry->TotemCategoryMask) == reqEntry->TotemCategoryMask;
}

bool DBCManager::Zone2MapCoordinates(float& x, float& y, uint32 zone) const
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(zone);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return false;

    std::swap(x, y);                                         // at client map coords swapped
    x = x * ((maEntry->LocBottom - maEntry->LocTop) / 100) + maEntry->LocTop;
    y = y * ((maEntry->LocRight - maEntry->LocLeft) / 100) + maEntry->LocLeft;      // client y coord from top to down

    return true;
}

void DBCManager::Map2ZoneCoordinates(float& x, float& y, uint32 zone)
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(zone);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return;

    x = (x - maEntry->LocTop) / ((maEntry->LocBottom - maEntry->LocTop) / 100);
    y = (y - maEntry->LocLeft) / ((maEntry->LocRight - maEntry->LocLeft) / 100);    // client y coord from top to down
    std::swap(x, y);                                         // client have map coords swapped
}

MapDifficulty const* DBCManager::GetMapDifficultyData(uint32 mapId, Difficulty difficulty)
{
    MapDifficultyMap::const_iterator itr = sMapDifficultyMap.find(MAKE_PAIR32(mapId, difficulty));
    return itr != sMapDifficultyMap.end() ? &itr->second : nullptr;
}

MapDifficulty const* DBCManager::GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty)
{
    uint32 tmpDiff = difficulty;
    MapDifficulty const* mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff));
    if (!mapDiff)
    {
        if (tmpDiff > RAID_DIFFICULTY_25MAN_NORMAL) // heroic, downscale to normal
            tmpDiff -= 2;
        else
            tmpDiff -= 1;   // any non-normal mode for raids like tbc (only one mode)

        // pull new data
        mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // we are 10 normal or 25 normal
        if (!mapDiff)
        {
            tmpDiff -= 1;
            mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // 10 normal
        }
    }

    difficulty = Difficulty(tmpDiff);
    return mapDiff;
}

PvPDifficultyEntry const* DBCManager::GetBattlegroundBracketByLevel(uint32 mapid, uint32 level)
{
    PvPDifficultyEntry const* maxEntry = nullptr;              // used for level > max listed level case
    for (uint32 i = 0; i < sPvPDifficultyStore.GetNumRows(); ++i)
    {
        if (PvPDifficultyEntry const* entry = sPvPDifficultyStore.LookupEntry(i))
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

PvPDifficultyEntry const* DBCManager::GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id)
{
    for (uint32 i = 0; i < sPvPDifficultyStore.GetNumRows(); ++i)
        if (PvPDifficultyEntry const* entry = sPvPDifficultyStore.LookupEntry(i))
            if (entry->MapID == mapid && entry->GetBracketId() == id)
                return entry;

    return nullptr;
}

uint32 const* DBCManager::GetTalentTabPages(uint8 cls)
{
    return sTalentTabPages[cls];
}

std::vector<uint32> const* DBCManager::GetTalentTreePrimarySpells(uint32 talentTree)
{
    TalentTreePrimarySpellsMap::const_iterator itr = sTalentTreePrimarySpellsMap.find(talentTree);
    if (itr == sTalentTreePrimarySpellsMap.end())
        return nullptr;

    return &itr->second;
}

uint32 DBCManager::GetLiquidFlags(uint32 liquidType)
{
    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquidType))
        return 1 << liq->SoundBank;

    return 0;
}

CharStartOutfitEntry const* DBCManager::GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender)
{
    std::map<uint32, CharStartOutfitEntry const*>::const_iterator itr = sCharStartOutfitMap.find(race | (class_ << 8) | (gender << 16));
    if (itr == sCharStartOutfitMap.end())
        return nullptr;

    return itr->second;
}

CharSectionsEntry const* DBCManager::GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color)
{
    std::pair<CharSectionsMap::const_iterator, CharSectionsMap::const_iterator> eqr = sCharSectionMap.equal_range(uint32(genType) | uint32(gender << 8) | uint32(race << 16));
    for (CharSectionsMap::const_iterator itr = eqr.first; itr != eqr.second; ++itr)
    {
        if (itr->second->VariationIndex == type && itr->second->ColorIndex == color)
            return itr->second;
    }

    return nullptr;
}

uint32 DBCManager::GetPowerIndexByClass(Powers power, uint32 classId)
{
    return PowersByClass[classId][power];
}

uint32 ScalingStatValuesEntry::GetStatMultiplier(uint32 inventoryType) const
{
    if (inventoryType < MAX_INVTYPE)
    {
        switch (inventoryType)
        {
            case INVTYPE_NON_EQUIP:
            case INVTYPE_BODY:
            case INVTYPE_BAG:
            case INVTYPE_TABARD:
            case INVTYPE_AMMO:
            case INVTYPE_QUIVER:
                return 0;
            case INVTYPE_HEAD:
            case INVTYPE_CHEST:
            case INVTYPE_LEGS:
            case INVTYPE_2HWEAPON:
            case INVTYPE_ROBE:
                return StatMultiplier[0];
            case INVTYPE_SHOULDERS:
            case INVTYPE_WAIST:
            case INVTYPE_FEET:
            case INVTYPE_HANDS:
            case INVTYPE_TRINKET:
                return StatMultiplier[1];
            case INVTYPE_NECK:
            case INVTYPE_WRISTS:
            case INVTYPE_FINGER:
            case INVTYPE_SHIELD:
            case INVTYPE_CLOAK:
            case INVTYPE_HOLDABLE:
                return StatMultiplier[2];
            case INVTYPE_RANGED:
            case INVTYPE_THROWN:
            case INVTYPE_RANGEDRIGHT:
            case INVTYPE_RELIC:
                return StatMultiplier[3];
            case INVTYPE_WEAPON:
            case INVTYPE_WEAPONMAINHAND:
            case INVTYPE_WEAPONOFFHAND:
                return StatMultiplier[4];
            default:
                break;
        }
    }
    return 0;
}

uint32 ScalingStatValuesEntry::GetArmor(uint32 inventoryType, uint32 armorType) const
{
    if (inventoryType <= INVTYPE_ROBE && armorType < 4)
    {
        switch (inventoryType)
        {
            case INVTYPE_NON_EQUIP:
            case INVTYPE_NECK:
            case INVTYPE_BODY:
            case INVTYPE_FINGER:
            case INVTYPE_TRINKET:
            case INVTYPE_WEAPON:
            case INVTYPE_SHIELD:
            case INVTYPE_RANGED:
            case INVTYPE_2HWEAPON:
            case INVTYPE_BAG:
            case INVTYPE_TABARD:
                break;
            case INVTYPE_SHOULDERS:
                return Armor[0][armorType];
            case INVTYPE_CHEST:
            case INVTYPE_ROBE:
                return Armor[1][armorType];
            case INVTYPE_HEAD:
                return Armor[2][armorType];
            case INVTYPE_LEGS:
                return Armor[3][armorType];
            case INVTYPE_FEET:
                return Armor[4][armorType];
            case INVTYPE_WAIST:
                return Armor[5][armorType];
            case INVTYPE_HANDS:
                return Armor[6][armorType];
            case INVTYPE_WRISTS:
                return Armor[7][armorType];
            case INVTYPE_CLOAK:
                return CloakArmor;
            default:
                break;
        }
    }
    return 0;
}

uint32 ScalingStatValuesEntry::GetDPSAndDamageMultiplier(uint32 subClass, bool isCasterWeapon, float* damageMultiplier) const
{
    if (!isCasterWeapon)
    {
        switch (subClass)
        {
            case ITEM_SUBCLASS_WEAPON_AXE:
            case ITEM_SUBCLASS_WEAPON_MACE:
            case ITEM_SUBCLASS_WEAPON_SWORD:
            case ITEM_SUBCLASS_WEAPON_DAGGER:
            case ITEM_SUBCLASS_WEAPON_THROWN:
                *damageMultiplier = 0.3f;
                return dpsMod[0];
            case ITEM_SUBCLASS_WEAPON_AXE2:
            case ITEM_SUBCLASS_WEAPON_MACE2:
            case ITEM_SUBCLASS_WEAPON_POLEARM:
            case ITEM_SUBCLASS_WEAPON_SWORD2:
            case ITEM_SUBCLASS_WEAPON_STAFF:
            case ITEM_SUBCLASS_WEAPON_FISHING_POLE:
                *damageMultiplier = 0.2f;
                return dpsMod[1];
            case ITEM_SUBCLASS_WEAPON_BOW:
            case ITEM_SUBCLASS_WEAPON_GUN:
            case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                *damageMultiplier = 0.3f;
                return dpsMod[4];
            case ITEM_SUBCLASS_WEAPON_Obsolete:
            case ITEM_SUBCLASS_WEAPON_EXOTIC:
            case ITEM_SUBCLASS_WEAPON_EXOTIC2:
            case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
            case ITEM_SUBCLASS_WEAPON_MISCELLANEOUS:
            case ITEM_SUBCLASS_WEAPON_SPEAR:
            case ITEM_SUBCLASS_WEAPON_WAND:
                break;
        }
    }
    else
    {
        if (subClass <= ITEM_SUBCLASS_WEAPON_WAND)
        {
            uint32 mask = 1 << subClass;
            // two-handed weapons
            if (mask & 0x562)
            {
                *damageMultiplier = 0.2f;
                return dpsMod[3];
            }

            if (mask & (1 << ITEM_SUBCLASS_WEAPON_WAND))
            {
                *damageMultiplier = 0.3f;
                return dpsMod[5];
            }
        }
        *damageMultiplier = 0.3f;
        return dpsMod[2];
    }
    return 0;
}

/// Returns LFGDungeonEntry for a specific map and difficulty. Will return first found entry if multiple dungeons use the same map (such as Scarlet Monastery)
LFGDungeonEntry const* DBCManager::GetLFGDungeon(uint32 mapId, Difficulty difficulty)
{
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(i);
        if (!dungeon)
            continue;

        if (dungeon->MapID == int32(mapId) && Difficulty(dungeon->DifficultyID) == difficulty)
            return dungeon;
    }

    return nullptr;
}

uint32 DBCManager::GetDefaultMapLight(uint32 mapId)
{
    for (int32 i = sLightStore.GetNumRows(); i >= 0; --i)
    {
        LightEntry const* light = sLightStore.LookupEntry(uint32(i));
        if (!light)
            continue;

        if (light->ContinentID == mapId && light->X == 0.0f && light->Y == 0.0f && light->Z == 0.0f)
            return light->ID;
    }

    return 0;
}

std::vector<SkillLineAbilityEntry const*> const* DBCManager::GetSkillLineAbilitiesBySkill(uint32 skillId) const
{
    return Trinity::Containers::MapGetValuePtr(_skillLineAbilitiesBySkillupSkill, skillId);
}

SkillRaceClassInfoEntry const* DBCManager::GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_)
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

    return nullptr;
}

std::vector<uint32> const* DBCManager::GetPhasesForGroup(uint32 group)
{
    auto itr = sPhasesByGroup.find(group);
    if (itr != sPhasesByGroup.end())
        return &itr->second;

    return nullptr;
}
ResponseCodes DBCManager::ValidateName(std::wstring const& name, LocaleConstant locale)
{
    if (locale >= TOTAL_LOCALES)
        return RESPONSE_FAILURE;

    for (Trinity::wregex const& regex : NamesProfaneValidators[locale])
        if (Trinity::regex_search(name, regex))
            return CHAR_NAME_PROFANE;

    // regexes at TOTAL_LOCALES are loaded from NamesReserved which is not locale specific
    for (Trinity::wregex const& regex : NamesReservedValidators[locale])
        if (Trinity::regex_search(name, regex))
            return CHAR_NAME_RESERVED;

    return CHAR_NAME_SUCCESS;
}

EmotesTextSoundEntry const* DBCManager::FindTextSoundEmoteFor(uint32 emote, uint32 race, uint32 gender)
{
    auto itr = sEmotesTextSoundMap.find(EmotesTextSoundKey(emote, race, gender));
    return itr != sEmotesTextSoundMap.end() ? itr->second : nullptr;
}

bool DBCManager::IsInArea(uint32 objectAreaId, uint32 areaId)
{
    do
    {
        if (objectAreaId == areaId)
            return true;

        AreaTableEntry const* objectArea = sAreaTableStore.LookupEntry(objectAreaId);
        if (!objectArea)
            break;

        objectAreaId = objectArea->ParentAreaID;
    } while (objectAreaId);

    return false;
}
