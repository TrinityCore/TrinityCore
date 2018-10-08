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

#ifndef TRINITY_DBCSFRM_H
#define TRINITY_DBCSFRM_H

char constexpr Achievementfmt[]       = "niixssssssssssssssssxxxxxxxxxxxxxxxxxxiixixxxxxxxxxxxxxxxxxxii";
char constexpr CustomAchievementfmt[] = "pppaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaapapaaaaaaaaaaaaaaaaaapp";
char constexpr CustomAchievementIndex[] = "ID";
char constexpr AchievementCriteriafmt[] = "niiiiiiiixxxxxxxxxxxxxxxxxiiiix";
char constexpr AreaTableEntryfmt[] = "niiiixxxxxissssssssssssssssxiiiiixxx";
char constexpr AreaGroupEntryfmt[] = "niiiiiii";
char constexpr AreaPOIEntryfmt[] = "niiiiiiiiiiifffixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxix";
char constexpr AreaTriggerEntryfmt[] = "niffffffff";
char constexpr AuctionHouseEntryfmt[] = "niiixxxxxxxxxxxxxxxxx";
char constexpr BankBagSlotPricesEntryfmt[] = "ni";
char constexpr BannedAddOnsfmt[] = "nxxxxxxxxxx";
char constexpr BarberShopStyleEntryfmt[] = "nixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiii";
char constexpr BattlemasterListEntryfmt[] = "niiiiiiiiixssssssssssssssssxiixx";
char constexpr CharacterFacialHairStylesfmt[] = "iiixxxxx";
char constexpr CharStartOutfitEntryfmt[] = "dbbbXiiiiiiiiiiiiiiiiiiiiiiiixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr CharSectionsEntryfmt[] = "diiixxxiii";
char constexpr CharTitlesEntryfmt[] = "nxssssssssssssssssxssssssssssssssssxi";
char constexpr ChatChannelsEntryfmt[] = "nixssssssssssssssssxxxxxxxxxxxxxxxxxx";
char constexpr ChrClassesEntryfmt[] = "nxixssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixii";
char constexpr ChrRacesEntryfmt[] = "niixiixixxxxixssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxi";
char constexpr CinematicCameraEntryfmt[] = "nsiffff";
char constexpr CinematicSequencesEntryfmt[] = "nxixxxxxxx";
char constexpr CreatureDisplayInfofmt[] = "nixifxxxxxxxxxxx";
char constexpr CreatureDisplayInfoExtrafmt[] = "diixxxxxxxxxxxxxxxxxx";
char constexpr CreatureFamilyfmt[] = "nfifiiiiixssssssssssssssssxx";
char constexpr CreatureModelDatafmt[] = "nisxfxxxxxxxxxxffxxxxxxxxxxx";
char constexpr CreatureSpellDatafmt[] = "niiiixxxx";
char constexpr CreatureTypefmt[] = "nxxxxxxxxxxxxxxxxxx";
char constexpr CurrencyTypesfmt[] = "xnxi";
char constexpr DestructibleModelDatafmt[] = "nxxixxxixxxixxxixxx";
char constexpr DungeonEncounterfmt[] = "niixissssssssssssssssxx";
char constexpr DurabilityCostsfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char constexpr DurabilityQualityfmt[] = "nf";
char constexpr EmotesEntryfmt[] = "nxxiiix";
char constexpr EmotesTextEntryfmt[] = "nxixxxxxxxxxxxxxxxx";
char constexpr EmotesTextSoundEntryfmt[] = "niiii";
char constexpr FactionEntryfmt[] = "niiiiiiiiiiiiiiiiiiffixssssssssssssssssxxxxxxxxxxxxxxxxxx";
char constexpr FactionTemplateEntryfmt[] = "niiiiiiiiiiiii";
char constexpr GameObjectDisplayInfofmt[] = "nsxxxxxxxxxxffffffx";
char constexpr GemPropertiesEntryfmt[] = "nixxi";
char constexpr GlyphPropertiesfmt[] = "niii";
char constexpr GlyphSlotfmt[] = "nii";
char constexpr GtBarberShopCostBasefmt[] = "f";
char constexpr GtCombatRatingsfmt[] = "f";
char constexpr GtChanceToMeleeCritBasefmt[] = "f";
char constexpr GtChanceToMeleeCritfmt[] = "f";
char constexpr GtChanceToSpellCritBasefmt[] = "f";
char constexpr GtChanceToSpellCritfmt[] = "f";
char constexpr GtNPCManaCostScalerfmt[] = "f";
char constexpr GtOCTClassCombatRatingScalarfmt[] = "df";
char constexpr GtOCTRegenHPfmt[] = "f";
//char constexpr GtOCTRegenMPfmt[] = "f";
char constexpr GtRegenHPPerSptfmt[] = "f";
char constexpr GtRegenMPPerSptfmt[] = "f";
char constexpr Holidaysfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiixxsiix";
char constexpr Itemfmt[] = "niiiiiii";
char constexpr ItemBagFamilyfmt[] = "nxxxxxxxxxxxxxxxxx";
char constexpr ItemDisplayTemplateEntryfmt[] = "nxxxxsxxxxxxxxxxxxxxxxxxx";
//char constexpr ItemCondExtCostsEntryfmt[] = "xiii";
char constexpr ItemExtendedCostEntryfmt[] = "niiiiiiiiiiiiiix";
char constexpr ItemLimitCategoryEntryfmt[] = "nxxxxxxxxxxxxxxxxxii";
char constexpr ItemRandomPropertiesfmt[] = "nxiiixxssssssssssssssssx";
char constexpr ItemRandomSuffixfmt[] = "nssssssssssssssssxxiiixxiiixx";
char constexpr ItemSetEntryfmt[] = "dssssssssssssssssxiiiiiiiiiixxxxxxxiiiiiiiiiiiiiiiiii";
char constexpr LFGDungeonEntryfmt[] = "nssssssssssssssssxiiiiiiiiixxixixxxxxxxxxxxxxxxxx";
char constexpr LightEntryfmt[] = "nifffxxxxxxxxxx";
char constexpr LiquidTypefmt[] = "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr LockEntryfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiixxxxxxxx";
char constexpr MailTemplateEntryfmt[] = "nxxxxxxxxxxxxxxxxxssssssssssssssssx";
char constexpr MapEntryfmt[] = "nxiixssssssssssssssssxixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixiffxiii";
char constexpr MapDifficultyEntryfmt[] = "diisxxxxxxxxxxxxxxxxiix";
char constexpr MovieEntryfmt[] = "nxx";
char constexpr NamesProfanityEntryfmt[] = "dsi";
char constexpr NamesReservedEntryfmt[] = "dsi";
char constexpr OverrideSpellDatafmt[] = "niiiiiiiiiix";
char constexpr QuestFactionRewardfmt[] = "niiiiiiiiii";
char constexpr QuestSortEntryfmt[] = "nxxxxxxxxxxxxxxxxx";
char constexpr QuestXPfmt[] = "niiiiiiiiii";
char constexpr PowerDisplayfmt[] = "nixxxx";
char constexpr PvPDifficultyfmt[] = "diiiii";
char constexpr RandomPropertiesPointsfmt[] = "niiiiiiiiiiiiiii";
char constexpr ScalingStatDistributionfmt[] = "niiiiiiiiiiiiiiiiiiiii";
char constexpr ScalingStatValuesfmt[] = "iniiiiiiiiiiiiiiiiiiiiii";
char constexpr SkillLinefmt[] = "nixssssssssssssssssxxxxxxxxxxxxxxxxxxixxxxxxxxxxxxxxxxxi";
char constexpr SkillLineAbilityfmt[] = "niiiixxiiiiixx";
char constexpr SkillRaceClassInfofmt[] = "diiiixix";
char constexpr SkillTiersfmt[] = "nxxxxxxxxxxxxxxxxiiiiiiiiiiiiiiii";
char constexpr SoundEntriesfmt[] = "nxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr SpellCastTimefmt[] = "nixx";
char constexpr SpellCategoryfmt[] = "ni";
char constexpr SpellDifficultyfmt[]       = "niiii";
char constexpr CustomSpellDifficultyfmt[] = "ppppp";
char constexpr CustomSpellDifficultyIndex[] = "id";
char constexpr SpellDurationfmt[] = "niii";
char constexpr SpellEntryfmt[]       = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiifxiiiiiiiiiiiiiiiiiiiiiiiiiiiifffiiiiiiiiiiiiiiiiiiiiifffiiiiiiiiiiiiiiifffiiiiiiiiiiiiiissssssssssssssssxssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiiiiiiiiiiixfffxxxiiiiixxfffxx";
char constexpr CustomSpellEntryfmt[] = "papppppppppppapapaaaaaaaaaaapaaapapppppppaaaaapaapaaaaaaaaaaaaaaaaaappppppppppppppppppppppppppppppppppppaaappppppppppppaaapppppppppaaaaapaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaappppppppapppaaaaappaaaaaaaa";
char constexpr CustomSpellEntryIndex[] = "Id";
char constexpr SpellFocusObjectfmt[] = "nxxxxxxxxxxxxxxxxx";
char constexpr SpellItemEnchantmentfmt[] = "nxiiiiiixxxiiissssssssssssssssxiiiiiii";
char constexpr SpellItemEnchantmentConditionfmt[] = "nbbbbbxxxxxbbbbbbbbbbiiiiiXXXXX";
char constexpr SpellRadiusfmt[] = "nfff";
char constexpr SpellRangefmt[] = "nffffixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr SpellRuneCostfmt[] = "niiii";
char constexpr SpellShapeshiftfmt[] = "nxxxxxxxxxxxxxxxxxxiixiiixxiiiiiiii";
char constexpr StableSlotPricesfmt[] = "ni";
char constexpr SummonPropertiesfmt[] = "niiiii";
char constexpr TalentEntryfmt[] = "niiiiiiiixxxxixxixxxxxx";
char constexpr TalentTabEntryfmt[] = "nxxxxxxxxxxxxxxxxxxxiiix";
char constexpr TaxiNodesEntryfmt[] = "nifffssssssssssssssssxii";
char constexpr TaxiPathEntryfmt[] = "niii";
char constexpr TaxiPathNodeEntryfmt[] = "diiifffiiii";
char constexpr TeamContributionPointsfmt[] = "df";
char constexpr TotemCategoryEntryfmt[] = "nxxxxxxxxxxxxxxxxxii";
char constexpr TransportAnimationfmt[] = "diifffx";
char constexpr TransportRotationfmt[] = "diiffff";
char constexpr VehicleEntryfmt[] = "niffffiiiiiiiifffffffffffffffssssfifiixx";
char constexpr VehicleSeatEntryfmt[] = "niiffffffffffiiiiiifffffffiiifffiiiiiiiffiiiiixxxxxxxxxxxx";
char constexpr WMOAreaTableEntryfmt[] = "niiixxxxxiixxxxxxxxxxxxxxxxx";
char constexpr WorldMapAreaEntryfmt[] = "xinxffffixx";
char constexpr WorldMapOverlayEntryfmt[] = "nxiiiixxxxxxxxxxx";
char constexpr WorldSafeLocsEntryfmt[] = "nifffxxxxxxxxxxxxxxxxx";

#endif
