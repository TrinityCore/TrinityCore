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

typedef std::multimap<uint32, CharSectionsEntry const*> CharSectionsMap;
typedef std::map<uint32, std::vector<uint32>> FactionTeamMap;
typedef std::map<WMOAreaTableTripple, WMOAreaTableEntry const*> WMOAreaInfoByTripple;

DBCStorage<BannedAddOnsEntry>               sBannedAddOnsStore(BannedAddOnsfmt);
DBCStorage<BattlemasterListEntry>           sBattlemasterListStore(BattlemasterListfmt);

DBCStorage<CharSectionsEntry>               sCharSectionsStore(CharSectionsfmt);
CharSectionsMap                             sCharSectionMap;
DBCStorage<ChrClassesEntry>                 sChrClassesStore(ChrClassesfmt);
DBCStorage<CreatureModelDataEntry>          sCreatureModelDataStore(CreatureModelDatafmt);

DBCStorage<FactionEntry>                    sFactionStore(Factionfmt);
static FactionTeamMap                       sFactionTeamMap;
DBCStorage<FactionTemplateEntry>            sFactionTemplateStore(FactionTemplatefmt);

DBCStorage<LFGDungeonEntry>                 sLFGDungeonStore(LFGDungeonfmt);
DBCStorage<LightEntry>                      sLightStore(Lightfmt);
DBCStorage<LiquidTypeEntry>                 sLiquidTypeStore(LiquidTypefmt);

DBCStorage<MapDifficultyEntry>              sMapDifficultyStore(MapDifficultyfmt); // only for loading
MapDifficultyMap                            sMapDifficultyMap;

DBCStorage<SpellItemEnchantmentEntry>       sSpellItemEnchantmentStore(SpellItemEnchantmentfmt);

DBCStorage<TalentEntry>                     sTalentStore(Talentfmt);
TalentsByPosition                           sTalentByPos;

DBCStorage<VehicleEntry>                    sVehicleStore(Vehiclefmt);

DBCStorage<WMOAreaTableEntry>               sWMOAreaTableStore(WMOAreaTablefmt);
static WMOAreaInfoByTripple                 sWMOAreaInfoByTripple;
DBCStorage<WorldMapAreaEntry>               sWorldMapAreaStore(WorldMapAreafmt);
DBCStorage<WorldSafeLocsEntry>              sWorldSafeLocsStore(WorldSafeLocsfmt);

GameTable<GtBarberShopCostBaseEntry>        sGtBarberShopCostBaseStore;
GameTable<GtChanceToMeleeCritBaseEntry>     sGtChanceToMeleeCritBaseStore;
GameTable<GtChanceToMeleeCritEntry>         sGtChanceToMeleeCritStore;
GameTable<GtChanceToSpellCritBaseEntry>     sGtChanceToSpellCritBaseStore;
GameTable<GtChanceToSpellCritEntry>         sGtChanceToSpellCritStore;
GameTable<GtCombatRatingsEntry>             sGtCombatRatingsStore;
GameTable<GtItemSocketCostPerLevelEntry>    sGtItemSocketCostPerLevelStore;
GameTable<GtNPCManaCostScalerEntry>         sGtNPCManaCostScalerStore;
GameTable<GtNpcTotalHpEntry>                sGtNpcTotalHpStore[MAX_EXPANSIONS];
GameTable<GtNpcDamageByClassEntry>          sGtNpcDamageByClassStore[MAX_EXPANSIONS];
GameTable<GtOCTBaseHPByClassEntry>          sGtOCTBaseHPByClassStore;
GameTable<GtOCTBaseMPByClassEntry>          sGtOCTBaseMPByClassStore;
GameTable<GtOCTHpPerStaminaEntry>           sGtOCTHpPerStaminaStore;
GameTable<GtOCTLevelExperienceEntry>        sGtOCTLevelExperienceStore;
GameTable<GtRegenMPPerSptEntry>             sGtRegenMPPerSptStore;
GameTable<GtSpellScalingEntry>              sGtSpellScalingStore;

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
            if (i == LOCALE_none || !(availableDbcLocales & (1 << i)))
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
                if (l != LOCALE_none && tableName == gt->Name->Str[l])
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

    LOAD_DBC(sBannedAddOnsStore, "BannedAddOns.dbc");//20810
    LOAD_DBC(sBattlemasterListStore, "BattlemasterList.dbc");//20810
    LOAD_DBC(sCharSectionsStore, "CharSections.dbc");//20810
    LOAD_DBC(sChrClassesStore, "ChrClasses.dbc");//20810
    LOAD_DBC(sCreatureModelDataStore, "CreatureModelData.dbc");//20810
    LOAD_DBC(sFactionStore, "Faction.dbc");//20810
    LOAD_DBC(sFactionTemplateStore, "FactionTemplate.dbc");//20810
    LOAD_DBC(sLFGDungeonStore, "LfgDungeons.dbc");//20810
    LOAD_DBC(sLightStore, "Light.dbc"); //20810
    LOAD_DBC(sLiquidTypeStore, "LiquidType.dbc");//20810
    LOAD_DBC(sMapDifficultyStore, "MapDifficulty.dbc");//20810
    LOAD_DBC(sSpellItemEnchantmentStore, "SpellItemEnchantment.dbc");//20810
    LOAD_DBC(sTalentStore, "Talent.dbc");//20810
    LOAD_DBC(sVehicleStore, "Vehicle.dbc");//20810
    LOAD_DBC(sWMOAreaTableStore, "WMOAreaTable.dbc");//20810
    LOAD_DBC(sWorldMapAreaStore, "WorldMapArea.dbc");//20810
    LOAD_DBC(sWorldSafeLocsStore, "WorldSafeLocs.dbc"); // 20810

#undef LOAD_DBC

    for (uint32 i = 0; i < sCharSectionsStore.GetNumRows(); ++i)
        if (CharSectionsEntry const* entry = sCharSectionsStore.LookupEntry(i))
            if (entry->Race && ((1 << (entry->Race - 1)) & RACEMASK_ALL_PLAYABLE) != 0) //ignore Nonplayable races
                sCharSectionMap.insert({ entry->GenType | (entry->Gender << 8) | (entry->Race << 16), entry });

    for (uint32 i = 0; i < sFactionStore.GetNumRows(); ++i)
    {
        FactionEntry const* faction = sFactionStore.LookupEntry(i);
        if (faction && faction->ParentFactionID)
            sFactionTeamMap[faction->ParentFactionID].push_back(i);
    }

    // fill data
    for (uint32 i = 0; i < sMapDifficultyStore.GetNumRows(); ++i)
        if (MapDifficultyEntry const* entry = sMapDifficultyStore.LookupEntry(i))
            sMapDifficultyMap[entry->MapID][entry->DifficultyID] = entry;
    sMapDifficultyMap[0][0] = sMapDifficultyMap[1][0]; //map 0 is missing from MapDifficulty.dbc use this till its ported to sql

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

    TC_LOG_INFO("server.loading", ">> Initialized %d DBC data stores in %u ms", DBCFileCount, GetMSTimeDiffToNow(oldMSTime));
}

void LoadGameTables(const std::string& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string dbcPath = dataPath + "dbc/" + localeNames[defaultLocale] + '/';

    StoreProblemList bad_dbc_files;

#define LOAD_GT(tableName, store, file) LoadGameTable(bad_dbc_files, tableName, store, dbcPath, file)

    LOAD_GT("BarberShopCostBase", sGtBarberShopCostBaseStore, "gtBarberShopCostBase.dbc");                      // 20810
    LOAD_GT("CombatRatings", sGtCombatRatingsStore, "gtCombatRatings.dbc");                                     // 20810
    LOAD_GT("ChanceToMeleeCritBase", sGtChanceToMeleeCritBaseStore, "gtChanceToMeleeCritBase.dbc");             // 20810
    LOAD_GT("ChanceToMeleeCrit", sGtChanceToMeleeCritStore, "gtChanceToMeleeCrit.dbc");                         // 20810
    LOAD_GT("ChanceToSpellCritBase", sGtChanceToSpellCritBaseStore, "gtChanceToSpellCritBase.dbc");             // 20810
    LOAD_GT("ChanceToSpellCrit", sGtChanceToSpellCritStore, "gtChanceToSpellCrit.dbc");                         // 20810
    LOAD_GT("ItemSocketCostPerLevel", sGtItemSocketCostPerLevelStore, "gtItemSocketCostPerLevel.dbc");          // 20810
    LOAD_GT("NPCManaCostScaler", sGtNPCManaCostScalerStore, "gtNPCManaCostScaler.dbc");                         // 20810
    LOAD_GT("NpcTotalHp", sGtNpcTotalHpStore[0], "gtNpcTotalHp.dbc");                                           // 20810
    LOAD_GT("NpcTotalHpExp1", sGtNpcTotalHpStore[1], "gtNpcTotalHpExp1.dbc");                                   // 20810
    LOAD_GT("NpcTotalHpExp2", sGtNpcTotalHpStore[2], "gtNpcTotalHpExp2.dbc");                                   // 20810
    LOAD_GT("NpcTotalHpExp3", sGtNpcTotalHpStore[3], "gtNpcTotalHpExp3.dbc");                                   // 20810
    LOAD_GT("NpcTotalHpExp4", sGtNpcTotalHpStore[4], "gtNpcTotalHpExp4.dbc");                                   // 20810
    LOAD_GT("NpcTotalHpExp5", sGtNpcTotalHpStore[5], "gtNpcTotalHpExp5.dbc");                                   // 20810
    LOAD_GT("NpcTotalHpExp6", sGtNpcTotalHpStore[6], "gtNpcTotalHpExp6.dbc");                                   // 20810
    LOAD_GT("NpcDamageByClass", sGtNpcDamageByClassStore[0], "gtNpcDamageByClass.dbc");                         // 20810
    LOAD_GT("NpcDamageByClassExp1", sGtNpcDamageByClassStore[1], "gtNpcDamageByClassExp1.dbc");                 // 20810
    LOAD_GT("NpcDamageByClassExp2", sGtNpcDamageByClassStore[2], "gtNpcDamageByClassExp2.dbc");                 // 20810
    LOAD_GT("NpcDamageByClassExp3", sGtNpcDamageByClassStore[3], "gtNpcDamageByClassExp3.dbc");                 // 20810
    LOAD_GT("NpcDamageByClassExp4", sGtNpcDamageByClassStore[4], "gtNpcDamageByClassExp4.dbc");                 // 20810
    LOAD_GT("NpcDamageByClassExp5", sGtNpcDamageByClassStore[5], "gtNpcDamageByClassExp5.dbc");                 // 20810
    LOAD_GT("NpcDamageByClassExp6", sGtNpcDamageByClassStore[6], "gtNpcDamageByClassExp6.dbc");                 // 20810
    LOAD_GT("OCTHPPerStamina", sGtOCTHpPerStaminaStore, "gtOCTHpPerStamina.dbc");                               // 20810
    LOAD_GT("OCTLevelExperience", sGtOCTLevelExperienceStore, "gtOCTLevelExperience.dbc");                      // 20810
    LOAD_GT("RegenMPPerSpt", sGtRegenMPPerSptStore, "gtRegenMPPerSpt.dbc");                                     // 20810
    LOAD_GT("SpellScaling", sGtSpellScalingStore, "gtSpellScaling.dbc");                                        // 20810
    LOAD_GT("OCTBaseHPByClass", sGtOCTBaseHPByClassStore, "gtOCTBaseHPByClass.dbc");                            // 20810
    LOAD_GT("OCTBaseMPByClass", sGtOCTBaseMPByClassStore, "gtOCTBaseMPByClass.dbc");                            // 20810

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

WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid)
{
    WMOAreaInfoByTripple::iterator i = sWMOAreaInfoByTripple.find(WMOAreaTableTripple(rootid, adtid, groupid));
    if (i == sWMOAreaInfoByTripple.end())
        return NULL;
    return i->second;
}

char const* GetClassName(uint8 class_, uint8 /*locale*/)
{
    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);
    return classEntry ? classEntry->Name_lang : NULL;
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
        case EXPANSION_LEGION:
            return 110;
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
    else if (level < 100)
        return EXPANSION_WARLORDS_OF_DRAENOR;
    else
        return CURRENT_EXPANSION;
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
