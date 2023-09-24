/*
 * Copyright (C) 2019+ ATieshCore <https://at-wow.org/>
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

#include "DBCStoresMgr.h"
#include "DatabaseEnv.h"
#include "SpellMgr.h"
#include "Log.h"

DBCStoresMgr* DBCStoresMgr::instance()
{
    static DBCStoresMgr instance;
    return &instance;
}

DBCStoresMgr::DBCStoresMgr()
{
    _bannedAddonsNumRow         = 0;
    _itemRandomSuffixNumRow     = 0;
    _spellNumRow                = 0;
    _spellItemEnchantmentNumRow = 0;
    _taxiPathNumRow             = 0;
}

DBCStoresMgr::~DBCStoresMgr()
{
    _achievementMap.clear();
    _achievementCriteriaMap.clear();
    _areaTableMap.clear();
    _areaGroupMap.clear();
    _areaPOIMap.clear();
    _areaTriggerMap.clear();
    _auctionHouseMap.clear();
    _bankBagSlotPricesMap.clear();
    _bannedAddonsMap.clear();
    _barberShopStyleMap.clear();
    _battlemasterListMap.clear();
    _characterFacialHairStyleMap.clear();
    _charSectionMap.clear();
    _charStartOutfitMap.clear();
    _charTitlesMap.clear();
    _chatChannelsMap.clear();
    _chrClassesMap.clear();
    _chrRacesMap.clear();
    _cinematicCameraMap.clear();
    _cinematicSequencesMap.clear();
    _creatureDisplayInfoMap.clear();
    _creatureDisplayInfoExtraMap.clear();
    _creatureFamilyMap.clear();
    _creatureModelDataMap.clear();
    _creatureSpellDataMap.clear();
    _creatureTypeMap.clear();
    _currencyCategoryMap.clear();
    _currencyTypesMap.clear();
    _destructibleModelDataMap.clear();
    _dungeonEncounterMap.clear();
    _durabilityCoastsMap.clear();
    _durabilityQualityMap.clear();
    _emotesMap.clear();
    _emotesTextMap.clear();
    _emotesTextSoundMap.clear();
    _factionMap.clear();
    _factionTemplateMap.clear();
    _gameobjectArtKitMap.clear();
    _gameobjectDisplayInfoMap.clear();
    _gemPropertiesMap.clear();
    _glyphPropertiesMap.clear();
    _glyphSlotMap.clear();
    _gtBarberShopCostBaseMap.clear();
    _gtCombatRatingsMap.clear();
    _gtChanceToMeleeCritBaseMap.clear();
    _gtChanceToMeleeCritMap.clear();
    _gtChanceToSpellCritBaseMap.clear();
    _gtChanceToSpellCritMap.clear();
    _gtNPCManaCostScalerMap.clear();
    _gtOCTClassCombatRatingScalarMap.clear();
    _gtOCTRegenHPMap.clear();
    _gtOCTRegenMPMap.clear();
    _gtRegenHPPerSptMap.clear();
    _gtRegenMPPerSptMap.clear();
    _holidaysMap.clear();
    _itemMap.clear();
    _itemBagFamilyMap.clear();
    _itemDisplayInfoMap.clear();
    _itemExtendedCostMap.clear();
    _itemLimitCategoryMap.clear();
    _itemRandomPropertiesMap.clear();
    _itemRandomSuffixMap.clear();
    _itemSetMap.clear();
    _lfgDungeonMap.clear();
    _lightMap.clear();
    _liquidTypeMap.clear();
    _lockMap.clear();
    _mailTemplateMap.clear();
    _mapMap.clear();
    _mapDifficultyMap.clear();
    _movieMap.clear();
    _namesProfanityMap.clear();
    _namesReservedMap.clear();    
    _overrideSpellDataMap.clear();
    _powerDisplayMap.clear();
    _pvpDifficultyMap.clear();
    _questSortMap.clear();
    _questXPMap.clear();
    _questFactionRewardMap.clear();
    _randPropPointsMap.clear();
    _scalingStatDistributionMap.clear();
    _scalingStatValuesMap.clear();
    _skillLineMap.clear();
    _skillLineAbilityMap.clear();
    _skillRaceClassInfoMap.clear();
    _skillTiersMap.clear();
    _soundEntriesMap.clear();
    _spellMap.clear();
    _spellCastTimesMap.clear();
    _spellCategoryMap.clear();
    _spellItemEnchantmentMap.clear();
    _spellDiffucultyMap.clear();
    _spellDurationMap.clear();
    _spellFocusObjectMap.clear();
    _spellItemEnchantmentConditionMap.clear();
    _spellRadiusMap.clear();
    _spellRangeMap.clear();
    _spellRuneCostMap.clear();
    _spellShapeShiftFormMap.clear();
    _spellVisualMap.clear();
    _stableSlotPricesMap.clear();
    _summonPropertiesMap.clear();
    _talentMap.clear();
    _talentTabMap.clear();
    _taxiNodesMap.clear();
    _taxiPathMap.clear();
    _taxiPathNodeMap.clear();
    _teamContributionPointsMap.clear();
    _totemCategoryMap.clear();
    _transportAnimationMap.clear();
    _transportRotationMap.clear();
    _vehicleMap.clear();
    _vehicleSeatMap.clear();
    _wmoAreaTableMap.clear();
    _worldMapAreaMap.clear();
    _worldMapOverlayMap.clear();
    _worldSafeLocsMap.clear();

    // handle additional containers
    for (uint8 i = 0; i < TOTAL_LOCALES; i++)
        NamesProfaneValidators[i].clear();
    for (uint8 i = 0; i < TOTAL_LOCALES; i++)
        NamesReservedValidators[i].clear();

    for (auto& pfsID : _petFamilySpellsStore)
        pfsID.second.clear();
    _petFamilySpellsStore.clear();
    _petTalentSpells.clear();
    _talentSpellPos.clear();

    _bannedAddonsNumRow         = 0;
    _itemRandomSuffixNumRow     = 0;
    _spellNumRow                = 0;
    _spellItemEnchantmentNumRow = 0;
    _taxiPathNumRow             = 0;

    for (uint8 i = 0; i < MAX_CLASSES; i++)
        for (uint8 j = 0; j < 3; j++)
            _TalentTabPages[i][j] = 0;

    _TaxiNodesMask.fill(0);
    _OldContinentsNodesMask.fill(0);
    _HordeTaxiNodesMask.fill(0);
    _AllianceTaxiNodesMask.fill(0);
    _DeathKnightTaxiNodesMask.fill(0);

    for (auto& tpsID : _taxiPathSetBySource)
        tpsID.second.clear();
    _taxiPathSetBySource.clear();

    for (uint32 i = 1; i < _taxiPathNodesByPath.size(); ++i)
        _taxiPathNodesByPath[i].clear();

    _characterFacialHairStylesByTripple.clear();
    _charSectionsByPenta.clear();
    _charStartOutfitByTripple.clear();
    _emotesTextSoundByTripple.clear();
    _lfgDungeonByDouble.clear();
    _mapDifficultyByDouble.clear();
    _skillRaceClassInfoBySkill.clear();
    _wmoAreaInfoByTripple.clear();
}

void DBCStoresMgr::Initialize()
{
    _Load_Achievement();
    _Load_AchievementCriteria();
    _Load_AreaTable();
    _Load_AreaGroup();
    //_Load_AreaPOI(); // unused
    _Load_AreaTrigger();
    _Load_AuctionHouse();
    _Load_BankBagSlotPrices();
    _Load_BannedAddOns();
    _Load_BarberShopStyle();
    _Load_BattlemasterList();
    _Load_CharacterFacialHairStyles();
    _Load_CharSections();
    _Load_CharStartOutfit();
    _Load_CharTitles();
    _Load_ChatChannels();
    _Load_ChrClasses();
    _Load_ChrRaces();
    _Load_CinematicCamera();
    _Load_CinematicSequences();
    _Load_CreatureDisplayInfo();
    _Load_CreatureDisplayInfoExtra();
    _Load_CreatureFamily();
    _Load_CreatureModelData();
    _Load_CreatureSpellData();
    _Load_CreatureType();
    //_Load_CurrencyCategory(); // unused
    _Load_CurrencyTypes();
    _Load_DestructibleModelData();
    _Load_DungeonEncounter();
    _Load_DurabilityCosts();
    _Load_DurabilityQuality();
    _Load_Emotes();
    _Load_EmotesText();
    _Load_EmotesTextSound();
    _Load_Faction();
    _Load_FactionTemplate();
    _Load_GameObjectArtKit();
    _Load_GameObjectDisplayInfo();
    _Load_GemProperties();
    _Load_GlyphProperties();
    _Load_GlyphSlot();
    _Load_gtBarberShopCostBase();
    _Load_gtCombatRatings();
    _Load_gtChanceToMeleeCritBase();
    _Load_gtChanceToMeleeCrit();
    _Load_gtChanceToSpellCritBase();
    _Load_gtChanceToSpellCrit();
    _Load_gtNPCManaCostScaler();
    _Load_gtOCTClassCombatRatingScalar();
    _Load_gtOCTRegenHP();
    //_Load_gtOCTRegenMP(); // unused
    _Load_gtRegenHPPerSpt();
    _Load_gtRegenMPPerSpt();
    _Load_Holidays();
    _Load_Item();
    _Load_ItemBagFamily();
    _Load_ItemDisplayInfo();
    _Load_ItemExtendedCost();
    _Load_ItemLimitCategory();
    _Load_ItemRandomProperties();
    _Load_ItemRandomSuffix();
    _Load_ItemSet();
    _Load_LFGDungeons();
    _Load_Light();
    _Load_LiquidType();
    _Load_Lock();
    _Load_MailTemplate();
    _Load_Map();
    _Load_MapDifficulty();
    _Load_Movie();
    _Load_NamesProfanity();
    _Load_NamesReserved();
    _Load_OverrideSpellData();
    _Load_PowerDisplay();
    _Load_PvpDifficulty();
    _Load_QuestSort();
    _Load_QuestXP();
    _Load_QuestFactionReward();
    _Load_RandPropPoints();
    _Load_ScalingStatDistribution();
    _Load_ScalingStatValues();
    _Load_SkillLine();
    _Load_SkillLineAbility();
    _Load_SkillRaceClassInfo();
    _Load_SkillTiers();
    _Load_SoundEntries();
    _Load_Spell();
    _Load_SpellCastTimes();
    _Load_SpellCategory();
    _Load_SpellItemEnchantment();
    _Load_SpellDifficulty();
    _Load_SpellDuration();
    _Load_SpellFocusObject();
    _Load_SpellItemEnchantmentCondition();
    _Load_SpellRadius();
    _Load_SpellRange();
    _Load_SpellRuneCost();
    _Load_SpellShapeshiftForm();
    _Load_SpellVisual();
    _Load_StableSlotPrices();
    _Load_SummonProperties();
    _Load_Talent();
    _Load_TalentTab();
    _Load_TaxiNodes();
    _Load_TaxiPath();
    _Load_TaxiPathNode();
    _Load_TeamContributionPoints();
    _Load_TotemCategory();
    _Load_TransportAnimation();
    _Load_TransportRotation();
    _Load_Vehicle();
    _Load_VehicleSeat();
    _Load_WMOAreaTable();
    _Load_WorldMapArea();
    _Load_WorldMapOverlay();
    _Load_WorldSafeLocs();

    // Before we will start handle dbc-data we should to add dbc-corrections from WorldDB dbc-tables : achievement_dbc and spell_dbc and spelldifficulty_dbc
    Initialize_WorldDBC_Corrections();

    // Handle additional data from DBC
    Initialize_Additional_Data();
}

void DBCStoresMgr::Initialize_WorldDBC_Corrections()
{
    TC_LOG_INFO("server.loading", "Initialize DBC corrections (server-side data stores)");
    // here we adding data in exist DBC containers from world tables:
    // achievement_dbc
    _Handle_World_Achievement();
    // spell_dbc
    _Handle_World_Spell();
    // spelldifficulty_dbc
    _Handle_World_SpellDifficulty();
}

void DBCStoresMgr::Initialize_Additional_Data()
{
    TC_LOG_INFO("server.loading", "Initialize Additional Data from DBC");
    // Handle additional data-containers from DBC
    _Handle_NamesProfanityRegex();
    _Handle_NamesReservedRegex();
    _Handle_PetFamilySpellsStore();
    _Handle_TalentSpellPosStore();
    _Handle_TalentTabPages();
    _Handle_TaxiNodesMask();
    _Handle_TaxiPathSetBySource();
    _Handle_TaxiPathNodesByPath();

    //tuple for indexes search
    _Handle_CharacterFacialHairStylesByTripple();
    _Handle_CharSectionsByPenta();
    _Handle_CharStartOutfitByTripple();
    _Handle_EmotesTextSoundByTripple();
    _Handle_LFGDungeonDBCByDouble();
    _Handle_MapDifficultyByDouble();
    _Handle_SkillRaceClassInfo();
    _Handle_WMOAreaInfoByTripple();
}

// load Achievement.dbc
void DBCStoresMgr::_Load_Achievement()
{
    uint32 oldMSTime = getMSTime();

    _achievementMap.clear();
    //                                                0      1         2               3           4                    5                6                7                8                9                10               11             12               13               14               15                16             17            18       19     20        21                22
    QueryResult result = DBCDatabase.Query("SELECT ID, Faction, Instance_Id, Title_Lang_enUS, Title_Lang_enGB, Title_Lang_koKR, Title_Lang_frFR, Title_Lang_deDE, Title_Lang_enCN, Title_Lang_zhCN, Title_Lang_enTW, Title_Lang_zhTW, Title_Lang_esES, Title_Lang_esMX, Title_Lang_ruRU, Title_Lang_ptPT, Title_Lang_ptBR, Title_Lang_itIT, Category, Points, Flags, Minimum_Criteria, Shares_Criteria FROM dbc_achievement");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_achievements. DB table `dbc_achievement` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        AchievementDBC ach;
        ach.ID              = id;
        ach.Faction         = fields[1].GetInt32();
        ach.InstanceID      = fields[2].GetInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
        {
            const char* test = fields[3+i].GetCString();
            std::array<const char*, 16> name;
            std::memcpy(name.data(), test, 16);

            ach.Title[i] = name;
        }

        ach.Category        = fields[18].GetUInt32();
        ach.Points          = fields[19].GetUInt32();
        ach.Flags           = fields[20].GetUInt32();
        ach.MinimumCriteria = fields[21].GetUInt32();
        ach.SharesCriteria  = fields[22].GetUInt32();

        _achievementMap[id] = ach;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_achievements                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Achievement_Criteria.dbc
void DBCStoresMgr::_Load_AchievementCriteria()
{
    uint32 oldMSTime = getMSTime();

    _achievementCriteriaMap.clear();
    //                                                0          1        2         3       4           5           6            7            8                9                10                      11                   12                      13                       14                   15                       16                  17                        18                      19                  20                       21                     22                       23             24         25              26              27
    QueryResult result = DBCDatabase.Query("SELECT ID, Achievement_Id, Type, Asset_Id, Quantity, Start_Event, Start_Asset, Fail_Event, Fail_Asset, Description_Lang_enUS, Description_Lang_enGB, Description_Lang_koKR, Description_Lang_frFR, Description_Lang_deDE, Description_Lang_enCN, Description_Lang_zhCN, Description_Lang_enTW, Description_Lang_zhTW, Description_Lang_esES, Description_Lang_esMX, Description_Lang_ruRU, Description_Lang_ptPT, Description_Lang_ptBR, Description_Lang_itIT,  Flags, Timer_Start_Event, Timer_Asset_Id, Timer_Time FROM dbc_achievement_criteria");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_achievement_criteria. DB table `dbc_achievement_criteria` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        AchievementCriteriaDBC achc;
        achc.ID                  = id;
        achc.AchievementID       = fields[1].GetUInt32();
        achc.Type                = fields[2].GetUInt32();

        achc.Asset.ID            = fields[3].GetUInt32();
        achc.Quantity            = fields[4].GetUInt32();

        achc.AdditionalRequirements[0].Type = fields[5].GetUInt32();
        achc.AdditionalRequirements[0].Asset = fields[6].GetUInt32();
        achc.AdditionalRequirements[1].Type = fields[7].GetUInt32();
        achc.AdditionalRequirements[1].Asset = fields[8].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
        {
            const char* test = fields[9 + i].GetCString();
            std::array<const char*, 16> name;
            std::memcpy(name.data(), test, 16);

            achc.name[i] = name;
        }

        achc.Flags      = fields[24].GetUInt32();
        achc.StartEvent = fields[25].GetUInt32();
        achc.StartAsset = fields[26].GetUInt32();
        achc.StartTimer = fields[27].GetUInt32();

        _achievementCriteriaMap[id] = achc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_achievement_criteria          {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load AreaTable.dbc
void DBCStoresMgr::_Load_AreaTable()
{
    uint32 oldMSTime = getMSTime();

    _areaTableMap.clear();
    //                                             0       1            2           3       4           5                  6                  7                    8                   9                   10                  11                  12                  13                14                   15                16                  17                    18                 19                 20                 21               22              23              24              25
    QueryResult result = DBCDatabase.Query("SELECT ID, ContinentID, ParentAreaID, AreaBit, Flags, ExplorationLevel, AreaName_Lang_enUS, AreaName_Lang_enGB, AreaName_Lang_koKR, AreaName_Lang_frFR, AreaName_Lang_deDE, AreaName_Lang_enCN, AreaName_Lang_zhCN, AreaName_Lang_enTW, AreaName_Lang_zhTW, AreaName_Lang_esES, AreaName_Lang_esMX, AreaName_Lang_ruRU, AreaName_Lang_ptPT, AreaName_Lang_ptBR, AreaName_Lang_itIT, FactionGroupMask, LiquidTypeID_1, LiquidTypeID_2, LiquidTypeID_3, LiquidTypeID_4 FROM dbc_areatable");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_areatable. DB table `dbc_areatable` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        AreaTableDBC at;
        at.ID               = id;
        at.ContinentID      = fields[1].GetUInt32();
        at.ParentAreaID     = fields[2].GetUInt32();
        at.AreaBit          = fields[3].GetUInt32();
        at.Flags            = fields[4].GetUInt32();
        at.ExplorationLevel = fields[5].GetInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            at.AreaName[i] = fields[6 + i].GetString();

        at.FactionGroupMask = fields[21].GetUInt32();
        at.LiquidTypeID[0]  = fields[22].GetUInt32();
        at.LiquidTypeID[1]  = fields[23].GetUInt32();
        at.LiquidTypeID[2]  = fields[24].GetUInt32();
        at.LiquidTypeID[3]  = fields[25].GetUInt32();

        _areaTableMap[id] = at;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_areatable                     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load AreaGroup.dbc
void DBCStoresMgr::_Load_AreaGroup()
{
    uint32 oldMSTime = getMSTime();

    _areaGroupMap.clear();
    //                                                0     1         2         3         4         5         6         7
    QueryResult result = DBCDatabase.Query("SELECT ID, AreaID_1, AreaID_2, AreaID_3, AreaID_4, AreaID_5, AreaID_6, NextAreaID FROM dbc_areagroup");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_areagroup. DB table `dbc_areagroup` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        AreaGroupDBC ag;
        ag.ID = id;

        for (uint8 i = 0; i < MAX_GROUP_AREA_IDS; i++)
            ag.AreaID[i] = fields[1 + i].GetUInt32();

        ag.NextAreaID = fields[7].GetUInt32();
        _areaGroupMap[id] = ag;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_areagroup                     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load AreaPOI.dbc  (NOT USED)
void DBCStoresMgr::_Load_AreaPOI()
{
    uint32 oldMSTime = getMSTime();

    _areaPOIMap.clear();
    //                                                0     1          2        3       4       5      6       7       8        9      10      11       12 13 14      15       16        17
    QueryResult result = DBCDatabase.Query("SELECT ID, Importance, Icon_1, Icon_2, Icon_3, Icon_4, Icon_5, Icon_6, Icon_7, Icon_8, Icon_9, FactionID, X, Y, Z, ContinentID, AreaID, WorldStateID FROM dbc_areapoi");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_areapoi. DB table `dbc_areapoi` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        AreaPOIDBC ap;
        ap.ID         = id;
        ap.Importance = fields[1].GetUInt32();

        for (uint8 i = 0; i < 9; i++)
            ap.Icon[i] = fields[2 + i].GetUInt32();

        ap.FactionID    = fields[11].GetUInt32();
        ap.Pos.X        = fields[12].GetFloat();
        ap.Pos.Y        = fields[13].GetFloat();
        ap.Pos.Z        = fields[14].GetFloat();
        ap.ContinentID  = fields[15].GetUInt32();
        ap.AreaID       = fields[16].GetUInt32();
        ap.WorldStateID = fields[17].GetUInt32();

        _areaPOIMap[id] = ap;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_areapoi                       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load AreaTrigger.dbc
void DBCStoresMgr::_Load_AreaTrigger()
{
    uint32 oldMSTime = getMSTime();

    _areaTriggerMap.clear();
    //                                                0     1       2  3  4     5        6          7          8           9
    QueryResult result = DBCDatabase.Query("SELECT ID, ContinentID, X, Y, Z, Radius, Box_Length, Box_Width, Box_Height, Box_Yaw FROM dbc_areatrigger");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_areatrigger. DB table `dbc_areatrigger` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        AreaTriggerDBC at;
        at.ID          = id;
        at.ContinentID = fields[1].GetUInt32();
        at.Pos.X       = fields[2].GetFloat();
        at.Pos.Y       = fields[3].GetFloat();
        at.Pos.Z       = fields[4].GetFloat();
        at.Radius      = fields[5].GetFloat();
        at.BoxLength   = fields[6].GetFloat();
        at.BoxWidth    = fields[7].GetFloat();
        at.BoxHeight   = fields[8].GetFloat();
        at.BoxYaw      = fields[9].GetFloat();

        _areaTriggerMap[id] = at;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_areatrigger                   {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load AuctionHouse.dbc
void DBCStoresMgr::_Load_AuctionHouse()
{
    uint32 oldMSTime = getMSTime();

    _auctionHouseMap.clear();
    //                                                0     1             2             3
    QueryResult result = DBCDatabase.Query("SELECT ID, FactionID, DepositRate, ConsignmentRate FROM dbc_auctionhouse");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_auctionhouse. DB table `dbc_auctionhouse` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        AuctionHouseDBC ah;
        ah.ID              = id;
        ah.FactionID       = fields[1].GetUInt32();
        ah.DepositRate     = fields[2].GetUInt32();
        ah.ConsignmentRate = fields[3].GetUInt32();

        _auctionHouseMap[id] = ah;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_auctionhouse                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load BankBagSlotPrices.dbc
void DBCStoresMgr::_Load_BankBagSlotPrices()
{
    uint32 oldMSTime = getMSTime();

    _bankBagSlotPricesMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Cost FROM dbc_bankbagslotprices");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_bankbagslotprices. DB table `dbc_bankbagslotprices` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        BankBagSlotPricesDBC bsp;
        bsp.ID   = id;
        bsp.Cost = fields[1].GetUInt32();

        _bankBagSlotPricesMap[id] = bsp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_bankbagslotprices             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load BannedAddOns.dbc
void DBCStoresMgr::_Load_BannedAddOns()
{
    uint32 oldMSTime = getMSTime();

    _bannedAddonsMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_bannedaddons");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_bannedaddons. DB table `dbc_bannedaddons` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        BannedAddOnsDBC ba;
        ba.ID = id;

        _bannedAddonsMap[id] = ba;

        if (_bannedAddonsNumRow)
        {
            if (_bannedAddonsNumRow < id)
                _bannedAddonsNumRow = id;
        }
        else
            _bannedAddonsNumRow = id;

        ++count;
    } while (result->NextRow());

    _bannedAddonsNumRow++; // this _bannedAddonsNumRow should be more then the last by 1 point
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_bannedaddons                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load BarberShopStyle.dbc
void DBCStoresMgr::_Load_BarberShopStyle()
{
    uint32 oldMSTime = getMSTime();

    _barberShopStyleMap.clear();
    //                                                0    1    2     3     4
    QueryResult result = DBCDatabase.Query("SELECT ID, Type, Race, Sex, Data FROM dbc_barbershopstyle");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_barbershopstyle. DB table `dbc_barbershopstyle` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        BarberShopStyleDBC bs;
        bs.ID   = id;
        bs.Type = fields[1].GetUInt32();
        bs.Race = fields[2].GetUInt32();
        bs.Sex  = fields[3].GetUInt32();
        bs.Data = fields[4].GetUInt32();

        _barberShopStyleMap[id] = bs;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_barbershopstyle               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load BattlemasterList.dbc
void DBCStoresMgr::_Load_BattlemasterList()
{
    uint32 oldMSTime = getMSTime();

    _battlemasterListMap.clear();
    //                                                0     1        2        3        4        5        6        7       8             9           10              11              12              13              14              15              16              17              18              19              20            21                22            23               24            25             26
    QueryResult result = DBCDatabase.Query("SELECT ID, MapID_1, MapID_2, MapID_3, MapID_4, MapID_5, MapID_6, MapID_7, MapID_8, InstanceType, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, MaxGroupSize, HolidayWorldState FROM dbc_battlemasterlist");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_battlemasterlist. DB table `dbc_battlemasterlist` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        BattlemasterListDBC bl;
        bl.ID = id;

        for (uint8 i = 0; i < 8; i++)
            bl.MapID[i] = fields[1 + i].GetInt32();

        bl.InstanceType = fields[9].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            bl.Name[i] = fields[10 + i].GetString();

        bl.MaxGroupSize      = fields[25].GetUInt32();
        bl.HolidayWorldState = fields[26].GetUInt32();

        _battlemasterListMap[id] = bl;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_battlemasterlist              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CharacterFacialHairStyles.dbc
void DBCStoresMgr::_Load_CharacterFacialHairStyles()
{
    uint32 oldMSTime = getMSTime();

    _characterFacialHairStyleMap.clear();
    //                                                0    1       2        3
    QueryResult result = DBCDatabase.Query("SELECT ID, RaceID, SexID, VariationID FROM dbc_characterfacialhairstyles");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_characterfacialhairstyles. DB table `dbc_characterfacialhairstyles` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CharacterFacialHairStylesDBC cfhs;
        cfhs.ID          = id;
        cfhs.RaceID      = fields[1].GetUInt8();
        cfhs.SexID       = fields[2].GetUInt8();
        cfhs.VariationID = fields[3].GetUInt8();

        _characterFacialHairStyleMap[id] = cfhs;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_characterfacialhairstyles     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CharSections.dbc
void DBCStoresMgr::_Load_CharSections()
{
    uint32 oldMSTime = getMSTime();

    _charSectionMap.clear();
    //                                                0    1       2         3         4         5             6
    QueryResult result = DBCDatabase.Query("SELECT ID, RaceID, SexID, BaseSection, Flags, VariationIndex, ColorIndex FROM dbc_charsections");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_charsections. DB table `dbc_charsections` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CharSectionsDBC cs;
        cs.ID             = id;
        cs.RaceID         = fields[1].GetUInt8();
        cs.SexID          = fields[2].GetUInt8();
        cs.BaseSection    = fields[3].GetUInt8();
        cs.Flags          = fields[4].GetUInt8();
        cs.VariationIndex = fields[5].GetUInt8();
        cs.ColorIndex     = fields[6].GetUInt8();

        _charSectionMap[id] = cs;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_charsections                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CharStartOutfit.dbc
void DBCStoresMgr::_Load_CharStartOutfit()
{
    uint32 oldMSTime = getMSTime();

    _charStartOutfitMap.clear();
    //                                                0    1        2       3       4         5         6         7         8         9         10        11        12        13        14          15        16          17        18          19         20         21        22          23         24         25        26          27
    QueryResult result = DBCDatabase.Query("SELECT ID, RaceID, ClassID, SexID, ItemID_1, ItemID_2, ItemID_3, ItemID_4, ItemID_5, ItemID_6, ItemID_7, ItemID_8, ItemID_9, ItemID_10, ItemID_11, ItemID_12, ItemID_13, ItemID_14, ItemID_15, ItemID_16, ItemID_17, ItemID_18, ItemID_19, ItemID_20, ItemID_21, ItemID_22, ItemID_23, ItemID_24 FROM dbc_charstartoutfit");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_charstartoutfit. DB table `dbc_charstartoutfit` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CharStartOutfitDBC cso;
        cso.ID      = id;
        cso.RaceID  = fields[1].GetUInt8();
        cso.ClassID = fields[2].GetUInt8();
        cso.SexID   = fields[3].GetUInt8();

        for (uint8 i = 0; i < MAX_OUTFIT_ITEMS; i++)
            cso.ItemID[i] = fields[4 + i].GetInt32();        

        _charStartOutfitMap[id] = cso;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_charstartoutfit               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CharTitles.dbc
void DBCStoresMgr::_Load_CharTitles()
{
    uint32 oldMSTime = getMSTime();

    _charTitlesMap.clear();
    //                                             0        1               2               3               4               5               6               7               8               9               10              11              12                13                14              15              16              17              18                 19            20                21               22              23                 24              25              26              27               28                29               30            31
    QueryResult result = DBCDatabase.Query("SELECT ID, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, Name1_Lang_enUS, Name1_Lang_enGB, Name1_Lang_koKR, Name1_Lang_frFR, Name1_Lang_deDE, Name1_Lang_enCN, Name1_Lang_zhCN, Name1_Lang_enTW, Name1_Lang_zhTW, Name1_Lang_esES, Name1_Lang_esMX, Name1_Lang_ruRU, Name1_Lang_ptPT, Name1_Lang_ptBR, Name1_Lang_itIT, Mask_ID FROM dbc_chartitles");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_chartitles. DB table `dbc_chartitles` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CharTitlesDBC ct;
        ct.ID = id;

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            ct.Name[i] = fields[1 + i].GetString();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            ct.Name1[i] = fields[16 + i].GetString();

        ct.MaskID = fields[31].GetUInt32();

        _charTitlesMap[id] = ct;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_chartitles                    {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ChatChannels.dbc
void DBCStoresMgr::_Load_ChatChannels()
{
    uint32 oldMSTime = getMSTime();

    _chatChannelsMap.clear();
    //                                                0    1             2           3               4               5               6               7               8               9               10             11               12              13             14              15              16
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT FROM dbc_chatchannels");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_chatchannels. DB table `dbc_chatchannels` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ChatChannelsDBC cc;
        cc.ID = id;
        cc.Flags = fields[1].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            cc.Name[i] = fields[2 + i].GetString();

        _chatChannelsMap[id] = cc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_chatchannels                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ChrClasses.dbc
void DBCStoresMgr::_Load_ChrClasses()
{
    uint32 oldMSTime = getMSTime();

    _chrClassesMap.clear();
    //                                                0       1              2               3               4               5               6               7               8               9               10              11              12            13             14              15               16            17              18                   19
    QueryResult result = DBCDatabase.Query("SELECT ID, DisplayPower, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, SpellClassSet, CinematicSequenceID, Required_Expansion FROM dbc_chrclasses");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_chrclasses. DB table `dbc_chrclasses` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ChrClassesDBC cc;
        cc.ID           = id;
        cc.DisplayPower = fields[1].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            cc.Name[i] = fields[2 + i].GetString();

        cc.SpellClassSet       = fields[17].GetUInt32();
        cc.CinematicSequenceID = fields[18].GetUInt32();
        cc.RequiredExpansion   = fields[19].GetUInt32();

        _chrClassesMap[id] = cc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_chrclasses                    {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ChrRaces.dbc
void DBCStoresMgr::_Load_ChrRaces()
{
    uint32 oldMSTime = getMSTime();

    _chrRacesMap.clear();
    //                                                0    1         2          3                4               5            6               7                     8               9            10           11              12              13              14               15              16              17               18              19            20            21               22                23            24               25
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags, FactionID, MaleDisplayId, FemaleDisplayId, BaseLanguage, CreatureType, ResSicknessSpellID, CinematicSequenceID, Alliance, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, Required_Expansion FROM dbc_chrraces");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_chrraces. DB table `dbc_chrraces` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ChrRacesDBC cr;
        cr.ID                  = id;
        cr.Flags               = fields[1].GetUInt32();
        cr.FactionID           = fields[2].GetUInt32();
        cr.MaleDisplayID       = fields[3].GetUInt32();
        cr.FemaleDisplayID     = fields[4].GetUInt32();
        cr.BaseLanguage        = fields[5].GetUInt32();
        cr.CreatureType        = fields[6].GetUInt32();
        cr.ResSicknessSpellID  = fields[7].GetUInt32();
        cr.CinematicSequenceID = fields[8].GetUInt32();
        cr.Alliance            = fields[9].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            cr.Name[i] = fields[10 + i].GetString();

        cr.RequiredExpansion   = fields[25].GetUInt32();

        _chrRacesMap[id] = cr;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_chrraces                      {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CinematicCamera.dbc
void DBCStoresMgr::_Load_CinematicCamera()
{
    uint32 oldMSTime = getMSTime();

    _cinematicCameraMap.clear();
    //                                               0     1       2        3        4         5       6
    QueryResult result = DBCDatabase.Query("SELECT ID, Model, SoundID, OriginX, OriginY, OriginZ, OriginFacing FROM dbc_cinematiccamera");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_cinematiccamera. DB table `dbc_cinematiccamera` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CinematicCameraDBC cc;
        cc.ID           = id;
        cc.Model        = fields[1].GetString();
        cc.SoundID      = fields[2].GetUInt32();
        cc.OriginX      = fields[3].GetFloat();
        cc.OriginY      = fields[4].GetFloat();
        cc.OriginZ      = fields[5].GetFloat();
        cc.OriginFacing = fields[6].GetFloat();

        _cinematicCameraMap[id] = cc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_cinematiccamera               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CinematicSequences.dbc
void DBCStoresMgr::_Load_CinematicSequences()
{
    uint32 oldMSTime = getMSTime();

    _cinematicSequencesMap.clear();
    //                                                0      1        2         3         4         5          6        7         8
    QueryResult result = DBCDatabase.Query("SELECT ID, Camera_1, Camera_2, Camera_3, Camera_4, Camera_5, Camera_6, Camera_7, Camera_8 FROM dbc_cinematicsequences");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_cinematicsequences. DB table `dbc_cinematicsequences` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CinematicSequencesDBC cs;
        cs.ID = id;

        for (uint8 i = 0; i < 8; i++)
            cs.Camera[i] = fields[1 + i].GetUInt32();

        _cinematicSequencesMap[id] = cs;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_cinematicsequences            {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CreatureDisplayInfo.dbc
void DBCStoresMgr::_Load_CreatureDisplayInfo()
{
    uint32 oldMSTime = getMSTime();

    _creatureDisplayInfoMap.clear();
    //                                                0    1                2                     3
    QueryResult result = DBCDatabase.Query("SELECT ID, ModelID, ExtendedDisplayInfoID, CreatureModelScale FROM dbc_creaturedisplayinfo");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_creaturedisplayinfo. DB table `dbc_creaturedisplayinfo` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();        
        CreatureDisplayInfoDBC cdi;
        cdi.ID = id;
        cdi.ModelID               = fields[1].GetUInt32();
        cdi.ExtendedDisplayInfoID = fields[2].GetUInt32();
        cdi.CreatureModelScale    = fields[3].GetFloat();

        _creatureDisplayInfoMap[id] = cdi;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_creaturedisplayinfo           {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CreatureDisplayInfoExtra.dbc
void DBCStoresMgr::_Load_CreatureDisplayInfoExtra()
{
    uint32 oldMSTime = getMSTime();

    _creatureDisplayInfoExtraMap.clear();
    //                                                0       1              2
    QueryResult result = DBCDatabase.Query("SELECT ID, DisplayRaceID, DisplaySexID FROM dbc_creaturedisplayinfoextra");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_creaturedisplayinfoextra. DB table `dbc_creaturedisplayinfoextra` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CreatureDisplayInfoExtraDBC cdie;
        cdie.ID = id;
        cdie.DisplayRaceID = fields[1].GetUInt32();
        cdie.DisplaySexID  = fields[2].GetUInt32();

        _creatureDisplayInfoExtraMap[id] = cdie;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_creaturedisplayinfoextra      {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CreatureFamily.dbc
void DBCStoresMgr::_Load_CreatureFamily()
{
    uint32 oldMSTime = getMSTime();

    _creatureFamilyMap.clear();
    //                                                0       1          2            3            4            5            6            7             8               9               10              11              12              13              14              15              16              17            18              19              20            21              22                23
    QueryResult result = DBCDatabase.Query("SELECT ID, MinScale, MinScaleLevel, MaxScale, MaxScaleLevel, SkillLine_1, SkillLine_2, PetFoodMask, PetTalentType, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT FROM dbc_creaturefamily");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_creaturefamily. DB table `dbc_creaturefamily` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CreatureFamilyDBC cf;
        cf.ID = id;
        cf.MinScale      = fields[1].GetFloat();
        cf.MinScaleLevel = fields[2].GetUInt32();
        cf.MaxScale      = fields[3].GetFloat();
        cf.MaxScaleLevel = fields[4].GetUInt32();
        cf.SkillLine[0]  = fields[5].GetUInt32();
        cf.SkillLine[1]  = fields[6].GetUInt32();
        cf.PetFoodMask   = fields[7].GetUInt32();
        cf.PetTalentType = fields[8].GetInt32();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            cf.Name[i] = fields[9 + i].GetString();

        _creatureFamilyMap[id] = cf;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_creaturefamily                {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CreatureModelData.dbc
void DBCStoresMgr::_Load_CreatureModelData()
{
    uint32 oldMSTime = getMSTime();

    _creatureModelDataMap.clear();
    //                                                0     1       2           3              4              5
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags, ModelName, ModelScale, CollisionHeight, MountHeight FROM dbc_creaturemodeldata");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_creaturemodeldata. DB table `dbc_creaturemodeldata` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CreatureModelDataDBC cmd;
        cmd.ID = id;
        cmd.Flags           = fields[1].GetUInt32();
        cmd.ModelName       = fields[2].GetString();
        cmd.ModelScale      = fields[3].GetFloat();
        cmd.CollisionHeight = fields[4].GetFloat();
        cmd.MountHeight     = fields[5].GetFloat();

        _creatureModelDataMap[id] = cmd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_creaturemodeldata             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CreatureSpellData.dbc
void DBCStoresMgr::_Load_CreatureSpellData()
{
    uint32 oldMSTime = getMSTime();

    _creatureSpellDataMap.clear();
    //                                                0     1         2         3         4
    QueryResult result = DBCDatabase.Query("SELECT ID, Spells_1, Spells_1, Spells_1, Spells_1 FROM dbc_creaturespelldata");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_creaturespelldata. DB table `dbc_creaturespelldata` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CreatureSpellDataDBC csd;
        csd.ID = id;
        for (uint8 i = 0; i < MAX_CREATURE_SPELL_DATA_SLOT; i++)
            csd.Spells[i] = fields[1 + i].GetUInt32();

        _creatureSpellDataMap[id] = csd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_creaturespelldata             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CreatureSpellData.dbc
void DBCStoresMgr::_Load_CreatureType()
{
    uint32 oldMSTime = getMSTime();

    _creatureTypeMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_creaturetype");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_creaturetype. DB table `dbc_creaturetype` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CreatureTypeDBC ct;
        ct.ID = id;

        _creatureTypeMap[id] = ct;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_creaturetype                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CurrencyCategory.dbc (NOT USED)
void DBCStoresMgr::_Load_CurrencyCategory()
{
    uint32 oldMSTime = getMSTime();

    _currencyCategoryMap.clear();
    //                                                0    1           2               3               4               5               6               7               8               9               10          11               12               13             14               15              16
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags,  Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT FROM dbc_currencycategory");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_currencycategory. DB table `dbc_currencycategory` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        CurrencyCategoryDBC cc;
        cc.ID = id;
        cc.Flags = fields[1].GetUInt32();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            cc.Name[i] = fields[2 + i].GetString();

        _currencyCategoryMap[id] = cc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_currencycategory              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load CurrencyTypes.dbc
void DBCStoresMgr::_Load_CurrencyTypes()
{
    uint32 oldMSTime = getMSTime();

    _currencyTypesMap.clear();
    //                                                0    1        2
    QueryResult result = DBCDatabase.Query("SELECT ID, ItemID, BitIndex FROM dbc_currencytypes");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_currencytypes. DB table `dbc_currencytypes` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 itemID = fields[1].GetUInt32();
        CurrencyTypesDBC ct;
        ct.ID       = fields[0].GetUInt32();
        ct.ItemID   = itemID;
        ct.BitIndex = fields[2].GetUInt32();

        _currencyTypesMap[itemID] = ct;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_currencytypes                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load DestructibleModelData.dbc
void DBCStoresMgr::_Load_DestructibleModelData()
{
    uint32 oldMSTime = getMSTime();

    _destructibleModelDataMap.clear();
    //                                                0       1         2           3           4
    QueryResult result = DBCDatabase.Query("SELECT ID, State1Wmo, State2Wmo, State3Wmo, RepairGroundFx FROM dbc_destructiblemodeldata");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_destructiblemodeldata. DB table `dbc_destructiblemodeldata` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        DestructibleModelDataDBC dmd;
        dmd.ID = id;
        dmd.State1Wmo      = fields[1].GetUInt32();
        dmd.State2Wmo      = fields[2].GetUInt32();
        dmd.State3Wmo      = fields[3].GetUInt32();
        dmd.RepairGroundFx = fields[4].GetUInt32();

        _destructibleModelDataMap[id] = dmd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_destructiblemodeldata         {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load DungeonEncounter.dbc
void DBCStoresMgr::_Load_DungeonEncounter()
{
    uint32 oldMSTime = getMSTime();

    _dungeonEncounterMap.clear();
    //                                                0     1       2      3          4               5               6               7               8               9               10               11               12          13               14               15            16              17              18
    QueryResult result = DBCDatabase.Query("SELECT ID, MapID, Difficulty, Bit, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT FROM dbc_dungeonencounter");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_dungeonencounter. DB table `dbc_dungeonencounter` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        DungeonEncounterDBC de;
        de.ID = id;
        de.MapID      = fields[1].GetUInt32();
        de.Difficulty = fields[2].GetUInt32();
        de.Bit        = fields[3].GetUInt32();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            de.Name[i] = fields[4 + i].GetString();

        _dungeonEncounterMap[id] = de;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_dungeonencounter              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load DurabilityCosts.dbc
void DBCStoresMgr::_Load_DurabilityCosts()
{
    uint32 oldMSTime = getMSTime();

    _durabilityCoastsMap.clear();
    //                                                0           1                    2                       3                    4                   5                      6                        7                   8                     9                     10                    11                        12                  13                      14                      15                  16                      17                      18                      19                     20                       21                  22                   23                   24                    25                  26                  27                  28                      29
    QueryResult result = DBCDatabase.Query("SELECT ID, WeaponSubClassCost_1, WeaponSubClassCost_2, WeaponSubClassCost_3, WeaponSubClassCost_4, WeaponSubClassCost_5, WeaponSubClassCost_6, WeaponSubClassCost_7, WeaponSubClassCost_8, WeaponSubClassCost_9, WeaponSubClassCost_10, WeaponSubClassCost_11, WeaponSubClassCost_12, WeaponSubClassCost_13, WeaponSubClassCost_14, WeaponSubClassCost_15, WeaponSubClassCost_16, WeaponSubClassCost_17, WeaponSubClassCost_18, WeaponSubClassCost_19, WeaponSubClassCost_20, WeaponSubClassCost_21, ArmorSubClassCost_1, ArmorSubClassCost_2, ArmorSubClassCost_3, ArmorSubClassCost_4, ArmorSubClassCost_5, ArmorSubClassCost_6, ArmorSubClassCost_7, ArmorSubClassCost_8 FROM dbc_durabilitycosts");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_durabilitycosts. DB table `dbc_durabilitycosts` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        DurabilityCostsDBC dc;
        dc.ID = id;
        for (uint8 i = 0; i < 21; i++)
            dc.WeaponSubClassCost[i] = fields[1 + i].GetUInt32();

        for (uint8 i = 0; i < 8; i++)
            dc.ArmorSubClassCost[i] = fields[22 + i].GetUInt32();

        _durabilityCoastsMap[id] = dc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_durabilitycosts               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load DurabilityQuality.dbc
void DBCStoresMgr::_Load_DurabilityQuality()
{
    uint32 oldMSTime = getMSTime();

    _durabilityQualityMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_durabilityquality");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_durabilityquality. DB table `dbc_durabilityquality` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        DurabilityQualityDBC dq;
        dq.ID = id;
        dq.Data = fields[1].GetFloat();

        _durabilityQualityMap[id] = dq;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_durabilityquality             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Emotes.dbc
void DBCStoresMgr::_Load_Emotes()
{
    uint32 oldMSTime = getMSTime();

    _emotesMap.clear();
    //                                                0      1              2               3
    QueryResult result = DBCDatabase.Query("SELECT ID, EmoteFlags, EmoteSpecProc, EmoteSpecProcParam FROM dbc_emotes");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_emotes. DB table `dbc_emotes` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        EmotesDBC e;
        e.ID = id;
        e.EmoteFlags         = fields[1].GetUInt32();
        e.EmoteSpecProc      = fields[2].GetUInt32();
        e.EmoteSpecProcParam = fields[3].GetUInt32();

        _emotesMap[id] = e;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_emotes                        {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load EmotesText.dbc
void DBCStoresMgr::_Load_EmotesText()
{
    uint32 oldMSTime = getMSTime();

    _emotesTextMap.clear();
    //                                                0      1
    QueryResult result = DBCDatabase.Query("SELECT ID, EmoteID FROM dbc_emotestext");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_emotestext. DB table `dbc_emotestext` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        EmotesTextDBC et;
        et.ID = id;
        et.EmoteID = fields[1].GetUInt32();

        _emotesTextMap[id] = et;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_emotestext                    {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load EmotesTextSound.dbc
void DBCStoresMgr::_Load_EmotesTextSound()
{
    uint32 oldMSTime = getMSTime();

    _emotesTextSoundMap.clear();
    //                                                0      1            2      3       4
    QueryResult result = DBCDatabase.Query("SELECT ID, EmotesTextID, RaceID, SexID, SoundID FROM dbc_emotestextsound");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_emotestextsound. DB table `dbc_emotestextsound` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        EmotesTextSoundDBC ets;
        ets.ID = id;
        ets.EmotesTextID = fields[1].GetUInt32();
        ets.RaceID       = fields[2].GetUInt8();
        ets.SexID        = fields[3].GetUInt8();
        ets.SoundID      = fields[4].GetUInt32();

        _emotesTextSoundMap[id] = ets;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_emotestextsound               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Faction.dbc
void DBCStoresMgr::_Load_Faction()
{
    uint32 oldMSTime = getMSTime();

    _factionMap.clear();
    //                                                0          1                  2                    3                    4                     5                       6                       7                     8                     9                   10                  11                12               13               14                    15                16                17                18                  19                  20                  21               22                  23               24              25             26             27                28               29           30                31            32            33              34             35               36              37
    QueryResult result = DBCDatabase.Query("SELECT ID, ReputationIndex, ReputationRaceMask_1, ReputationRaceMask_2, ReputationRaceMask_3, ReputationRaceMask_4, ReputationClassMask_1, ReputationClassMask_2, ReputationClassMask_3, ReputationClassMask_4, ReputationBase_1, ReputationBase_2, ReputationBase_3, ReputationBase_4, ReputationFlags_1, ReputationFlags_2, ReputationFlags_3, ReputationFlags_4, ParentFactionID, ParentFactionMod_1, ParentFactionMod_2, ParentFactionCap_1, ParentFactionCap_2, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT FROM dbc_faction");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_faction. DB table `dbc_faction` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        FactionDBC f;
        f.ID = id;
        f.ReputationIndex = fields[1].GetInt32();
        for (uint8 i = 0; i < 4; i++)
            f.ReputationRaceMask[i] = fields[2 + i].GetUInt32();
        for (uint8 i = 0; i < 4; i++)
            f.ReputationClassMask[i] = fields[6 + i].GetUInt32();
        for (uint8 i = 0; i < 4; i++)
            f.ReputationBase[i] = fields[10 + i].GetInt32();
        for (uint8 i = 0; i < 4; i++)
            f.ReputationFlags[i] = fields[14 + i].GetUInt32();

        f.ParentFactionID = fields[18].GetInt32();

        for (uint8 i = 0; i < 2; i++)
            f.ParentFactionMod[i] = fields[19 + i].GetFloat();

        for (uint8 i = 0; i < 2; i++)
            f.ParentFactionCap[i] = fields[21 + i].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            f.Name[i] = fields[23 + i].GetString();

        _factionMap[id] = f;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_faction                       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load FactionTemplate.dbc
void DBCStoresMgr::_Load_FactionTemplate()
{
    uint32 oldMSTime = getMSTime();

    _factionTemplateMap.clear();
    //                                                0     1       2         3             4            5          6           7         8         9          10        11        12         13
    QueryResult result = DBCDatabase.Query("SELECT ID, Faction, Flags, FactionGroup, FriendGroup, EnemyGroup, Enemies_1, Enemies_2, Enemies_3, Enemies_4, Friend_1, Friend_2, Friend_3, Friend_4  FROM dbc_factiontemplate");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_factiontemplate. DB table `dbc_factiontemplate` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        FactionTemplateDBC ft;
        ft.ID = id;
        ft.Faction      = fields[1].GetUInt32();
        ft.Flags        = fields[2].GetUInt32();
        ft.FactionGroup = fields[3].GetUInt32();
        ft.FriendGroup  = fields[4].GetUInt32();
        ft.EnemyGroup   = fields[5].GetUInt32();
        for (uint8 i = 0; i < MAX_FACTION_RELATIONS; i++)
            ft.Enemies[i] = fields[6 + i].GetUInt32();
        for (uint8 i = 0; i < MAX_FACTION_RELATIONS; i++)
            ft.Friend[i] = fields[10 + i].GetUInt32();

        _factionTemplateMap[id] = ft;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_factiontemplate               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load GameObjectArtKit.dbc
void DBCStoresMgr::_Load_GameObjectArtKit()
{
    uint32 oldMSTime = getMSTime();

    _gameobjectArtKitMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_gameobjectartkit");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gameobjectartkit. DB table `dbc_gameobjectartkit` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GameObjectArtKitDBC gak;
        gak.ID = id;

        _gameobjectArtKitMap[id] = gak;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gameobjectartkit              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load GameObjectDisplayInfo.dbc
void DBCStoresMgr::_Load_GameObjectDisplayInfo()
{
    uint32 oldMSTime = getMSTime();

    _gameobjectDisplayInfoMap.clear();
    //                                                0     1           2           3           4            5          6            7
    QueryResult result = DBCDatabase.Query("SELECT ID, ModelName, GeoBoxMinX, GeoBoxMinY, GeoBoxMinZ, GeoBoxMaxX, GeoBoxMaxY, GeoBoxMaxZ FROM dbc_gameobjectdisplayinfo");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gameobjectdisplayinfo. DB table `dbc_gameobjectdisplayinfo` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GameObjectDisplayInfoDBC gdi;
        gdi.ID = id;
        gdi.ModelName   = fields[1].GetString();
        gdi.GeoBoxMin.X = fields[2].GetFloat();
        gdi.GeoBoxMin.Y = fields[3].GetFloat();
        gdi.GeoBoxMin.Z = fields[4].GetFloat();
        gdi.GeoBoxMax.X = fields[5].GetFloat();
        gdi.GeoBoxMax.Y = fields[6].GetFloat();
        gdi.GeoBoxMax.Z = fields[7].GetFloat();

        _gameobjectDisplayInfoMap[id] = gdi;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gameobjectdisplayinfo         {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load GemProperties.dbc
void DBCStoresMgr::_Load_GemProperties()
{
    uint32 oldMSTime = getMSTime();

    _gemPropertiesMap.clear();
    //                                                0     1          2
    QueryResult result = DBCDatabase.Query("SELECT ID, Enchant_Id, Type FROM dbc_gemproperties");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gemproperties. DB table `dbc_gemproperties` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GemPropertiesDBC gp;
        gp.ID = id;
        gp.EnchantID = fields[1].GetUInt32();
        gp.Type      = fields[2].GetUInt32();

        _gemPropertiesMap[id] = gp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gemproperties                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load GlyphProperties.dbc
void DBCStoresMgr::_Load_GlyphProperties()
{
    uint32 oldMSTime = getMSTime();

    _glyphPropertiesMap.clear();
    //                                                0     1          2                3
    QueryResult result = DBCDatabase.Query("SELECT ID, SpellID, GlyphSlotFlags, SpellIconID FROM dbc_glyphproperties");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_glyphproperties. DB table `dbc_glyphproperties` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GlyphPropertiesDBC gp;
        gp.ID = id;
        gp.SpellID        = fields[1].GetUInt32();
        gp.GlyphSlotFlags = fields[2].GetUInt32();
        gp.SpellIconID    = fields[3].GetUInt32();

        _glyphPropertiesMap[id] = gp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_glyphproperties               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load GlyphSlot.dbc
void DBCStoresMgr::_Load_GlyphSlot()
{
    uint32 oldMSTime = getMSTime();

    _glyphSlotMap.clear();
    //                                                0     1     2
    QueryResult result = DBCDatabase.Query("SELECT ID, Type, Tooltip FROM dbc_glyphslot");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_glyphslot. DB table `dbc_glyphslot` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GlyphSlotDBC gs;
        gs.ID = id;
        gs.Type    = fields[1].GetUInt32();
        gs.Tooltip = fields[2].GetUInt32();

        _glyphSlotMap[id] = gs;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_glyphslot                     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtBarberShopCostBase.dbc
void DBCStoresMgr::_Load_gtBarberShopCostBase()
{
    uint32 oldMSTime = getMSTime();

    _gtBarberShopCostBaseMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtbarbershopcostbase");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtbarbershopcostbase. DB table `dbc_gtbarbershopcostbase` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtBarberShopCostBaseDBC gtbsc;
        gtbsc.ID = id;
        gtbsc.Data = fields[1].GetFloat();

        _gtBarberShopCostBaseMap[id] = gtbsc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtbarbershopcostbase          {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtCombatRatings.dbc
void DBCStoresMgr::_Load_gtCombatRatings()
{
    uint32 oldMSTime = getMSTime();

    _gtCombatRatingsMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtcombatratings");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtcombatratings. DB table `dbc_gtcombatratings` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtCombatRatingsDBC gtcr;
        gtcr.ID = id;
        gtcr.Data = fields[1].GetFloat();

        _gtCombatRatingsMap[id] = gtcr;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtcombatratings               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtChanceToMeleeCritBase.dbc
void DBCStoresMgr::_Load_gtChanceToMeleeCritBase()
{
    uint32 oldMSTime = getMSTime();

    _gtChanceToMeleeCritBaseMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtchancetomeleecritbase");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtchancetomeleecritbase. DB table `dbc_gtchancetomeleecritbase` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtChanceToMeleeCritBaseDBC gtcmcb;
        gtcmcb.ID = id;
        gtcmcb.Data = fields[1].GetFloat();

        _gtChanceToMeleeCritBaseMap[id] = gtcmcb;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtchancetomeleecritbase       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtChanceToMeleeCrit.dbc
void DBCStoresMgr::_Load_gtChanceToMeleeCrit()
{
    uint32 oldMSTime = getMSTime();

    _gtChanceToMeleeCritMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtchancetomeleecrit");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtchancetomeleecrit. DB table `dbc_gtchancetomeleecrit` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtChanceToMeleeCritDBC gtcmc;
        gtcmc.ID = id;
        gtcmc.Data = fields[1].GetFloat();

        _gtChanceToMeleeCritMap[id] = gtcmc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtchancetomeleecrit           {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtChanceToSpellCritBase.dbc
void DBCStoresMgr::_Load_gtChanceToSpellCritBase()
{
    uint32 oldMSTime = getMSTime();

    _gtChanceToSpellCritBaseMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtchancetospellcritbase");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtchancetospellcritbase. DB table `dbc_gtchancetospellcritbase` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtChanceToSpellCritBaseDBC gtcscb;
        gtcscb.ID = id;
        gtcscb.Data = fields[1].GetFloat();

        _gtChanceToSpellCritBaseMap[id] = gtcscb;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtchancetospellcritbase       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtChanceToSpellCrit.dbc
void DBCStoresMgr::_Load_gtChanceToSpellCrit()
{
    uint32 oldMSTime = getMSTime();

    _gtChanceToSpellCritMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtchancetospellcrit");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtchancetospellcrit. DB table `dbc_gtchancetospellcrit` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtChanceToSpellCritDBC gtcsc;
        gtcsc.ID = id;
        gtcsc.Data = fields[1].GetFloat();

        _gtChanceToSpellCritMap[id] = gtcsc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtchancetospellcrit           {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtNPCManaCostScaler.dbc
void DBCStoresMgr::_Load_gtNPCManaCostScaler()
{
    uint32 oldMSTime = getMSTime();

    _gtNPCManaCostScalerMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtnpcmanacostscaler");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtnpcmanacostscaler. DB table `dbc_gtnpcmanacostscaler` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtNPCManaCostScalerDBC gtnpcMCS;
        gtnpcMCS.ID = id;
        gtnpcMCS.Data = fields[1].GetFloat();

        _gtNPCManaCostScalerMap[id] = gtnpcMCS;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtnpcmanacostscaler           {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtOCTClassCombatRatingScalar.dbc
void DBCStoresMgr::_Load_gtOCTClassCombatRatingScalar()
{
    uint32 oldMSTime = getMSTime();

    _gtOCTClassCombatRatingScalarMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtoctclasscombatratingscalar");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtoctclasscombatratingscalar. DB table `dbc_gtoctclasscombatratingscalar` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtOCTClassCombatRatingScalarDBC gtOCTccrs;
        gtOCTccrs.ID = id;
        gtOCTccrs.Data = fields[1].GetFloat();

        _gtOCTClassCombatRatingScalarMap[id] = gtOCTccrs;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtoctclasscombatratingscalar  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtOCTRegenHP.dbc
void DBCStoresMgr::_Load_gtOCTRegenHP()
{
    uint32 oldMSTime = getMSTime();

    _gtOCTRegenHPMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtoctregenhp");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtoctregenhp. DB table `dbc_gtoctregenhp` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtOCTRegenHPDBC gtOCTrhp;
        gtOCTrhp.ID = id;
        gtOCTrhp.Data = fields[1].GetFloat();

        _gtOCTRegenHPMap[id] = gtOCTrhp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtoctregenhp                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtOCTRegenMP.dbc
void DBCStoresMgr::_Load_gtOCTRegenMP()
{
    uint32 oldMSTime = getMSTime();

    _gtOCTRegenMPMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtoctregenmp");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtoctregenmp. DB table `dbc_gtoctregenmp` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtOCTRegenMPDBC gtOCTrmp;
        gtOCTrmp.ID = id;
        gtOCTrmp.Data = fields[1].GetFloat();

        _gtOCTRegenMPMap[id] = gtOCTrmp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtoctregenmp                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtRegenHPPerSpt.dbc
void DBCStoresMgr::_Load_gtRegenHPPerSpt()
{
    uint32 oldMSTime = getMSTime();

    _gtRegenHPPerSptMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtregenhpperspt");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtregenhpperspt. DB table `dbc_gtregenhpperspt` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtRegenHPPerSptDBC gtrhpps;
        gtrhpps.ID = id;
        gtrhpps.Data = fields[1].GetFloat();

        _gtRegenHPPerSptMap[id] = gtrhpps;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtregenhpperspt               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load gtRegenMPPerSpt.dbc
void DBCStoresMgr::_Load_gtRegenMPPerSpt()
{
    uint32 oldMSTime = getMSTime();

    _gtRegenMPPerSptMap.clear();
    //                                                0   1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_gtregenmpperspt");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_gtregenmpperspt. DB table `dbc_gtregenmpperspt` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        GtRegenMPPerSptDBC gtrmpps;
        gtrmpps.ID = id;
        gtrmpps.Data = fields[1].GetFloat();

        _gtRegenMPPerSptMap[id] = gtrmpps;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_gtregenmpperspt               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Holidays.dbc
void DBCStoresMgr::_Load_Holidays()
{
    uint32 oldMSTime = getMSTime();

    _holidaysMap.clear();
    //                                                0      1           2           3           4           5           6           7           8            9         10         11       12      13      14      15      16      17      18      19      20      21        22        23      24        25      26        27      28        29      30        31      32        33       34       35      36       37       38          39                 40             41              42                  43             44               45              46               47                 48               49            50               51   
    QueryResult result = DBCDatabase.Query("SELECT ID, Duration_1, Duration_2, Duration_3, Duration_4, Duration_5, Duration_6, Duration_7, Duration_8, Duration_9, Duration_10, Date_1, Date_2, Date_3, Date_4, Date_5, Date_6, Date_7, Date_8, Date_9, Date_10, Date_11, Date_12, Date_13, Date_14, Date_15, Date_16, Date_17, Date_18, Date_19, Date_20, Date_21, Date_22, Date_23, Date_24, Date_25, Date_26, Region, Looping, CalendarFlags_1, CalendarFlags_2, CalendarFlags_3, CalendarFlags_4, CalendarFlags_5, CalendarFlags_6, CalendarFlags_7, CalendarFlags_8, CalendarFlags_9, CalendarFlags_10, TextureFilename, Priority, CalendarFilterType FROM dbc_holidays");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_holidays. DB table `dbc_holidays` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        HolidaysDBC h;
        h.ID = id;
        for (uint8 i = 0; i < MAX_HOLIDAY_DURATIONS; i++)
            h.Duration[i] = fields[1 + i].GetUInt32();
        for (uint8 i = 0; i < MAX_HOLIDAY_DATES; i++)
            h.Date[i] = fields[11 + i].GetUInt32();
        h.Region  = fields[37].GetUInt32();
        h.Looping = fields[38].GetUInt32();
        for (uint8 i = 0; i < MAX_HOLIDAY_FLAGS; i++)
            h.CalendarFlags[i] = fields[39 + i].GetUInt32();
        h.TextureFilename    = fields[49].GetString();
        h.Priority           = fields[50].GetUInt32();
        h.CalendarFilterType = fields[51].GetInt32();

        _holidaysMap[id] = h;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_holidays                      {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Item.dbc
void DBCStoresMgr::_Load_Item()
{
    uint32 oldMSTime = getMSTime();

    _itemMap.clear();
    //                                                0      1          2               3                   4            5              6             7
    QueryResult result = DBCDatabase.Query("SELECT ID, ClassID, SubclassID, Sound_Override_Subclassid, Material, DisplayInfoID, InventoryType, SheatheType FROM dbc_item");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_item. DB table `dbc_item` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemDBC i;
        i.ID = id;
        i.ClassID                 = fields[1].GetUInt32();
        i.SubclassID              = fields[2].GetUInt32();
        i.SoundOverrideSubclassID = fields[3].GetInt32();
        i.Material                = fields[4].GetInt32();
        i.DisplayInfoID           = fields[5].GetUInt32();
        i.InventoryType           = fields[6].GetUInt32();
        i.SheatheType             = fields[7].GetUInt32();

        _itemMap[id] = i;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_item                          {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ItemBagFamily.dbc
void DBCStoresMgr::_Load_ItemBagFamily()
{
    uint32 oldMSTime = getMSTime();

    _itemBagFamilyMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_itembagfamily");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_itembagfamily. DB table `dbc_itembagfamily` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemBagFamilyDBC ibf;
        ibf.ID = id;

        _itemBagFamilyMap[id] = ibf;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_itembagfamily                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ItemDisplayInfo.dbc
void DBCStoresMgr::_Load_ItemDisplayInfo()
{
    uint32 oldMSTime = getMSTime();

    _itemDisplayInfoMap.clear();
    //                                                0       1            2              3               4                5               6               7              8             9           10      11                  12              13                  14             15         16        17         18          19         20        21          22         23           24
    QueryResult result = DBCDatabase.Query("SELECT ID, ModelName_1, ModelName_2, ModelTexture_1, ModelTexture_2, InventoryIcon_1, InventoryIcon_2, GeosetGroup_1, GeosetGroup_2, GeosetGroup_3, Flags, SpellVisualID, GroupSoundIndex, HelmetGeosetVis_1, HelmetGeosetVis_2, Texture_1, Texture_2, Texture_3, Texture_4, Texture_5, Texture_6, Texture_7, Texture_8, ItemVisual, ParticleColorID FROM dbc_itemdisplayinfo");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_itemdisplayinfo. DB table `dbc_itemdisplayinfo` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemDisplayInfoDBC idi;
        idi.ID = id;
        for (uint8 i = 0; i < 2; i++)
            idi.ModelName[i] = fields[1 + i].GetString();
        for (uint8 i = 0; i < 2; i++)
            idi.ModelTexture[i] = fields[3 + i].GetString();
        for (uint8 i = 0; i < 2; i++)
            idi.InventoryIcon[i] = fields[5 + i].GetString();
        for (uint8 i = 0; i < 3; i++)
            idi.GeosetGroup[i] = fields[7 + i].GetUInt32();

        idi.Flags           = fields[10].GetUInt32();
        idi.SpellVisualID   = fields[11].GetUInt32();
        idi.GroupSoundIndex = fields[12].GetUInt32();

        for (uint8 i = 0; i < 2; i++)
            idi.HelmetGeosetVisID[i] = fields[13+i].GetUInt32();
        for (uint8 i = 0; i < 8; i++)
            idi.Texture[i] = fields[15 + i].GetString();

        idi.ItemVisual      = fields[23].GetInt32();
        idi.ParticleColorID = fields[24].GetUInt32();

        _itemDisplayInfoMap[id] = idi;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_itemdisplayinfo               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ItemExtendedCost.dbc
void DBCStoresMgr::_Load_ItemExtendedCost()
{
    uint32 oldMSTime = getMSTime();

    _itemExtendedCostMap.clear();
    //                                                0       1            2              3          4        5         6         7         8           9           10           11            12          13                14
    QueryResult result = DBCDatabase.Query("SELECT ID, HonorPoints, ArenaPoints, ArenaBracket, ItemID_1, ItemID_2, ItemID_3, ItemID_4, ItemID_5, ItemCount_1, ItemCount_2, ItemCount_3, ItemCount_4, ItemCount_5, RequiredArenaRating FROM dbc_itemextendedcost");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_itemextendedcost. DB table `dbc_itemextendedcost` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemExtendedCostDBC iec;
        iec.ID = id;
        iec.HonorPoints = fields[1].GetUInt32();
        iec.ArenaPoints = fields[2].GetUInt32();
        iec.ArenaBracket = fields[3].GetUInt32();
        for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; i++)
            iec.ItemID[i] = fields[4 + i].GetUInt32();
        for (uint8 i = 0; i < MAX_ITEM_EXTENDED_COST_REQUIREMENTS; i++)
            iec.ItemCount[i] = fields[9 + i].GetUInt32();
        iec.RequiredArenaRating = fields[14].GetUInt32();

        _itemExtendedCostMap[id] = iec;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_itemextendedcost              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ItemLimitCategory.dbc
void DBCStoresMgr::_Load_ItemLimitCategory()
{
    uint32 oldMSTime = getMSTime();

    _itemLimitCategoryMap.clear();
    //                                                0     1        2
    QueryResult result = DBCDatabase.Query("SELECT ID, Quantity, Flags FROM dbc_itemlimitcategory");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_itemlimitcategory. DB table `dbc_itemlimitcategory` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemLimitCategoryDBC ilc;
        ilc.ID = id;
        ilc.Quantity = fields[1].GetUInt32();
        ilc.Flags    = fields[2].GetUInt32();

        _itemLimitCategoryMap[id] = ilc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_itemlimitcategory             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ItemRandomProperties.dbc
void DBCStoresMgr::_Load_ItemRandomProperties()
{
    uint32 oldMSTime = getMSTime();

    _itemRandomPropertiesMap.clear();
    //                                                0       1              2              3                4              5               6               7               8               9               10              11              12            13              14              15             16               17             18
    QueryResult result = DBCDatabase.Query("SELECT ID, Enchantment_1, Enchantment_2, Enchantment_3, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT FROM dbc_itemrandomproperties");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_itemrandomproperties. DB table `dbc_itemrandomproperties` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemRandomPropertiesDBC irp;
        irp.ID = id;
        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; i++)
            irp.Enchantment[i] = fields[1 + i].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            irp.Name[i] = fields[4 + i].GetString();

        _itemRandomPropertiesMap[id] = irp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_itemrandomproperties          {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ItemRandomSuffix.dbc
void DBCStoresMgr::_Load_ItemRandomSuffix()
{
    uint32 oldMSTime = getMSTime();

    _itemRandomSuffixMap.clear();
    //                                             0          1              2              3                4              5               6               7               8               9                10           11             12              13              14                15               16            17              18              19              20               21
    QueryResult result = DBCDatabase.Query("SELECT ID, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, Enchantment_1, Enchantment_2, Enchantment_3, AllocationPct_1, AllocationPct_2, AllocationPct_3 FROM dbc_itemrandomsuffix");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_itemrandomsuffix. DB table `dbc_itemrandomsuffix` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemRandomSuffixDBC irs;
        irs.ID = id;
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            irs.Name[i] = fields[1 + i].GetString();

        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; i++)
            irs.Enchantment[i] = fields[16 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; i++)
            irs.AllocationPct[i] = fields[19 + i].GetUInt32();

        _itemRandomSuffixMap[id] = irs;

        if (_itemRandomSuffixNumRow)
        {
            if (_itemRandomSuffixNumRow < id)
                _itemRandomSuffixNumRow = id;
        }
        else
            _itemRandomSuffixNumRow = id;

        ++count;
    } while (result->NextRow());

    _itemRandomSuffixNumRow++; // this _itemRandomSuffixTheLastIndex should be more then the last by 1 point

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_itemrandomsuffix              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ItemSet.dbc
void DBCStoresMgr::_Load_ItemSet()
{
    uint32 oldMSTime = getMSTime();

    _itemSetMap.clear();
    //                                             0          1              2              3                4              5               6               7               8               9                10              11              12              13              14             15           16        17        18        19        20        21        22         23        24         25          26           27             28             29            30          31             32           33              34              35              36              37              38               39            40              41              42                 43
    QueryResult result = DBCDatabase.Query("SELECT ID, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, ItemID_1, ItemID_2, ItemID_3, ItemID_4, ItemID_5, ItemID_6, ItemID_7, ItemID_8, ItemID_9, ItemID_10, SetSpellID_1, SetSpellID_2, SetSpellID_3, SetSpellID_4, SetSpellID_5, SetSpellID_6, SetSpellID_7, SetSpellID_8, SetThreshold_1, SetThreshold_2, SetThreshold_3, SetThreshold_4, SetThreshold_5, SetThreshold_6, SetThreshold_7, SetThreshold_8, RequiredSkill, RequiredSkillRank FROM dbc_itemset");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_itemset. DB table `dbc_itemset` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ItemSetDBC is;
        is.ID = id;
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            is.Name[i] = fields[1 + i].GetString();

        for (uint8 i = 0; i < MAX_ITEM_SET_ITEMS; i++)
            is.ItemID[i] = fields[16 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_ITEM_SET_SPELLS; i++)
            is.SetSpellID[i] = fields[26 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_ITEM_SET_SPELLS; i++)
            is.SetThreshold[i] = fields[34 + i].GetUInt32();

        is.RequiredSkill     = fields[42].GetUInt32();
        is.RequiredSkillRank = fields[43].GetUInt32();

        _itemSetMap[id] = is;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_itemset                       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load LFGDungeons.dbc
void DBCStoresMgr::_Load_LFGDungeons()
{
    uint32 oldMSTime = getMSTime();

    _lfgDungeonMap.clear();
    //                                             0          1              2              3                4              5               6               7               8               9              10                11                12             13             14            15            16         17          18              19             20              21      22        23       24        25           26
    QueryResult result = DBCDatabase.Query("SELECT ID, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, MinLevel, MaxLevel, Target_Level, Target_Level_Min, Target_Level_Max, MapID, Difficulty, Flags, TypeID, ExpansionLevel, Group_Id FROM dbc_lfgdungeons");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_lfgdungeons. DB table `dbc_lfgdungeons` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        LFGDungeonDBC ld;
        ld.ID = id;
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            ld.Name[i] = fields[1 + i].GetString();

        ld.MinLevel       = fields[16].GetUInt32();
        ld.MaxLevel       = fields[17].GetUInt32();
        ld.TargetLevel    = fields[18].GetUInt32();
        ld.TargetLevelMin = fields[19].GetUInt32();
        ld.TargetLevelMax = fields[20].GetUInt32();
        ld.MapID          = fields[21].GetInt32();
        ld.Difficulty     = fields[22].GetUInt32();
        ld.Flags          = fields[23].GetUInt32();
        ld.TypeID         = fields[24].GetUInt32();
        ld.ExpansionLevel = fields[25].GetUInt32();
        ld.GroupID        = fields[26].GetUInt32();

        _lfgDungeonMap[id] = ld;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_lfgdungeons                   {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Light.dbc
void DBCStoresMgr::_Load_Light()
{
    uint32 oldMSTime = getMSTime();

    _lightMap.clear();
    //                                                0        1      2  3  4
    QueryResult result = DBCDatabase.Query("SELECT ID, ContinentID, X, Y, Z FROM dbc_light");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_light. DB table `dbc_light` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        LightDBC l;
        l.ID = id;
        l.ContinentID  = fields[1].GetUInt32();
        l.GameCoords.X = fields[2].GetFloat();
        l.GameCoords.Y = fields[3].GetFloat();
        l.GameCoords.Z = fields[4].GetFloat();

        _lightMap[id] = l;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_light                         {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load LiquidType.dbc
void DBCStoresMgr::_Load_LiquidType()
{
    uint32 oldMSTime = getMSTime();

    _liquidTypeMap.clear();
    //                                                0    1      2
    QueryResult result = DBCDatabase.Query("SELECT ID, Type, SpellID FROM dbc_liquidtype");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_liquidtype. DB table `dbc_liquidtype` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        LiquidTypeDBC lt;
        lt.ID = id;
        lt.SoundBank = fields[1].GetUInt32();
        lt.SpellID   = fields[2].GetUInt32();

        _liquidTypeMap[id] = lt;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_liquidtype                    {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Lock.dbc
void DBCStoresMgr::_Load_Lock()
{
    uint32 oldMSTime = getMSTime();

    _lockMap.clear();
    //                                                0    1      2         3        4      5       6       7       8       9       10       11         12      13      14        15        16      17      18       19       20        21      22       23       24
    QueryResult result = DBCDatabase.Query("SELECT ID, Type_1, Type_2, Type_3, Type_4, Type_5, Type_6, Type_7, Type_8, Index_1, Index_2, Index_3, Index_4, Index_5, Index_6, Index_7, Index_8, Skill_1, Skill_2, Skill_3, Skill_4, Skill_5, Skill_6, Skill_7, Skill_8 FROM dbc_lock");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_lock. DB table `dbc_lock` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        LockDBC l;
        l.ID = id;
        for (uint8 i = 0; i < MAX_LOCK_CASE; i++)
            l.Type[i] = fields[1 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_LOCK_CASE; i++)
            l.Index[i] = fields[9 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_LOCK_CASE; i++)
            l.Skill[i] = fields[17 + i].GetUInt32();

        _lockMap[id] = l;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_lock                          {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load MailTemplate.dbc
void DBCStoresMgr::_Load_MailTemplate()
{
    uint32 oldMSTime = getMSTime();

    _mailTemplateMap.clear();
    //                                             0         1               2               3               4               5               6               7               8               9              10               11             12                13               14            15
    QueryResult result = DBCDatabase.Query("SELECT ID, Body_Lang_enUS, Body_Lang_enGB, Body_Lang_koKR, Body_Lang_frFR, Body_Lang_deDE, Body_Lang_enCN, Body_Lang_zhCN, Body_Lang_enTW, Body_Lang_zhTW, Body_Lang_esES, Body_Lang_esMX, Body_Lang_ruRU, Body_Lang_ptPT, Body_Lang_ptBR, Body_Lang_itIT FROM dbc_mailtemplate");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_mailtemplate. DB table `dbc_mailtemplate` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        MailTemplateDBC mt;
        mt.ID = id;
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            mt.Body[i] = fields[1 + i].GetString();

        _mailTemplateMap[id] = mt;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_mailtemplate                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Map.dbc
void DBCStoresMgr::_Load_Map()
{
    uint32 oldMSTime = getMSTime();

    _mapMap.clear();
    //                                             0         1         2            3                  4               5                   6                   7                  8                  9                10                    11                12                13                    14             15                  16                   17             18           19                20       21         22         23           24         25
    QueryResult result = DBCDatabase.Query("SELECT ID, InstanceType, Flags, MapName_Lang_enUS, MapName_Lang_enGB, MapName_Lang_koKR, MapName_Lang_frFR, MapName_Lang_deDE, MapName_Lang_enCN, MapName_Lang_zhCN, MapName_Lang_enTW, MapName_Lang_zhTW, MapName_Lang_esES, MapName_Lang_esMX, MapName_Lang_ruRU, MapName_Lang_ptPT, MapName_Lang_ptBR, MapName_Lang_itIT, AreaTableID, LoadingScreenID, CorpseMapID, CorpseX, CorpseY, ExpansionID, RaidOffset, MaxPlayers FROM dbc_map");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_map. DB table `dbc_map` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        MapDBC m;
        m.ID = id;
        m.InstanceType = fields[1].GetUInt32();
        m.Flags        = fields[2].GetUInt32();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            m.MapName[i] = fields[3 + i].GetString();

        m.AreaTableID     = fields[18].GetUInt32();
        m.LoadingScreenID = fields[19].GetUInt32();
        m.CorpseMapID     = fields[20].GetInt32();
        m.Corpse.X        = fields[21].GetFloat();
        m.Corpse.Y        = fields[22].GetFloat();
        m.ExpansionID     = fields[23].GetUInt32();
        m.RaidOffset      = fields[24].GetUInt32();
        m.MaxPlayers      = fields[25].GetUInt32();

        _mapMap[id] = m;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_map                           {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load MapDifficulty.dbc
void DBCStoresMgr::_Load_MapDifficulty()
{
    uint32 oldMSTime = getMSTime();

    _mapDifficultyMap.clear();
    //                                                0    1        2                3                  4                  5                   6                   7                 8                  9                  10               11              12                    13              14                 15                   16                17             18            19
    QueryResult result = DBCDatabase.Query("SELECT ID, MapID, Difficulty,  Message_Lang_enUS, Message_Lang_enGB, Message_Lang_koKR, Message_Lang_frFR, Message_Lang_deDE, Message_Lang_enCN, Message_Lang_zhCN, Message_Lang_enTW, Message_Lang_zhTW, Message_Lang_esES, Message_Lang_esMX, Message_Lang_ruRU, Message_Lang_ptPT, Message_Lang_ptBR, Message_Lang_itIT, RaidDuration, MaxPlayers FROM dbc_mapdifficulty");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_mapdifficulty. DB table `dbc_mapdifficulty` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        MapDifficultyDBC md;
        md.ID = id;
        md.MapID      = fields[1].GetUInt32();
        md.Difficulty = fields[2].GetUInt32();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            md.Message[i] = fields[3 + i].GetString();

        md.RaidDuration = fields[18].GetUInt32();
        md.MaxPlayers   = fields[19].GetUInt32();

        _mapDifficultyMap[id] = md;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_mapdifficulty                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Movie.dbc
void DBCStoresMgr::_Load_Movie()
{
    uint32 oldMSTime = getMSTime();

    _movieMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_movie");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_movie. DB table `dbc_movie` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        MovieDBC m;
        m.ID = id;

        _movieMap[id] = m;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_movie                         {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load NamesProfanity.dbc
void DBCStoresMgr::_Load_NamesProfanity()
{
    uint32 oldMSTime = getMSTime();

    _namesProfanityMap.clear();
    //                                                0    1       2
    QueryResult result = DBCDatabase.Query("SELECT ID, Name, Language FROM dbc_namesprofanity");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_namesprofanity. DB table `dbc_namesprofanity` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        NamesProfanityDBC np;
        np.ID = id;
        np.Name     = fields[1].GetString();
        np.Language = fields[2].GetInt32();

        _namesProfanityMap[id] = np;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_namesprofanity                {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load NamesReserved.dbc
void DBCStoresMgr::_Load_NamesReserved()
{
    uint32 oldMSTime = getMSTime();

    _namesReservedMap.clear();
    //                                                0    1       2
    QueryResult result = DBCDatabase.Query("SELECT ID, Name, Language FROM dbc_namesreserved");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_namesreserved. DB table `dbc_namesreserved` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        NamesReservedDBC nr;
        nr.ID = id;
        nr.Name = fields[1].GetString();
        nr.Language = fields[2].GetInt32();

        _namesReservedMap[id] = nr;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_namesreserved                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load OverrideSpellData.dbc
void DBCStoresMgr::_Load_OverrideSpellData()
{
    uint32 oldMSTime = getMSTime();

    _overrideSpellDataMap.clear();
    //                                                0     1          2        3         4         5         6         7           8       9         10
    QueryResult result = DBCDatabase.Query("SELECT ID, Spells_1, Spells_2, Spells_3, Spells_4, Spells_5, Spells_6, Spells_7, Spells_8, Spells_9, Spells_10 FROM dbc_overridespelldata");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_overridespelldata. DB table `dbc_overridespelldata` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        OverrideSpellDataDBC osd;
        osd.ID = id;
        for (uint8 i = 0; i < MAX_OVERRIDE_SPELL; i++)
            osd.Spells[i] = fields[1 + i].GetUInt32();

        _overrideSpellDataMap[id] = osd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_overridespelldata             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load PowerDisplay.dbc
void DBCStoresMgr::_Load_PowerDisplay()
{
    uint32 oldMSTime = getMSTime();

    _powerDisplayMap.clear();
    //                                                0     1
    QueryResult result = DBCDatabase.Query("SELECT ID, ActualType FROM dbc_powerdisplay");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_powerdisplay. DB table `dbc_powerdisplay` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        PowerDisplayDBC pd;
        pd.ID = id;
        pd.ActualType = fields[1].GetUInt32();

        _powerDisplayMap[id] = pd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_powerdisplay                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load PvpDifficulty.dbc
void DBCStoresMgr::_Load_PvpDifficulty()
{
    uint32 oldMSTime = getMSTime();

    _pvpDifficultyMap.clear();
    //                                                0     1       2           3         4         5
    QueryResult result = DBCDatabase.Query("SELECT ID, MapID, RangeIndex, MinLevel, MaxLevel, Difficulty FROM dbc_pvpdifficulty");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_pvpdifficulty. DB table `dbc_pvpdifficulty` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        PvPDifficultyDBC pd;
        pd.ID = id;
        pd.MapID      = fields[1].GetUInt32();
        pd.RangeIndex = fields[2].GetUInt32();
        pd.MinLevel   = fields[3].GetUInt32();
        pd.MaxLevel   = fields[4].GetUInt32();
        pd.Difficulty = fields[5].GetUInt32();

        ASSERT(pd.RangeIndex < MAX_BATTLEGROUND_BRACKETS, "PvpDifficulty bracket (%d) exceeded max allowed value (%d)", pd.RangeIndex, MAX_BATTLEGROUND_BRACKETS);

        _pvpDifficultyMap[id] = pd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_pvpdifficulty                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load QuestSort.dbc
void DBCStoresMgr::_Load_QuestSort()
{
    uint32 oldMSTime = getMSTime();

    _questSortMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_questsort");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_questsort. DB table `dbc_questsort` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        QuestSortDBC qs;
        qs.ID = id;

        _questSortMap[id] = qs;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_questsort                     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load QuestXP.dbc
void DBCStoresMgr::_Load_QuestXP()
{
    uint32 oldMSTime = getMSTime();

    _questXPMap.clear();
    //                                                0         1           2              3            4               5           6               7           8              9            10
    QueryResult result = DBCDatabase.Query("SELECT ID, Difficulty_1, Difficulty_2, Difficulty_3, Difficulty_4, Difficulty_5, Difficulty_6, Difficulty_7, Difficulty_8, Difficulty_9, Difficulty_10 FROM dbc_questxp");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_questxp. DB table `dbc_questxp` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        QuestXPDBC qxp;
        qxp.ID = id;
        for (uint8 i = 0; i < 10; i++)
            qxp.Difficulty[i] = fields[1 + i].GetUInt32();

        _questXPMap[id] = qxp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_questxp                       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load QuestFactionReward.dbc
void DBCStoresMgr::_Load_QuestFactionReward()
{
    uint32 oldMSTime = getMSTime();

    _questFactionRewardMap.clear();
    //                                                0         1           2              3            4               5           6               7           8              9            10
    QueryResult result = DBCDatabase.Query("SELECT ID, Difficulty_1, Difficulty_2, Difficulty_3, Difficulty_4, Difficulty_5, Difficulty_6, Difficulty_7, Difficulty_8, Difficulty_9, Difficulty_10 FROM dbc_questfactionreward");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_questfactionreward. DB table `dbc_questfactionreward` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        QuestFactionRewardDBC qfr;
        qfr.ID = id;
        for (uint8 i = 0; i < 10; i++)
            qfr.Difficulty[i] = fields[1 + i].GetInt32();

        _questFactionRewardMap[id] = qfr;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_questfactionreward            {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load RandPropPoints.dbc
void DBCStoresMgr::_Load_RandPropPoints()
{
    uint32 oldMSTime = getMSTime();

    _randPropPointsMap.clear();
    //                                                0     1       2       3       4      5          6          7           8           9          10        11      12      13      14      15
    QueryResult result = DBCDatabase.Query("SELECT ID, Epic_1, Epic_2, Epic_3, Epic_4, Epic_5, Superior_1, Superior_2, Superior_3, Superior_4, Superior_5, Good_1, Good_2, Good_3, Good_4, Good_5 FROM dbc_randproppoints");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_randproppoints. DB table `dbc_randproppoints` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        RandPropPointsDBC rpp;
        rpp.ID = id;
        for (uint8 i = 0; i < 5; i++)
            rpp.Epic[i] = fields[1 + i].GetUInt32();

        for (uint8 i = 0; i < 5; i++)
            rpp.Superior[i] = fields[6 + i].GetUInt32();

        for (uint8 i = 0; i < 5; i++)
            rpp.Good[i] = fields[11 + i].GetUInt32();

        _randPropPointsMap[id] = rpp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_randproppoints                {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ScalingStatDistribution.dbc
void DBCStoresMgr::_Load_ScalingStatDistribution()
{
    uint32 oldMSTime = getMSTime();

    _scalingStatDistributionMap.clear();
    //                                                0     1          2        3          4         5          6       7         8          9         10       11      12         13       14      15      16        17       18       19        20        21
    QueryResult result = DBCDatabase.Query("SELECT ID, StatID_1, StatID_2, StatID_3, StatID_4, StatID_5, StatID_6, StatID_7, StatID_8, StatID_9, StatID_10, Bonus_1, Bonus_2, Bonus_3, Bonus_4, Bonus_5, Bonus_6, Bonus_7, Bonus_8, Bonus_9, Bonus_10, Maxlevel FROM dbc_scalingstatdistribution");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_scalingstatdistribution. DB table `dbc_scalingstatdistribution` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        ScalingStatDistributionDBC ssd;
        ssd.ID = id;
        for (uint8 i = 0; i < 10; i++)
            ssd.StatID[i] = fields[1 + i].GetInt32();

        for (uint8 i = 0; i < 10; i++)
            ssd.Bonus[i] = fields[11 + i].GetUInt32();

        ssd.Maxlevel = fields[21].GetUInt32();

        _scalingStatDistributionMap[id] = ssd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_scalingstatdistribution       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load ScalingStatValues.dbc
void DBCStoresMgr::_Load_ScalingStatValues()
{
    uint32 oldMSTime = getMSTime();

    _scalingStatValuesMap.clear();
    //                                                0      1             2                3           4               5               6                   7                       8                       9           10          11              12                13            14        15        16          17              18              19                 20               21                  22          23
    QueryResult result = DBCDatabase.Query("SELECT ID, Charlevel, ShoulderBudget, TrinketBudget, WeaponBudget1H, RangedBudget, ClothShoulderArmor, LeatherShoulderArmor, MailShoulderArmor, PlateShoulderArmor, WeaponDPS1H, WeaponDPS2H, SpellcasterDPS1H, SpellcasterDPS2H, RangedDPS, WandDPS, SpellPower, PrimaryBudget, TertiaryBudget, ClothCloakArmor, ClothChestArmor, LeatherChestArmor, MailChestArmor, PlateChestArmor FROM dbc_scalingstatvalues");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_scalingstatvalues. DB table `dbc_scalingstatvalues` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        uint32 charlevel = fields[1].GetUInt32();
        ScalingStatValuesDBC ssv;
        ssv.ID        = id;
        ssv.Charlevel = charlevel;
        ssv.ShoulderBudget       = fields[2].GetUInt32();
        ssv.TrinketBudget        = fields[3].GetUInt32();
        ssv.WeaponBudget1H       = fields[4].GetUInt32();
        ssv.RangedBudget         = fields[5].GetUInt32();
        ssv.ClothShoulderArmor   = fields[6].GetUInt32();
        ssv.LeatherShoulderArmor = fields[7].GetUInt32();
        ssv.MailShoulderArmor    = fields[8].GetUInt32();
        ssv.PlateShoulderArmor   = fields[9].GetUInt32();
        ssv.WeaponDPS1H          = fields[10].GetUInt32();
        ssv.WeaponDPS2H          = fields[11].GetUInt32();
        ssv.SpellcasterDPS1H     = fields[12].GetUInt32();
        ssv.SpellcasterDPS2H     = fields[13].GetUInt32();
        ssv.RangedDPS            = fields[14].GetUInt32();
        ssv.WandDPS              = fields[15].GetUInt32();
        ssv.SpellPower           = fields[16].GetUInt32();
        ssv.PrimaryBudget        = fields[17].GetUInt32();
        ssv.TertiaryBudget       = fields[18].GetUInt32();
        ssv.ClothCloakArmor      = fields[19].GetUInt32();
        ssv.ClothChestArmor      = fields[20].GetUInt32();
        ssv.LeatherChestArmor    = fields[21].GetUInt32();
        ssv.MailChestArmor       = fields[22].GetUInt32();
        ssv.PlateChestArmor      = fields[23].GetUInt32();

        _scalingStatValuesMap[charlevel] = ssv;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_scalingstatvalues             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SkillLine.dbc
void DBCStoresMgr::_Load_SkillLine()
{
    uint32 oldMSTime = getMSTime();

    _skillLineMap.clear();
    //                                             0       1                    2                    3                       4                     5                     6                       7                   8                       9                         10                   11                        12               13                          14                  15                      16               17          18
    QueryResult result = DBCDatabase.Query("SELECT ID, CategoryID, DisplayName_Lang_enUS, DisplayName_Lang_enGB, DisplayName_Lang_koKR, DisplayName_Lang_frFR, DisplayName_Lang_deDE, DisplayName_Lang_enCN, DisplayName_Lang_zhCN, DisplayName_Lang_enTW, DisplayName_Lang_zhTW, DisplayName_Lang_esES, DisplayName_Lang_esMX, DisplayName_Lang_ruRU, DisplayName_Lang_ptPT, DisplayName_Lang_ptBR, DisplayName_Lang_itIT,  SpellIconID, CanLink FROM dbc_skillline");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_skillline. DB table `dbc_skillline` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SkillLineDBC sl;
        sl.ID = id;
        sl.CategoryID = fields[1].GetInt32();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            sl.DisplayName[i] = fields[2 + i].GetString();
        sl.SpellIconID = fields[17].GetUInt32();
        sl.CanLink     = fields[18].GetUInt32();        

        _skillLineMap[id] = sl;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_skillline                     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SkillLineAbility.dbc
void DBCStoresMgr::_Load_SkillLineAbility()
{
    uint32 oldMSTime = getMSTime();

    _skillLineAbilityMap.clear();
    //                                                0       1       2       3          4             5                  6                7                   8                       9
    QueryResult result = DBCDatabase.Query("SELECT ID, SkillLine, Spell, RaceMask, ClassMask, MinSkillLineRank, SupercededBySpell, AcquireMethod, TrivialSkillLineRankHigh, TrivialSkillLineRankLow FROM dbc_skilllineability");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_skilllineability. DB table `dbc_skilllineability` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SkillLineAbilityDBC sla;
        sla.ID = id;
        sla.SkillLine                = fields[1].GetUInt32();
        sla.Spell                    = fields[2].GetUInt32();
        sla.RaceMask                 = fields[3].GetUInt32();
        sla.ClassMask                = fields[4].GetUInt32();
        sla.MinSkillLineRank         = fields[5].GetUInt32();
        sla.SupercededBySpell        = fields[6].GetUInt32();
        sla.AcquireMethod            = fields[7].GetUInt32();
        sla.TrivialSkillLineRankHigh = fields[8].GetUInt32();
        sla.TrivialSkillLineRankLow  = fields[9].GetUInt32();

        _skillLineAbilityMap[id] = sla;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_skilllineability              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SkillRaceClassInfo.dbc
void DBCStoresMgr::_Load_SkillRaceClassInfo()
{
    uint32 oldMSTime = getMSTime();

    _skillRaceClassInfoMap.clear();
    //                                                0     1         2          3       4          5
    QueryResult result = DBCDatabase.Query("SELECT ID, SkillID, RaceMask, ClassMask, Flags, SkillTierID FROM dbc_skillraceclassinfo");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_skillraceclassinfo. DB table `dbc_skillraceclassinfo` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SkillRaceClassInfoDBC srci;
        srci.ID = id;
        srci.SkillID     = fields[1].GetUInt32();
        srci.RaceMask    = fields[2].GetUInt32();
        srci.ClassMask   = fields[3].GetUInt32();
        srci.Flags       = fields[4].GetUInt32();
        srci.SkillTierID = fields[5].GetUInt32();

        _skillRaceClassInfoMap[id] = srci;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_skillraceclassinfo            {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SkillTiers.dbc
void DBCStoresMgr::_Load_SkillTiers()
{
    uint32 oldMSTime = getMSTime();

    _skillTiersMap.clear();
    //                                                0     1        2        3        4        5        6        7        8        9       10         11       12         13       14          15       16
    QueryResult result = DBCDatabase.Query("SELECT ID, Value_1, Value_2, Value_3, Value_4, Value_5, Value_6, Value_7, Value_8, Value_9, Value_10, Value_11, Value_12, Value_13, Value_14, Value_15, Value_16 FROM dbc_skilltiers");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_skilltiers. DB table `dbc_skilltiers` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SkillTiersDBC st;
        st.ID = id;
        for (uint8 i = 0; i < MAX_SKILL_STEP; i++)
            st.Value[i] = fields[1 + i].GetUInt32();        

        _skillTiersMap[id] = st;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_skilltiers                    {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SkillTiers.dbc
void DBCStoresMgr::_Load_SoundEntries()
{
    uint32 oldMSTime = getMSTime();

    _soundEntriesMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_soundentries");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_soundentries. DB table `dbc_soundentries` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SoundEntriesDBC se;
        se.ID = id;

        _soundEntriesMap[id] = se;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_soundentries                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Spell.dbc
void DBCStoresMgr::_Load_Spell()
{
    uint32 oldMSTime = getMSTime();

    _spellMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID, "
        "Category, "    // 1
        "DispelType, "  // 2
        "Mechanic, "    // 3
        "Attributes, "  // 4
        "AttributesEx, "// 5
        "AttributesExB, "// 6
        "AttributesExC, "// 7
        "AttributesExD, "// 8
        "AttributesExE, "// 9
        "AttributesExF, "// 10
        "AttributesExG, "// 11
        "ShapeshiftMask_1, "// 12
        "ShapeshiftMask_2, "// 13
        "ShapeshiftExclude_1, "// 14
        "ShapeshiftExclude_2, "// 15
        "Targets, "// 16
        "TargetCreatureType, "// 17
        "RequiresSpellFocus, "// 18
        "FacingCasterFlags, "// 19
        "CasterAuraState, "// 20
        "TargetAuraState, "// 21
        "ExcludeCasterAuraState, "// 22
        "ExcludeTargetAuraState, "// 23
        "CasterAuraSpell, "// 24
        "TargetAuraSpell, "// 25
        "ExcludeCasterAuraSpell, "// 26
        "ExcludeTargetAuraSpell, "// 27
        "CastingTimeIndex, "// 28
        "RecoveryTime, "// 29
        "CategoryRecoveryTime, "// 30
        "InterruptFlags, "// 31
        "AuraInterruptFlags, "// 32
        "ChannelInterruptFlags, "// 33
        "ProcTypeMask, "// 34
        "ProcChance, "// 35
        "ProcCharges, "// 36
        "MaxLevel, "// 37
        "BaseLevel, "// 38
        "SpellLevel, "// 39
        "DurationIndex, "// 40
        "PowerType, "// 41
        "ManaCost, "// 42
        "ManaCostPerLevel, "// 43
        "ManaPerSecond, "// 44
        "ManaPerSecondPerLevel, "// 45
        "RangeIndex, "// 46
        "Speed, "// 47
        //"ModalNextSpell, "// 48
        "CumulativeAura, "// 49                   48
        "Totem_1, "// 50                   49
        "Totem_2, "// 51                   50
        "Reagent_1, "// 52                   51
        "Reagent_2, "// 53                   52
        "Reagent_3, "// 54                   53
        "Reagent_4, "// 55                   54
        "Reagent_5, "// 56                   55
        "Reagent_6, "// 57                   56
        "Reagent_7, "// 58                   57
        "Reagent_8, "// 59                   58
        "ReagentCount_1, "// 60                   59
        "ReagentCount_2, "// 61                   60
        "ReagentCount_3, "// 62                   61
        "ReagentCount_4, "// 63                   62
        "ReagentCount_5, "// 64                   63
        "ReagentCount_6, "// 65                   64
        "ReagentCount_7, "// 66                   65
        "ReagentCount_8, "// 67                   66
        "EquippedItemClass, "// 68                   67
        "EquippedItemSubclass, "// 69                   68
        "EquippedItemInvTypes, "// 70                   69
        "Effect_1, "// 71                   70
        "Effect_2, "// 72                   71
        "Effect_3, "// 73                   72
        "EffectDieSides_1, "// 74                   73
        "EffectDieSides_2, "// 75                   74
        "EffectDieSides_3, "// 76                   75
        "EffectRealPointsPerLevel_1, "// 77                   76
        "EffectRealPointsPerLevel_2, "// 78                   77
        "EffectRealPointsPerLevel_3, "// 79                   78
        "EffectBasePoints_1, "// 80                   79
        "EffectBasePoints_2, "// 81                   80
        "EffectBasePoints_3, "// 82                   81
        "EffectMechanic_1, "// 83                   82
        "EffectMechanic_2, "// 84                   83
        "EffectMechanic_3, "// 85                   84
        "ImplicitTargetA_1, "// 86                   85
        "ImplicitTargetA_2, "// 87                   86
        "ImplicitTargetA_3, "// 88                   87
        "ImplicitTargetB_1, "// 89                   88
        "ImplicitTargetB_2, "// 90                   89
        "ImplicitTargetB_3, "// 91                   90
        "EffectRadiusIndex_1, "// 92                   91
        "EffectRadiusIndex_2, "// 93                   92
        "EffectRadiusIndex_3, "// 94                   93
        "EffectAura_1, "// 95                   94
        "EffectAura_2, "// 96                   95
        "EffectAura_3, "// 97                   96
        "EffectAuraPeriod_1, "// 98                   97
        "EffectAuraPeriod_2, "// 99                   98
        "EffectAuraPeriod_3, "// 100                   99
        "EffectAmplitude_1, "// 101                   100
        "EffectAmplitude_2, "// 102                   101
        "EffectAmplitude_3, "// 103                   102
        "EffectChainTargets_1, "// 104                   103
        "EffectChainTargets_2, "// 105                   104
        "EffectChainTargets_3, "// 106                   105
        "EffectItemType_1, "// 107                   106
        "EffectItemType_2, "// 108                   107
        "EffectItemType_3, "// 109                   108
        "EffectMiscValue_1, "// 110                   109
        "EffectMiscValue_2, "// 111                   110
        "EffectMiscValue_3, "// 112                   111
        "EffectMiscValueB_1, "// 113                   112
        "EffectMiscValueB_2, "// 114                   113
        "EffectMiscValueB_3, "// 115                   114
        "EffectTriggerSpell_1, "// 116                   115
        "EffectTriggerSpell_2, "// 117                   116
        "EffectTriggerSpell_3, "// 118                   117
        "EffectPointsPerCombo_1, "// 119                   118
        "EffectPointsPerCombo_2, "// 120                   119
        "EffectPointsPerCombo_3, "// 121                   120
        "EffectSpellClassMaskA_1, "// 122                   121
        "EffectSpellClassMaskA_2, "// 123                   122
        "EffectSpellClassMaskA_3, "// 124                   123
        "EffectSpellClassMaskB_1, "// 125                   124
        "EffectSpellClassMaskB_2, "// 126                   125
        "EffectSpellClassMaskB_3, "// 127                   126
        "EffectSpellClassMaskC_1, "// 128                   127
        "EffectSpellClassMaskC_2, "// 129                   128
        "EffectSpellClassMaskC_3, "// 130                   129
        "SpellVisualID_1, "// 131                   130
        "SpellVisualID_2, "// 132                   131
        "SpellIconID, "// 133                   132
        "ActiveIconID, "// 134                   133
        "SpellPriority, "// 135                   134
        "Name_Lang_enUS, "// 136                   135
        "Name_Lang_enGB, "// 137
        "Name_Lang_koKR, "// 138                   136
        "Name_Lang_frFR, "// 139                   137
        "Name_Lang_deDE, "// 140                   138
        "Name_Lang_enCN, "// 141
        "Name_Lang_zhCN, "// 142                   139
        "Name_Lang_enTW, "// 143
        "Name_Lang_zhTW, "// 144                   140
        "Name_Lang_esES, "// 145                   141
        "Name_Lang_esMX, "// 146                   142
        "Name_Lang_ruRU, "// 147                   143
        "Name_Lang_ptPT, "// 148
        "Name_Lang_ptBR, "// 149
        "Name_Lang_itIT, "// 150
        //"Name_Lang_Unk, "// 151
        //"Name_Lang_Mask, "// 152
        "NameSubtext_Lang_enUS, "// 153                   144
        "NameSubtext_Lang_enGB, "// 154
        "NameSubtext_Lang_koKR, "// 155                   145
        "NameSubtext_Lang_frFR, "// 156                   146
        "NameSubtext_Lang_deDE, "// 157                   147
        "NameSubtext_Lang_enCN, "// 158
        "NameSubtext_Lang_zhCN, "// 159                   148
        "NameSubtext_Lang_enTW, "// 160
        "NameSubtext_Lang_zhTW, "// 161                   149
        "NameSubtext_Lang_esES, "// 162                   150
        "NameSubtext_Lang_esMX, "// 163                   151
        "NameSubtext_Lang_ruRU, "// 164                   152
        "NameSubtext_Lang_ptPT, "// 165
        "NameSubtext_Lang_ptBR, "// 166
        "NameSubtext_Lang_itIT, "// 167
        //"NameSubtext_Lang_Unk, "// 168
        /*"NameSubtext_Lang_Mask, "// 169
        "Description_Lang_enUS, "// 170
        //"Description_Lang_enGB, "// 171
        "Description_Lang_koKR, "// 172
        "Description_Lang_frFR, "// 173
        "Description_Lang_deDE, "// 174
        //"Description_Lang_enCN, "// 175
        "Description_Lang_zhCN, "// 176
        //"Description_Lang_enTW, "// 177
        "Description_Lang_zhTW, "// 178
        "Description_Lang_esES, "// 179
        "Description_Lang_esMX, "// 180
        "Description_Lang_ruRU, "// 181
        //"Description_Lang_ptPT, "// 182
        //"Description_Lang_ptBR, "// 183
        //"Description_Lang_itIT, "// 184
        //"Description_Lang_Unk, "// 185
        "Description_Lang_Mask, "// 186
        "AuraDescription_Lang_enUS, "// 187
        //"AuraDescription_Lang_enGB, "// 188
        "AuraDescription_Lang_koKR, "// 189
        "AuraDescription_Lang_frFR, "// 190
        "AuraDescription_Lang_deDE, "// 191
        //"AuraDescription_Lang_enCN, "// 192
        "AuraDescription_Lang_zhCN, "// 193
        //"AuraDescription_Lang_enTW, "// 194
        "AuraDescription_Lang_zhTW, "// 195
        "AuraDescription_Lang_esES, "// 196
        "AuraDescription_Lang_esMX, "// 197
        "AuraDescription_Lang_ruRU, "// 198
        //"AuraDescription_Lang_ptPT, "// 199
        //"AuraDescription_Lang_ptBR, "// 200
        //"AuraDescription_Lang_itIT, "// 201
        //"AuraDescription_Lang_Unk, "// 202
        "AuraDescription_Lang_Mask, "// 203*/
        "ManaCostPct, "// 204                   153
        "StartRecoveryCategory, "// 205                   154
        "StartRecoveryTime, "// 206                   155
        "MaxTargetLevel, "// 207                   156
        "SpellClassSet, "// 208                   157
        "SpellClassMask_1, "// 209                   158
        "SpellClassMask_2, "// 210                   159
        "SpellClassMask_3, "// 211                   160
        "MaxTargets, "// 212                   161
        "DefenseType, "// 213                   162
        "PreventionType, "// 214                   163
        //"StanceBarOrder, "// 215
        "EffectChainAmplitude_1, "// 216                   164
        "EffectChainAmplitude_2, "// 217                   165
        "EffectChainAmplitude_3, "// 218                   166
        //"MinFactionID, "// 219
        //"MinReputation, "// 220
        //"RequiredAuraVision, "// 221
        "RequiredTotemCategoryID_1, "// 222                   167
        "RequiredTotemCategoryID_2, "// 223                   168
        "RequiredAreasID, "// 224                   169
        "SchoolMask, "// 225                   170
        "RuneCostID, "// 226                   171
        //"SpellMissileID, "// 227
        //"PowerDisplayID, "// 228
        "EffectBonusCoefficient_1, "// 229                   172
        "EffectBonusCoefficient_2, "// 230                   173
        "EffectBonusCoefficient_3 "// 231                   174
        //"SpellDescriptionVariableID, "// 232
        //"SpellDifficultyID "// 233
        "FROM dbc_spell");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_soundentries. DB table `dbc_soundentries` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellDBC s;
        s.ID = id;
        s.Category      = fields[1].GetUInt32();
        s.DispelType    = fields[2].GetUInt32();
        s.Mechanic      = fields[3].GetUInt32();
        s.Attributes    = fields[4].GetUInt32();
        s.AttributesEx  = fields[5].GetUInt32();
        s.AttributesExB = fields[6].GetUInt32();
        s.AttributesExC = fields[7].GetUInt32();
        s.AttributesExD = fields[8].GetUInt32();
        s.AttributesExE = fields[9].GetUInt32();
        s.AttributesExF = fields[10].GetUInt32();
        s.AttributesExG = fields[11].GetUInt32();
        for (uint8 i = 0; i < 2; i++)
            s.ShapeshiftMask[i] = fields[12 + i].GetUInt32();
        for (uint8 i = 0; i < 2; i++)
            s.ShapeshiftExclude[i] = fields[14 + i].GetUInt32();
        s.Targets = fields[16].GetUInt32();
        s.TargetCreatureType        = fields[17].GetUInt32();
        s.RequiresSpellFocus        = fields[18].GetUInt32();
        s.FacingCasterFlags         = fields[19].GetUInt32();
        s.CasterAuraState           = fields[20].GetUInt32();
        s.TargetAuraState           = fields[21].GetUInt32();
        s.ExcludeCasterAuraState    = fields[22].GetUInt32();
        s.ExcludeTargetAuraState    = fields[23].GetUInt32();
        s.CasterAuraSpell           = fields[24].GetUInt32();
        s.TargetAuraSpell           = fields[25].GetUInt32();
        s.ExcludeCasterAuraSpell    = fields[26].GetUInt32();
        s.ExcludeTargetAuraSpell    = fields[27].GetUInt32();
        s.CastingTimeIndex          = fields[28].GetUInt32();
        s.RecoveryTime              = fields[29].GetUInt32();
        s.CategoryRecoveryTime      = fields[30].GetUInt32();
        s.InterruptFlags            = fields[31].GetUInt32();
        s.AuraInterruptFlags        = fields[32].GetUInt32();
        s.ChannelInterruptFlags     = fields[33].GetUInt32();
        s.ProcTypeMask              = fields[34].GetUInt32();
        s.ProcChance                = fields[35].GetUInt32();
        s.ProcCharges               = fields[36].GetUInt32();
        s.MaxLevel                  = fields[37].GetUInt32();
        s.BaseLevel                 = fields[38].GetUInt32();
        s.SpellLevel                = fields[39].GetUInt32();
        s.DurationIndex             = fields[40].GetUInt32();
        s.PowerType                 = fields[41].GetUInt32();
        s.ManaCost                  = fields[42].GetUInt32();
        s.ManaCostPerLevel          = fields[43].GetUInt32();
        s.ManaPerSecond             = fields[44].GetUInt32();
        s.ManaPerSecondPerLevel     = fields[45].GetUInt32();
        s.RangeIndex                = fields[46].GetUInt32();
        s.Speed                     = fields[47].GetFloat();
        //uint32 ModalNextSpell; (UNUSED)
        s.CumulativeAura            = fields[48].GetUInt32();
        for (uint8 i = 0; i < 2; i++)
            s.Totem[i] = fields[49 + i].GetUInt32();
        for (uint8 i = 0; i < MAX_SPELL_REAGENTS; i++)
            s.Reagent[i] = fields[51 + i].GetInt32();
        for (uint8 i = 0; i < MAX_SPELL_REAGENTS; i++)
            s.ReagentCount[i] = fields[59 + i].GetInt32();

        s.EquippedItemClass    = fields[67].GetInt32();
        s.EquippedItemSubclass = fields[68].GetInt32();
        s.EquippedItemInvTypes = fields[69].GetInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.Effect[i] = fields[70 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectDieSides[i] = fields[73 + i].GetInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectRealPointsPerLevel[i] = fields[76 + i].GetFloat();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectBasePoints[i] = fields[79 + i].GetInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectMechanic[i] = fields[82 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectImplicitTargetA[i] = fields[85 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectImplicitTargetB[i] = fields[88 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectRadiusIndex[i] = fields[91 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectAura[i] = fields[94 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectAuraPeriod[i] = fields[97 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectAmplitude[i] = fields[100 + i].GetFloat();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectChainTargets[i] = fields[103 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectItemType[i] = fields[106 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectMiscValue[i] = fields[109 + i].GetInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectMiscValueB[i] = fields[112 + i].GetInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectTriggerSpell[i] = fields[115 + i].GetUInt32();

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectPointsPerCombo[i] = fields[118 + i].GetFloat();

        // TODO: check this
        // variant 1 : flag = [A1, B1, C1], [A2,B2,C2]...
        // variant 2 : flag = [A1, A2, A3], [B1,B2,B3]...
        // var1:
        //for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
        //    s.EffectSpellClassMask[i].Set(fields[121 + i].GetUInt32(), fields[124 + i].GetUInt32(), fields[127 + i].GetUInt32());
        // var2:
        s.EffectSpellClassMask[0].Set(fields[121].GetUInt32(), fields[122].GetUInt32(), fields[123].GetUInt32());
        s.EffectSpellClassMask[1].Set(fields[124].GetUInt32(), fields[125].GetUInt32(), fields[126].GetUInt32());
        s.EffectSpellClassMask[2].Set(fields[127].GetUInt32(), fields[128].GetUInt32(), fields[129].GetUInt32());

        for (uint8 i = 0; i < 2; i++)
            s.SpellVisualID[i] = fields[130 + i].GetUInt32();

        s.SpellIconID   = fields[132].GetUInt32();
        s.ActiveIconID  = fields[133].GetUInt32();
        s.SpellPriority = fields[134].GetUInt32();

        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            s.Name[i] = fields[135 + i].GetString();

        //uint32 Name_lang_mask; (UNUSED)
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            s.NameSubtext[i] = fields[150 + i].GetString();

        //uint32 NameSubtext_lang_mask; (UNUSED)
        //std::array<char const*, 16> Description; (UNUSED)
        //uint32 Description_lang_mask; (UNUSED)
        //std::array<char const*, 16> AuraDescription; (UNUSED)
        //uint32 AuraDescription_lang_mask; (UNUSED)
        s.ManaCostPct           = fields[165].GetUInt32();
        s.StartRecoveryCategory = fields[166].GetUInt32();
        s.StartRecoveryTime     = fields[167].GetUInt32();
        s.MaxTargetLevel        = fields[168].GetUInt32();
        s.SpellClassSet         = fields[169].GetUInt32();
        s.SpellClassMask.Set(fields[170].GetUInt32(), fields[171].GetUInt32(), fields[172].GetUInt32());
        s.MaxTargets            = fields[173].GetUInt32();
        s.DefenseType           = fields[174].GetUInt32();
        s.PreventionType        = fields[175].GetUInt32();
        //uint32 StanceBarOrder; (UNUSED)
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectChainAmplitude[i] = fields[176 + i].GetFloat();

        //uint32 MinFactionID; (UNUSED)
        //uint32 MinReputation; (UNUSED)
        //uint32 RequiredAuraVision; (UNUSED)
        for (uint8 i = 0; i < 2; i++)
            s.RequiredTotemCategoryID[i] = fields[179].GetUInt32();

        s.RequiredAreasID = fields[181].GetUInt32();
        s.SchoolMask      = fields[182].GetUInt32();
        s.RuneCostID      = fields[183].GetUInt32();
        //uint32 SpellMissileID; (UNUSED)
        //uint32 PowerDisplayID; (UNUSED)
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            s.EffectBonusCoefficient[i] = fields[184 + i].GetFloat();

        //uint32 DescriptionVariablesID; (UNUSED)
        //uint32 Difficulty; (UNUSED)

        _spellMap[id] = s;

        if (!_spellNumRow || _spellNumRow <= id)
            _spellNumRow = id + 1;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spell                         {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellCastTimes.dbc
void DBCStoresMgr::_Load_SpellCastTimes()
{
    uint32 oldMSTime = getMSTime();

    _spellCastTimesMap.clear();
    //                                                0    1
    QueryResult result = DBCDatabase.Query("SELECT ID, Base FROM dbc_spellcasttimes");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellcasttimes. DB table `dbc_spellcasttimes` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellCastTimesDBC sct;
        sct.ID = id;
        sct.Base = fields[1].GetInt32();

        _spellCastTimesMap[id] = sct;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellcasttimes                {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellCategory.dbc
void DBCStoresMgr::_Load_SpellCategory()
{
    uint32 oldMSTime = getMSTime();

    _spellCategoryMap.clear();
    //                                                0    1
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags FROM dbc_spellcategory");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellcategory. DB table `dbc_spellcategory` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellCategoryDBC sc;
        sc.ID = id;
        sc.Flags = fields[1].GetUInt32();

        _spellCategoryMap[id] = sc;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellcategory                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellItemEnchantment.dbc
void DBCStoresMgr::_Load_SpellItemEnchantment()
{
    uint32 oldMSTime = getMSTime();

    _spellItemEnchantmentMap.clear();
    //                                                0    1           2        3           4                   5                   6               7           8              9            10              11              12              13              14              15              16              17              18             19                20              21             22               23          24             25        26        27        28               29                30             31
    QueryResult result = DBCDatabase.Query("SELECT ID, Effect_1, Effect_2, Effect_3, EffectPointsMin_1, EffectPointsMin_2, EffectPointsMin_3, EffectArg_1, EffectArg_2, EffectArg_3, Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT, ItemVisual, Flags, Src_ItemID, Condition_Id, RequiredSkillID, RequiredSkillRank, MinLevel FROM dbc_spellitemenchantment");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellitemenchantment. DB table `dbc_spellitemenchantment` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellItemEnchantmentDBC sie;
        sie.ID = id;
        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; i++)
            sie.Effect[i] = fields[1 + i].GetUInt32();
        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; i++)
            sie.EffectPointsMin[i] = fields[4 + i].GetUInt32();
        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; i++)
            sie.EffectArg[i] = fields[7 + i].GetUInt32();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            sie.Name[i] = fields[10 + i].GetString();

        sie.ItemVisual        = fields[25].GetUInt32();
        sie.Flags             = fields[26].GetUInt32();
        sie.SrcItemID         = fields[27].GetUInt32();
        sie.ConditionID       = fields[28].GetUInt32();
        sie.RequiredSkillID   = fields[29].GetUInt32();
        sie.RequiredSkillRank = fields[30].GetUInt32();
        sie.MinLevel          = fields[31].GetUInt32();

        _spellItemEnchantmentMap[id] = sie;

        if (_spellItemEnchantmentNumRow)
        {
            if (_spellItemEnchantmentNumRow < id)
                _spellItemEnchantmentNumRow = id;
        }
        else
            _spellItemEnchantmentNumRow = id;

        ++count;
    } while (result->NextRow());

    _spellItemEnchantmentNumRow++; // this _spellItemEnchantmentNumRow should be more then the last by 1 point
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellitemenchantment          {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellDifficulty.dbc
void DBCStoresMgr::_Load_SpellDifficulty()
{
    uint32 oldMSTime = getMSTime();

    _spellDiffucultyMap.clear();
    //                                                0           1                     2                   3                   4
    QueryResult result = DBCDatabase.Query("SELECT ID, DifficultySpellID_1, DifficultySpellID_2, DifficultySpellID_3, DifficultySpellID_4 FROM dbc_spelldifficulty");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spelldifficulty. DB table `dbc_spelldifficulty` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellDifficultyDBC sd;
        sd.ID = id;
        for (uint8 i = 0; i < MAX_DIFFICULTY; i++)
            sd.DifficultySpellID[i] = fields[1 + i].GetInt32();

        _spellDiffucultyMap[id] = sd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spelldifficulty               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellDuration.dbc
void DBCStoresMgr::_Load_SpellDuration()
{
    uint32 oldMSTime = getMSTime();

    _spellDurationMap.clear();
    //                                                0      1           2                3
    QueryResult result = DBCDatabase.Query("SELECT ID, Duration, DurationPerLevel, MaxDuration FROM dbc_spellduration");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellduration. DB table `dbc_spellduration` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellDurationDBC sd;
        sd.ID = id;
        sd.Duration         = fields[1].GetInt32();
        sd.DurationPerLevel = fields[2].GetInt32();
        sd.MaxDuration      = fields[3].GetInt32();

        _spellDurationMap[id] = sd;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellduration                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellFocusObject.dbc
void DBCStoresMgr::_Load_SpellFocusObject()
{
    uint32 oldMSTime = getMSTime();

    _spellFocusObjectMap.clear();
    //                                                0
    QueryResult result = DBCDatabase.Query("SELECT ID FROM dbc_spellfocusobject");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellfocusobject. DB table `dbc_spellfocusobject` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellFocusObjectDBC sfo;
        sfo.ID = id;

        _spellFocusObjectMap[id] = sfo;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellfocusobject              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellItemEnchantmentCondition.dbc
void DBCStoresMgr::_Load_SpellItemEnchantmentCondition()
{
    uint32 oldMSTime = getMSTime();

    _spellItemEnchantmentConditionMap.clear();
    //                                                0         1                   2                 3                 4               5
    QueryResult result = DBCDatabase.Query("SELECT ID, Lt_OperandType_1, Lt_OperandType_2, Lt_OperandType_3, Lt_OperandType_4, Lt_OperandType_5, "
    //      6           7           8           9           10
        "Operator_1, Operator_2, Operator_3, Operator_4, Operator_5, "
    //      11                  12                  13                  14              15
        "Rt_OperandType_1, Rt_OperandType_2, Rt_OperandType_3, Rt_OperandType_4, Rt_OperandType_5, "
    //          16          17            18            19          20
        "Rt_Operand_1, Rt_Operand_2, Rt_Operand_3, Rt_Operand_4, Rt_Operand_5 "
        "FROM dbc_spellitemenchantmentcondition");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellitemenchantmentcondition. DB table `dbc_spellitemenchantmentcondition` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellItemEnchantmentConditionDBC siec;
        siec.ID = id;
        for (uint8 i = 0; i < 5; i++)
            siec.LtOperandType[i] = fields[1 + i].GetUInt8();
        for (uint8 i = 0; i < 5; i++)
            siec.Operator[i] = fields[5 + i].GetUInt8();
        for (uint8 i = 0; i < 5; i++)
            siec.RtOperandType[i] = fields[11 + i].GetUInt8();
        for (uint8 i = 0; i < 5; i++)
            siec.RtOperand[i] = fields[16 + i].GetUInt32();

        _spellItemEnchantmentConditionMap[id] = siec;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellitemenchantmentcondition {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellRadius.dbc
void DBCStoresMgr::_Load_SpellRadius()
{
    uint32 oldMSTime = getMSTime();

    _spellRadiusMap.clear();
    //                                                0     1           2            3
    QueryResult result = DBCDatabase.Query("SELECT ID, Radius, RadiusPerLevel, RadiusMax FROM dbc_spellradius");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellradius. DB table `dbc_spellradius` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellRadiusDBC sr;
        sr.ID = id;
        sr.Radius         = fields[1].GetFloat();
        sr.RadiusPerLevel = fields[2].GetFloat();
        sr.RadiusMax      = fields[3].GetFloat();

        _spellRadiusMap[id] = sr;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellradius                   {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellRange.dbc
void DBCStoresMgr::_Load_SpellRange()
{
    uint32 oldMSTime = getMSTime();

    _spellRangeMap.clear();
    //                                                0     1           2            3          4          5
    QueryResult result = DBCDatabase.Query("SELECT ID, RangeMin_1, RangeMin_2, RangeMax_1, RangeMax_2, Flags FROM dbc_spellrange");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellrange. DB table `dbc_spellrange` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellRangeDBC sr;
        sr.ID = id;
        for (uint8 i = 0; i < 2; i++)
            sr.RangeMin[i] = fields[1 + i].GetFloat();
        for (uint8 i = 0; i < 2; i++)
            sr.RangeMax[i] = fields[3 + i].GetFloat();
        sr.Flags = fields[5].GetUInt32();

        _spellRangeMap[id] = sr;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellrange                    {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellRuneCost.dbc
void DBCStoresMgr::_Load_SpellRuneCost()
{
    uint32 oldMSTime = getMSTime();

    _spellRuneCostMap.clear();
    //                                                0     1      2      3         4
    QueryResult result = DBCDatabase.Query("SELECT ID, Blood, Unholy, Frost, RunicPower FROM dbc_spellrunecost");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellrunecost. DB table `dbc_spellrunecost` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellRuneCostDBC src;
        src.ID = id;
        for (uint8 i = 0; i < 3; i++)
            src.RuneCost[i] = fields[1 + i].GetUInt32();
        src.RunicPower = fields[4].GetUInt32();

        _spellRuneCostMap[id] = src;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellrunecost                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellShapeshiftForm.dbc
void DBCStoresMgr::_Load_SpellShapeshiftForm()
{
    uint32 oldMSTime = getMSTime();

    _spellShapeShiftFormMap.clear();
    //                                                0    1         2             3
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags, CreatureType, CombatRoundTime, "
    //          4                   5                       6                   7
        "CreatureDisplayID_1, CreatureDisplayID_2, CreatureDisplayID_3, CreatureDisplayID_4, "
    //          8               9              10                  11              12              13              14              15
        "PresetSpellID_1, PresetSpellID_2, PresetSpellID_3, PresetSpellID_4, PresetSpellID_5, PresetSpellID_6, PresetSpellID_7, PresetSpellID_8 "
        "FROM dbc_spellshapeshiftform");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellshapeshiftform. DB table `dbc_spellshapeshiftform` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellShapeshiftFormDBC ssf;
        ssf.ID = id;
        ssf.Flags = fields[1].GetUInt32();
        ssf.CreatureType = fields[2].GetInt32();
        ssf.CombatRoundTime = fields[3].GetUInt32();
        for (uint8 i = 0; i < 4; i++)
            ssf.CreatureDisplayID[i] = fields[4 + i].GetUInt32();
        for (uint8 i = 0; i < MAX_SHAPESHIFT_SPELLS; i++)
            ssf.PresetSpellID[i] = fields[8 + i].GetUInt32();

        _spellShapeShiftFormMap[id] = ssf;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellshapeshiftform           {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SpellVisual.dbc
void DBCStoresMgr::_Load_SpellVisual()
{
    uint32 oldMSTime = getMSTime();

    _spellVisualMap.clear();
    //                                                0       1           2
    QueryResult result = DBCDatabase.Query("SELECT ID, HasMissile, MissileModel FROM dbc_spellvisual");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_spellvisual. DB table `dbc_spellvisual` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SpellVisualDBC sv;
        sv.ID = id;
        sv.HasMissile   = fields[1].GetUInt32();
        sv.MissileModel = fields[2].GetInt32();

        _spellVisualMap[id] = sv;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_spellvisual                   {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load StableSlotPrices.dbc
void DBCStoresMgr::_Load_StableSlotPrices()
{
    uint32 oldMSTime = getMSTime();

    _stableSlotPricesMap.clear();
    //                                                0    1
    QueryResult result = DBCDatabase.Query("SELECT ID, Cost FROM dbc_stableslotprices");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_stableslotprices. DB table `dbc_stableslotprices` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        StableSlotPricesDBC ssp;
        ssp.ID = id;
        ssp.Cost = fields[1].GetUInt32();

        _stableSlotPricesMap[id] = ssp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_stableslotprices              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load SummonProperties.dbc
void DBCStoresMgr::_Load_SummonProperties()
{
    uint32 oldMSTime = getMSTime();

    _summonPropertiesMap.clear();
    //                                                0    1        2        3      4     5
    QueryResult result = DBCDatabase.Query("SELECT ID, Control, Faction, Title, Slot, Flags FROM dbc_summonproperties");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_summonproperties. DB table `dbc_summonproperties` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        SummonPropertiesDBC sp;
        sp.ID = id;
        sp.Control = fields[1].GetUInt32();
        sp.Faction = fields[2].GetUInt32();
        sp.Title   = fields[3].GetUInt32();
        sp.Slot    = fields[4].GetUInt32();
        sp.Flags   = fields[5].GetUInt32();

        _summonPropertiesMap[id] = sp;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_summonproperties              {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Talent.dbc
void DBCStoresMgr::_Load_Talent()
{
    uint32 oldMSTime = getMSTime();

    _talentMap.clear();
    //                                                0    1        2        3             4           5            6           7           8
    QueryResult result = DBCDatabase.Query("SELECT ID, TabID, TierID, ColumnIndex, SpellRank_1, SpellRank_2, SpellRank_3, SpellRank_4, SpellRank_5, "
    //          9              10
        "PrereqTalent_1, PrereqRank_1 FROM dbc_talent");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_talent. DB table `dbc_talent` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TalentDBC t;
        t.ID = id;
        t.TabID       = fields[1].GetUInt32();
        t.TierID      = fields[2].GetUInt32();
        t.ColumnIndex = fields[3].GetUInt32();
        for (uint8 i = 0; i < MAX_TALENT_RANK; i++)
            t.SpellRank[i] = fields[4 + i].GetUInt32();
        t.PrereqTalent = fields[9].GetUInt32();
        t.PrereqRank   = fields[10].GetUInt32();

        _talentMap[id] = t;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_talent                        {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Talent.dbc
void DBCStoresMgr::_Load_TalentTab()
{
    uint32 oldMSTime = getMSTime();

    _talentTabMap.clear();
    //                                                0    1               2           3
    QueryResult result = DBCDatabase.Query("SELECT ID, ClassMask, PetTalentMask, OrderIndex FROM dbc_talenttab");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_talenttab. DB table `dbc_talenttab` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TalentTabDBC tt;
        tt.ID = id;
        tt.ClassMask     = fields[1].GetUInt32();
        tt.PetTalentMask = fields[2].GetUInt32();
        tt.OrderIndex    = fields[3].GetUInt32();

        _talentTabMap[id] = tt;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_talenttab                     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load TaxiNodes.dbc
void DBCStoresMgr::_Load_TaxiNodes()
{
    uint32 oldMSTime = getMSTime();

    _taxiNodesMap.clear();
    //                                             0     1          2  3  4
    QueryResult result = DBCDatabase.Query("SELECT ID, ContinentID, X, Y, Z, "
    //          5               6               7               8               9               10              11              12          13                14              15              16              17              18              19
        "Name_Lang_enUS, Name_Lang_enGB, Name_Lang_koKR, Name_Lang_frFR, Name_Lang_deDE, Name_Lang_enCN, Name_Lang_zhCN, Name_Lang_enTW, Name_Lang_zhTW, Name_Lang_esES, Name_Lang_esMX, Name_Lang_ruRU, Name_Lang_ptPT, Name_Lang_ptBR, Name_Lang_itIT,"
    //          20                  21
        "MountCreatureID_1, MountCreatureID_2 FROM dbc_taxinodes");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_taxinodes. DB table `dbc_taxinodes` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TaxiNodesDBC tn;
        tn.ID = id;
        tn.ContinentID = fields[1].GetUInt32();
        tn.Pos.X       = fields[2].GetFloat();
        tn.Pos.Y       = fields[3].GetFloat();
        tn.Pos.Z       = fields[4].GetFloat();
        for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            tn.Name[i] = fields[5 + i].GetString();
        for (uint8 i = 0; i < 2; i++)
            tn.MountCreatureID[i] = fields[20 + i].GetUInt32();

        _taxiNodesMap[id] = tn;

        ++count;
    } while (result->NextRow());

    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_taxinodes                     {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load TaxiNodes.dbc
void DBCStoresMgr::_Load_TaxiPath()
{
    uint32 oldMSTime = getMSTime();

    _taxiPathMap.clear();
    //                                                0         1          2         3
    QueryResult result = DBCDatabase.Query("SELECT ID, FromTaxiNode, ToTaxiNode, Cost FROM dbc_taxipath");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_taxipath. DB table `dbc_taxipath` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TaxiPathDBC tp;
        tp.ID = id;
        tp.FromTaxiNode = fields[1].GetUInt32();
        tp.ToTaxiNode   = fields[2].GetUInt32();
        tp.Cost         = fields[3].GetUInt32();

        _taxiPathMap[id] = tp;

        if (_taxiPathNumRow)
        {
            if (_taxiPathNumRow < id)
                _taxiPathNumRow = id;
        }
        else
            _taxiPathNumRow = id;

        ++count;
    } while (result->NextRow());

    _taxiPathNumRow++; // this _taxiPathNumRow should be more then the last by 1 point
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_taxipath                      {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load TaxiPathNode.dbc
void DBCStoresMgr::_Load_TaxiPathNode()
{
    uint32 oldMSTime = getMSTime();

    _taxiPathNodeMap.clear();
    //                                                0     1        2           3          4   5     6      7      8           9               10
    QueryResult result = DBCDatabase.Query("SELECT ID, PathID, NodeIndex, ContinentID, LocX, LocY, LocZ, Flags, Delay, ArrivalEventID, DepartureEventID FROM dbc_taxipathnode");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_taxipathnode. DB table `dbc_taxipathnode` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TaxiPathNodeDBC tp;
        tp.ID = id;
        tp.PathID           = fields[1].GetUInt32();
        tp.NodeIndex        = fields[2].GetUInt32();
        tp.ContinentID      = fields[3].GetUInt32();
        tp.Loc.X            = fields[4].GetFloat();
        tp.Loc.Y            = fields[5].GetFloat();
        tp.Loc.Z            = fields[6].GetFloat();
        tp.Flags            = fields[7].GetUInt32();
        tp.Delay            = fields[8].GetUInt32();
        tp.ArrivalEventID   = fields[9].GetUInt32();
        tp.DepartureEventID = fields[10].GetUInt32();

        _taxiPathNodeMap[id] = tp;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_taxipathnode                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load TeamContributionPoints.dbc
void DBCStoresMgr::_Load_TeamContributionPoints()
{
    uint32 oldMSTime = getMSTime();

    _teamContributionPointsMap.clear();
    //                                                0     1
    QueryResult result = DBCDatabase.Query("SELECT ID, Data FROM dbc_teamcontributionpoints");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_teamcontributionpoints. DB table `dbc_teamcontributionpoints` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TeamContributionPointsDBC tcp;
        tcp.ID = id;
        tcp.Data = fields[1].GetFloat();

        _teamContributionPointsMap[id] = tcp;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_teamcontributionpoints        {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load TotemCategory.dbc
void DBCStoresMgr::_Load_TotemCategory()
{
    uint32 oldMSTime = getMSTime();

    _totemCategoryMap.clear();
    //                                                0          1                  2
    QueryResult result = DBCDatabase.Query("SELECT ID, TotemCategoryType, TotemCategoryMask FROM dbc_totemcategory");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_totemcategory. DB table `dbc_totemcategory` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TotemCategoryDBC tc;
        tc.ID = id;
        tc.TotemCategoryType = fields[1].GetUInt32();
        tc.TotemCategoryMask = fields[2].GetUInt32();

        _totemCategoryMap[id] = tc;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_totemcategory                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load TransportAnimation.dbc
void DBCStoresMgr::_Load_TransportAnimation()
{
    uint32 oldMSTime = getMSTime();

    _transportAnimationMap.clear();
    //                                                0        1           2       3    4     5
    QueryResult result = DBCDatabase.Query("SELECT ID, TransportID, TimeIndex, PosX, PosY, PosZ FROM dbc_transportanimation");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_transportanimation. DB table `dbc_transportanimation` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TransportAnimationDBC ta;
        ta.ID = id;
        ta.TransportID = fields[1].GetUInt32();
        ta.TimeIndex   = fields[2].GetUInt32();
        ta.Pos.X       = fields[3].GetFloat();
        ta.Pos.Y       = fields[4].GetFloat();
        ta.Pos.Z       = fields[5].GetFloat();

        _transportAnimationMap[id] = ta;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_transportanimation            {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load TransportRotation.dbc
void DBCStoresMgr::_Load_TransportRotation()
{
    uint32 oldMSTime = getMSTime();

    _transportRotationMap.clear();
    //                                                0        1            2        3     4     5    6
    QueryResult result = DBCDatabase.Query("SELECT ID, GameObjectsID, TimeIndex, RotX, RotY, RotZ, RotW FROM dbc_transportrotation");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_transportrotation. DB table `dbc_transportrotation` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        TransportRotationDBC tr;
        tr.ID = id;
        tr.GameObjectsID = fields[1].GetUInt32();
        tr.TimeIndex     = fields[2].GetUInt32();
        tr.X             = fields[3].GetFloat();
        tr.Y             = fields[4].GetFloat();
        tr.Z             = fields[5].GetFloat();
        tr.W             = fields[6].GetFloat();

        _transportRotationMap[id] = tr;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_transportrotation             {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load Vehicle.dbc
void DBCStoresMgr::_Load_Vehicle()
{
    uint32 oldMSTime = getMSTime();

    _vehicleMap.clear();
    //                                                0     1       2           3          4        5          6        7         8         9        10        11        12         13
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags, TurnSpeed, PitchSpeed, PitchMin, PitchMax, SeatID_1, SeatID_2, SeatID_3, SeatID_4, SeatID_5, SeatID_6, SeatID_7, SeatID_8, "
    //           14                     15                      16                      17              18                  19
        "MouseLookOffsetPitch, CameraFadeDistScalarMin, CameraFadeDistScalarMax, CameraPitchOffset, FacingLimitRight, FacingLimitLeft, "
    //           20                        21                       22                  23              24                  25                  26                  27                      28
        "MsslTrgtTurnLingering, MsslTrgtPitchLingering, MsslTrgtMouseLingering, MsslTrgtEndOpacity, MsslTrgtArcSpeed, MsslTrgtArcRepeat, MsslTrgtArcWidth, MsslTrgtImpactRadius_1, MsslTrgtImpactRadius_2, "
    //           29                     30                    31                    32                  33                34                    35                      36                 37
        "MsslTrgtArcTexture, MsslTrgtImpactTexture, MsslTrgtImpactModel_1, MsslTrgtImpactModel_2, CameraYawOffset, UilocomotionType, MsslTrgtImpactTexRadius, VehicleUIIndicatorID, PowerDisplayID_1 FROM dbc_vehicle");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_vehicle. DB table `dbc_vehicle` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        VehicleDBC v;
        v.ID = id;
        v.Flags      = fields[1].GetUInt32();
        v.TurnSpeed  = fields[2].GetFloat();
        v.PitchSpeed = fields[3].GetFloat();
        v.PitchMin   = fields[4].GetFloat();
        v.PitchMax   = fields[5].GetFloat();
        for (uint8 i = 0; i < MAX_VEHICLE_SEATS; i++)
            v.SeatID[i] = fields[6 + i].GetUInt32();

        v.MouseLookOffsetPitch    = fields[14].GetFloat();
        v.CameraFadeDistScalarMin = fields[15].GetFloat();
        v.CameraFadeDistScalarMax = fields[16].GetFloat();
        v.CameraPitchOffset       = fields[17].GetFloat();
        v.FacingLimitRight        = fields[18].GetFloat();
        v.FacingLimitLeft         = fields[19].GetFloat();
        v.MsslTrgtTurnLingering   = fields[20].GetFloat();
        v.MsslTrgtPitchLingering  = fields[21].GetFloat();
        v.MsslTrgtMouseLingering  = fields[22].GetFloat();
        v.MsslTrgtEndOpacity      = fields[23].GetFloat();
        v.MsslTrgtArcSpeed        = fields[24].GetFloat();
        v.MsslTrgtArcRepeat       = fields[25].GetFloat();
        v.MsslTrgtArcWidth        = fields[26].GetFloat();
        for (uint8 i = 0; i < 2; i++)
            v.MsslTrgtImpactRadius[i] = fields[27 + i].GetFloat();

        v.MsslTrgtArcTexture    = fields[29].GetCString();
        v.MsslTrgtImpactTexture = fields[30].GetCString();
        for (uint8 i = 0; i < 2; i++)
            v.MsslTrgtImpactModel[i] = fields[31 + i].GetCString();

        v.CameraYawOffset         = fields[33].GetFloat();
        v.UiLocomotionType        = fields[34].GetUInt32();
        v.MsslTrgtImpactTexRadius = fields[35].GetFloat();
        v.VehicleUIIndicatorID    = fields[36].GetUInt32();
        v.PowerDisplayID          = fields[37].GetUInt32();

        _vehicleMap[id] = v;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_vehicle                       {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load VehicleSeat.dbc
void DBCStoresMgr::_Load_VehicleSeat()
{
    uint32 oldMSTime = getMSTime();

    _vehicleSeatMap.clear();
    //                                                0    1        2                   3               4                   5
    QueryResult result = DBCDatabase.Query("SELECT ID, Flags, AttachmentID, AttachmentOffsetX, AttachmentOffsetY, AttachmentOffsetZ, "
    //          6           7              8              9                 10              11                  12                 13           14
        "EnterPreDelay, EnterSpeed, EnterGravity, EnterMinDuration, EnterMaxDuration, EnterMinArcHeight, EnterMaxArcHeight, EnterAnimStart, EnterAnimLoop, "
    //          15            16               17                   18           19            20           21          22                 23               24               25                26           27          28
        "RideAnimStart, RideAnimLoop, RideUpperAnimStart, RideUpperAnimLoop, ExitPreDelay, ExitSpeed, ExitGravity, ExitMinDuration, ExitMaxDuration, ExitMinArcHeight, ExitMaxArcHeight, ExitAnimStart, ExitAnimLoop, ExitAnimEnd, "
    //          29          30              31                  32                  33              34                  35                  36                      37                      38                      39                  40                  41
        "PassengerYaw, PassengerPitch, PassengerRoll, PassengerAttachmentID, VehicleEnterAnim, VehicleExitAnim, VehicleRideAnimLoop, VehicleEnterAnimBone, VehicleExitAnimBone, VehicleRideAnimLoopBone, VehicleEnterAnimDelay, VehicleExitAnimDelay, VehicleAbilityDisplay, "
    //          42             43         44      45
        "EnterUISoundID, ExitUISoundID, UiSkin, FlagsB FROM dbc_vehicleseat");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_vehicleseat. DB table `dbc_vehicleseat` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        VehicleSeatDBC vs;
        vs.ID = id;
        vs.Flags                   = fields[1].GetUInt32();
        vs.AttachmentID            = fields[2].GetInt32();
        vs.AttachmentOffset.X      = fields[3].GetFloat();
        vs.AttachmentOffset.Y      = fields[4].GetFloat();
        vs.AttachmentOffset.Z      = fields[5].GetFloat();
        vs.EnterPreDelay           = fields[6].GetFloat();
        vs.EnterSpeed              = fields[7].GetFloat();
        vs.EnterGravity            = fields[8].GetFloat();
        vs.EnterMinDuration        = fields[9].GetFloat();
        vs.EnterMaxDuration        = fields[10].GetFloat();
        vs.EnterMinArcHeight       = fields[11].GetFloat();
        vs.EnterMaxArcHeight       = fields[12].GetFloat();
        vs.EnterAnimStart          = fields[13].GetInt32();
        vs.EnterAnimLoop           = fields[14].GetInt32();
        vs.RideAnimStart           = fields[15].GetInt32();
        vs.RideAnimLoop            = fields[16].GetInt32();
        vs.RideUpperAnimStart      = fields[17].GetInt32();
        vs.RideUpperAnimLoop       = fields[18].GetInt32();
        vs.ExitPreDelay            = fields[19].GetFloat();
        vs.ExitSpeed               = fields[20].GetFloat();
        vs.ExitGravity             = fields[21].GetFloat();
        vs.ExitMinDuration         = fields[22].GetFloat();
        vs.ExitMaxDuration         = fields[23].GetFloat();
        vs.ExitMinArcHeight        = fields[24].GetFloat();
        vs.ExitMaxArcHeight        = fields[25].GetFloat();
        vs.ExitAnimStart           = fields[26].GetInt32();
        vs.ExitAnimLoop            = fields[27].GetInt32();
        vs.ExitAnimEnd             = fields[28].GetInt32();
        vs.PassengerYaw            = fields[29].GetFloat();
        vs.PassengerPitch          = fields[30].GetFloat();
        vs.PassengerRoll           = fields[31].GetFloat();
        vs.PassengerAttachmentID   = fields[32].GetInt32();
        vs.VehicleEnterAnim        = fields[33].GetInt32();
        vs.VehicleExitAnim         = fields[34].GetInt32();
        vs.VehicleRideAnimLoop     = fields[35].GetInt32();
        vs.VehicleEnterAnimBone    = fields[36].GetInt32();
        vs.VehicleExitAnimBone     = fields[37].GetInt32();
        vs.VehicleRideAnimLoopBone = fields[38].GetInt32();
        vs.VehicleEnterAnimDelay   = fields[39].GetFloat();
        vs.VehicleExitAnimDelay    = fields[40].GetFloat();
        vs.VehicleAbilityDisplay   = fields[41].GetUInt32();
        vs.EnterUISoundID          = fields[42].GetUInt32();
        vs.ExitUISoundID           = fields[43].GetUInt32();
        vs.UiSkin                  = fields[44].GetInt32();
        vs.FlagsB                  = fields[45].GetUInt32();

        _vehicleSeatMap[id] = vs;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_vehicleseat                   {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load WMOAreaTable.dbc
void DBCStoresMgr::_Load_WMOAreaTable()
{
    uint32 oldMSTime = getMSTime();

    _wmoAreaTableMap.clear();
    //                                                0    1        2           3        4         5
    QueryResult result = DBCDatabase.Query("SELECT ID, WMOID, NameSetID, WMOGroupID, Flags, AreaTableID FROM dbc_wmoareatable");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_wmoareatable. DB table `dbc_wmoareatable` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        WMOAreaTableDBC wat;
        wat.ID = id;
        wat.WMOID       = fields[1].GetInt32();
        wat.NameSetID   = fields[2].GetInt32();
        wat.WMOGroupID  = fields[3].GetInt32();
        wat.Flags       = fields[4].GetUInt32();
        wat.AreaTableID = fields[5].GetUInt32();

        _wmoAreaTableMap[id] = wat;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_wmoareatable                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load WMOAreaTable.dbc
void DBCStoresMgr::_Load_WorldMapArea()
{
    uint32 oldMSTime = getMSTime();

    _worldMapAreaMap.clear();
    //                                                0    1      2        3        4         5         6           7
    QueryResult result = DBCDatabase.Query("SELECT ID, MapID, AreaID, LocLeft, LocRight, LocTop, LocBottom, DisplayMapID FROM dbc_worldmaparea");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_worldmaparea. DB table `dbc_worldmaparea` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        WorldMapAreaDBC wma;
        wma.ID = id;
        wma.MapID        = fields[1].GetUInt32();
        uint32 AreaId    = fields[2].GetUInt32();
        wma.AreaID       = AreaId;        
        wma.LocLeft      = fields[3].GetFloat();
        wma.LocRight     = fields[4].GetFloat();
        wma.LocTop       = fields[5].GetFloat();
        wma.LocBottom    = fields[6].GetFloat();
        wma.DisplayMapID = fields[7].GetInt32();        

        _worldMapAreaMap[AreaId] = wma;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_worldmaparea                  {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load WorldMapOverlay.dbc
void DBCStoresMgr::_Load_WorldMapOverlay()
{
    uint32 oldMSTime = getMSTime();

    _worldMapOverlayMap.clear();
    //                                                0     1         2         3         4
    QueryResult result = DBCDatabase.Query("SELECT ID, AreaID_1, AreaID_2, AreaID_3, AreaID_4 FROM dbc_worldmapoverlay");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_worldmapoverlay. DB table `dbc_worldmapoverlay` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        WorldMapOverlayDBC wmo;
        wmo.ID = id;
        for (uint8 i = 0; i < MAX_WORLD_MAP_OVERLAY_AREA_IDX; i++)
            wmo.AreaID[i] = fields[1 + i].GetUInt32();

        _worldMapOverlayMap[id] = wmo;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_worldmapoverlay               {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load WorldSafeLocs.dbc
void DBCStoresMgr::_Load_WorldSafeLocs()
{
    uint32 oldMSTime = getMSTime();

    _worldSafeLocsMap.clear();
    //                                                0     1         2     3     4
    QueryResult result = DBCDatabase.Query("SELECT ID, Continent, LocX, LocY, LocZ FROM dbc_worldsafelocs");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 DBC_worldsafelocs. DB table `dbc_worldsafelocs` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        WorldSafeLocsDBC wsl;
        wsl.ID = id;
        wsl.Continent = fields[1].GetUInt32();
        wsl.Loc.X     = fields[2].GetFloat();
        wsl.Loc.Y     = fields[3].GetFloat();
        wsl.Loc.Z     = fields[4].GetFloat();

        _worldSafeLocsMap[id] = wsl;

        ++count;
    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded DBC_worldsafelocs                 {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// Handle Additional dbc from World db
void DBCStoresMgr::_Handle_World_Achievement()
{
    uint32 oldMSTime = getMSTime();

    //                                                0         1           2       3       4     5         6
    QueryResult result = WorldDatabase.Query("SELECT ID, requiredFaction, mapID, points, flags, count, refAchievement FROM achievement_dbc");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 WorldDB::achievement_dbc. DB table `achievement_dbc` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        if (!GetAchievementDBC(id))
        {
            AchievementDBC ach;
            ach.ID = id;
            ach.Faction = fields[1].GetInt32();
            ach.InstanceID = fields[2].GetInt32();

            /*for (uint8 i = 0; i < TOTAL_LOCALES; i++)
            {
                const char* test = fields[3 + i].GetCString();
                std::array<const char*, 16> name;
                std::memcpy(name.data(), test, 16);

                ach.Title[i] = name;
            }*/

            //ach.Category = fields[12].GetUInt32();
            ach.Points = fields[3].GetUInt32();
            ach.Flags = fields[4].GetUInt32();
            ach.MinimumCriteria = fields[5].GetUInt32();
            ach.SharesCriteria = fields[6].GetUInt32();

            _achievementMap[id] = ach;

            ++count;
        }
        else
            TC_LOG_INFO("server.loading", ">> WorldDB::achievement_dbc          {} already exist, need to override?", id);

    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded WorldDB::achievement_dbc          {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void DBCStoresMgr::_Handle_World_Spell()
{
    uint32 oldMSTime = getMSTime();

    //                                                0
    QueryResult result = WorldDatabase.Query("SELECT ID, "
        "Dispel, "// 1
        "Mechanic, "// 2
        "Attributes, "// 3
        "AttributesEx, "// 4
        "AttributesEx2, "// 5
        "AttributesEx3, "// 6
        "AttributesEx4, "// 7
        "AttributesEx5, "// 8
        "AttributesEx6, "// 9
        "AttributesEx7, "// 10
        "Stances, "// 11
        "StancesNot, "// 12
        "Targets, "// 13
        "CastingTimeIndex, "// 14
        "AuraInterruptFlags, "// 15
        "ProcFlags, "// 16
        "ProcChance, "// 17
        "ProcCharges, "// 18
        "MaxLevel, "// 19
        "BaseLevel, "// 20
        "SpellLevel, "// 21
        "DurationIndex, "// 22
        "RangeIndex, "// 23
        "StackAmount, "// 24
        "EquippedItemClass, "// 25
        "EquippedItemSubClassMask, "// 26
        "EquippedItemInventoryTypeMask, "// 27
        "Effect1, "// 28
        "Effect2, "// 29
        "Effect3, "// 30
        "EffectDieSides1, "// 31
        "EffectDieSides2, "// 32
        "EffectDieSides3, "// 33
        "EffectRealPointsPerLevel1, "// 34
        "EffectRealPointsPerLevel2, "// 35
        "EffectRealPointsPerLevel3, "// 36
        "EffectBasePoints1, "// 37
        "EffectBasePoints2, "// 38
        "EffectBasePoints3, "// 39
        "EffectMechanic1, "// 40
        "EffectMechanic2, "// 41
        "EffectMechanic3, "// 42
        "EffectImplicitTargetA1, "// 43
        "EffectImplicitTargetA2, "// 44
        "EffectImplicitTargetA3, "// 45
        "EffectImplicitTargetB1, "// 46
        "EffectImplicitTargetB2, "// 47
        "EffectImplicitTargetB3, "// 48
        "EffectRadiusIndex1, "// 49
        "EffectRadiusIndex2, "// 50
        "EffectRadiusIndex3, "// 51
        "EffectApplyAuraName1, "// 52
        "EffectApplyAuraName2, "// 53
        "EffectApplyAuraName3, "// 54
        "EffectAmplitude1, "// 55
        "EffectAmplitude2, "// 56
        "EffectAmplitude3, "// 57
        "EffectMultipleValue1, "// 58
        "EffectMultipleValue2, "// 59
        "EffectMultipleValue3, "// 60
        "EffectItemType1, "// 61
        "EffectItemType2, "// 62
        "EffectItemType3, "// 63
        "EffectMiscValue1, "// 64
        "EffectMiscValue2, "// 65
        "EffectMiscValue3, "// 66
        "EffectMiscValueB1, "// 67
        "EffectMiscValueB2, "// 68
        "EffectMiscValueB3, "// 69
        "EffectTriggerSpell1, "// 70
        "EffectTriggerSpell2, "// 71
        "EffectTriggerSpell3, "// 72
        "EffectSpellClassMaskA1, "// 73
        "EffectSpellClassMaskA2, "// 74
        "EffectSpellClassMaskA3, "// 75
        "EffectSpellClassMaskB1, "// 76
        "EffectSpellClassMaskB2, "// 77
        "EffectSpellClassMaskB3, "// 78
        "EffectSpellClassMaskC1, "// 79
        "EffectSpellClassMaskC2, "// 80
        "EffectSpellClassMaskC3, "// 81
        "SpellName, "// 82
        "MaxTargetLevel, "// 83
        "SpellFamilyName, "// 84
        "SpellFamilyFlags1, "// 85
        "SpellFamilyFlags2, "// 86
        "SpellFamilyFlags3, "// 87
        "MaxAffectedTargets, "// 88
        "DmgClass, "// 89
        "PreventionType, "// 90
        "DmgMultiplier1, "// 91
        "DmgMultiplier2, "// 92
        "DmgMultiplier3, "// 93
        "AreaGroupId, "// 94
        "SchoolMask "// 95
        "FROM spell_dbc");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 WorldDB::spell_dbc. DB table `spell_dbc` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        if (!GetSpellDBC(id))
        {
            SpellDBC s;
            s.ID = id;

            // ZERO
            s.Category = 0;

            s.DispelType = fields[1].GetUInt32();
            s.Mechanic = fields[2].GetUInt32();
            s.Attributes = fields[3].GetUInt32();
            s.AttributesEx = fields[4].GetUInt32();
            s.AttributesExB = fields[5].GetUInt32();
            s.AttributesExC = fields[6].GetUInt32();
            s.AttributesExD = fields[7].GetUInt32();
            s.AttributesExE = fields[8].GetUInt32();
            s.AttributesExF = fields[9].GetUInt32();
            s.AttributesExG = fields[10].GetUInt32();

            s.ShapeshiftMask[0] = fields[11].GetUInt32();
            s.ShapeshiftExclude[0] = fields[12].GetUInt32();

            s.Targets = fields[13].GetUInt32();

            // ZERO
            s.TargetCreatureType     = 0;
            s.RequiresSpellFocus     = 0;
            s.FacingCasterFlags      = 0;
            s.CasterAuraState        = 0;
            s.TargetAuraState        = 0;
            s.ExcludeCasterAuraState = 0;
            s.ExcludeTargetAuraState = 0;
            s.CasterAuraSpell        = 0;
            s.TargetAuraSpell        = 0;
            s.ExcludeCasterAuraSpell = 0;
            s.ExcludeTargetAuraSpell = 0;

            s.CastingTimeIndex = fields[14].GetUInt32();

            // ZERO
            s.RecoveryTime         = 0;
            s.CategoryRecoveryTime = 0;
            s.InterruptFlags       = 0;

            s.AuraInterruptFlags = fields[15].GetUInt32();

            // ZERO
            s.ChannelInterruptFlags = 0;

            s.ProcTypeMask = fields[16].GetUInt32();
            s.ProcChance = fields[17].GetUInt32();
            s.ProcCharges = fields[18].GetUInt32();
            s.MaxLevel = fields[19].GetUInt32();
            s.BaseLevel = fields[20].GetUInt32();
            s.SpellLevel = fields[21].GetUInt32();
            s.DurationIndex = fields[22].GetUInt32();

            // ZERO
            s.PowerType             = 0;
            s.ManaCost              = 0;
            s.ManaCostPerLevel      = 0;
            s.ManaPerSecond         = 0;
            s.ManaPerSecondPerLevel = 0;

            s.RangeIndex = fields[23].GetUInt32();

            // ZERO
            s.Speed = 0;

            //uint32 ModalNextSpell; (UNUSED)

            s.CumulativeAura = fields[24].GetUInt32();

            // ZERO
            for (uint8 i = 0; i < 2; i++)
                s.Totem[i] = 0;
            for (uint8 i = 0; i < MAX_SPELL_REAGENTS; i++)
                s.Reagent[i] = 0;
            for (uint8 i = 0; i < MAX_SPELL_REAGENTS; i++)
                s.ReagentCount[i] = 0;

            s.EquippedItemClass = fields[25].GetInt32();
            s.EquippedItemSubclass = fields[26].GetInt32();
            s.EquippedItemInvTypes = fields[27].GetInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.Effect[i] = fields[28 + i].GetUInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectDieSides[i] = fields[31 + i].GetInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectRealPointsPerLevel[i] = fields[34 + i].GetFloat();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectBasePoints[i] = fields[37 + i].GetInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectMechanic[i] = fields[40 + i].GetUInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectImplicitTargetA[i] = fields[43 + i].GetUInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectImplicitTargetB[i] = fields[46 + i].GetUInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectRadiusIndex[i] = fields[49 + i].GetUInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectAura[i] = fields[52 + i].GetUInt32();

            // ZERO
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectAuraPeriod[i] = 0;

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectAmplitude[i] = fields[55 + i].GetFloat();

            // ZERO (where 58-60?)
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectChainTargets[i] = 0;

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectItemType[i] = fields[61 + i].GetUInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectMiscValue[i] = fields[64 + i].GetInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectMiscValueB[i] = fields[67 + i].GetInt32();

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectTriggerSpell[i] = fields[70 + i].GetUInt32();

            // ZERO
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectPointsPerCombo[i] = 0;

            // TODO: check this
            // variant 1 : flag = [A1, B1, C1], [A2,B2,C2]...
            // variant 2 : flag = [A1, A2, A3], [B1,B2,B3]...
            // var1:
            //for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            //    s.EffectSpellClassMask[i].Set(fields[121 + i].GetUInt32(), fields[124 + i].GetUInt32(), fields[127 + i].GetUInt32());
            // var2:
            s.EffectSpellClassMask[0].Set(fields[73].GetUInt32(), fields[74].GetUInt32(), fields[75].GetUInt32());
            s.EffectSpellClassMask[1].Set(fields[76].GetUInt32(), fields[77].GetUInt32(), fields[78].GetUInt32());
            s.EffectSpellClassMask[2].Set(fields[79].GetUInt32(), fields[80].GetUInt32(), fields[81].GetUInt32());

            // ZERO
            for (uint8 i = 0; i < 2; i++)
                s.SpellVisualID[i] = 0;
            s.SpellIconID   = 0;
            s.ActiveIconID  = 0;
            s.SpellPriority = 0;

            for (uint8 i = 0; i < TOTAL_LOCALES; i++)
                s.Name[i] = fields[82].GetString();

            //uint32 Name_lang_mask; (UNUSED)

            // ZERO
            for (uint8 i = 0; i < TOTAL_LOCALES; i++)
                s.NameSubtext[i] = "";

            //uint32 NameSubtext_lang_mask; (UNUSED)
            //std::array<char const*, 16> Description; (UNUSED)
            //uint32 Description_lang_mask; (UNUSED)
            //std::array<char const*, 16> AuraDescription; (UNUSED)
            //uint32 AuraDescription_lang_mask; (UNUSED)

            // ZERO
            s.ManaCostPct           = 0;
            s.StartRecoveryCategory = 0;
            s.StartRecoveryTime     = 0;

            s.MaxTargetLevel = fields[83].GetUInt32();
            s.SpellClassSet = fields[84].GetUInt32();
            s.SpellClassMask.Set(fields[85].GetUInt32(), fields[86].GetUInt32(), fields[87].GetUInt32());
            s.MaxTargets = fields[88].GetUInt32();
            s.DefenseType = fields[89].GetUInt32();
            s.PreventionType = fields[90].GetUInt32();
            //uint32 StanceBarOrder; (UNUSED)
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectChainAmplitude[i] = fields[91 + i].GetFloat();

            //uint32 MinFactionID; (UNUSED)
            //uint32 MinReputation; (UNUSED)
            //uint32 RequiredAuraVision; (UNUSED)

            // ZERO
            for (uint8 i = 0; i < 2; i++)
                s.RequiredTotemCategoryID[i] = 0;

            s.RequiredAreasID = fields[94].GetUInt32();
            s.SchoolMask = fields[95].GetUInt32();

            // ZERO
            s.RuneCostID = 0;
            //uint32 SpellMissileID; (UNUSED)
            //uint32 PowerDisplayID; (UNUSED)

            // ZERO
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                s.EffectBonusCoefficient[i] = 0;

            //uint32 DescriptionVariablesID; (UNUSED)
            //uint32 Difficulty; (UNUSED)

            _spellMap[id] = s;

            if (!_spellNumRow || _spellNumRow <= id)
                _spellNumRow = id + 1;

            ++count;
        }
        else
            TC_LOG_INFO("server.loading", ">> WorldDB::spell_dbc          {} already exist, need to override?", id);

    } while (result->NextRow());    
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded WorldDB::spell_dbc                {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void DBCStoresMgr::_Handle_World_SpellDifficulty()
{
    uint32 oldMSTime = getMSTime();

    //                                                0      1        2         3          4
    QueryResult result = WorldDatabase.Query("SELECT ID, spellid0, spellid1, spellid2, spellid3 FROM spelldifficulty_dbc");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 WorldDB::spelldifficulty_dbc. DB table `spelldifficulty_dbc` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        if (!GetSpellDifficultyDBC(id))
        {
            SpellDifficultyDBC sd;
            sd.ID = id;
            for (uint8 i = 0; i < MAX_DIFFICULTY; i++)
                sd.DifficultySpellID[i] = fields[1 + i].GetInt32();

            _spellDiffucultyMap[id] = sd;

            ++count;
        }
        else
            TC_LOG_INFO("server.loading", ">> WorldDB::spelldifficulty_dbc          {} already exist, need to override?", id);

    } while (result->NextRow());
    //                                       1111111111111111111111111111111111
    TC_LOG_INFO("server.loading", ">> Loaded WorldDB::spelldifficulty_dbc      {} in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// Handle others containers
void DBCStoresMgr::_Handle_NamesProfanityRegex()
{
    // Separate namesprofanity for languages
    for (NamesProfanityDBCMap::const_iterator itr = _namesProfanityMap.begin(); itr != _namesProfanityMap.end(); ++itr)
    {
        ASSERT(itr->second.Language < TOTAL_LOCALES || itr->second.Language == -1);
        std::wstring wname;
        bool conversionResult = Utf8toWStr(itr->second.Name, wname);
        ASSERT(conversionResult);

        if (itr->second.Language != -1)
            NamesProfaneValidators[itr->second.Language].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
        else
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                NamesProfaneValidators[i].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
    }

    // clear this DBC container (UNUSED in life-cycle server)
    _namesProfanityMap.clear();
}

void DBCStoresMgr::_Handle_NamesReservedRegex()
{
    // Separate namesreserved for languages
    for (NamesReservedDBCMap::const_iterator itr = _namesReservedMap.begin(); itr != _namesReservedMap.end(); ++itr)
    {
        ASSERT(itr->second.Language < TOTAL_LOCALES || itr->second.Language == -1);
        std::wstring wname;
        bool conversionResult = Utf8toWStr(itr->second.Name, wname);
        ASSERT(conversionResult);

        if (itr->second.Language != -1)
            NamesReservedValidators[itr->second.Language].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
        else
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                NamesReservedValidators[i].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
    }

    // clear this DBC container (UNUSED in life-cycle server)
    _namesReservedMap.clear();
}

void DBCStoresMgr::_Handle_PetFamilySpellsStore()
{
    for (const auto& skaID : _skillLineAbilityMap)
    {
        if (SkillLineAbilityDBC const* skillLine = &skaID.second)
        {
            SpellDBC const* spellInfo = sDBCStoresMgr->GetSpellDBC(skillLine->Spell);
            if (spellInfo && spellInfo->Attributes & SPELL_ATTR0_PASSIVE)
            {
                for (const auto& indexID : _creatureFamilyMap)
                {
                    if (CreatureFamilyDBC const* cFamily = &indexID.second)
                    {
                        if (skillLine->SkillLine != cFamily->SkillLine[0] && skillLine->SkillLine != cFamily->SkillLine[1])
                            continue;

                        if (spellInfo->SpellLevel)
                            continue;

                        if (skillLine->AcquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                            continue;

                        _petFamilySpellsStore[cFamily->ID].insert(spellInfo->ID);
                    }
                }
            }
        }
    }
}

void DBCStoresMgr::Handle_SpellDifficultyInSpellMgr()
{
    for (const auto& sdID : _spellDiffucultyMap)
    {
        if (SpellDifficultyDBC const* spellDiff = &sdID.second)
        {
            SpellDifficultyDBC newEntry;
            memset(newEntry.DifficultySpellID, 0, 4 * sizeof(uint32));
            for (uint8 x = 0; x < MAX_DIFFICULTY; ++x)
            {
                if (spellDiff->DifficultySpellID[x] <= 0 || !GetSpellDBC(spellDiff->DifficultySpellID[x]))
                {
                    if (spellDiff->DifficultySpellID[x] > 0)//don't show error if spell is <= 0, not all modes have spells and there are unknown negative values
                        TC_LOG_ERROR("sql.sql", "spelldifficulty_dbc: spell {} at field id:{} at spellid{} does not exist in SpellStore (spell.dbc), loaded as 0", spellDiff->DifficultySpellID[x], spellDiff->ID, x);
                    newEntry.DifficultySpellID[x] = 0;//spell was <= 0 or invalid, set to 0
                }
                else
                    newEntry.DifficultySpellID[x] = spellDiff->DifficultySpellID[x];
            }
            if (newEntry.DifficultySpellID[0] <= 0 || newEntry.DifficultySpellID[1] <= 0)//id0-1 must be always set!
                continue;

            for (uint8 x = 0; x < MAX_DIFFICULTY; ++x)
                if (newEntry.DifficultySpellID[x])
                    sSpellMgr->SetSpellDifficultyId(uint32(newEntry.DifficultySpellID[x]), spellDiff->ID);
        }
    }
}

void DBCStoresMgr::_Handle_TalentSpellPosStore()
{
    // create talent spells set
    for (const auto& talentID : _talentMap)
    {
        if (TalentDBC const* talentInfo = &talentID.second)
        {
            TalentTabDBC const* talentTab = GetTalentTabDBC(talentInfo->TabID);
            for (uint8 j = 0; j < MAX_TALENT_RANK; ++j)
            {
                if (talentInfo->SpellRank[j])
                {
                    _talentSpellPos[talentInfo->SpellRank[j]] = TalentSpellPos(talentInfo->ID, j);
                    if (talentTab && talentTab->PetTalentMask)
                        _petTalentSpells.insert(talentInfo->SpellRank[j]);
                }
            }
        }
    }
}

void DBCStoresMgr::_Handle_TalentTabPages()
{
    // prepare fast data access to bit pos of talent ranks for use at inspecting
    // now have all max ranks (and then bit amount used for store talent ranks in inspect)
    for (const auto& ttabID : _talentTabMap)
    {
        if (TalentTabDBC const* talentTabInfo = &ttabID.second)
        {
            // prevent memory corruption; otherwise cls will become 12 below
            if ((talentTabInfo->ClassMask & CLASSMASK_ALL_PLAYABLE) == 0)
                continue;

            // store class talent tab pages
            for (uint32 cls = 1; cls < MAX_CLASSES; ++cls)
                if (talentTabInfo->ClassMask & (1 << (cls - 1)))
                    _TalentTabPages[cls][talentTabInfo->OrderIndex] = talentTabInfo->ID;
        }
    }
}

void DBCStoresMgr::_Handle_TaxiNodesMask()
{
    // Initialize global taxinodes mask
    // include existed nodes that have at least single not spell base (scripted) path
    std::set<uint32> spellPaths;
    SpellDBCMap const& spellMap = sDBCStoresMgr->GetSpellDBCMap();
    for (const auto& sID : spellMap)
        if (SpellDBC const* sInfo = &sID.second)
            for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
                if (sInfo->Effect[j] == SPELL_EFFECT_SEND_TAXI)
                    spellPaths.insert(sInfo->EffectMiscValue[j]);

    _TaxiNodesMask.fill(0);
    _OldContinentsNodesMask.fill(0);
    _HordeTaxiNodesMask.fill(0);
    _AllianceTaxiNodesMask.fill(0);
    _DeathKnightTaxiNodesMask.fill(0);

    for (const auto& tnID : _taxiNodesMap)
    {
        if (TaxiNodesDBC const* node = &tnID.second)
        {
            TaxiPathSetBySource::const_iterator src_i = _taxiPathSetBySource.find(node->ID);
            if (src_i != _taxiPathSetBySource.end() && !src_i->second.empty())
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
            uint8  field = (uint8)((node->ID - 1) / 32);
            uint32 submask = 1 << ((node->ID - 1) % 32);
            _TaxiNodesMask[field] |= submask;

            if (node->MountCreatureID[0] && node->MountCreatureID[0] != 32981)
                _HordeTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[1] && node->MountCreatureID[1] != 32981)
                _AllianceTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[0] == 32981 || node->MountCreatureID[1] == 32981)
                _DeathKnightTaxiNodesMask[field] |= submask;

            // old continent node (+ nodes virtually at old continents, check explicitly to avoid loading map files for zone info)
            if (node->ContinentID < 2 || node->ID == 82 || node->ID == 83 || node->ID == 93 || node->ID == 94)
                _OldContinentsNodesMask[field] |= submask;

            // fix DK node at Ebon Hold and Shadow Vault flight master
            if (node->ID == 315 || node->ID == 333)
                const_cast<TaxiNodesDBC*>(node)->MountCreatureID[1] = 32981;
        }
    }
    spellPaths.clear();
}

void DBCStoresMgr::_Handle_TaxiPathSetBySource()
{
    for (const auto& tpID : _taxiPathMap)
    {
        if (TaxiPathDBC const* entry = &tpID.second)
            _taxiPathSetBySource[entry->FromTaxiNode][entry->ToTaxiNode] = TaxiPathBySourceAndDestination(entry->ID, entry->Cost);
    }
}

void DBCStoresMgr::_Handle_TaxiPathNodesByPath()
{
    uint32 pathCount = _taxiPathNumRow;
    // Calculate path nodes count
    std::vector<uint32> pathLength;
    pathLength.resize(pathCount);                           // 0 and some other indexes not used
    for (const auto& tpnID : _taxiPathNodeMap)
    {
        if (TaxiPathNodeDBC const* entry = &tpnID.second)
            if (pathLength[entry->PathID] < entry->NodeIndex + 1)
                pathLength[entry->PathID] = entry->NodeIndex + 1;
    }

    // Set path length
    _taxiPathNodesByPath.resize(pathCount);                 // 0 and some other indexes not used
    for (uint32 i = 1; i < _taxiPathNodesByPath.size(); ++i)
        _taxiPathNodesByPath[i].resize(pathLength[i]);
    // fill data
    for (const auto& tpnID : _taxiPathNodeMap)
    {
        if (TaxiPathNodeDBC const* entry = &tpnID.second)
            _taxiPathNodesByPath[entry->PathID][entry->NodeIndex] = entry;
    }
}

// map with tuple
void DBCStoresMgr::_Handle_CharacterFacialHairStylesByTripple()
{
    for (const auto& cfhsID : _characterFacialHairStyleMap)
    {
        if (CharacterFacialHairStylesDBC const* entry = &cfhsID.second)
            _characterFacialHairStylesByTripple[CharacterFacialHairStylesKey(entry->RaceID, entry->SexID, entry->VariationID)] = entry;
    }
}

void DBCStoresMgr::_Handle_CharSectionsByPenta()
{
    for (const auto& csID : _charSectionMap)
    {
        if (CharSectionsDBC const* entry = &csID.second)
            _charSectionsByPenta[CharSectionsKey(entry->RaceID, CharSectionType(entry->BaseSection), entry->SexID, entry->VariationIndex, entry->ColorIndex)] = entry;
    }
}

void DBCStoresMgr::_Handle_CharStartOutfitByTripple()
{
    for (const auto& csoID : _charStartOutfitMap)
    {
        if (CharStartOutfitDBC const* entry = &csoID.second)
            _charStartOutfitByTripple[CharStartOutfitKey(entry->RaceID, entry->ClassID, entry->SexID)] = entry;
    }
}

void DBCStoresMgr::_Handle_EmotesTextSoundByTripple()
{
    for (const auto& etsID : _emotesTextSoundMap)
    {
        if (EmotesTextSoundDBC const* entry = &etsID.second)
            _emotesTextSoundByTripple[EmotesTextSoundKey(entry->EmotesTextID, entry->RaceID, entry->SexID)] = entry;
    }
}

void DBCStoresMgr::_Handle_LFGDungeonDBCByDouble()
{
    for (const auto& lfgdID : _lfgDungeonMap)
    {
        if (LFGDungeonDBC const* entry = &lfgdID.second)
            _lfgDungeonByDouble[LFGDungeonKey(entry->MapID, Difficulty(entry->Difficulty))] = entry;
    }
}

void DBCStoresMgr::_Handle_MapDifficultyByDouble()
{
    for (const auto& mpID : _mapDifficultyMap)
    {
        if (MapDifficultyDBC const* entry = &mpID.second)
            _mapDifficultyByDouble[MapDifficultyKey(entry->MapID, Difficulty(entry->Difficulty))] = entry;
    }
}

void DBCStoresMgr::_Handle_SkillRaceClassInfo()
{
    for (const auto& srciID : _skillRaceClassInfoMap)
    {
        if (SkillRaceClassInfoDBC const* entry = &srciID.second)
            if (GetSkillLineDBC(entry->SkillID))
                _skillRaceClassInfoBySkill.emplace(entry->SkillID, entry);
    }
}

void DBCStoresMgr::_Handle_WMOAreaInfoByTripple()
{
    for (const auto& wmoID : _wmoAreaTableMap)
    {
        if (WMOAreaTableDBC const* entry = &wmoID.second)
            _wmoAreaInfoByTripple[WMOAreaTableKey(entry->WMOID, entry->NameSetID, entry->WMOGroupID)] = entry;
    }
}
