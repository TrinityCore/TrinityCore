/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_DBCSFRM_H
#define MANGOS_DBCSFRM_H

const char Achievementfmt[]="niixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiixixxxxxxxxxxxxxxxxxxii";
const char AchievementCriteriafmt[]="niiiiiiiixxxxxxxxxxxxxxxxxiixix";
const char AreaTableEntryfmt[]="iiinixxxxxissssssssssssssssxixxxxxxx";
const char AreaGroupEntryfmt[]="niiiiiii";
const char AreaPOIEntryfmt[]="niiiiiiiiiiifffixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxix";
const char AreaTriggerEntryfmt[]="niffffffff";
const char AuctionHouseEntryfmt[]="niiixxxxxxxxxxxxxxxxx";
const char BankBagSlotPricesEntryfmt[]="ni";
const char BarberShopStyleEntryfmt[]="nixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiii";
const char BattlemasterListEntryfmt[]="niiiiiiiiiiiixxxssssssssssssssssxxx";
const char CharStartOutfitEntryfmt[]="diiiiiiiiiiiiiiiiiiiiiiiiixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char CharTitlesEntryfmt[]="nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxi";
const char ChatChannelsEntryfmt[]="iixssssssssssssssssxxxxxxxxxxxxxxxxxx";
                                                            // ChatChannelsEntryfmt, index not used (more compact store)
const char ChrClassesEntryfmt[]="nxixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixii";
const char ChrRacesEntryfmt[]="nxixiixxixxxxissssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxi";
const char CinematicSequencesEntryfmt[]="nxxxxxxxxx";
const char CreatureDisplayInfofmt[]="nxxxfxxxxxxxxxxx";
const char CreatureFamilyfmt[]="nfifiiiiixssssssssssssssssxx";
const char CreatureSpellDatafmt[]="niiiixxxx";
const char CreatureTypefmt[]="nxxxxxxxxxxxxxxxxxx";
const char CurrencyTypesfmt[]="xnxi";
const char DurabilityCostsfmt[]="niiiiiiiiiiiiiiiiiiiiiiiiiiiii";
const char DurabilityQualityfmt[]="nf";
const char EmotesEntryfmt[]="nxxiiix";
const char EmotesTextEntryfmt[]="nxixxxxxxxxxxxxxxxx";
const char FactionEntryfmt[]="niiiiiiiiiiiiiiiiiissssssssssssssssxxxxxxxxxxxxxxxxxx";
const char FactionTemplateEntryfmt[]="niiiiiiiiiiiii";
const char GameObjectDisplayInfofmt[]="nxxxxxxxxxxxffffffx";
const char GemPropertiesEntryfmt[]="nixxi";
const char GlyphPropertiesfmt[]="niii";
const char GlyphSlotfmt[]="nii";
const char GtBarberShopCostBasefmt[]="f";
const char GtCombatRatingsfmt[]="f";
const char GtChanceToMeleeCritBasefmt[]="f";
const char GtChanceToMeleeCritfmt[]="f";
const char GtChanceToSpellCritBasefmt[]="f";
const char GtChanceToSpellCritfmt[]="f";
const char GtOCTRegenHPfmt[]="f";
//const char GtOCTRegenMPfmt[]="f";
const char GtRegenHPPerSptfmt[]="f";
const char GtRegenMPPerSptfmt[]="f";
const char Holidaysfmt[]="nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char Itemfmt[]="niiiiiii";
const char ItemBagFamilyfmt[]="nxxxxxxxxxxxxxxxxx";
//const char ItemDisplayTemplateEntryfmt[]="nxxxxxxxxxxixxxxxxxxxxx";
//const char ItemCondExtCostsEntryfmt[]="xiii";
const char ItemExtendedCostEntryfmt[]="niiiiiiiiiiiiix";
const char ItemLimitCategoryEntryfmt[]="nxxxxxxxxxxxxxxxxxix";
const char ItemRandomPropertiesfmt[]="nxiiiiixxxxxxxxxxxxxxxxx";
const char ItemRandomSuffixfmt[]="nxxxxxxxxxxxxxxxxxxiiiiiiiiii";
const char ItemSetEntryfmt[]="dssssssssssssssssxxxxxxxxxxxxxxxxxxiiiiiiiiiiiiiiiiii";
const char LockEntryfmt[]="niiiiiiiiiiiiiiiiiiiiiiiixxxxxxxx";
const char MailTemplateEntryfmt[]="nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char MapEntryfmt[]="nxixssssssssssssssssxixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiffiixxix";
const char MovieEntryfmt[]="nxx";
const char QuestSortEntryfmt[]="nxxxxxxxxxxxxxxxxx";
const char RandomPropertiesPointsfmt[]="niiiiiiiiiiiiiii";
const char ScalingStatDistributionfmt[]="niiiiiiiiiiiiiiiiiiiii";
const char ScalingStatValuesfmt[]="iniiiiiiiiiiiiiiiii";
const char SkillLinefmt[]="nixssssssssssssssssxxxxxxxxxxxxxxxxxxixxxxxxxxxxxxxxxxxi";
const char SkillLineAbilityfmt[]="niiiixxiiiiixx";
const char SoundEntriesfmt[]="nxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char SpellCastTimefmt[]="nixx";
const char SpellDurationfmt[]="niii";
const char SpellEntryfmt[]="niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiifxiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiffffffiiiiiiiiiiiiiiiiiiiiifffiiiiiiiiiiiiiiifffiiiiiiiiiiiiixssssssssssssssssxssssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiiiiiiiiiiixfffxxxiiiiixx";
const char SpellFocusObjectfmt[]="nxxxxxxxxxxxxxxxxx";
const char SpellItemEnchantmentfmt[]="nxiiiiiixxxiiissssssssssssssssxiiiixxx";
const char SpellItemEnchantmentConditionfmt[]="nbbbbbxxxxxbbbbbbbbbbiiiiiXXXXX";
const char SpellRadiusfmt[]="nfxf";
const char SpellRangefmt[]="nffffixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char SpellRuneCostfmt[]="niiii";
const char SpellShapeshiftfmt[]="nxxxxxxxxxxxxxxxxxxiixixxxxiiiiiiii";
const char StableSlotPricesfmt[] = "ni";
const char SummonPropertiesfmt[] = "niiiii";
const char TalentEntryfmt[]="niiiiiiiixxxxixxixxxxxx";
const char TalentTabEntryfmt[]="nxxxxxxxxxxxxxxxxxxxiiix";
const char TaxiNodesEntryfmt[]="nifffssssssssssssssssxii";
const char TaxiPathEntryfmt[]="niii";
const char TaxiPathNodeEntryfmt[]="diiifffiixx";
const char TotemCategoryEntryfmt[]="nxxxxxxxxxxxxxxxxxii";
const char VehicleEntryfmt[]="niffffiiiiiiiifffffffffffffffssssfifixxx";
const char VehicleSeatEntryfmt[]="niiffffffffffiiiiiifffffffiiifffiiiiiiiffiiiiixxxxxxxxxxxx";
const char WorldMapAreaEntryfmt[]="xinxffffix";
const char WorldMapOverlayEntryfmt[]="nxiiiixxxxxxxxxxx";
const char WorldSafeLocsEntryfmt[]="nifffxxxxxxxxxxxxxxxxx";

#endif
