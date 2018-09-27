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

char constexpr DBCfmt_Achievement[] = "niixssssssssssssssssxxxxxxxxxxxxxxxxxxiixixxxxxxxxxxxxxxxxxxii";
char constexpr DBCfmt_Achievement_DBFormat[] = "pppaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaapapaaaaaaaaaaaaaaaaaapp";
char constexpr DBCfmt_Achievement_DBIndex[] = "ID";
char constexpr DBCfmt_AchievementCriteria[] = "niiiiiiiixxxxxxxxxxxxxxxxxiiiix";
char constexpr DBCfmt_AreaTable[] = "niiiixxxxxissssssssssssssssxiiiiixxx";
char constexpr DBCfmt_AreaGroup[] = "niiiiiii";
char constexpr DBCfmt_AreaPOI[] = "niiiiiiiiiiifffixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxix";
char constexpr DBCfmt_AreaTrigger[] = "niffffffff";
char constexpr DBCfmt_AuctionHouse[] = "niiixxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_BankBagSlotPrices[] = "ni";
char constexpr DBCfmt_BannedAddOns[] = "nxxxxxxxxxx";
char constexpr DBCfmt_BarberShopStyle[] = "nixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiii";
char constexpr DBCfmt_BattlemasterList[] = "niiiiiiiiixssssssssssssssssxiixx";
char constexpr DBCfmt_CharacterFacialHairStyles[] = "iiixxxxx";
char constexpr DBCfmt_CharStartOutfit[] = "dbbbXiiiiiiiiiiiiiiiiiiiiiiiixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_CharSections[] = "diiixxxiii";
char constexpr DBCfmt_CharTitles[] = "nxssssssssssssssssxssssssssssssssssxi";
char constexpr DBCfmt_ChatChannels[] = "nixssssssssssssssssxxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_ChrClasses[] = "nxixssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixii";
char constexpr DBCfmt_ChrRaces[] = "niixiixixxxxixssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxi";
char constexpr DBCfmt_CinematicCamera[] = "nsiffff";
char constexpr DBCfmt_CinematicSequences[] = "nxixxxxxxx";
char constexpr DBCfmt_CreatureDisplayInfo[] = "nixifxxxxxxxxxxx";
char constexpr DBCfmt_CreatureDisplayInfoExtra[] = "diixxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_CreatureFamily[] = "nfifiiiiixssssssssssssssssxx";
char constexpr DBCfmt_CreatureModelData[] = "nisxfxxxxxxxxxxffxxxxxxxxxxx";
char constexpr DBCfmt_CreatureSpellData[] = "niiiixxxx";
char constexpr DBCfmt_CreatureType[] = "nxxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_CurrencyTypes[] = "xnxi";
char constexpr DBCfmt_DestructibleModelData[] = "nxxixxxixxxixxxixxx";
char constexpr DBCfmt_DungeonEncounter[] = "niixissssssssssssssssxx";
char constexpr DBCfmt_DurabilityCosts[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char constexpr DBCfmt_DurabilityQuality[] = "nf";
char constexpr DBCfmt_Emotes[] = "nxxiiix";
char constexpr DBCfmt_EmotesText[] = "nxixxxxxxxxxxxxxxxx";
char constexpr DBCfmt_EmotesTextSound[] = "niiii";
char constexpr DBCfmt_Faction[] = "niiiiiiiiiiiiiiiiiiffixssssssssssssssssxxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_FactionTemplate[] = "niiiiiiiiiiiii";
char constexpr DBCfmt_GameObjectDisplayInfo[] = "nsxxxxxxxxxxffffffx";
char constexpr DBCfmt_GemProperties[] = "nixxi";
char constexpr DBCfmt_GlyphProperties[] = "niii";
char constexpr DBCfmt_GlyphSlot[] = "nii";
char constexpr DBCfmt_gtBarberShopCostBase[] = "f";
char constexpr DBCfmt_gtCombatRatings[] = "f";
char constexpr DBCfmt_gtChanceToMeleeCritBase[] = "f";
char constexpr DBCfmt_gtChanceToMeleeCrit[] = "f";
char constexpr DBCfmt_gtChanceToSpellCritBase[] = "f";
char constexpr DBCfmt_gtChanceToSpellCrit[] = "f";
char constexpr DBCfmt_gtNPCManaCostScaler[] = "f";
char constexpr DBCfmt_gtOCTClassCombatRatingScalar[] = "df";
char constexpr DBCfmt_gtOCTRegenHP[] = "f";
//char constexpr DBCfmt_gtOCTRegenMP[] = "f";
char constexpr DBCfmt_gtRegenHPPerSpt[] = "f";
char constexpr DBCfmt_gtRegenMPPerSpt[] = "f";
char constexpr DBCfmt_Holidays[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiixxsiix";
char constexpr DBCfmt_Item[] = "niiiiiii";
char constexpr DBCfmt_ItemBagFamily[] = "nxxxxxxxxxxxxxxxxx";
//char constexpr DBCfmt_ItemDisplayTemplate[] = "nxxxxxxxxxxixxxxxxxxxxx";
//char constexpr DBCfmt_ItemCondExtCosts[] = "xiii";
char constexpr DBCfmt_ItemExtendedCost[] = "niiiiiiiiiiiiiix";
char constexpr DBCfmt_ItemLimitCategory[] = "nxxxxxxxxxxxxxxxxxii";
char constexpr DBCfmt_ItemRandomProperties[] = "nxiiixxssssssssssssssssx";
char constexpr DBCfmt_ItemRandomSuffix[] = "nssssssssssssssssxxiiixxiiixx";
char constexpr DBCfmt_ItemSet[] = "dssssssssssssssssxiiiiiiiiiixxxxxxxiiiiiiiiiiiiiiiiii";
char constexpr DBCfmt_LFGDungeons[] = "nssssssssssssssssxiiiiiiiiixxixixxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_Light[] = "nifffxxxxxxxxxx";
char constexpr DBCfmt_LiquidType[] = "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_Lock[] = "niiiiiiiiiiiiiiiiiiiiiiiixxxxxxxx";
char constexpr DBCfmt_MailTemplate[] = "nxxxxxxxxxxxxxxxxxssssssssssssssssx";
char constexpr DBCfmt_Map[] = "nxiixssssssssssssssssxixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixiffxiii";
char constexpr DBCfmt_MapDifficulty[] = "diisxxxxxxxxxxxxxxxxiix";
char constexpr DBCfmt_Movie[] = "nxx";
char constexpr DBCfmt_NamesProfanity[] = "dsi";
char constexpr DBCfmt_NamesReserved[] = "dsi";
char constexpr DBCfmt_OverrideSpellData[] = "niiiiiiiiiix";
char constexpr DBCfmt_QuestFactionReward[] = "niiiiiiiiii";
char constexpr DBCfmt_QuestSort[] = "nxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_QuestXP[] = "niiiiiiiiii";
char constexpr DBCfmt_PowerDisplay[] = "nixxxx";
char constexpr DBCfmt_PvPDifficulty[] = "diiiii";
char constexpr DBCfmt_RandomPropertiesPoints[] = "niiiiiiiiiiiiiii";
char constexpr DBCfmt_ScalingStatDistribution[] = "niiiiiiiiiiiiiiiiiiiii";
char constexpr DBCfmt_ScalingStatValues[] = "iniiiiiiiiiiiiiiiiiiiiii";
char constexpr DBCfmt_SkillLine[] = "nixssssssssssssssssxxxxxxxxxxxxxxxxxxixxxxxxxxxxxxxxxxxi";
char constexpr DBCfmt_SkillLineAbility[] = "niiiixxiiiiixx";
char constexpr DBCfmt_SkillRaceClassInfo[] = "diiiixix";
char constexpr DBCfmt_SkillTiers[] = "nxxxxxxxxxxxxxxxxiiiiiiiiiiiiiiii";
char constexpr DBCfmt_SoundEntries[] = "nxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_SpellCastTimes[] = "nixx";
char constexpr DBCfmt_SpellCategory[] = "ni";
char constexpr DBCfmt_SpellDifficulty[] = "niiii";
char constexpr DBCfmt_SpellDifficulty_DBFormat[] = "ppppp";
char constexpr DBCfmt_SpellDifficulty_DBIndex[] = "id";
char constexpr DBCfmt_SpellDuration[] = "niii";
char constexpr DBCfmt_Spell[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiifxiiiiiiiiiiiiiiiiiiiiiiiiiiiifffiiiiiiiiiiiiiiiiiiiiifffiiiiiiiiiiiiiiifffiiiiiiiiiiiiiissssssssssssssssxssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiiiiiiiiiiixfffxxxiiiiixxfffxx";
char constexpr DBCfmt_Spell_DBFormat[] = "papppppppppppapapaaaaaaaaaaapaaapapppppppaaaaapaapaaaaaaaaaaaaaaaaaappppppppppppppppppppppppppppppppppppaaappppppppppppaaapppppppppaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaappppppppapppaaaaappaaaaaaa";
char constexpr DBCfmt_Spell_DBIndex[] = "Id";
char constexpr DBCfmt_SpellFocusObject[] = "nxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_SpellItemEnchantment[] = "nxiiiiiixxxiiissssssssssssssssxiiiiiii";
char constexpr DBCfmt_SpellItemEnchantmentCondition[] = "nbbbbbxxxxxbbbbbbbbbbiiiiiXXXXX";
char constexpr DBCfmt_SpellRadius[] = "nfff";
char constexpr DBCfmt_SpellRange[] = "nffffixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_SpellRuneCost[] = "niiii";
char constexpr DBCfmt_SpellShapeshift[] = "nxxxxxxxxxxxxxxxxxxiixiiixxiiiiiiii";
char constexpr DBCfmt_StableSlotPrices[] = "ni";
char constexpr DBCfmt_SummonProperties[] = "niiiii";
char constexpr DBCfmt_Talent[] = "niiiiiiiixxxxixxixxxxxx";
char constexpr DBCfmt_TalentTab[] = "nxxxxxxxxxxxxxxxxxxxiiix";
char constexpr DBCfmt_TaxiNodes[] = "nifffssssssssssssssssxii";
char constexpr DBCfmt_TaxiPath[] = "niii";
char constexpr DBCfmt_TaxiPathNode[] = "diiifffiiii";
char constexpr DBCfmt_TeamContributionPoints[] = "df";
char constexpr DBCfmt_TotemCategory[] = "nxxxxxxxxxxxxxxxxxii";
char constexpr DBCfmt_TransportAnimation[] = "diifffx";
char constexpr DBCfmt_TransportRotation[] = "diiffff";
char constexpr DBCfmt_Vehicle[] = "niffffiiiiiiiifffffffffffffffssssfifiixx";
char constexpr DBCfmt_VehicleSeat[] = "niiffffffffffiiiiiifffffffiiifffiiiiiiiffiiiiixxxxxxxxxxxx";
char constexpr DBCfmt_WMOAreaTable[] = "niiixxxxxiixxxxxxxxxxxxxxxxx";
char constexpr DBCfmt_WorldMapArea[] = "xinxffffixx";
char constexpr DBCfmt_WorldMapOverlay[] = "nxiiiixxxxxxxxxxx";
char constexpr DBCfmt_WorldSafeLocs[] = "nifffxxxxxxxxxxxxxxxxx";

#endif
