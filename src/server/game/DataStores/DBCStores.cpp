/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "DBCFileLoader.h"
#include "DBCfmt.h"
#include "Errors.h"
#include "IteratorPair.h"
#include "Log.h"
#include "ObjectDefines.h"
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

#define DEFINE_DBC_STORAGE(dbc) DBCStorage <dbc ## Entry> s ## dbc ## Store(DBCfmt_ ## dbc);

DEFINE_DBC_STORAGE(AreaTable);
DEFINE_DBC_STORAGE(AreaGroup);
DEFINE_DBC_STORAGE(AreaPOI);

static WMOAreaInfoByTripple sWMOAreaInfoByTripple;

DEFINE_DBC_STORAGE(Achievement);
DEFINE_DBC_STORAGE(AchievementCriteria);
DEFINE_DBC_STORAGE(AreaTrigger);
DEFINE_DBC_STORAGE(AuctionHouse);
DEFINE_DBC_STORAGE(BankBagSlotPrices);
DEFINE_DBC_STORAGE(BannedAddOns);
DEFINE_DBC_STORAGE(BattlemasterList);
DEFINE_DBC_STORAGE(BarberShopStyle);
DEFINE_DBC_STORAGE(CharacterFacialHairStyles);
std::unordered_map<uint32, CharacterFacialHairStylesEntry const*> sCharFacialHairMap;
DEFINE_DBC_STORAGE(CharSections);
std::unordered_multimap<uint32, CharSectionsEntry const*> sCharSectionMap;
DEFINE_DBC_STORAGE(CharStartOutfit);
std::map<uint32, CharStartOutfitEntry const*> sCharStartOutfitMap;
DEFINE_DBC_STORAGE(CharTitles);
DEFINE_DBC_STORAGE(ChatChannels);
DEFINE_DBC_STORAGE(ChrClasses);
DEFINE_DBC_STORAGE(ChrRaces);
DEFINE_DBC_STORAGE(CinematicCamera);
DEFINE_DBC_STORAGE(CinematicSequences);
DEFINE_DBC_STORAGE(CreatureDisplayInfo);
DEFINE_DBC_STORAGE(CreatureDisplayInfoExtra);
DEFINE_DBC_STORAGE(CreatureFamily);
DEFINE_DBC_STORAGE(CreatureModelData);
DEFINE_DBC_STORAGE(CreatureSpellData);
DEFINE_DBC_STORAGE(CreatureType);
DEFINE_DBC_STORAGE(CurrencyTypes);

DEFINE_DBC_STORAGE(DestructibleModelData);
DEFINE_DBC_STORAGE(DungeonEncounter);
DEFINE_DBC_STORAGE(DurabilityQuality);
DEFINE_DBC_STORAGE(DurabilityCosts);

DEFINE_DBC_STORAGE(Emotes);
DEFINE_DBC_STORAGE(EmotesText);
typedef std::tuple<uint32, uint32, uint32> EmotesTextSoundKey;
static std::map<EmotesTextSoundKey, EmotesTextSoundEntry const*> sEmotesTextSoundMap;
DEFINE_DBC_STORAGE(EmotesTextSound);

typedef std::map<uint32, SimpleFactionsList> FactionTeamMap;
static FactionTeamMap sFactionTeamMap;
DEFINE_DBC_STORAGE(Faction);
DEFINE_DBC_STORAGE(FactionTemplate);

DEFINE_DBC_STORAGE(GameObjectDisplayInfo);
DEFINE_DBC_STORAGE(GemProperties);
DEFINE_DBC_STORAGE(GlyphProperties);
DEFINE_DBC_STORAGE(GlyphSlot);

DEFINE_DBC_STORAGE(gtBarberShopCostBase);
DEFINE_DBC_STORAGE(gtCombatRatings);
DEFINE_DBC_STORAGE(gtChanceToMeleeCritBase);
DEFINE_DBC_STORAGE(gtChanceToMeleeCrit);
DEFINE_DBC_STORAGE(gtChanceToSpellCritBase);
DEFINE_DBC_STORAGE(gtChanceToSpellCrit);
DEFINE_DBC_STORAGE(gtNPCManaCostScaler);
DEFINE_DBC_STORAGE(gtOCTClassCombatRatingScalar);
DEFINE_DBC_STORAGE(gtOCTRegenHP);
//DEFINE_DBC_STORAGE(gtOCTRegenMP);
DEFINE_DBC_STORAGE(gtRegenHPPerSpt);
DEFINE_DBC_STORAGE(gtRegenMPPerSpt);

DEFINE_DBC_STORAGE(Holidays);

DEFINE_DBC_STORAGE(Item);
DEFINE_DBC_STORAGE(ItemBagFamily);
//DEFINE_DBC_STORAGE(ItemCondExtCosts);
//DEFINE_DBC_STORAGE(ItemDisplayInfo);
DEFINE_DBC_STORAGE(ItemExtendedCost);
DEFINE_DBC_STORAGE(ItemLimitCategory);
DEFINE_DBC_STORAGE(ItemRandomProperties);
DEFINE_DBC_STORAGE(ItemRandomSuffix);
DEFINE_DBC_STORAGE(ItemSet);

DEFINE_DBC_STORAGE(LFGDungeons);
DEFINE_DBC_STORAGE(Light);
DEFINE_DBC_STORAGE(LiquidType);
DEFINE_DBC_STORAGE(Lock);

DEFINE_DBC_STORAGE(MailTemplate);
DEFINE_DBC_STORAGE(Map);

// DBC used only for initialization sMapDifficultyMap at startup.
DEFINE_DBC_STORAGE(MapDifficulty);
MapDifficultyMap sMapDifficultyMap;

DEFINE_DBC_STORAGE(Movie);

DEFINE_DBC_STORAGE(NamesProfanity);
DEFINE_DBC_STORAGE(NamesReserved);
typedef std::array<std::vector<Trinity::wregex>, TOTAL_LOCALES> NameValidationRegexContainer;
NameValidationRegexContainer NamesProfaneValidators;
NameValidationRegexContainer NamesReservedValidators;

DEFINE_DBC_STORAGE(OverrideSpellData);

DEFINE_DBC_STORAGE(PowerDisplay);
DEFINE_DBC_STORAGE(PvPDifficulty);

DEFINE_DBC_STORAGE(QuestSort);
DEFINE_DBC_STORAGE(QuestXP);
DEFINE_DBC_STORAGE(QuestFactionReward);
DEFINE_DBC_STORAGE(RandomPropertiesPoints);
DEFINE_DBC_STORAGE(ScalingStatDistribution);
DEFINE_DBC_STORAGE(ScalingStatValues);

DEFINE_DBC_STORAGE(SkillLine);
DEFINE_DBC_STORAGE(SkillLineAbility);
DEFINE_DBC_STORAGE(SkillRaceClassInfo);
SkillRaceClassInfoMap SkillRaceClassInfoBySkill;
DEFINE_DBC_STORAGE(SkillTiers);

DEFINE_DBC_STORAGE(SoundEntries);

DEFINE_DBC_STORAGE(SpellItemEnchantment);
DEFINE_DBC_STORAGE(SpellItemEnchantmentCondition);
DEFINE_DBC_STORAGE(Spell);
PetFamilySpellsStore sPetFamilySpellsStore;

DEFINE_DBC_STORAGE(SpellCastTimes);
DEFINE_DBC_STORAGE(SpellCategory);
DEFINE_DBC_STORAGE(SpellDifficulty);
DEFINE_DBC_STORAGE(SpellDuration);
DEFINE_DBC_STORAGE(SpellFocusObject);
DEFINE_DBC_STORAGE(SpellRadius);
DEFINE_DBC_STORAGE(SpellRange);
DEFINE_DBC_STORAGE(SpellRuneCost);
DEFINE_DBC_STORAGE(SpellShapeshift);
DEFINE_DBC_STORAGE(StableSlotPrices);
DEFINE_DBC_STORAGE(SummonProperties);
DEFINE_DBC_STORAGE(Talent);
TalentSpellPosMap sTalentSpellPosMap;
DEFINE_DBC_STORAGE(TalentTab);

// store absolute bit position for first rank for talent inspect
static uint32 sTalentTabPages[MAX_CLASSES][3];

DEFINE_DBC_STORAGE(TaxiNodes);
TaxiMask sTaxiNodesMask;
TaxiMask sOldContinentsNodesMask;
TaxiMask sHordeTaxiNodesMask;
TaxiMask sAllianceTaxiNodesMask;
TaxiMask sDeathKnightTaxiNodesMask;

// DBC used only for initialization sTaxiPathSetBySource at startup.
TaxiPathSetBySource sTaxiPathSetBySource;
DEFINE_DBC_STORAGE(TaxiPath);

// DBC used only for initialization sTaxiPathNodeStore at startup.
TaxiPathNodesByPath sTaxiPathNodesByPath;
static DEFINE_DBC_STORAGE(TaxiPathNode);

DEFINE_DBC_STORAGE(TeamContributionPoints);
DEFINE_DBC_STORAGE(TotemCategory);
DEFINE_DBC_STORAGE(TransportAnimation);
DEFINE_DBC_STORAGE(TransportRotation);
DEFINE_DBC_STORAGE(Vehicle);
DEFINE_DBC_STORAGE(VehicleSeat);
DEFINE_DBC_STORAGE(WMOAreaTable);
DEFINE_DBC_STORAGE(WorldMapArea);
DEFINE_DBC_STORAGE(WorldMapOverlay);
DEFINE_DBC_STORAGE(WorldSafeLocs);

#undef DEFINE_DBC_STORAGE

typedef std::list<std::string> StoreProblemList;

uint32 DBCFileCount = 0;

static bool LoadDBC_assert_print(uint32 fsize, uint32 rsize, const std::string& filename)
{
    TC_LOG_ERROR("misc", "Size of '%s' set by format string (%u) not equal size of C++ structure (%u).", filename.c_str(), fsize, rsize);

    // ASSERT must fail after function call
    return false;
}

template<class T>
inline void LoadDBC(uint32& availableDbcLocales, StoreProblemList& errors, DBCStorage<T>& storage, std::string const& dbcPath, std::string const& filename, std::string const& customFormat = std::string(), std::string const& customIndexName = std::string())
{
    // compatibility format and C++ structure sizes
    ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T) || LoadDBC_assert_print(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()), sizeof(T), filename));

    ++DBCFileCount;
    std::string dbcFilename = dbcPath + filename;

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

            if (!storage.LoadStringsFrom(localizedName))
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

void LoadDBCStores(const std::string& dataPath)
{
    uint32 oldMSTime = getMSTime();

    std::string dbcPath = dataPath + "dbc/";

    StoreProblemList bad_dbc_files;
    uint32 availableDbcLocales = 0xFFFFFFFF;

#define LOAD_DBC(dbc) LoadDBC(availableDbcLocales, bad_dbc_files, s ## dbc ## Store, dbcPath, #dbc ".dbc")
#define LOAD_DBC_EXT(dbc) LoadDBC(availableDbcLocales, bad_dbc_files, s ## dbc ## Store, dbcPath, #dbc ".dbc", DBCfmt_ ## dbc ## _DBFormat, DBCfmt_ ## dbc ## _DBIndex)

    LOAD_DBC(AreaTable);
    LOAD_DBC(AchievementCriteria);
    LOAD_DBC(AreaTrigger);
    LOAD_DBC(AreaGroup);
    LOAD_DBC(AreaPOI);
    LOAD_DBC(AuctionHouse);
    LOAD_DBC(BankBagSlotPrices);
    LOAD_DBC(BannedAddOns);
    LOAD_DBC(BattlemasterList);
    LOAD_DBC(BarberShopStyle);
    LOAD_DBC(CharacterFacialHairStyles);
    LOAD_DBC(CharSections);
    LOAD_DBC(CharStartOutfit);
    LOAD_DBC(CharTitles);
    LOAD_DBC(ChatChannels);
    LOAD_DBC(ChrClasses);
    LOAD_DBC(ChrRaces);
    LOAD_DBC(CinematicCamera);
    LOAD_DBC(CinematicSequences);
    LOAD_DBC(CreatureDisplayInfo);
    LOAD_DBC(CreatureDisplayInfoExtra);
    LOAD_DBC(CreatureFamily);
    LOAD_DBC(CreatureModelData);
    LOAD_DBC(CreatureSpellData);
    LOAD_DBC(CreatureType);
    LOAD_DBC(CurrencyTypes);
    LOAD_DBC(DestructibleModelData);
    LOAD_DBC(DungeonEncounter);
    LOAD_DBC(DurabilityCosts);
    LOAD_DBC(DurabilityQuality);
    LOAD_DBC(Emotes);
    LOAD_DBC(EmotesText);
    LOAD_DBC(EmotesTextSound);
    LOAD_DBC(Faction);
    LOAD_DBC(FactionTemplate);
    LOAD_DBC(GameObjectDisplayInfo);
    LOAD_DBC(GemProperties);
    LOAD_DBC(GlyphProperties);
    LOAD_DBC(GlyphSlot);
    LOAD_DBC(gtBarberShopCostBase);
    LOAD_DBC(gtCombatRatings);
    LOAD_DBC(gtChanceToMeleeCritBase);
    LOAD_DBC(gtChanceToMeleeCrit);
    LOAD_DBC(gtChanceToSpellCritBase);
    LOAD_DBC(gtChanceToSpellCrit);
    LOAD_DBC(gtNPCManaCostScaler);
    LOAD_DBC(gtOCTClassCombatRatingScalar);
    LOAD_DBC(gtOCTRegenHP);
    //LOAD_DBC(gtOCTRegenMP);
    LOAD_DBC(gtRegenHPPerSpt);
    LOAD_DBC(gtRegenMPPerSpt);
    LOAD_DBC(Holidays);
    LOAD_DBC(Item);
    LOAD_DBC(ItemBagFamily);
    //LOAD_DBC(ItemDisplayInfo);
    //LOAD_DBC(ItemCondExtCosts);
    LOAD_DBC(ItemExtendedCost);
    LOAD_DBC(ItemLimitCategory);
    LOAD_DBC(ItemRandomProperties);
    LOAD_DBC(ItemRandomSuffix);
    LOAD_DBC(ItemSet);
    LOAD_DBC(LFGDungeons);
    LOAD_DBC(Light);
    LOAD_DBC(LiquidType);
    LOAD_DBC(Lock);
    LOAD_DBC(MailTemplate);
    LOAD_DBC(Map);
    LOAD_DBC(MapDifficulty);
    LOAD_DBC(Movie);
    LOAD_DBC(NamesProfanity);
    LOAD_DBC(NamesReserved);
    LOAD_DBC(OverrideSpellData);
    LOAD_DBC(PowerDisplay);
    LOAD_DBC(PvPDifficulty);
    LOAD_DBC(QuestXP);
    LOAD_DBC(QuestFactionReward);
    LOAD_DBC(QuestSort);
    LOAD_DBC(RandomPropertiesPoints);
    LOAD_DBC(ScalingStatDistribution);
    LOAD_DBC(ScalingStatValues);
    LOAD_DBC(SkillLine);
    LOAD_DBC(SkillLineAbility);
    LOAD_DBC(SkillRaceClassInfo);
    LOAD_DBC(SkillTiers);
    LOAD_DBC(SoundEntries);
    LOAD_DBC(SpellCastTimes);
    LOAD_DBC(SpellCategory);
    LOAD_DBC(SpellDuration);
    LOAD_DBC(SpellFocusObject);
    LOAD_DBC(SpellItemEnchantment);
    LOAD_DBC(SpellItemEnchantmentCondition);
    LOAD_DBC(SpellRadius);
    LOAD_DBC(SpellRange);
    LOAD_DBC(SpellRuneCost);
    LOAD_DBC(SpellShapeshift);
    LOAD_DBC(StableSlotPrices);
    LOAD_DBC(SummonProperties);
    LOAD_DBC(Talent);
    LOAD_DBC(TalentTab);
    LOAD_DBC(TaxiNodes);
    LOAD_DBC(TaxiPath);
    LOAD_DBC(TaxiPathNode);
    LOAD_DBC(TeamContributionPoints);
    LOAD_DBC(TotemCategory);
    LOAD_DBC(TransportAnimation);
    LOAD_DBC(TransportRotation);
    LOAD_DBC(Vehicle);
    LOAD_DBC(VehicleSeat);
    LOAD_DBC(WMOAreaTable);
    LOAD_DBC(WorldMapArea);
    LOAD_DBC(WorldMapOverlay);
    LOAD_DBC(WorldSafeLocs);
    
    LOAD_DBC_EXT(Achievement);
    LOAD_DBC_EXT(Spell);
    LOAD_DBC_EXT(SpellDifficulty);

#undef LOAD_DBC
#undef LOAD_DBC_EXT


    for (CharacterFacialHairStylesEntry const* entry : sCharacterFacialHairStylesStore)
        if (entry->Race && ((1 << (entry->Race - 1)) & RACEMASK_ALL_PLAYABLE) != 0) // ignore nonplayable races
            sCharFacialHairMap.insert({ entry->Race | (entry->Gender << 8) | (entry->Variation << 16), entry });

    for (CharSectionsEntry const* entry : sCharSectionsStore)
        if (entry->Race && ((1 << (entry->Race - 1)) & RACEMASK_ALL_PLAYABLE) != 0) // ignore nonplayable races
            sCharSectionMap.insert({ entry->GenType | (entry->Gender << 8) | (entry->Race << 16), entry });

    for (CharStartOutfitEntry const* outfit : sCharStartOutfitStore)
        sCharStartOutfitMap[outfit->Race | (outfit->Class << 8) | (outfit->Gender << 16)] = outfit;

    for (EmotesTextSoundEntry const* entry : sEmotesTextSoundStore)
        sEmotesTextSoundMap[EmotesTextSoundKey(entry->EmotesTextId, entry->RaceId, entry->SexId)] = entry;

    for (FactionEntry const* faction : sFactionStore)
    {
        if (faction->team)
        {
            SimpleFactionsList& flist = sFactionTeamMap[faction->team];
            flist.push_back(faction->ID);
        }
    }

    for (GameObjectDisplayInfoEntry const* info : sGameObjectDisplayInfoStore)
    {
        if (info->maxX < info->minX)
            std::swap(*(float*)(&info->maxX), *(float*)(&info->minX));
        if (info->maxY < info->minY)
            std::swap(*(float*)(&info->maxY), *(float*)(&info->minY));
        if (info->maxZ < info->minZ)
            std::swap(*(float*)(&info->maxZ), *(float*)(&info->minZ));
    }

    // fill data
    for (MapDifficultyEntry const* entry : sMapDifficultyStore)
        sMapDifficultyMap[MAKE_PAIR32(entry->MapId, entry->Difficulty)] = MapDifficulty(entry->resetTime, entry->maxPlayers, entry->areaTriggerText[0] != '\0');

    for (NamesProfanityEntry const* namesProfanity : sNamesProfanityStore)
    {
        ASSERT(namesProfanity->Language < TOTAL_LOCALES || namesProfanity->Language == -1);
        std::wstring wname;
        bool conversionResult = Utf8toWStr(namesProfanity->Name, wname);
        ASSERT(conversionResult);

        if (namesProfanity->Language != -1)
            NamesProfaneValidators[namesProfanity->Language].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
        else
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                NamesProfaneValidators[i].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
    }

    for (NamesReservedEntry const* namesReserved : sNamesReservedStore)
    {
        ASSERT(namesReserved->Language < TOTAL_LOCALES || namesReserved->Language == -1);
        std::wstring wname;
        bool conversionResult = Utf8toWStr(namesReserved->Name, wname);
        ASSERT(conversionResult);

        if (namesReserved->Language != -1)
            NamesReservedValidators[namesReserved->Language].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
        else
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                NamesReservedValidators[i].emplace_back(wname, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
    }

    for (PvPDifficultyEntry const* entry : sPvPDifficultyStore)
    {
        ASSERT(entry->bracketId < MAX_BATTLEGROUND_BRACKETS, "PvpDifficulty bracket (%d) exceeded max allowed value (%d)", entry->bracketId, MAX_BATTLEGROUND_BRACKETS);
    }

    for (SkillRaceClassInfoEntry const* entry : sSkillRaceClassInfoStore)
        if (sSkillLineStore.LookupEntry(entry->SkillId))
            SkillRaceClassInfoBySkill.emplace(entry->SkillId, entry);

    for (SkillLineAbilityEntry const* skillLine : sSkillLineAbilityStore)
    {
        SpellEntry const* spellInfo = sSpellStore.LookupEntry(skillLine->spellId);
        if (spellInfo && spellInfo->Attributes & SPELL_ATTR0_PASSIVE)
        {
            for (CreatureFamilyEntry const* cFamily : sCreatureFamilyStore)
            {
                if (skillLine->skillId != cFamily->skillLine[0] && skillLine->skillId != cFamily->skillLine[1])
                    continue;
                if (spellInfo->spellLevel)
                    continue;

                if (skillLine->AutolearnType != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                sPetFamilySpellsStore[cFamily->ID].insert(spellInfo->Id);
            }
        }
    }

    // Create Spelldifficulty searcher
    for (SpellDifficultyEntry const* spellDiff : sSpellDifficultyStore)
    {
        SpellDifficultyEntry newEntry;
        memset(newEntry.SpellID, 0, 4*sizeof(uint32));
        for (uint8 x = 0; x < MAX_DIFFICULTY; ++x)
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

        for (uint8 x = 0; x < MAX_DIFFICULTY; ++x)
            if (newEntry.SpellID[x])
                sSpellMgr->SetSpellDifficultyId(uint32(newEntry.SpellID[x]), spellDiff->ID);
    }

    // create talent spells set
    for (TalentEntry const* talentInfo : sTalentStore)
    {
        for (uint8 j = 0; j < MAX_TALENT_RANK; ++j)
            if (talentInfo->RankID[j])
                sTalentSpellPosMap[talentInfo->RankID[j]] = TalentSpellPos(talentInfo->TalentID, j);
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
                    sTalentTabPages[cls][talentTabInfo->tabpage] = talentTabInfo->TalentTabID;
        }
    }

    for (TaxiPathEntry const* entry : sTaxiPathStore)
        sTaxiPathSetBySource[entry->from][entry->to] = TaxiPathBySourceAndDestination(entry->ID, entry->price);

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
        for (SpellEntry const* sInfo : sSpellStore)
            for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
                if (sInfo->Effect[j] == SPELL_EFFECT_SEND_TAXI)
                    spellPaths.insert(sInfo->EffectMiscValue[j]);

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
            uint8  field   = (uint8)((node->ID - 1) / 32);
            uint32 submask = 1  <<  ((node->ID - 1) % 32);
            sTaxiNodesMask[field] |= submask;

            if (node->MountCreatureID[0] && node->MountCreatureID[0] != 32981)
                sHordeTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[1] && node->MountCreatureID[1] != 32981)
                sAllianceTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[0] == 32981 || node->MountCreatureID[1] == 32981)
                sDeathKnightTaxiNodesMask[field] |= submask;

            // old continent node (+ nodes virtually at old continents, check explicitly to avoid loading map files for zone info)
            if (node->map_id < 2 || node->ID == 82 || node->ID == 83 || node->ID == 93 || node->ID == 94)
                sOldContinentsNodesMask[field] |= submask;

            // fix DK node at Ebon Hold and Shadow Vault flight master
            if (node->ID == 315 || node->ID == 333)
                const_cast<TaxiNodesEntry*>(node)->MountCreatureID[1] = 32981;
        }
    }

    for (WMOAreaTableEntry const* entry : sWMOAreaTableStore)
        sWMOAreaInfoByTripple[WMOAreaTableKey(entry->rootId, entry->adtId, entry->groupId)] = entry;

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
    if (!sAreaTableStore.LookupEntry(4987)         ||       // last area added in 3.3.5a
        !sCharTitlesStore.LookupEntry(177)         ||       // last char title added in 3.3.5a
        !sGemPropertiesStore.LookupEntry(1629)     ||       // last gem property added in 3.3.5a
        !sItemStore.LookupEntry(56806)             ||       // last client known item added in 3.3.5a
        !sItemExtendedCostStore.LookupEntry(2997)  ||       // last item extended cost added in 3.3.5a
        !sMapStore.LookupEntry(724)                ||       // last map added in 3.3.5a
        !sSpellStore.LookupEntry(80864)            )        // last added spell in 3.3.5a
    {
        TC_LOG_ERROR("misc", "You have _outdated_ DBC files. Please extract correct versions from current using client.");
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d data stores in %u ms", DBCFileCount, GetMSTimeDiffToNow(oldMSTime));

}

SimpleFactionsList const* GetFactionTeamList(uint32 faction)
{
    FactionTeamMap::const_iterator itr = sFactionTeamMap.find(faction);
    if (itr != sFactionTeamMap.end())
        return &itr->second;

    return nullptr;
}

char* GetPetName(uint32 petfamily, uint32 dbclang)
{
    if (!petfamily)
        return nullptr;
    CreatureFamilyEntry const* pet_family = sCreatureFamilyStore.LookupEntry(petfamily);
    if (!pet_family)
        return nullptr;
    return pet_family->Name[dbclang]?pet_family->Name[dbclang]:nullptr;
}

TalentSpellPos const* GetTalentSpellPos(uint32 spellId)
{
    TalentSpellPosMap::const_iterator itr = sTalentSpellPosMap.find(spellId);
    if (itr == sTalentSpellPosMap.end())
        return nullptr;

    return &itr->second;
}

uint32 GetTalentSpellCost(uint32 spellId)
{
    if (TalentSpellPos const* pos = GetTalentSpellPos(spellId))
        return pos->rank+1;

    return 0;
}

WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid)
{
    auto i = sWMOAreaInfoByTripple.find(WMOAreaTableKey(int16(rootid), int8(adtid), groupid));
    if (i != sWMOAreaInfoByTripple.end())
        return i->second;

    return nullptr;
}

char const* GetRaceName(uint8 race, uint8 locale)
{
    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
    return raceEntry ? raceEntry->name[locale] : nullptr;
}

char const* GetClassName(uint8 class_, uint8 locale)
{
    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);
    return classEntry ? classEntry->name[locale] : nullptr;
}

uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId)
{
    if (mapid != 530 && mapid != 571)                        // speed for most cases
        return mapid;

    if (WorldMapAreaEntry const* wma = sWorldMapAreaStore.LookupEntry(zoneId))
        return wma->virtual_map_id >= 0 ? wma->virtual_map_id : wma->map_id;

    return mapid;
}

ContentLevels GetContentLevelsForMapAndZone(uint32 mapid, uint32 zoneId)
{
    mapid = GetVirtualMapForMapAndZone(mapid, zoneId);
    if (mapid < 2)
        return CONTENT_1_60;

    MapEntry const* mapEntry = sMapStore.LookupEntry(mapid);
    if (!mapEntry)
        return CONTENT_1_60;

    switch (mapEntry->Expansion())
    {
        default: return CONTENT_1_60;
        case 1:  return CONTENT_61_70;
        case 2:  return CONTENT_71_80;
    }
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

    if (itemEntry->categoryType != reqEntry->categoryType)
        return false;

    return (itemEntry->categoryMask & reqEntry->categoryMask) == reqEntry->categoryMask;
}

void Zone2MapCoordinates(float& x, float& y, uint32 zone)
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(zone);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return;

    std::swap(x, y);                                         // at client map coords swapped
    x = x*((maEntry->x2-maEntry->x1)/100)+maEntry->x1;
    y = y*((maEntry->y2-maEntry->y1)/100)+maEntry->y1;      // client y coord from top to down
}

void Map2ZoneCoordinates(float& x, float& y, uint32 zone)
{
    WorldMapAreaEntry const* maEntry = sWorldMapAreaStore.LookupEntry(zone);

    // if not listed then map coordinates (instance)
    if (!maEntry)
        return;

    x = (x-maEntry->x1)/((maEntry->x2-maEntry->x1)/100);
    y = (y-maEntry->y1)/((maEntry->y2-maEntry->y1)/100);    // client y coord from top to down
    std::swap(x, y);                                         // client have map coords swapped
}

MapDifficulty const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty)
{
    MapDifficultyMap::const_iterator itr = sMapDifficultyMap.find(MAKE_PAIR32(mapId, difficulty));
    return itr != sMapDifficultyMap.end() ? &itr->second : nullptr;
}

MapDifficulty const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty)
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

PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level)
{
    PvPDifficultyEntry const* maxEntry = nullptr;              // used for level > max listed level case
    for (uint32 i = 0; i < sPvPDifficultyStore.GetNumRows(); ++i)
    {
        if (PvPDifficultyEntry const* entry = sPvPDifficultyStore.LookupEntry(i))
        {
            // skip unrelated and too-high brackets
            if (entry->mapId != mapid || entry->minLevel > level)
                continue;

            // exactly fit
            if (entry->maxLevel >= level)
                return entry;

            // remember for possible out-of-range case (search higher from existed)
            if (!maxEntry || maxEntry->maxLevel < entry->maxLevel)
                maxEntry = entry;
        }
    }

    return maxEntry;
}

PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id)
{
    for (uint32 i = 0; i < sPvPDifficultyStore.GetNumRows(); ++i)
        if (PvPDifficultyEntry const* entry = sPvPDifficultyStore.LookupEntry(i))
            if (entry->mapId == mapid && entry->GetBracketId() == id)
                return entry;

    return nullptr;
}

uint32 const* GetTalentTabPages(uint8 cls)
{
    return sTalentTabPages[cls];
}

uint32 GetLiquidFlags(uint32 liquidType)
{
    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquidType))
        return 1 << liq->Type;

    return 0;
}

CharacterFacialHairStylesEntry const* GetCharFacialHairEntry(uint8 race, uint8 gender, uint8 facialHairID)
{
    auto itr = sCharFacialHairMap.find(uint32(race) | uint32(gender << 8) | uint32(facialHairID << 16));
    if (itr == sCharFacialHairMap.end())
        return nullptr;

    return itr->second;
}

CharSectionsEntry const* GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color)
{
    uint32 const key = uint32(genType) | uint32(gender << 8) | uint32(race << 16);
    for (auto const& section : Trinity::Containers::MapEqualRange(sCharSectionMap, key))
    {
        if (section.second->Type == type && section.second->Color == color)
            return section.second;
    }

    return nullptr;
}

CharStartOutfitEntry const* GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender)
{
    std::map<uint32, CharStartOutfitEntry const*>::const_iterator itr = sCharStartOutfitMap.find(race | (class_ << 8) | (gender << 16));
    if (itr == sCharStartOutfitMap.end())
        return nullptr;

    return itr->second;
}

/// Returns LFGDungeonsEntry for a specific map and difficulty. Will return first found entry if multiple dungeons use the same map (such as Scarlet Monastery)
LFGDungeonsEntry const* GetLFGDungeon(uint32 mapId, Difficulty difficulty)
{
    for (uint32 i = 0; i < sLFGDungeonsStore.GetNumRows(); ++i)
    {
        LFGDungeonsEntry const* dungeon = sLFGDungeonsStore.LookupEntry(i);
        if (!dungeon)
            continue;

        if (dungeon->map == int32(mapId) && Difficulty(dungeon->difficulty) == difficulty)
            return dungeon;
    }

    return nullptr;
}

uint32 GetDefaultMapLight(uint32 mapId)
{
    for (int32 i = sLightStore.GetNumRows(); i >= 0; --i)
    {
        LightEntry const* light = sLightStore.LookupEntry(uint32(i));
        if (!light)
            continue;

        if (light->MapId == mapId && light->X == 0.0f && light->Y == 0.0f && light->Z == 0.0f)
            return light->Id;
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

    return nullptr;
}

ResponseCodes ValidateName(std::wstring const& name, LocaleConstant locale)
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

EmotesTextSoundEntry const* FindTextSoundEmoteFor(uint32 emote, uint32 race, uint32 gender)
{
    auto itr = sEmotesTextSoundMap.find(EmotesTextSoundKey(emote, race, gender));
    return itr != sEmotesTextSoundMap.end() ? itr->second : nullptr;
}
