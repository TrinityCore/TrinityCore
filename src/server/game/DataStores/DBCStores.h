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

#ifndef TRINITY_DBCSTORES_H
#define TRINITY_DBCSTORES_H

#include "DBCStore.h"
#include "DBCStructure.h"
#include "SharedDefines.h"
#include <list>
#include <map>
#include <unordered_map>

enum LocaleConstant : uint8;

 // temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

typedef std::list<uint32> SimpleFactionsList;
TC_GAME_API SimpleFactionsList const* GetFactionTeamList(uint32 faction);

TC_GAME_API char* GetPetName(uint32 petfamily, uint32 dbclang);
TC_GAME_API uint32 GetTalentSpellCost(uint32 spellId);
TC_GAME_API TalentSpellPos const* GetTalentSpellPos(uint32 spellId);

TC_GAME_API char const* GetRaceName(uint8 race, uint8 locale);
TC_GAME_API char const* GetClassName(uint8 class_, uint8 locale);

TC_GAME_API WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid);

TC_GAME_API uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId);

enum ContentLevels : uint8
{
    CONTENT_1_60 = 0,
    CONTENT_61_70,
    CONTENT_71_80
};
TC_GAME_API ContentLevels GetContentLevelsForMapAndZone(uint32 mapid, uint32 zoneId);

TC_GAME_API bool IsTotemCategoryCompatiableWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId);

TC_GAME_API void Zone2MapCoordinates(float &x, float &y, uint32 zone);
TC_GAME_API void Map2ZoneCoordinates(float &x, float &y, uint32 zone);

typedef std::map<uint32/*pair32(map, diff)*/, MapDifficulty> MapDifficultyMap;
TC_GAME_API MapDifficulty const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty);
TC_GAME_API MapDifficulty const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty);

TC_GAME_API uint32 const* /*[MAX_TALENT_TABS]*/ GetTalentTabPages(uint8 cls);

TC_GAME_API uint32 GetLiquidFlags(uint32 liquidType);

TC_GAME_API PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level);
TC_GAME_API PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id);

TC_GAME_API CharacterFacialHairStylesEntry const* GetCharFacialHairEntry(uint8 race, uint8 gender, uint8 facialHairID);
TC_GAME_API CharSectionsEntry const* GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color);
TC_GAME_API CharStartOutfitEntry const* GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender);

TC_GAME_API LFGDungeonsEntry const* GetLFGDungeon(uint32 mapId, Difficulty difficulty);

TC_GAME_API uint32 GetDefaultMapLight(uint32 mapId);

typedef std::unordered_multimap<uint32, SkillRaceClassInfoEntry const*> SkillRaceClassInfoMap;
typedef std::pair<SkillRaceClassInfoMap::iterator, SkillRaceClassInfoMap::iterator> SkillRaceClassInfoBounds;
TC_GAME_API SkillRaceClassInfoEntry const* GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_);

TC_GAME_API ResponseCodes ValidateName(std::wstring const& name, LocaleConstant locale);

TC_GAME_API EmotesTextSoundEntry const* FindTextSoundEmoteFor(uint32 emote, uint32 race, uint32 gender);

#define DECLARE_DBC_STORAGE(dbc) TC_GAME_API extern DBCStorage <dbc ## Entry> s ## dbc ## Store;

DECLARE_DBC_STORAGE(Achievement);
DECLARE_DBC_STORAGE(AchievementCriteria);
DECLARE_DBC_STORAGE(AreaTable);
DECLARE_DBC_STORAGE(AreaGroup);
DECLARE_DBC_STORAGE(AreaPOI);
DECLARE_DBC_STORAGE(AreaTrigger);
DECLARE_DBC_STORAGE(AuctionHouse);
DECLARE_DBC_STORAGE(BankBagSlotPrices);
DECLARE_DBC_STORAGE(BannedAddOns);
DECLARE_DBC_STORAGE(BarberShopStyle);
DECLARE_DBC_STORAGE(BattlemasterList);
DECLARE_DBC_STORAGE(ChatChannels);
DECLARE_DBC_STORAGE(CharacterFacialHairStyles);
DECLARE_DBC_STORAGE(CharSections);
DECLARE_DBC_STORAGE(CharStartOutfit);
DECLARE_DBC_STORAGE(CharTitles);
DECLARE_DBC_STORAGE(ChrClasses);
DECLARE_DBC_STORAGE(ChrRaces);
DECLARE_DBC_STORAGE(CinematicCamera);
DECLARE_DBC_STORAGE(CinematicSequences);
DECLARE_DBC_STORAGE(CreatureDisplayInfo);
DECLARE_DBC_STORAGE(CreatureDisplayInfoExtra);
DECLARE_DBC_STORAGE(CreatureFamily);
DECLARE_DBC_STORAGE(CreatureModelData);
DECLARE_DBC_STORAGE(CreatureSpellData);
DECLARE_DBC_STORAGE(CreatureType);
DECLARE_DBC_STORAGE(CurrencyTypes);
DECLARE_DBC_STORAGE(DestructibleModelData);
DECLARE_DBC_STORAGE(DungeonEncounter);
DECLARE_DBC_STORAGE(DurabilityCosts);
DECLARE_DBC_STORAGE(DurabilityQuality);
DECLARE_DBC_STORAGE(Emotes);
DECLARE_DBC_STORAGE(EmotesText);
DECLARE_DBC_STORAGE(EmotesTextSound);
DECLARE_DBC_STORAGE(Faction);
DECLARE_DBC_STORAGE(FactionTemplate);
DECLARE_DBC_STORAGE(GameObjectDisplayInfo);
DECLARE_DBC_STORAGE(GemProperties);
DECLARE_DBC_STORAGE(GlyphProperties);
DECLARE_DBC_STORAGE(GlyphSlot);

DECLARE_DBC_STORAGE(gtBarberShopCostBase);
DECLARE_DBC_STORAGE(gtCombatRatings);
DECLARE_DBC_STORAGE(gtChanceToMeleeCritBase);
DECLARE_DBC_STORAGE(gtChanceToMeleeCrit);
DECLARE_DBC_STORAGE(gtChanceToSpellCritBase);
DECLARE_DBC_STORAGE(gtChanceToSpellCrit);
DECLARE_DBC_STORAGE(gtNPCManaCostScaler);
DECLARE_DBC_STORAGE(gtOCTClassCombatRatingScalar);
DECLARE_DBC_STORAGE(gtOCTRegenHP);
//DECLARE_DBC_STORAGE(gtOCTRegenMP);
DECLARE_DBC_STORAGE(gtRegenHPPerSpt);
DECLARE_DBC_STORAGE(gtRegenMPPerSpt);
DECLARE_DBC_STORAGE(Holidays);
DECLARE_DBC_STORAGE(Item);
DECLARE_DBC_STORAGE(ItemBagFamily);
//DECLARE_DBC_STORAGE(ItemDisplayInfo);
DECLARE_DBC_STORAGE(ItemExtendedCost);
DECLARE_DBC_STORAGE(ItemLimitCategory);
DECLARE_DBC_STORAGE(ItemRandomProperties);
DECLARE_DBC_STORAGE(ItemRandomSuffix);
DECLARE_DBC_STORAGE(ItemSet);
DECLARE_DBC_STORAGE(LFGDungeons);
DECLARE_DBC_STORAGE(LiquidType);
DECLARE_DBC_STORAGE(Lock);
DECLARE_DBC_STORAGE(MailTemplate);
DECLARE_DBC_STORAGE(Map);
//DECLARE_DBC_STORAGE(MapDifficulty);
TC_GAME_API extern MapDifficultyMap                          sMapDifficultyMap;
DECLARE_DBC_STORAGE(Movie);
DECLARE_DBC_STORAGE(OverrideSpellData);
DECLARE_DBC_STORAGE(PowerDisplay);
DECLARE_DBC_STORAGE(QuestSort);
DECLARE_DBC_STORAGE(QuestXP);
DECLARE_DBC_STORAGE(QuestFactionReward);
DECLARE_DBC_STORAGE(RandomPropertiesPoints);
DECLARE_DBC_STORAGE(ScalingStatDistribution);
DECLARE_DBC_STORAGE(ScalingStatValues);
DECLARE_DBC_STORAGE(SkillLine);
DECLARE_DBC_STORAGE(SkillLineAbility);
DECLARE_DBC_STORAGE(SkillTiers);
DECLARE_DBC_STORAGE(SoundEntries);
DECLARE_DBC_STORAGE(SpellCastTimes);
DECLARE_DBC_STORAGE(SpellCategory);
DECLARE_DBC_STORAGE(SpellDifficulty);
DECLARE_DBC_STORAGE(SpellDuration);
DECLARE_DBC_STORAGE(SpellFocusObject);
DECLARE_DBC_STORAGE(SpellItemEnchantment);
DECLARE_DBC_STORAGE(SpellItemEnchantmentCondition);
TC_GAME_API extern PetFamilySpellsStore                      sPetFamilySpellsStore;
DECLARE_DBC_STORAGE(SpellRadius);
DECLARE_DBC_STORAGE(SpellRange);
DECLARE_DBC_STORAGE(SpellRuneCost);
DECLARE_DBC_STORAGE(SpellShapeshift);
DECLARE_DBC_STORAGE(Spell);
DECLARE_DBC_STORAGE(StableSlotPrices);
DECLARE_DBC_STORAGE(SummonProperties);
DECLARE_DBC_STORAGE(Talent);
DECLARE_DBC_STORAGE(TalentTab);
DECLARE_DBC_STORAGE(TaxiNodes);
DECLARE_DBC_STORAGE(TaxiPath);
TC_GAME_API extern TaxiMask                                  sTaxiNodesMask;
TC_GAME_API extern TaxiMask                                  sOldContinentsNodesMask;
TC_GAME_API extern TaxiMask                                  sHordeTaxiNodesMask;
TC_GAME_API extern TaxiMask                                  sAllianceTaxiNodesMask;
TC_GAME_API extern TaxiMask                                  sDeathKnightTaxiNodesMask;
TC_GAME_API extern TaxiPathSetBySource                       sTaxiPathSetBySource;
TC_GAME_API extern TaxiPathNodesByPath                       sTaxiPathNodesByPath;
DECLARE_DBC_STORAGE(TransportAnimation);
DECLARE_DBC_STORAGE(TransportRotation);
DECLARE_DBC_STORAGE(TeamContributionPoints);
DECLARE_DBC_STORAGE(TotemCategory);
DECLARE_DBC_STORAGE(Vehicle);
DECLARE_DBC_STORAGE(VehicleSeat);
DECLARE_DBC_STORAGE(WMOAreaTable);
//DECLARE_DBC_STORAGE(WorldMapArea);
DECLARE_DBC_STORAGE(WorldMapOverlay);
DECLARE_DBC_STORAGE(WorldSafeLocs);

#undef DECLARE_DBC_STORAGE

TC_GAME_API void LoadDBCStores(const std::string& dataPath);

#endif
