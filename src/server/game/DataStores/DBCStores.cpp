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
#include "Containers.h"
#include "Log.h"
#include "SharedDefines.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "TransportMgr.h"
#include "DBCfmt.h"
#include "ItemTemplate.h"
#include "Timer.h"
#include "ObjectDefines.h"

#include <map>

typedef std::map<uint16, uint32> AreaFlagByAreaID;
typedef std::map<uint32, uint32> AreaFlagByMapID;

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

typedef std::map<WMOAreaTableTripple, WMOAreaTableEntry const*> WMOAreaInfoByTripple;

DBCStorage <AreaTableEntry> sAreaStore(AreaTableEntryfmt);
DBCStorage <AreaGroupEntry> sAreaGroupStore(AreaGroupEntryfmt);
static AreaFlagByAreaID sAreaFlagByAreaID;
static AreaFlagByMapID sAreaFlagByMapID;                    // for instances without generated *.map files

static WMOAreaInfoByTripple sWMOAreaInfoByTripple;

DBCStorage <AchievementEntry> sAchievementStore(Achievementfmt);
DBCStorage <AreaTriggerEntry> sAreaTriggerStore(AreaTriggerEntryfmt);
DBCStorage <ArmorLocationEntry> sArmorLocationStore(ArmorLocationfmt);
DBCStorage <AuctionHouseEntry> sAuctionHouseStore(AuctionHouseEntryfmt);
DBCStorage <BankBagSlotPricesEntry> sBankBagSlotPricesStore(BankBagSlotPricesEntryfmt);
DBCStorage <BannedAddOnsEntry> sBannedAddOnsStore(BannedAddOnsfmt);
DBCStorage <BattlemasterListEntry> sBattlemasterListStore(BattlemasterListEntryfmt);
DBCStorage <BarberShopStyleEntry> sBarberShopStyleStore(BarberShopStyleEntryfmt);
DBCStorage <CharStartOutfitEntry> sCharStartOutfitStore(CharStartOutfitEntryfmt);
std::map<uint32, CharStartOutfitEntry const*> sCharStartOutfitMap;
DBCStorage <CharTitlesEntry> sCharTitlesStore(CharTitlesEntryfmt);
DBCStorage <ChatChannelsEntry> sChatChannelsStore(ChatChannelsEntryfmt);
DBCStorage <ChrClassesEntry> sChrClassesStore(ChrClassesEntryfmt);
DBCStorage <ChrRacesEntry> sChrRacesStore(ChrRacesEntryfmt);
DBCStorage <ChrPowerTypesEntry> sChrPowerTypesStore(ChrClassesXPowerTypesfmt);
DBCStorage <ChrSpecializationEntry> sChrSpecializationStore(ChrSpecializationEntryfmt);
ChrSpecializationByIndexArray sChrSpecializationByIndexStore;
SpecializationSpellsBySpecStore sSpecializationSpellsBySpecStore;
DBCStorage <CinematicSequencesEntry> sCinematicSequencesStore(CinematicSequencesEntryfmt);
DBCStorage <CreatureDisplayInfoEntry> sCreatureDisplayInfoStore(CreatureDisplayInfofmt);
DBCStorage <CreatureDisplayInfoExtraEntry> sCreatureDisplayInfoExtraStore(CreatureDisplayInfoExtrafmt);
DBCStorage <CreatureFamilyEntry> sCreatureFamilyStore(CreatureFamilyfmt);
DBCStorage <CreatureModelDataEntry> sCreatureModelDataStore(CreatureModelDatafmt);
DBCStorage <CreatureSpellDataEntry> sCreatureSpellDataStore(CreatureSpellDatafmt);
DBCStorage <CreatureTypeEntry> sCreatureTypeStore(CreatureTypefmt);
DBCStorage <CriteriaEntry> sCriteriaStore(Criteriafmt);
DBCStorage <CriteriaTreeEntry> sCriteriaTreeStore(CriteriaTreefmt);
DBCStorage <CurrencyTypesEntry> sCurrencyTypesStore(CurrencyTypesfmt);
uint32 PowersByClass[MAX_CLASSES][MAX_POWERS];

DBCStorage <DestructibleModelDataEntry> sDestructibleModelDataStore(DestructibleModelDatafmt);
DBCStorage <DifficultyEntry> sDifficultyStore(DifficultyFmt);
DBCStorage <DungeonEncounterEntry> sDungeonEncounterStore(DungeonEncounterfmt);
DBCStorage <DurabilityQualityEntry> sDurabilityQualityStore(DurabilityQualityfmt);
DBCStorage <DurabilityCostsEntry> sDurabilityCostsStore(DurabilityCostsfmt);

DBCStorage <EmotesEntry> sEmotesStore(EmotesEntryfmt);
DBCStorage <EmotesTextEntry> sEmotesTextStore(EmotesTextEntryfmt);

typedef std::map<uint32, SimpleFactionsList> FactionTeamMap;
static FactionTeamMap sFactionTeamMap;
DBCStorage <FactionEntry> sFactionStore(FactionEntryfmt);
DBCStorage <FactionTemplateEntry> sFactionTemplateStore(FactionTemplateEntryfmt);

DBCStorage <GameObjectDisplayInfoEntry> sGameObjectDisplayInfoStore(GameObjectDisplayInfofmt);
DBCStorage <GameTablesEntry> sGameTablesStore(GameTablesFmt);
DBCStorage <GemPropertiesEntry> sGemPropertiesStore(GemPropertiesEntryfmt);
DBCStorage <GlyphPropertiesEntry> sGlyphPropertiesStore(GlyphPropertiesfmt);
DBCStorage <GlyphSlotEntry> sGlyphSlotStore(GlyphSlotfmt);

GameTable <GtBarberShopCostBaseEntry>    sGtBarberShopCostBaseStore(GtBarberShopCostBasefmt);
GameTable <GtCombatRatingsEntry>         sGtCombatRatingsStore(GtCombatRatingsfmt);
GameTable <GtChanceToMeleeCritBaseEntry> sGtChanceToMeleeCritBaseStore(GtChanceToMeleeCritBasefmt);
GameTable <GtChanceToMeleeCritEntry>     sGtChanceToMeleeCritStore(GtChanceToMeleeCritfmt);
GameTable <GtChanceToSpellCritBaseEntry> sGtChanceToSpellCritBaseStore(GtChanceToSpellCritBasefmt);
GameTable <GtChanceToSpellCritEntry>     sGtChanceToSpellCritStore(GtChanceToSpellCritfmt);
GameTable <GtItemSocketCostPerLevelEntry> sGtItemSocketCostPerLevelStore(GtItemSocketCostPerLevelfmt);
GameTable <GtNPCManaCostScalerEntry>     sGtNPCManaCostScalerStore(GtNPCManaCostScalerfmt);
GameTable <GtNpcTotalHpEntry>            sGtNpcTotalHpStore(GtNpcTotalHpfmt);
GameTable <GtNpcTotalHpExp1Entry>        sGtNpcTotalHpExp1Store(GtNpcTotalHpExp1fmt);
GameTable <GtNpcTotalHpExp2Entry>        sGtNpcTotalHpExp2Store(GtNpcTotalHpExp2fmt);
GameTable <GtNpcTotalHpExp3Entry>        sGtNpcTotalHpExp3Store(GtNpcTotalHpExp3fmt);
GameTable <GtNpcTotalHpExp4Entry>        sGtNpcTotalHpExp4Store(GtNpcTotalHpExp4fmt);
GameTable <GtNpcTotalHpExp5Entry>        sGtNpcTotalHpExp5Store(GtNpcTotalHpExp5fmt);
GameTable <GtOCTClassCombatRatingScalarEntry> sGtOCTClassCombatRatingScalarStore(GtOCTClassCombatRatingScalarfmt);
GameTable <GtOCTLevelExperienceEntry>    sGtOCTLevelExperienceStore(GtOCTLevelExperiencefmt);
GameTable <GtOCTRegenHPEntry>            sGtOCTRegenHPStore(GtOCTRegenHPfmt);
GameTable <gtOCTHpPerStaminaEntry>       sGtOCTHpPerStaminaStore(GtOCTHpPerStaminafmt);
GameTable <GtRegenMPPerSptEntry>         sGtRegenMPPerSptStore(GtRegenMPPerSptfmt);
GameTable <GtSpellScalingEntry>          sGtSpellScalingStore(GtSpellScalingfmt);
GameTable <GtOCTBaseHPByClassEntry>      sGtOCTBaseHPByClassStore(GtOCTBaseHPByClassfmt);
GameTable <GtOCTBaseMPByClassEntry>      sGtOCTBaseMPByClassStore(GtOCTBaseMPByClassfmt);
DBCStorage <GuildPerkSpellsEntry>         sGuildPerkSpellsStore(GuildPerkSpellsfmt);

DBCStorage <ImportPriceArmorEntry>        sImportPriceArmorStore(ImportPriceArmorfmt);
DBCStorage <ImportPriceQualityEntry>      sImportPriceQualityStore(ImportPriceQualityfmt);
DBCStorage <ImportPriceShieldEntry>       sImportPriceShieldStore(ImportPriceShieldfmt);
DBCStorage <ImportPriceWeaponEntry>       sImportPriceWeaponStore(ImportPriceWeaponfmt);
DBCStorage <ItemPriceBaseEntry>           sItemPriceBaseStore(ItemPriceBasefmt);
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
//DBCStorage <ItemDisplayInfoEntry>       sItemDisplayInfoStore(ItemDisplayTemplateEntryfmt); -- not used currently
DBCStorage <ItemLimitCategoryEntry>       sItemLimitCategoryStore(ItemLimitCategoryEntryfmt);
DBCStorage <ItemRandomPropertiesEntry>    sItemRandomPropertiesStore(ItemRandomPropertiesfmt);
DBCStorage <ItemRandomSuffixEntry>        sItemRandomSuffixStore(ItemRandomSuffixfmt);
DBCStorage <ItemSetEntry>                 sItemSetStore(ItemSetEntryfmt);
DBCStorage <ItemSetSpellEntry>            sItemSetSpellStore(ItemSetSpellEntryfmt);
ItemSetSpellsStore                        sItemSetSpellsStore;

DBCStorage <LFGDungeonEntry> sLFGDungeonStore(LFGDungeonEntryfmt);
DBCStorage <LightEntry> sLightStore(LightEntryfmt);
DBCStorage <LiquidTypeEntry> sLiquidTypeStore(LiquidTypefmt);
DBCStorage <LockEntry> sLockStore(LockEntryfmt);

DBCStorage <MailTemplateEntry> sMailTemplateStore(MailTemplateEntryfmt);
DBCStorage <MapEntry> sMapStore(MapEntryfmt);

// DBC used only for initialization sMapDifficultyMap at startup.
DBCStorage <MapDifficultyEntry> sMapDifficultyStore(MapDifficultyEntryfmt); // only for loading
MapDifficultyMap sMapDifficultyMap;

DBCStorage <ModifierTreeEntry> sModifierTreeStore(ModifierTreefmt);
DBCStorage <MovieEntry> sMovieStore(MovieEntryfmt);
DBCStorage <MountCapabilityEntry> sMountCapabilityStore(MountCapabilityfmt);
DBCStorage <MountTypeEntry> sMountTypeStore(MountTypefmt);

DBCStorage <NameGenEntry> sNameGenStore(NameGenfmt);
NameGenContainer sGenerateNamesMap;

DBCStorage <PowerDisplayEntry> sPowerDisplayStore(PowerDisplayfmt);
DBCStorage <PvPDifficultyEntry> sPvPDifficultyStore(PvPDifficultyfmt);

DBCStorage <QuestSortEntry> sQuestSortStore(QuestSortEntryfmt);
DBCStorage <QuestV2Entry> sQuestV2Store(QuestV2fmt);
DBCStorage <QuestXPEntry>   sQuestXPStore(QuestXPfmt);
DBCStorage <QuestFactionRewEntry>  sQuestFactionRewardStore(QuestFactionRewardfmt);
DBCStorage <RandomPropertiesPointsEntry> sRandomPropertiesPointsStore(RandomPropertiesPointsfmt);
DBCStorage <ScalingStatDistributionEntry> sScalingStatDistributionStore(ScalingStatDistributionfmt);

DBCStorage <SkillLineEntry> sSkillLineStore(SkillLinefmt);
DBCStorage <SkillLineAbilityEntry> sSkillLineAbilityStore(SkillLineAbilityfmt);
DBCStorage <SkillRaceClassInfoEntry> sSkillRaceClassInfoStore(SkillRaceClassInfofmt);
SkillRaceClassInfoMap SkillRaceClassInfoBySkill;
DBCStorage <SkillTiersEntry> sSkillTiersStore(SkillTiersfmt);

DBCStorage <SoundEntriesEntry> sSoundEntriesStore(SoundEntriesfmt);

DBCStorage <SpecializationSpellsEntry> sSpecializationSpellsStore(SpecializationSpellsEntryfmt);
DBCStorage <SpellItemEnchantmentEntry> sSpellItemEnchantmentStore(SpellItemEnchantmentfmt);
DBCStorage <SpellItemEnchantmentConditionEntry> sSpellItemEnchantmentConditionStore(SpellItemEnchantmentConditionfmt);
DBCStorage <SpellEntry> sSpellStore(SpellEntryfmt);
DBCStorage <SpellEffectScalingEntry> sSpellEffectScalingStore(SpellEffectScalingfmt);

SpellCategoryStore sSpellsByCategoryStore;
PetFamilySpellsStore sPetFamilySpellsStore;
SpellsPerClassStore sSpellsPerClassStore;
ClassBySkillIdStore sClassBySkillIdStore;
SpellEffectScallingByEffectId sSpellEffectScallingByEffectId;


DBCStorage <SpellScalingEntry> sSpellScalingStore(SpellScalingEntryfmt);
DBCStorage <SpellTargetRestrictionsEntry> sSpellTargetRestrictionsStore(SpellTargetRestrictionsEntryfmt);
DBCStorage <SpellLevelsEntry> sSpellLevelsStore(SpellLevelsEntryfmt);
DBCStorage <SpellInterruptsEntry> sSpellInterruptsStore(SpellInterruptsEntryfmt);
DBCStorage <SpellEquippedItemsEntry> sSpellEquippedItemsStore(SpellEquippedItemsEntryfmt);
DBCStorage <SpellCooldownsEntry> sSpellCooldownsStore(SpellCooldownsEntryfmt);
DBCStorage <SpellAuraOptionsEntry> sSpellAuraOptionsStore(SpellAuraOptionsEntryfmt);
DBCStorage <SpellCastTimesEntry> sSpellCastTimesStore(SpellCastTimefmt);
DBCStorage <SpellCategoriesEntry> sSpellCategoriesStore(SpellCategoriesEntryfmt);
DBCStorage <SpellCategoryEntry> sSpellCategoryStore(SpellCategoryfmt);
DBCStorage <SpellEffectEntry> sSpellEffectStore(SpellEffectEntryfmt);
DBCStorage <SpellDurationEntry> sSpellDurationStore(SpellDurationfmt);
DBCStorage <SpellFocusObjectEntry> sSpellFocusObjectStore(SpellFocusObjectfmt);
DBCStorage <SpellRadiusEntry> sSpellRadiusStore(SpellRadiusfmt);
DBCStorage <SpellRangeEntry> sSpellRangeStore(SpellRangefmt);
DBCStorage <SpellShapeshiftEntry> sSpellShapeshiftStore(SpellShapeshiftEntryfmt);
DBCStorage <SpellShapeshiftFormEntry> sSpellShapeshiftFormStore(SpellShapeshiftFormfmt);
DBCStorage <StableSlotPricesEntry> sStableSlotPricesStore(StableSlotPricesfmt);
DBCStorage <SummonPropertiesEntry> sSummonPropertiesStore(SummonPropertiesfmt);
DBCStorage <TalentEntry> sTalentStore(TalentEntryfmt);
TalentBySpellIDMap sTalentBySpellIDMap;
SpecializationSpellsMap sSpecializationSpellsMap;
SpecializationOverrideSpellsMap sSpecializationOverrideSpellMap;

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

typedef std::list<std::string> StoreProblemList;

uint32 DBCFileCount = 0;

template<class T>
inline void LoadDBC(uint32& availableDbcLocales, StoreProblemList& errors, DBCStorage<T>& storage, std::string const& dbcPath, std::string const& filename, std::string const* customFormat = NULL, std::string const* customIndexName = NULL)
{
    // compatibility format and C++ structure sizes
    ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T),
        "Size of '%s' set by format string (%u) not equal size of C++ structure (%u).",
        filename.c_str(), DBCFileLoader::GetFormatRecordSize(storage.GetFormat()), uint32(sizeof(T)));

    ++DBCFileCount;
    std::string dbcFilename = dbcPath + filename;
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

    ++DBCFileCount;
    std::string dbcFilename = dbcPath + filename;

    if (storage.Load(dbcFilename.c_str()))
    {
        bool found = false;
        // Find table definition in GameTables.dbc
        for (uint32 i = 0; i < sGameTablesStore.GetNumRows(); ++i)
        {
            GameTablesEntry const* gt = sGameTablesStore.LookupEntry(i);
            if (!gt)
                continue;

            if (tableName == gt->Name)
            {
                found = true;
                storage.SetGameTableEntry(gt);
                break;
            }
        }

        ASSERT(found, "Game table %s definition not found in GameTables.dbc", tableName.c_str());
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

void LoadDBCStores(const std::string& dataPath)
{
    uint32 oldMSTime = getMSTime();

    std::string dbcPath = dataPath+"dbc/";

    StoreProblemList bad_dbc_files;
    uint32 availableDbcLocales = 0xFFFFFFFF;

    LoadDBC(availableDbcLocales, bad_dbc_files, sAreaStore,                   dbcPath, "AreaTable.dbc");

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

    LoadDBC(availableDbcLocales, bad_dbc_files, sAchievementStore,            dbcPath, "Achievement.dbc"/*, &CustomAchievementfmt, &CustomAchievementIndex*/);//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sAreaTriggerStore,            dbcPath, "AreaTrigger.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sAreaGroupStore,              dbcPath, "AreaGroup.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sAuctionHouseStore,           dbcPath, "AuctionHouse.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sArmorLocationStore,          dbcPath, "ArmorLocation.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sBankBagSlotPricesStore,      dbcPath, "BankBagSlotPrices.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sBannedAddOnsStore,           dbcPath, "BannedAddOns.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sBattlemasterListStore,       dbcPath, "BattlemasterList.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sBarberShopStyleStore,        dbcPath, "BarberShopStyle.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCharStartOutfitStore,        dbcPath, "CharStartOutfit.dbc");//19116
    for (uint32 i = 0; i < sCharStartOutfitStore.GetNumRows(); ++i)
        if (CharStartOutfitEntry const* outfit = sCharStartOutfitStore.LookupEntry(i))
            sCharStartOutfitMap[outfit->RaceID | (outfit->ClassID << 8) | (outfit->GenderID << 16)] = outfit;

    LoadDBC(availableDbcLocales, bad_dbc_files, sCharTitlesStore,             dbcPath, "CharTitles.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sChatChannelsStore,           dbcPath, "ChatChannels.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sChrClassesStore,             dbcPath, "ChrClasses.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sChrRacesStore,               dbcPath, "ChrRaces.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sChrPowerTypesStore,          dbcPath, "ChrClassesXPowerTypes.dbc");//19116
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

    LoadDBC(availableDbcLocales, bad_dbc_files, sChrSpecializationStore,      dbcPath, "ChrSpecialization.dbc");
    memset(sChrSpecializationByIndexStore, 0, sizeof(sChrSpecializationByIndexStore));
    for (uint32 i = 0; i < sChrSpecializationStore.GetNumRows(); ++i)
        if (ChrSpecializationEntry const* chrSpec = sChrSpecializationStore.LookupEntry(i))
            sChrSpecializationByIndexStore[chrSpec->ClassID][chrSpec->OrderIndex] = chrSpec;

    LoadDBC(availableDbcLocales, bad_dbc_files, sCinematicSequencesStore,     dbcPath, "CinematicSequences.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCreatureDisplayInfoStore,    dbcPath, "CreatureDisplayInfo.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCreatureDisplayInfoExtraStore, dbcPath, "CreatureDisplayInfoExtra.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCreatureFamilyStore,         dbcPath, "CreatureFamily.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCreatureModelDataStore,      dbcPath, "CreatureModelData.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCreatureSpellDataStore,      dbcPath, "CreatureSpellData.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCreatureTypeStore,           dbcPath, "CreatureType.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sCriteriaStore,               dbcPath, "Criteria.dbc");//19342
    LoadDBC(availableDbcLocales, bad_dbc_files, sCriteriaTreeStore,           dbcPath, "CriteriaTree.dbc");//19342
    LoadDBC(availableDbcLocales, bad_dbc_files, sCurrencyTypesStore,          dbcPath, "CurrencyTypes.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sDestructibleModelDataStore,  dbcPath, "DestructibleModelData.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sDifficultyStore,             dbcPath, "Difficulty.dbc");//19342
    LoadDBC(availableDbcLocales, bad_dbc_files, sDungeonEncounterStore,       dbcPath, "DungeonEncounter.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sDurabilityCostsStore,        dbcPath, "DurabilityCosts.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sDurabilityQualityStore,      dbcPath, "DurabilityQuality.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sEmotesStore,                 dbcPath, "Emotes.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sEmotesTextStore,             dbcPath, "EmotesText.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sFactionStore,                dbcPath, "Faction.dbc");//19116
    for (uint32 i = 0; i < sFactionStore.GetNumRows(); ++i)
    {
        FactionEntry const* faction = sFactionStore.LookupEntry(i);
        if (faction && faction->ParentFactionID)
        {
            SimpleFactionsList &flist = sFactionTeamMap[faction->ParentFactionID];
            flist.push_back(i);
        }
    }

    LoadDBC(availableDbcLocales, bad_dbc_files, sFactionTemplateStore,        dbcPath, "FactionTemplate.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sGameObjectDisplayInfoStore,  dbcPath, "GameObjectDisplayInfo.dbc");//19116
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

    LoadDBC(availableDbcLocales, bad_dbc_files, sGameTablesStore,             dbcPath, "GameTables.dbc");//19243
    LoadDBC(availableDbcLocales, bad_dbc_files, sGemPropertiesStore,          dbcPath, "GemProperties.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sGlyphPropertiesStore,        dbcPath, "GlyphProperties.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sGlyphSlotStore,              dbcPath, "GlyphSlot.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sGuildPerkSpellsStore,        dbcPath, "GuildPerkSpells.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sImportPriceArmorStore,       dbcPath, "ImportPriceArmor.dbc"); // 19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sImportPriceQualityStore,     dbcPath, "ImportPriceQuality.dbc"); // 19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sImportPriceShieldStore,      dbcPath, "ImportPriceShield.dbc"); // 19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sImportPriceWeaponStore,      dbcPath, "ImportPriceWeapon.dbc"); // 19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemPriceBaseStore,          dbcPath, "ItemPriceBase.dbc"); // 15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemBagFamilyStore,          dbcPath, "ItemBagFamily.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemClassStore,              dbcPath, "ItemClass.dbc"); // 19116
    //LoadDBC(dbcCount, availableDbcLocales, bad_dbc_files, sItemDisplayInfoStore,        dbcPath, "ItemDisplayInfo.dbc");     -- not used currently
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemLimitCategoryStore,      dbcPath, "ItemLimitCategory.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemRandomPropertiesStore,   dbcPath, "ItemRandomProperties.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemRandomSuffixStore,       dbcPath, "ItemRandomSuffix.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemSetStore,                dbcPath, "ItemSet.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemSetSpellStore,           dbcPath, "ItemSetSpell.dbc");//19116
    for (uint32 i = 0; i < sItemSetSpellStore.GetNumRows(); ++i)
        if (ItemSetSpellEntry const* entry = sItemSetSpellStore.LookupEntry(i))
            sItemSetSpellsStore[entry->ItemSetID].push_back(entry);

    LoadDBC(availableDbcLocales, bad_dbc_files, sItemArmorQualityStore,       dbcPath, "ItemArmorQuality.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemArmorShieldStore,        dbcPath, "ItemArmorShield.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemArmorTotalStore,         dbcPath, "ItemArmorTotal.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageAmmoStore,         dbcPath, "ItemDamageAmmo.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageOneHandStore,      dbcPath, "ItemDamageOneHand.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageOneHandCasterStore, dbcPath, "ItemDamageOneHandCaster.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageRangedStore,       dbcPath, "ItemDamageRanged.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageThrownStore,       dbcPath, "ItemDamageThrown.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageTwoHandStore,      dbcPath, "ItemDamageTwoHand.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageTwoHandCasterStore, dbcPath, "ItemDamageTwoHandCaster.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDamageWandStore,         dbcPath, "ItemDamageWand.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sItemDisenchantLootStore,     dbcPath, "ItemDisenchantLoot.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sLFGDungeonStore,             dbcPath, "LfgDungeons.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sLightStore,                  dbcPath, "Light.dbc"); //19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sLiquidTypeStore,             dbcPath, "LiquidType.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sLockStore,                   dbcPath, "Lock.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sMailTemplateStore,           dbcPath, "MailTemplate.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sMapStore,                    dbcPath, "Map.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sMapDifficultyStore,          dbcPath, "MapDifficulty.dbc");//19116
    // fill data
    sMapDifficultyMap[0][0] = MapDifficulty(DIFFICULTY_NONE, 0, 0, false);//map 0 is missingg from MapDifficulty.dbc use this till its ported to sql
    for (uint32 i = 0; i < sMapDifficultyStore.GetNumRows(); ++i)
        if (MapDifficultyEntry const* entry = sMapDifficultyStore.LookupEntry(i))
            sMapDifficultyMap[entry->MapID][entry->DifficultyID] = MapDifficulty(entry->DifficultyID, entry->RaidDuration, entry->MaxPlayers, entry->Message_lang[0] > 0);
    sMapDifficultyStore.Clear();

    LoadDBC(availableDbcLocales, bad_dbc_files, sModifierTreeStore,           dbcPath, "ModifierTree.dbc");//19342
    LoadDBC(availableDbcLocales, bad_dbc_files, sMountCapabilityStore,        dbcPath, "MountCapability.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sMountTypeStore,              dbcPath, "MountType.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sNameGenStore,                dbcPath, "NameGen.dbc"); // 19116
    for (uint32 i = 0; i < sNameGenStore.GetNumRows(); ++i)
        if (NameGenEntry const* entry = sNameGenStore.LookupEntry(i))
            sGenerateNamesMap[entry->Race].Contents[entry->Sex].emplace_back(entry->Name);
    sNameGenStore.Clear();

    LoadDBC(availableDbcLocales, bad_dbc_files, sMovieStore,                  dbcPath, "Movie.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sPhaseStore,                  dbcPath, "Phase.dbc"); // 19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sPowerDisplayStore,           dbcPath, "PowerDisplay.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sPvPDifficultyStore,          dbcPath, "PvpDifficulty.dbc");//19116

    for (uint32 i = 0; i < sPvPDifficultyStore.GetNumRows(); ++i)
        if (PvPDifficultyEntry const* entry = sPvPDifficultyStore.LookupEntry(i))
            if (entry->BracketID > MAX_BATTLEGROUND_BRACKETS)
                ASSERT(false && "Need update MAX_BATTLEGROUND_BRACKETS by DBC data");

    LoadDBC(availableDbcLocales, bad_dbc_files, sQuestV2Store,                dbcPath, "QuestV2.dbc");//19342
    LoadDBC(availableDbcLocales, bad_dbc_files, sQuestXPStore,                dbcPath, "QuestXP.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sQuestFactionRewardStore,     dbcPath, "QuestFactionReward.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sQuestSortStore,              dbcPath, "QuestSort.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sRandomPropertiesPointsStore, dbcPath, "RandPropPoints.dbc");//19116

    LoadDBC(availableDbcLocales, bad_dbc_files, sScalingStatDistributionStore, dbcPath, "ScalingStatDistribution.dbc");
    LoadDBC(availableDbcLocales, bad_dbc_files, sSkillLineStore,              dbcPath, "SkillLine.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSkillLineAbilityStore,       dbcPath, "SkillLineAbility.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSkillRaceClassInfoStore,     dbcPath, "SkillRaceClassInfo.dbc");//19116
    for (uint32 i = 0; i < sSkillRaceClassInfoStore.GetNumRows(); ++i)
        if (SkillRaceClassInfoEntry const* entry = sSkillRaceClassInfoStore.LookupEntry(i))
            if (sSkillLineStore.LookupEntry(entry->SkillID))
                SkillRaceClassInfoBySkill.emplace(entry->SkillID, entry);

    LoadDBC(availableDbcLocales, bad_dbc_files, sSkillTiersStore,             dbcPath, "SkillTiers.dbc");
    LoadDBC(availableDbcLocales, bad_dbc_files, sSoundEntriesStore,           dbcPath, "SoundEntries.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpecializationSpellsStore,   dbcPath, "SpecializationSpells.dbc");
    for (uint32 i = 1; i < sSpecializationSpellsStore.GetNumRows(); ++i)
    {
        SpecializationSpellsEntry const* specSpells = sSpecializationSpellsStore.LookupEntry(i);
        if (!specSpells)
            continue;
        sSpecializationSpellsBySpecStore[specSpells->SpecID].push_back(specSpells);

        if (specSpells->OverridesSpellID)
            sSpecializationOverrideSpellMap[specSpells->SpecID][specSpells->OverridesSpellID] = specSpells->SpellID;
    }
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellStore,                  dbcPath, "Spell.dbc"/*, &CustomSpellEntryfmt, &CustomSpellEntryIndex*/);
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellCategoriesStore,        dbcPath, "SpellCategories.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellCategoryStore,          dbcPath, "SpellCategory.dbc");
    for (uint32 i = 1; i < sSpellStore.GetNumRows(); ++i)
    {
        SpellEntry const* spell = sSpellStore.LookupEntry(i);
        if (!spell)
            continue;

        if (SpellCategoriesEntry const* category = sSpellCategoriesStore.LookupEntry(spell->CategoriesID))
            sSpellsByCategoryStore[category->Category].insert(i);
    }

    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellScalingStore,           dbcPath,"SpellScaling.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellTargetRestrictionsStore, dbcPath,"SpellTargetRestrictions.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellLevelsStore,            dbcPath,"SpellLevels.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellInterruptsStore,        dbcPath,"SpellInterrupts.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellEquippedItemsStore,     dbcPath,"SpellEquippedItems.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellCooldownsStore,         dbcPath,"SpellCooldowns.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellAuraOptionsStore,       dbcPath,"SpellAuraOptions.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellEffectStore,            dbcPath,"SpellEffect.dbc"/*, &CustomSpellEffectEntryfmt, &CustomSpellEffectEntryIndex*/);//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellCastTimesStore,         dbcPath, "SpellCastTimes.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellDurationStore,          dbcPath, "SpellDuration.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellFocusObjectStore,       dbcPath, "SpellFocusObject.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellEffectScalingStore,     dbcPath, "SpellEffectScaling.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellItemEnchantmentStore,   dbcPath, "SpellItemEnchantment.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellItemEnchantmentConditionStore, dbcPath, "SpellItemEnchantmentCondition.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellRadiusStore,            dbcPath, "SpellRadius.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellRangeStore,             dbcPath, "SpellRange.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellShapeshiftStore,        dbcPath, "SpellShapeshift.dbc");//19116
    LoadDBC(availableDbcLocales, bad_dbc_files, sSpellShapeshiftFormStore,    dbcPath, "SpellShapeshiftForm.dbc");//19116
    //LoadDBC(availableDbcLocales, bad_dbc_files, sStableSlotPricesStore,       dbcPath, "StableSlotPrices.dbc");
    LoadDBC(availableDbcLocales, bad_dbc_files, sSummonPropertiesStore,       dbcPath, "SummonProperties.dbc");//15595

    for (uint32 j = 0; j < sSpellEffectScalingStore.GetNumRows(); j++)
    {
        SpellEffectScalingEntry const* spellEffectScaling = sSpellEffectScalingStore.LookupEntry(j);
        if (!spellEffectScaling)
            continue;

        sSpellEffectScallingByEffectId.insert(std::make_pair(spellEffectScaling->SpellEffectID, j));
    }
    std::map<std::string, uint32> classIdByName;
    for (uint32 j = 0; j < sChrClassesStore.GetNumRows(); j++)
    {
        ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(j);
        if (!classEntry)
            continue;

        classIdByName.insert(std::make_pair(std::string(classEntry->Name_lang), j));
    }

    for (uint32 j = 0; j < sSkillLineStore.GetNumRows(); j++)
    {
        SkillLineEntry const* skillEntry = sSkillLineStore.LookupEntry(j);
        if (!skillEntry)
            continue;

        if (skillEntry->CategoryID!= SKILL_CATEGORY_CLASS)
            continue;

        std::map<std::string, uint32> ::const_iterator iter = classIdByName.find(std::string(skillEntry->DisplayName_lang));
        if (iter == classIdByName.end())
            continue;

        sClassBySkillIdStore.insert(std::make_pair(j, iter->second));
    }

    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const* skillAbility = sSkillLineAbilityStore.LookupEntry(j);
        if (!skillAbility)
            continue;

        if (skillAbility->AquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
            continue;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(skillAbility->SpellID);
        if (!spellInfo)
            continue;

        SpellLevelsEntry const* spellLevels = sSpellLevelsStore.LookupEntry(spellInfo->LevelsID);
        if (!spellLevels || !spellLevels->SpellLevel)
            continue;

        uint32 classId = GetClassBySkillId(skillAbility->SkillLine);

        if (!classId)
            continue;

        if (sSpellsPerClassStore.find(classId) == sSpellsPerClassStore.end())
            sSpellsPerClassStore.insert(make_pair(classId, std::list<SkillLineAbilityEntry const*>()));

        sSpellsPerClassStore[classId].push_back(skillAbility);
    }

    LoadDBC(availableDbcLocales, bad_dbc_files, sTalentStore,                 dbcPath, "Talent.dbc");//15595

    // Create Spelldifficulty searcher
    /* TODO: 6.x update to new spell diffs
    for (uint32 i = 0; i < sSpellDifficultyStore.GetNumRows(); ++i)
    {
        SpellDifficultyEntry const* spellDiff = sSpellDifficultyStore.LookupEntry(i);
        if (!spellDiff)
            continue;

        SpellDifficultyEntry newEntry;
        memset(newEntry.SpellID, 0, 4*sizeof(uint32));
        for (uint32 x = 0; x < MAX_DIFFICULTY; ++x)
        {
            if (spellDiff->SpellID[x] <= 0 || !sSpellStore.LookupEntry(spellDiff->SpellID[x]))
            {
                if (spellDiff->SpellID[x] > 0)//don't show error if spell is <= 0, not all modes have spells and there are unknown negative values
                    TC_LOG_ERROR("sql.sql", "spelldifficulty_dbc: spell %i at field id:%u at spellid%i does not exist in SpellStore (spell.dbc), loaded as 0", spellDiff->SpellID[x], spellDiff->ID, x);
                newEntry.SpellID[x] = 0;//spell was <= 0 or invalid, set to 0
            }
            else
                newEntry.SpellID[x] = spellDiff->SpellID[x];
        }

        if (newEntry.SpellID[0] <= 0 || newEntry.SpellID[1] <= 0)//id0-1 must be always set!
            continue;

        for (uint32 x = 0; x < MAX_DIFFICULTY; ++x)
            if (newEntry.SpellID[x])
                sSpellMgr->SetSpellDifficultyId(uint32(newEntry.SpellID[x]), spellDiff->ID);
    }*/

    for (unsigned int i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        sTalentBySpellIDMap[talentInfo->SpellID] = talentInfo;
    }

    //LoadDBC(availableDbcLocales, bad_dbc_files, sTeamContributionPointsStore, dbcPath, "TeamContributionPoints.dbc");
    LoadDBC(availableDbcLocales, bad_dbc_files, sTotemCategoryStore,          dbcPath, "TotemCategory.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sTransportAnimationStore,     dbcPath, "TransportAnimation.dbc");
    for (uint32 i = 0; i < sTransportAnimationStore.GetNumRows(); ++i)
    {
        TransportAnimationEntry const* anim = sTransportAnimationStore.LookupEntry(i);
        if (!anim)
            continue;

        sTransportMgr->AddPathNodeToTransport(anim->TransportID, anim->TimeIndex, anim);
    }

    LoadDBC(availableDbcLocales, bad_dbc_files, sTransportRotationStore,     dbcPath, "TransportRotation.dbc");
    for (uint32 i = 0; i < sTransportRotationStore.GetNumRows(); ++i)
    {
        TransportRotationEntry const* rot = sTransportRotationStore.LookupEntry(i);
        if (!rot)
            continue;

        sTransportMgr->AddPathRotationToTransport(rot->TransportID, rot->TimeIndex, rot);
    }

    LoadDBC(availableDbcLocales, bad_dbc_files, sUnitPowerBarStore,           dbcPath, "UnitPowerBar.dbc");//15595

    LoadDBC(availableDbcLocales, bad_dbc_files, sVehicleStore,                dbcPath, "Vehicle.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sVehicleSeatStore,            dbcPath, "VehicleSeat.dbc");//15595

    LoadDBC(availableDbcLocales, bad_dbc_files, sWMOAreaTableStore,           dbcPath, "WMOAreaTable.dbc");//15595
    for (uint32 i = 0; i < sWMOAreaTableStore.GetNumRows(); ++i)
        if (WMOAreaTableEntry const* entry = sWMOAreaTableStore.LookupEntry(i))
            sWMOAreaInfoByTripple.insert(WMOAreaInfoByTripple::value_type(WMOAreaTableTripple(entry->WMOID, entry->NameSet, entry->WMOGroupID), entry));
    LoadDBC(availableDbcLocales, bad_dbc_files, sWorldMapAreaStore,           dbcPath, "WorldMapArea.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sWorldMapOverlayStore,        dbcPath, "WorldMapOverlay.dbc");//15595
    LoadDBC(availableDbcLocales, bad_dbc_files, sWorldSafeLocsStore,          dbcPath, "WorldSafeLocs.dbc"); // 19116

    LoadGameTable(bad_dbc_files, "BarberShopCostBase", sGtBarberShopCostBaseStore, dbcPath, "gtBarberShopCostBase.dbc");//19342
    LoadGameTable(bad_dbc_files, "CombatRatings", sGtCombatRatingsStore, dbcPath, "gtCombatRatings.dbc");//19342
    LoadGameTable(bad_dbc_files, "ChanceToMeleeCritBase", sGtChanceToMeleeCritBaseStore, dbcPath, "gtChanceToMeleeCritBase.dbc");//19342
    LoadGameTable(bad_dbc_files, "ChanceToMeleeCrit", sGtChanceToMeleeCritStore, dbcPath, "gtChanceToMeleeCrit.dbc");//19342
    LoadGameTable(bad_dbc_files, "ChanceToSpellCritBase", sGtChanceToSpellCritBaseStore, dbcPath, "gtChanceToSpellCritBase.dbc");//19342
    LoadGameTable(bad_dbc_files, "ChanceToSpellCrit", sGtChanceToSpellCritStore, dbcPath, "gtChanceToSpellCrit.dbc");//19342
    LoadGameTable(bad_dbc_files, "ItemSocketCostPerLevel", sGtItemSocketCostPerLevelStore, dbcPath, "gtItemSocketCostPerLevel.dbc");//19342
    LoadGameTable(bad_dbc_files, "NPCManaCostScaler", sGtNPCManaCostScalerStore, dbcPath, "gtNPCManaCostScaler.dbc");//19342
    LoadGameTable(bad_dbc_files, "NpcTotalHp", sGtNpcTotalHpStore, dbcPath, "gtNpcTotalHp.dbc"); // 19445
    LoadGameTable(bad_dbc_files, "NpcTotalHpExp1", sGtNpcTotalHpExp1Store, dbcPath, "gtNpcTotalHpExp1.dbc"); // 19445
    LoadGameTable(bad_dbc_files, "NpcTotalHpExp2", sGtNpcTotalHpExp2Store, dbcPath, "gtNpcTotalHpExp2.dbc"); // 19445
    LoadGameTable(bad_dbc_files, "NpcTotalHpExp3", sGtNpcTotalHpExp3Store, dbcPath, "gtNpcTotalHpExp3.dbc"); // 19445
    LoadGameTable(bad_dbc_files, "NpcTotalHpExp4", sGtNpcTotalHpExp4Store, dbcPath, "gtNpcTotalHpExp4.dbc"); // 19445
    LoadGameTable(bad_dbc_files, "NpcTotalHpExp5", sGtNpcTotalHpExp5Store, dbcPath, "gtNpcTotalHpExp5.dbc"); // 19445
    LoadGameTable(bad_dbc_files, "OCTClassCombatRatingScalar", sGtOCTClassCombatRatingScalarStore, dbcPath, "gtOCTClassCombatRatingScalar.dbc");//19342
    LoadGameTable(bad_dbc_files, "OCTHPPerStamina", sGtOCTHpPerStaminaStore, dbcPath, "gtOCTHpPerStamina.dbc");//19342
    LoadGameTable(bad_dbc_files, "OCTLevelExperience", sGtOCTLevelExperienceStore, dbcPath, "gtOCTLevelExperience.dbc"); // 19342
    LoadGameTable(bad_dbc_files, "RegenMPPerSpt", sGtRegenMPPerSptStore, dbcPath, "gtRegenMPPerSpt.dbc");//19342
    LoadGameTable(bad_dbc_files, "SpellScaling", sGtSpellScalingStore, dbcPath, "gtSpellScaling.dbc");//19342
    LoadGameTable(bad_dbc_files, "OCTBaseHPByClass", sGtOCTBaseHPByClassStore, dbcPath, "gtOCTBaseHPByClass.dbc");//19342
    LoadGameTable(bad_dbc_files, "OCTBaseMPByClass", sGtOCTBaseMPByClassStore, dbcPath, "gtOCTBaseMPByClass.dbc");//19342

    // error checks
    if (bad_dbc_files.size() >= DBCFileCount)
    {
        TC_LOG_ERROR("misc", "Incorrect DataDir value in worldserver.conf or ALL required *.dbc files (%d) not found by path: %sdbc", DBCFileCount, dataPath.c_str());
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
    if (!sAreaStore.LookupEntry(6133)          ||     // last area (areaflag) added in 6.0.3 (19342)
        !sCharTitlesStore.LookupEntry(444)     ||     // last char title added in 6.0.3 (19342)
        !sGemPropertiesStore.LookupEntry(2534) ||     // last gem property added in 6.0.3 (19342)
        !sMapStore.LookupEntry(1447)            ||     // last map added in 6.0.3 (19342)
        !sSpellStore.LookupEntry(178987)       )      // last spell added in 6.0.3 (19342)
    {
        TC_LOG_ERROR("misc", "You have _outdated_ DBC files. Please extract correct versions from current using client.");
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d DBC data stores in %u ms", DBCFileCount, GetMSTimeDiffToNow(oldMSTime));
}

std::string const& GetRandomCharacterName(uint8 race, uint8 gender)
{
    ASSERT(gender < GENDER_NONE);
    return Trinity::Containers::SelectRandomContainerElement(sGenerateNamesMap[race].Contents[gender]);
}

SimpleFactionsList const* GetFactionTeamList(uint32 faction)
{
    FactionTeamMap::const_iterator itr = sFactionTeamMap.find(faction);
    if (itr != sFactionTeamMap.end())
        return &itr->second;

    return NULL;
}

char const* GetPetName(uint32 petfamily, uint32 /*dbclang*/)
{
    if (!petfamily)
        return NULL;
    CreatureFamilyEntry const* pet_family = sCreatureFamilyStore.LookupEntry(petfamily);
    if (!pet_family)
        return NULL;
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
        case CONTENT_1_60:
            return 60;
        case CONTENT_61_70:
            return 70;
        case CONTENT_71_80:
            return 80;
        case CONTENT_81_85:
            return 85;
        case CONTENT_86_90:
            return 90;
        case CONTENT_91_100:
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

bool IsTotemCategoryCompatiableWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId)
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

void Zone2MapCoordinates(float& x, float& y, uint32 zone)
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(zone);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return;

    std::swap(x, y);                                         // at client map coords swapped
    x = x*((maEntry->LocBottom-maEntry->LocTop)/100)+maEntry->LocTop;
    y = y*((maEntry->LocRight-maEntry->LocLeft)/100)+maEntry->LocLeft;      // client y coord from top to down
}

void Map2ZoneCoordinates(float& x, float& y, uint32 zone)
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(zone);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return;

    x = (x - maEntry->LocTop) / ((maEntry->LocBottom - maEntry->LocTop) / 100);
    y = (y - maEntry->LocLeft) / ((maEntry->LocRight - maEntry->LocLeft) / 100);    // client y coord from top to down
    std::swap(x, y);                                         // client have map coords swapped
}

MapDifficulty const* GetDefaultMapDifficulty(uint32 mapID)
{
    auto itr = sMapDifficultyMap.find(mapID);
    if (itr == sMapDifficultyMap.end())
        return nullptr;

    if (itr->second.empty())
        return nullptr;

    for (auto& p : itr->second)
    {
        DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(p.first);
        if (!difficulty)
            continue;

        if (difficulty->Flags & DIFFICULTY_FLAG_DEFAULT)
            return &p.second;
    }

    return &itr->second.begin()->second;
}

MapDifficulty const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty)
{
    auto itr = sMapDifficultyMap.find(mapId);
    if (itr == sMapDifficultyMap.end())
        return nullptr;

    auto diffItr = itr->second.find(difficulty);
    if (diffItr == itr->second.end())
        return nullptr;

    return &diffItr->second;
}

MapDifficulty const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty)
{
    DifficultyEntry const* diffEntry = sDifficultyStore.LookupEntry(difficulty);
    if (!diffEntry)
        return GetDefaultMapDifficulty(mapId);

    uint32 tmpDiff = difficulty;
    MapDifficulty const* mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff));
    while (!mapDiff)
    {
        tmpDiff = diffEntry->FallbackDifficultyID;
        diffEntry = sDifficultyStore.LookupEntry(tmpDiff);
        if (!diffEntry)
            return GetDefaultMapDifficulty(mapId);

        // pull new data
        mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // we are 10 normal or 25 normal
    }

    difficulty = Difficulty(tmpDiff);
    return mapDiff;
}

PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level)
{
    PvPDifficultyEntry const* maxEntry = NULL;              // used for level > max listed level case
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

PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id)
{
    for (uint32 i = 0; i < sPvPDifficultyStore.GetNumRows(); ++i)
        if (PvPDifficultyEntry const* entry = sPvPDifficultyStore.LookupEntry(i))
            if (entry->MapID == mapid && entry->GetBracketId() == id)
                return entry;

    return NULL;
}

TalentEntry const* GetTalentBySpellID(uint32 spellID)
{
    auto itr = sTalentBySpellIDMap.find(spellID);
    if (itr != sTalentBySpellIDMap.end())
        return itr->second;
    return nullptr;
}

uint32 GetLiquidFlags(uint32 liquidType)
{
    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquidType))
        return 1 << liq->Type;

    return 0;
}

CharStartOutfitEntry const* GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender)
{
    std::map<uint32, CharStartOutfitEntry const*>::const_iterator itr = sCharStartOutfitMap.find(race | (class_ << 8) | (gender << 16));
    if (itr == sCharStartOutfitMap.end())
        return NULL;

    return itr->second;
}

uint32 GetPowerIndexByClass(uint32 powerType, uint32 classId)
{
    return PowersByClass[classId][powerType];
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

uint32 GetClassBySkillId(uint32 skillId)
{
    ClassBySkillIdStore::const_iterator iter = sClassBySkillIdStore.find(skillId);
    if (iter != sClassBySkillIdStore.end())
        return iter->second;
    return 0;
}

uint32 GetSkillIdByClass(uint32 classId)
{
    for (ClassBySkillIdStore::const_iterator iter = sClassBySkillIdStore.begin(); iter != sClassBySkillIdStore.end(); iter++)
        if (iter->second == classId)
            return iter->first;
    return 0;
}

std::list<uint32> GetSpellsForLevels(uint32 classId, uint32 raceMask, uint32 specializationId, uint32 minLevel, uint32 maxLevel)
{
    std::list<uint32> spellList;

    if (classId != 0)
    {
        SpellsPerClassStore::const_iterator classIter = sSpellsPerClassStore.find(classId);
        if (classIter != sSpellsPerClassStore.end())
        {
            const std::list<SkillLineAbilityEntry const*>& learnSpellList = classIter->second;
            for (std::list<SkillLineAbilityEntry const*>::const_iterator iter = learnSpellList.begin(); iter != learnSpellList.end(); iter++)
            {
                SkillLineAbilityEntry const* skillLine = *iter;
                if (!skillLine)
                    continue;

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->SpellID);
                if (!spellInfo)
                    continue;

                if (skillLine->RaceMask && !(skillLine->RaceMask & raceMask))
                    continue;

                if (spellInfo->SpellLevel <= minLevel || spellInfo->SpellLevel > maxLevel)
                    continue;

                spellList.push_back(spellInfo->Id);
            }
        }
    }

    if (!specializationId)
        return spellList;

    SpecializationSpellsBySpecStore::const_iterator specIter = sSpecializationSpellsBySpecStore.find(specializationId);
    if (specIter != sSpecializationSpellsBySpecStore.end())
    {
        SpecializationSpellsBySpecEntry learnSpellList = specIter->second;
        for (size_t i = 0; i < learnSpellList.size(); ++i)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(learnSpellList[i]->SpellID);
            if (!spellInfo)
            {
                TC_LOG_ERROR("spells", "GetSpellsForLevels: spell %u not found in spellstore", learnSpellList[i]->SpellID);
                continue;
            }
            if (spellInfo->SpellLevel <= minLevel || spellInfo->SpellLevel > maxLevel)
                continue;

            spellList.push_back(spellInfo->Id);
        }
    }
    return spellList;
}

uint32 GetTalentSpellCost(uint32 spellId)
{
    TalentBySpellIDMap::const_iterator itr = sTalentBySpellIDMap.find(spellId);
    if (itr == sTalentBySpellIDMap.end())
        return 0;
    return 1;
}

uint32 GetQuestUniqueBitFlag(uint32 questId)
{
    QuestV2Entry const* v2 = sQuestV2Store.LookupEntry(questId);
    if (!v2)
        return 0;

    return v2->UniqueBitFlag;
}
