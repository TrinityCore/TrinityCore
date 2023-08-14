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

#ifndef TRINITY_DBCSFRM_H
#define TRINITY_DBCSFRM_H

// x - skip<uint32>, X - skip<uint8>, s - char*, f - float, i - uint32, b - uint8, d - index (not included)
// n - index (included), l - bool, p - field present in sql dbc, a - field absent in sql dbc

char const Achievementfmt[] = "niixsxiixixxii";
const std::string CustomAchievementfmt = "pppaaaapapaapp";
const std::string CustomAchievementIndex = "ID";
char const AnimKitfmt[] = "nxx";
char const AchievementCriteriafmt[] = "niiiliiiisiiiiiiiiiiiii";
char const AreaTableEntryfmt[] = "niiiiiiiiiisiiiiiffiiiiiii";
char const AreaGroupEntryfmt[] = "niiiiiii";
char const AreaPOIEntryfmt[] = "nxiiiiiiiiixffixixxixx";
char const AreaTriggerEntryfmt[] = "nifffiiifffff";
char const ArmorLocationfmt[] = "nfffff";
char const AuctionHouseEntryfmt[] = "niiix";
char const BankBagSlotPricesEntryfmt[] = "ni";
char const BannedAddOnsfmt[] = "nxxxxxxxxxx";
char const BarberShopStyleEntryfmt[] = "nixxxiii";
char const BattlemasterListEntryfmt[] = "niiiiiiiiixsiiiixxxx";
char const CharStartOutfitEntryfmt[] = "dbbbXiiiiiiiiiiiiiiiiiiiiiiiixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxii";
char const CharSectionsEntryfmt[] = "diiixxxiii";
char const CharTitlesEntryfmt[] = "nxssix";
char const ChatChannelsEntryfmt[] = "nixsx";
char const ChrClassesEntryfmt[] = "nixsxxxixiiiii";
char const ChrRacesEntryfmt[] = "niixiixixxxxixsxxxxxixxx";
char const ChrClassesXPowerTypesfmt[] = "nii";
char const CinematicCameraEntryfmt[] = "nsiffff";
char const CinematicSequencesEntryfmt[] = "nxiiiiiiii";
char const CreatureDisplayInfofmt[] = "nixifxxxxxxxxxxxx";
char const CreatureDisplayInfoExtrafmt[] = "diixxxxxxxxxxxxxxxxxx";
char const CreatureModelDatafmt[] = "nisxfxxxxxxxxxxffxxxxxxxxxxxxxf";
char const CreatureFamilyfmt[] = "nfifiiiiixsx";
char const CreatureSpellDatafmt[] = "niiiixxxx";
char const CreatureTypefmt[] = "nxx";
char const CurrencyTypesfmt[] = "nixxxxiiiix";
char const DestructibleModelDatafmt[] = "ixxixxxixxxixxxixxxxxxxx";
char const DungeonEncounterfmt[] = "niixisxx";
char const DurabilityCostsfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const DurabilityQualityfmt[] = "nf";
char const EmotesEntryfmt[] = "nxxiiixx";
char const EmotesTextEntryfmt[] = "nxixxxxxxxxxxxxxxxx";
char const EmotesTextSoundEntryfmt[] = "niiii";
char const FactionEntryfmt[] = "niiiiiiiiiiiiiiiiiiffiisxi";
char const FactionTemplateEntryfmt[] = "niiiiiiiiiiiii";
char const GameObjectArtKitfmt[] = "nxxxxxxx";
char const GameObjectDisplayInfofmt[] = "nsxxxxxxxxxxffffffxxx";
char const GemPropertiesEntryfmt[] = "nixxii";
char const GlyphPropertiesfmt[] = "niii";
char const GlyphSlotfmt[] = "nii";
char const GtBarberShopCostBasefmt[] = "xf";
char const GtCombatRatingsfmt[] = "xf";
char const GtOCTHpPerStaminafmt[] = "df";
char const GtChanceToMeleeCritBasefmt[] = "xf";
char const GtChanceToMeleeCritfmt[] = "xf";
char const GtChanceToSpellCritBasefmt[] = "xf";
char const GtChanceToSpellCritfmt[] = "xf";
char const GtNPCManaCostScalerfmt[] = "xf";
char const GtOCTClassCombatRatingScalarfmt[] = "df";
char const GtOCTRegenHPfmt[] = "f";
//char const GtOCTRegenMPfmt[] = "f";
char const GtRegenMPPerSptfmt[] = "xf";
char const GtSpellScalingfmt[] = "df";
char const GtOCTBaseHPByClassfmt[] = "df";
char const GtOCTBaseMPByClassfmt[] = "df";
char const GuildPerkSpellsfmt[] = "dii";
char const Holidaysfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiixxsiix";
char const ImportPriceArmorfmt[] = "nffff";
char const ImportPriceQualityfmt[] = "nf";
char const ImportPriceShieldfmt[] = "nf";
char const ImportPriceWeaponfmt[] = "nf";
char const ItemPriceBasefmt[] = "diff";
char const ItemReforgefmt[] = "nifif";
char const ItemBagFamilyfmt[] = "nx";
char const ItemArmorQualityfmt[] = "nfffffffi";
char const ItemArmorShieldfmt[] = "nifffffff";
char const ItemArmorTotalfmt[] = "niffff";
char const ItemClassfmt[] = "dixxfx";
char const ItemDamagefmt[] = "nfffffffi";
char const ItemDisenchantLootfmt[] = "niiiiii";
//char const ItemDisplayTemplateEntryfmt[] = "nxxxxxxxxxxixxxxxxxxxxx";
char const ItemLimitCategoryEntryfmt[] = "nxii";
char const ItemRandomPropertiesfmt[] = "nxiiiiis";
char const ItemRandomSuffixfmt[] = "nsxiiiiiiiiii";
char const ItemSetEntryfmt[] = "dsiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const LFGDungeonEntryfmt[] = "nsiiiiiiiiixxixixiiii";
char const LFGDungeonsGroupingMapfmt[] = "niii";
char const LightEntryfmt[] = "nifffxxxxxxxxxx";
char const LiquidTypefmt[] = "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const LockEntryfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiixxxxxxxx";
char const PhaseEntryfmt[] = "nsi";
char const PhaseGroupfmt[] = "nii";
char const MailTemplateEntryfmt[] = "nxs";
char const MapEntryfmt[] = "nsiiiisissififfiiiii";
char const MapDifficultyEntryfmt[] = "diisiix";
char const MovieEntryfmt[] = "nxxx";
char const NamesProfanityEntryfmt[] = "dsi";
char const NamesReservedEntryfmt[] = "dsi";
char const MountCapabilityfmt[] = "niiiiiii";
char const MountTypefmt[] = "niiiiiiiiiiiiiiiiiiiiiiii";
char const NameGenfmt[] = "dsii";
char const NumTalentsAtLevelfmt[] = "df";
char const OverrideSpellDatafmt[] = "niiiiiiiiiixx";
char const QuestFactionRewardfmt[] = "niiiiiiiiii";
const char QuestPOIBlobfmt[] = "niii";
const char QuestPOIPointfmt[] = "niii";
char const QuestSortEntryfmt[] = "nx";
char const QuestXPfmt[] = "niiiiiiiiii";
char const PlayerConditionfmt[] = "ns";
const std::string CustomPlayerConditionEntryfmt = "pa";
const std::string CustomPlayerConditionEntryIndex = "ID";
char const PowerDisplayfmt[] = "nixxxx";
char const PvPDifficultyfmt[] = "diiiii";
char const RandomPropertiesPointsfmt[] = "niiiiiiiiiiiiiii";
char const ResearchBranchEntryfmt[] = "nsiisi";
char const ResearchFieldEntryfmt[] = "nsi";
char const ResearchProjectEntryfmt[] = "nssiiiisi";
char const ResearchSiteEntryfmt[] = "niiss";
char const ScalingStatDistributionfmt[] = "niiiiiiiiiiiiiiiiiiiiii";
char const ScalingStatValuesfmt[] = "iniiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const SkillLinefmt[] = "nisxixi";
char const SkillLineAbilityfmt[] = "niiiixxiiiiiii";
char const SkillRaceClassInfofmt[] = "diiiiixix";
char const SkillTiersfmt[] = "nxxxxxxxxxxxxxxxxiiiiiiiiiiiiiiii";
char const SoundEntriesfmt[] = "nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const SpellCastTimefmt[] = "nixx";
char const SpellCategoriesEntryfmt[] = "diiiiii";
char const SpellCategoryfmt[] = "niix";
char const SpellDifficultyfmt[] = "niiii";
const std::string CustomSpellDifficultyfmt = "ppppp";
const std::string CustomSpellDifficultyIndex = "id";
char const SpellDurationfmt[] = "niii";
//                                             0         10        20    26
char const SpellEffectEntryfmt[] =            "nifiiiffiiiiiifiifiiiiiiiix";
const std::string CustomSpellEffectEntryfmt = "ppppppppppppppppppppppppppa";
const std::string CustomSpellEffectEntryIndex = "Id";
//                                       0         10        20        30        40     47
char const SpellEntryfmt[] =            "niiiiiiiiiiiiiiifiiiissxxiixxifiiiiiiixiiiiiiiii";
const std::string CustomSpellEntryfmt = "ppppppppppppppapaaaaaaaaapaaaaaapapppaapppaaapaa";
const std::string CustomSpellEntryIndex = "Id";
char const SpellFocusObjectfmt[] = "nx";
char const SpellItemEnchantmentfmt[] = "nxiiiiiixxxiiisiiiiiiix";
char const SpellItemEnchantmentConditionfmt[] = "nbbbXxxxxxxbbbXXbbbxiiixxXXXXXX";
char const SpellRadiusfmt[] = "nfff";
char const SpellRangefmt[] = "nffffixx";
char const SpellReagentsEntryfmt[] = "diiiiiiiiiiiiiiii";
char const SpellScalingEntryfmt[] = "diiiiffffffffffi";
char const SpellTotemsEntryfmt[] = "niiii";
char const SpellTargetRestrictionsEntryfmt[] = "nfiiii";
char const SpellPowerEntryfmt[] = "diiiixxf";
char const SpellInterruptsEntryfmt[] = "diiiii";
char const SpellEquippedItemsEntryfmt[] = "diii";
char const SpellAuraOptionsEntryfmt[] = "niiii";
char const SpellAuraRestrictionsEntryfmt[] = "diiiiiiii";
char const SpellCastingRequirementsEntryfmt[] = "niiiiii";
char const SpellClassOptionsEntryfmt[] = "dxiiiix";
char const SpellCooldownsEntryfmt[] = "diii";
char const SpellLevelsEntryfmt[] = "diii";
char const SpellRuneCostfmt[] = "niiii";
char const SpellShapeshiftEntryfmt[] = "niiiix";
char const SpellShapeshiftFormfmt[] = "nxxiixiiiiiiiiiiiiiix";
char const SpellVisualfmt[] = "dxxxxxxiixxxxxxxxxxxxxxxxxxxxxxxi";
char const SpellVisualKitfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const StableSlotPricesfmt[] = "ni";
char const SummonPropertiesfmt[] = "niiiii";
char const TalentEntryfmt[] = "niiiiiiiiiiiiiixxxx";
char const TalentTabEntryfmt[] = "nxxiiixxxii";
char const TalentTreePrimarySpellsfmt[] = "diix";
char const TaxiNodesEntryfmt[] = "nifffsiiiff";
char const TaxiPathEntryfmt[] = "niii";
char const TaxiPathNodeEntryfmt[] = "diiifffiiii";
char const TotemCategoryEntryfmt[] = "nxii";
char const UnitPowerBarfmt[] = "niiixffxxxxxxxxxxxxxxxxxxxx";
char const TransportAnimationfmt[] = "diifffx";
char const TransportRotationfmt[] = "diiffff";
char const VehicleEntryfmt[] = "niffffiiiiiiiifffffffffffffffssssfifiiii";
char const VehicleSeatEntryfmt[] = "niiffffffffffiiiiiifffffffiiifffiiiiiiiffiiiiiffffffffffffiiiiiiii";
char const WMOAreaTableEntryfmt[] = "niiixxxxxiixxxx";
char const WorldMapAreaEntryfmt[] = "xinxffffixxxxi";
char const WorldMapOverlayEntryfmt[] = "nxiiiixxxxxxxxx";
char const WorldSafeLocsEntryfmt[] = "nifffx";

#endif
