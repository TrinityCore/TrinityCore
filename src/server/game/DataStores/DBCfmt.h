/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_DBCSFRM_H
#define TRINITY_DBCSFRM_H

// x - skip<uint32>, X - skip<uint8>, s - char*, f - float, i - uint32, b - uint8, d - index (not included)
// n - index (included), l - bool, p - field present in sql dbc, a - field absent in sql dbc

char const Achievementfmt[] = "niixsxiixixxiix";
const std::string CustomAchievementfmt = "pppaaaapapaapp";
const std::string CustomAchievementIndex = "ID";
char const AchievementCriteriafmt[] = "niiiliiiisiiiiixxiiiiii";
char const AreaTableEntryfmt[] = "iiinixxxxxisiiiiiffixxxxxx";
char const AreaGroupEntryfmt[] = "niiiiiii";
char const AreaTriggerEntryfmt[] = "nifffxxxfffffxxxx";
char const ArmorLocationfmt[] = "nfffff";
char const AuctionHouseEntryfmt[] = "niiix";
char const BankBagSlotPricesEntryfmt[] = "ni";
char const BannedAddOnsfmt[] = "nxxxxxxxxxx";
char const BarberShopStyleEntryfmt[] = "nixxxiii";
char const BattlemasterListEntryfmt[] = "niiiiiiiiiiiiiiiiixsiiiixxxxxxx";
char const CharStartOutfitEntryfmt[] = "dbbbXiiiiiiiiiiiiiiiiiiiiiiiixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxii";
char const CharTitlesEntryfmt[] = "nxssix";
char const ChatChannelsEntryfmt[] = "nixsx";
char const ChrClassesEntryfmt[] = "nixsxxxixiiiixxxxxx";
char const ChrRacesEntryfmt[] = "niixiixxxxxxiisxxxxxxxxxxxxxxxxxxxxxxxxx";
char const ChrClassesXPowerTypesfmt[] = "nii";
char const ChrSpecializationEntryfmt[] = "nxiiiiiiiiixxxii";
char const CinematicSequencesEntryfmt[] = "nxxxxxxxxx";
char const CreatureDisplayInfofmt[] = "nixifxxxxxxxxxxxxxxxx";
char const CreatureDisplayInfoExtrafmt[] = "dixxxxxxxxxxxxxxxxxxx";
char const CreatureFamilyfmt[] = "nfifiiiiixsx";
char const CreatureModelDatafmt[] = "nixxxxxxxxxxxxxffxxxxxxxxxxxxxxxxx";
char const CreatureSpellDatafmt[] = "niiiixxxx";
char const CreatureTypefmt[] = "nxx";
char const CurrencyTypesfmt[] = "nixxxxxiiixx";
char const DestructibleModelDatafmt[] = "nixxxixxxxixxxxixxxxxxxx";
char const DungeonEncounterfmt[] = "niiixsxx";
char const DurabilityCostsfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const DurabilityQualityfmt[] = "nf";
char const EmotesEntryfmt[] = "nxxiiixx";
char const EmotesTextEntryfmt[] = "nxixxxxxxxxxxxxxxxx";
char const FactionEntryfmt[] = "niiiiiiiiiiiiiiiiiiffixsxixx";
char const FactionTemplateEntryfmt[] = "niiiiiiiiiiiii";
char const GameObjectDisplayInfofmt[] = "nixxxxxxxxxxffffffxxx";
char const GemPropertiesEntryfmt[] = "nixxii";
char const GlyphPropertiesfmt[] = "niiix";
char const GlyphSlotfmt[] = "nix";
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
char const ItemClassfmt[] = "nxfx";
char const ItemDamagefmt[] = "nfffffffi";
char const ItemDisenchantLootfmt[] = "niiiiii";
//char const ItemDisplayTemplateEntryfmt[] = "nxxxxxxxxxxixxxxxxxxxxx";
char const ItemLimitCategoryEntryfmt[] = "nxii";
char const ItemRandomPropertiesfmt[] = "nxiiiiis";
char const ItemRandomSuffixfmt[] = "nsxiiiiiiiiii";
char const ItemSetEntryfmt[] = "nsiiiiiiiiiiiiiiiiiii";
char const ItemSetSpellEntryfmt[] = "niiii";
char const LFGDungeonEntryfmt[] = "nsiiixxiiiixxixixxxxxxxxxx";
char const LightEntryfmt[] = "nifffxxxxxxxxxxxxx";
char const LiquidTypefmt[] = "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const LockEntryfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiixxxxxxxx";
char const PhaseEntryfmt[] = "nsi";
char const PhaseGroupfmt[] = "nii";
char const MailTemplateEntryfmt[] = "nxs";
char const MapEntryfmt[] = "nxiixxsixxixiffxiiiixx";
char const MapDifficultyEntryfmt[] = "diisiix";
char const MovieEntryfmt[] = "nxxxx";
char const MountCapabilityfmt[] = "niiiiiii";
char const MountTypefmt[] = "niiiiiiiiiiiiiiiiiiiiiiii";
char const NameGenfmt[] = "dsii";
char const NumTalentsAtLevelfmt[] = "df";
char const OverrideSpellDatafmt[] = "niiiiiiiiiixx";
char const QuestFactionRewardfmt[] = "niiiiiiiiii";
char const QuestSortEntryfmt[] = "nx";
char const QuestXPfmt[] = "niiiiiiiiii";
char const PowerDisplayfmt[] = "nixXXX";
char const PvPDifficultyfmt[] = "diiii";
char const RandomPropertiesPointsfmt[] = "niiiiiiiiiiiiiii";
char const ScalingStatDistributionfmt[] = "niiiiiiiiiiiiiiiiiiiixi";
char const ScalingStatValuesfmt[] = "iniiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const SkillLinefmt[] = "nisxixixx";
char const SkillLineAbilityfmt[] = "niiiiiiiiiiii";
char const SkillRaceClassInfofmt[] = "diiiixxi";
char const SkillTiersfmt[] = "niiiiiiiiiiiiiiii";
char const SoundEntriesfmt[] = "nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const SpecializationSpellsEntryfmt[] = "niiix";
char const SpellCastTimefmt[] = "nixx";
char const SpellCategoriesEntryfmt[] = "diiiiiiiix";
char const SpellCategoryfmt[] = "nixxxx";
char const SpellDurationfmt[] = "niii";
char const SpellEffectEntryfmt[] =            "niifiiiffiiiiiifiifiiiiifiiiiif";
const std::string CustomSpellEffectEntryfmt = "ppppppppppppppappppppppppp";
const std::string CustomSpellEffectEntryIndex = "Id";
char const SpellEntryfmt[] = "nsxxxiiiiiiiiiiiiiiiiiii";
const std::string CustomSpellEntryfmt = "ppppppppppppppapaaaaaaaaapaaaaaapapppaapppaaapa";
const std::string CustomSpellEntryIndex = "Id";
char const SpellFocusObjectfmt[] = "nx";
char const SpellItemEnchantmentfmt[] = "niiiiiiiiiiiiiiiixiiiiiiiiiiiiiiif";
char const SpellItemEnchantmentConditionfmt[] = "nbbbbbXXXiiiiibbbbbbbbbbXXiiiiibbbbbXXX";
char const SpellRadiusfmt[] = "nxfff";
char const SpellRangefmt[] = "nffffixx";
char const SpellScalingEntryfmt[] = "niiiifiii";
char const SpellTotemsEntryfmt[] = "niiii";
char const SpellTargetRestrictionsEntryfmt[] = "niiffiiii";
char const SpellPowerEntryfmt[] = "diiiiixf";
char const SpellInterruptsEntryfmt[] = "diiiiiii";
char const SpellEquippedItemsEntryfmt[] = "diiiii";
char const SpellAuraOptionsEntryfmt[] = "niiiiiiii";
char const SpellCastingRequirementsEntryfmt[] = "dixxixi";
char const SpellCooldownsEntryfmt[] = "diiiii";
char const SpellLevelsEntryfmt[] = "diiiii";
char const SpellShapeshiftEntryfmt[] = "niiiix";
char const SpellShapeshiftFormfmt[] = "nxxiixiiiiiiiiiiiiixx";
char const StableSlotPricesfmt[] = "ni";
char const SummonPropertiesfmt[] = "niiiii";
char const TalentEntryfmt[] = "niiiiiiiiixxixxxxxx";
char const TalentTabEntryfmt[] = "nxxiiixxxii";
char const TalentTreePrimarySpellsfmt[] = "diix";
char const TaxiNodesEntryfmt[] = "nifffsiiixx";
char const TaxiPathEntryfmt[] = "niii";
char const TaxiPathNodeEntryfmt[] = "diiifffiiii";
char const TotemCategoryEntryfmt[] = "nxii";
char const UnitPowerBarfmt[] = "niixxxxxxxxxxxxxxxxxxxxxxxx";
char const TransportAnimationfmt[] = "diifffx";
char const TransportRotationfmt[] = "diiffff";
char const VehicleEntryfmt[] = "niffffiiiiiiiifffffffffffffffssssfifiixx";
char const VehicleSeatEntryfmt[] = "niiffffffffffiiiiiifffffffiiifffiiiiiiiffiiiiixxxxxxxxxxxxxxxxxxxx";
char const WMOAreaTableEntryfmt[] = "niiixxxxxiixxxx";
char const WorldMapAreaEntryfmt[] = "xinxffffixxxxx";
char const WorldMapOverlayEntryfmt[] = "nxiiiixxxxxxxxx";
char const WorldSafeLocsEntryfmt[] = "niffff";

#endif
