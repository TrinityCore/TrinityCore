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

char const Achievementfmt[] = "niixssssssssssssssssxxxxxxxxxxxxxxxxxxiixixxxxxxxxxxxxxxxxxxii";
const std::string CustomAchievementfmt = "pppaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaapapaaaaaaaaaaaaaaaaaapp";
const std::string CustomAchievementIndex = "ID";
char const AchievementCriteriafmt[] = "niiiiiiiixxxxxxxxxxxxxxxxxiiiix";
char const AreaTableEntryfmt[] = "iiinixxxxxissssssssssssssssxiiiiixxx";
char const AreaGroupEntryfmt[] = "niiiiiii";
char const AreaPOIEntryfmt[] = "niiiiiiiiiiifffixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxix";
char const AreaTriggerEntryfmt[] = "niffffffff";
char const AuctionHouseEntryfmt[] = "niiixxxxxxxxxxxxxxxxx";
char const BankBagSlotPricesEntryfmt[] = "ni";
char const BannedAddOnsfmt[] = "nxxxxxxxxxx";
char const BarberShopStyleEntryfmt[] = "nixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiii";
char const BattlemasterListEntryfmt[] = "niiiiiiiiixssssssssssssssssxiixx";
char const CharStartOutfitEntryfmt[] = "dbbbXiiiiiiiiiiiiiiiiiiiiiiiixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const CharTitlesEntryfmt[] = "nxssssssssssssssssxssssssssssssssssxi";
char const ChatChannelsEntryfmt[] = "nixssssssssssssssssxxxxxxxxxxxxxxxxxx";
char const ChrClassesEntryfmt[] = "nxixssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixii";
char const ChrRacesEntryfmt[] = "niixiixixxxxixssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxi";
char const CinematicSequencesEntryfmt[] = "nxxxxxxxxx";
char const CreatureDisplayInfofmt[] = "nixifxxxxxxxxxxx";
char const CreatureDisplayInfoExtrafmt[] = "diixxxxxxxxxxxxxxxxxx";
char const CreatureFamilyfmt[] = "nfifiiiiixssssssssssssssssxx";
char const CreatureModelDatafmt[] = "nixxfxxxxxxxxxxffxxxxxxxxxxx";
char const CreatureSpellDatafmt[] = "niiiixxxx";
char const CreatureTypefmt[] = "nxxxxxxxxxxxxxxxxxx";
char const CurrencyTypesfmt[] = "xnxi";
char const DestructibleModelDatafmt[] = "nxxixxxixxxixxxixxx";
char const DungeonEncounterfmt[] = "niixissssssssssssssssxx";
char const DurabilityCostsfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const DurabilityQualityfmt[] = "nf";
char const EmotesEntryfmt[] = "nxxiiix";
char const EmotesTextEntryfmt[] = "nxixxxxxxxxxxxxxxxx";
char const FactionEntryfmt[] = "niiiiiiiiiiiiiiiiiiffixssssssssssssssssxxxxxxxxxxxxxxxxxx";
char const FactionTemplateEntryfmt[] = "niiiiiiiiiiiii";
char const GameObjectDisplayInfofmt[] = "nsxxxxxxxxxxffffffx";
char const GemPropertiesEntryfmt[] = "nixxi";
char const GlyphPropertiesfmt[] = "niii";
char const GlyphSlotfmt[] = "nii";
char const GtBarberShopCostBasefmt[] = "f";
char const GtCombatRatingsfmt[] = "f";
char const GtChanceToMeleeCritBasefmt[] = "f";
char const GtChanceToMeleeCritfmt[] = "f";
char const GtChanceToSpellCritBasefmt[] = "f";
char const GtChanceToSpellCritfmt[] = "f";
char const GtNPCManaCostScalerfmt[] = "f";
char const GtOCTClassCombatRatingScalarfmt[] = "df";
char const GtOCTRegenHPfmt[] = "f";
//char const GtOCTRegenMPfmt[] = "f";
char const GtRegenHPPerSptfmt[] = "f";
char const GtRegenMPPerSptfmt[] = "f";
char const Holidaysfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiixxsiix";
char const Itemfmt[] = "niiiiiii";
char const ItemBagFamilyfmt[] = "nxxxxxxxxxxxxxxxxx";
//char const ItemDisplayTemplateEntryfmt[] = "nxxxxxxxxxxixxxxxxxxxxx";
//char const ItemCondExtCostsEntryfmt[] = "xiii";
char const ItemExtendedCostEntryfmt[] = "niiiiiiiiiiiiiix";
char const ItemLimitCategoryEntryfmt[] = "nxxxxxxxxxxxxxxxxxii";
char const ItemRandomPropertiesfmt[] = "nxiiixxssssssssssssssssx";
char const ItemRandomSuffixfmt[] = "nssssssssssssssssxxiiixxiiixx";
char const ItemSetEntryfmt[] = "dssssssssssssssssxiiiiiiiiiixxxxxxxiiiiiiiiiiiiiiiiii";
char const LFGDungeonEntryfmt[] = "nssssssssssssssssxiiiiiiiiixxixixxxxxxxxxxxxxxxxx";
char const LightEntryfmt[] = "nifffxxxxxxxxxx";
char const LiquidTypefmt[] = "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const LockEntryfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiixxxxxxxx";
char const MailTemplateEntryfmt[] = "nxxxxxxxxxxxxxxxxxssssssssssssssssx";
char const MapEntryfmt[] = "nxiixssssssssssssssssxixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixiffxiii";
char const MapDifficultyEntryfmt[] = "diisxxxxxxxxxxxxxxxxiix";
char const MovieEntryfmt[] = "nxx";
char const OverrideSpellDatafmt[] = "niiiiiiiiiix";
char const QuestFactionRewardfmt[] = "niiiiiiiiii";
char const QuestSortEntryfmt[] = "nxxxxxxxxxxxxxxxxx";
char const QuestXPfmt[] = "niiiiiiiiii";
char const PowerDisplayfmt[] = "nixxxx";
char const PvPDifficultyfmt[] = "diiiii";
char const RandomPropertiesPointsfmt[] = "niiiiiiiiiiiiiii";
char const ScalingStatDistributionfmt[] = "niiiiiiiiiiiiiiiiiiiii";
char const ScalingStatValuesfmt[] = "iniiiiiiiiiiiiiiiiiiiiii";
char const SkillLinefmt[] = "nixssssssssssssssssxxxxxxxxxxxxxxxxxxixxxxxxxxxxxxxxxxxi";
char const SkillLineAbilityfmt[] = "niiiixxiiiiixx";
char const SkillRaceClassInfofmt[] = "diiiixix";
char const SkillTiersfmt[] = "nxxxxxxxxxxxxxxxxiiiiiiiiiiiiiiii";
char const SoundEntriesfmt[] = "nxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const SpellCastTimefmt[] = "nixx";
char const SpellCategoryfmt[] = "ni";
char const SpellDifficultyfmt[] = "niiii";
const std::string CustomSpellDifficultyfmt = "ppppp";
const std::string CustomSpellDifficultyIndex = "id";
char const SpellDurationfmt[] = "niii";
char const SpellEntryfmt[] = "niiiiiiiiiiiixixiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiifxiiiiiiiiiiiiiiiiiiiiiiiiiiiifffiiiiiiiiiiiiiiiiiiiiifffiiiiiiiiiiiiiiifffiiiiiiiiiiiiixssssssssssssssssxssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiiiiiiiiiiixfffxxxiiiiixxfffxx";
const std::string CustomSpellEntryfmt = "papppppppppppapapaaaaaaaaaaapaaapapppppppaaaaapaapaaaaaaaaaaaaaaaaaappppppppppppppppppppppppppppppppppppaaappppppppppppaaapppppppppaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaappppppppapppaaaaappaaaaaaa";
const std::string CustomSpellEntryIndex = "Id";
char const SpellFocusObjectfmt[] = "nxxxxxxxxxxxxxxxxx";
char const SpellItemEnchantmentfmt[] = "nxiiiiiixxxiiissssssssssssssssxiiiiiii";
char const SpellItemEnchantmentConditionfmt[] = "nbbbbbxxxxxbbbbbbbbbbiiiiiXXXXX";
char const SpellRadiusfmt[] = "nfff";
char const SpellRangefmt[] = "nffffixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const SpellRuneCostfmt[] = "niiii";
char const SpellShapeshiftfmt[] = "nxxxxxxxxxxxxxxxxxxiixiiixxiiiiiiii";
char const StableSlotPricesfmt[] = "ni";
char const SummonPropertiesfmt[] = "niiiii";
char const TalentEntryfmt[] = "niiiiiiiixxxxixxixxxxxx";
char const TalentTabEntryfmt[] = "nxxxxxxxxxxxxxxxxxxxiiix";
char const TaxiNodesEntryfmt[] = "nifffssssssssssssssssxii";
char const TaxiPathEntryfmt[] = "niii";
char const TaxiPathNodeEntryfmt[] = "diiifffiiii";
char const TeamContributionPointsfmt[] = "df";
char const TotemCategoryEntryfmt[] = "nxxxxxxxxxxxxxxxxxii";
char const TransportAnimationfmt[] = "diifffx";
char const TransportRotationfmt[] = "diiffff";
char const VehicleEntryfmt[] = "niffffiiiiiiiifffffffffffffffssssfifiixx";
char const VehicleSeatEntryfmt[] = "niiffffffffffiiiiiifffffffiiifffiiiiiiiffiiiiixxxxxxxxxxxx";
char const WMOAreaTableEntryfmt[] = "niiixxxxxiixxxxxxxxxxxxxxxxx";
char const WorldMapAreaEntryfmt[] = "xinxffffixx";
char const WorldMapOverlayEntryfmt[] = "nxiiiixxxxxxxxxxx";
char const WorldSafeLocsEntryfmt[] = "nifffxxxxxxxxxxxxxxxxx";

#endif
