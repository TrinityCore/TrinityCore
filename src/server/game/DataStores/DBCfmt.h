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

#ifndef TRINITY_DBCSFRM_H
#define TRINITY_DBCSFRM_H

// x - skip<uint32>, X - skip<uint8>, s - char*, f - float, i - uint32, b - uint8, d - index (not included)
// n - index (included), l - uint64, p - field present in sql dbc, a - field absent in sql dbc

char const AnimKitfmt[] = "nxxx";
char const AreaTablefmt[] = "niiiiixxxxxxisiiiiixxxxxxxxxx";
char const AreaTriggerfmt[] = "nifffxxxfffffxxxx";
char const ArmorLocationfmt[] = "nfffff";
char const BankBagSlotPricesfmt[] = "ni";
char const BannedAddOnsfmt[] = "nxxxxxxxxxx";
char const BattlemasterListfmt[] = "niiiiiiiiiiiiiiiiixsiiiixxxxxxx";
char const CharSectionsfmt[] = "diiixxxiii";
char const CharTitlesfmt[] = "nxssix";
char const ChatChannelsfmt[] = "nixsx";
char const ChrClassesfmt[] = "nixsxxxixiiiiixxxxx";
char const ChrRacesfmt[] = "niixiixxxxxxiisxxxxxxxxxxxxxxxxxxxxxxxxx";
char const ChrSpecializationfmt[] = "nxiiiiiiiiixxxii";
char const CreatureDisplayInfoExtrafmt[] = "dixxxxxxxxxxxxxxxxxxxx";
char const CreatureFamilyfmt[] = "nfifiiiiixsx";
char const CreatureModelDatafmt[] = "niixxxxxxxxxxxxffxxxxxxxxxxxxxxxxx";
char const DifficultyFmt[] = "niiiixiixxxxix";
char const DungeonEncounterfmt[] = "niiixsxxx";
char const DurabilityCostsfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const Emotesfmt[] = "nxxiiixx";
char const EmotesTextfmt[] = "nxixxxxxxxxxxxxxxxx";
char const EmotesTextSoundEntryfmt[] = "niiii";
char const Factionfmt[] = "niiiiiiiiiiiiiiiiiiffixsxixx";
char const FactionTemplatefmt[] = "niiiiiiiiiiiii";
char const GameObjectDisplayInfofmt[] = "nixxxxxxxxxxffffffxxx";
char const GemPropertiesfmt[] = "nixxii";
char const GlyphPropertiesfmt[] = "niiix";
char const GtArmorMitigationByLvlfmt[] = "xf";
char const GtBarberShopCostBasefmt[] = "xf";
char const GtCombatRatingsfmt[] = "xf";
char const GtOCTHpPerStaminafmt[] = "df";
char const GtOCTLevelExperiencefmt[] = "xf";
char const GtChanceToMeleeCritBasefmt[] = "xf";
char const GtChanceToMeleeCritfmt[] = "xf";
char const GtChanceToSpellCritBasefmt[] = "xf";
char const GtChanceToSpellCritfmt[] = "xf";
char const GtItemSocketCostPerLevelfmt[] = "xf";
char const GtNPCManaCostScalerfmt[] = "xf";
char const GtNpcTotalHpfmt[] = "xf";
char const GtNpcTotalHpExp1fmt[] = "xf";
char const GtNpcTotalHpExp2fmt[] = "xf";
char const GtNpcTotalHpExp3fmt[] = "xf";
char const GtNpcTotalHpExp4fmt[] = "xf";
char const GtNpcTotalHpExp5fmt[] = "xf";
char const GtRegenMPPerSptfmt[] = "xf";
char const GtSpellScalingfmt[] = "df";
char const GtOCTBaseHPByClassfmt[] = "df";
char const GtOCTBaseMPByClassfmt[] = "df";
char const GuildColorBackgroundfmt[] = "nXXX";
char const GuildColorBorderfmt[] = "nXXX";
char const GuildColorEmblemfmt[] = "nXXX";
char const ItemBagFamilyfmt[] = "nx";
char const ItemArmorQualityfmt[] = "nfffffffi";
char const ItemArmorShieldfmt[] = "nifffffff";
char const ItemArmorTotalfmt[] = "niffff";
char const ItemDamagefmt[] = "nfffffffi";
char const ItemSetfmt[] = "nsiiiiiiiiiiiiiiiiiii";
char const ItemSetSpellfmt[] = "niiii";
char const LFGDungeonfmt[] = "nsiiixxiiiixxixixxxxxxxxxxxxxx";
char const Lightfmt[] = "nifffxxxxxxxxxx";
char const LiquidTypefmt[] = "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const Lockfmt[] = "niiiiiiiiiiiiiiiiiiiiiiiixxxxxxxx";
char const Mapfmt[] = "nxiixxsixxixiffxiiiiix";
char const MapDifficultyfmt[] = "diisiiii";
char const MinorTalentfmt[] = "niii";
char const Moviefmt[] = "nxxxx";
char const Phasefmt[] = "ni";
char const QuestFactionRewardfmt[] = "niiiiiiiiii";
char const PowerDisplayfmt[] = "nixXXX";
char const PvpDifficultyfmt[] = "diiii";
char const RandPropPointsfmt[] = "niiiiiiiiiiiiiii";
char const SkillLinefmt[] = "nisxixixx";
char const SkillLineAbilityfmt[] = "niiiiiiiiiiii";
char const SkillRaceClassInfofmt[] = "diiiiiii";
char const SpellCategoriesfmt[] = "diiiiiiiii";
char const SpellCategoryfmt[] = "nixxii";
char const SpellEffectfmt[] = "niifiiiffiiiiiifiifiiiiifiiiiif";
const std::string CustomSpellEffectfmt = "ppppppppppppppappppppppppp";
const std::string CustomSpellEffectEntryIndex = "Id";
char const Spellfmt[] = "nsxxxiiiiiiiiiiiiiiiiiii";
const std::string CustomSpellfmt = "ppppppppppppppapaaaaaaaaapaaaaaapapppaapppaaapa";
const std::string CustomSpellEntryIndex = "Id";
char const SpellEffectScalingfmt[] = "nfffi";
char const SpellFocusObjectfmt[] = "nx";
char const SpellItemEnchantmentfmt[] = "niiiiiiiiiixiiiiiiiiiiifff";
char const SpellScalingfmt[] = "niiiifiii";
char const SpellTargetRestrictionsfmt[] = "niiffiiii";
char const SpellInterruptsfmt[] = "diiiiiii";
char const SpellEquippedItemsfmt[] = "diiiii";
char const SpellAuraOptionsfmt[] = "niiiiiiii";
char const SpellCooldownsfmt[] = "diiiii";
char const SpellLevelsfmt[] = "diiiii";
char const SpellShapeshiftfmt[] = "niiiix";
char const SpellShapeshiftFormfmt[] = "nxxiixiiiiiiiiiiiiixx";
char const SummonPropertiesfmt[] = "niiiii";
char const Talentfmt[] = "niiiiiiiiix";
char const Vehiclefmt[] = "niiffffiiiiiiiifffffffffffffffxxxxfifiiii";
char const VehicleSeatfmt[] = "niiffffffffffiiiiiifffffffiiifffiiiiiiiffiiiiffffffffffffiiiiiiiii";
char const WMOAreaTablefmt[] = "niiixxxxxiixxxx";
char const WorldMapAreafmt[] = "xinxffffixxxxx";
char const WorldMapTransformsfmt[] = "diffffffiffxxxf";
char const WorldSafeLocsfmt[] = "niffffx";

#endif
