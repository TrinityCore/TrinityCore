/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_DB2SFRM_H
#define TRINITY_DB2SFRM_H

char const AchievementFormat[] = "niiissiiiiisiii";
char const AreaGroupFormat[] = "n";
char const AreaGroupMemberFormat[] = "nii";
char const AuctionHouseFormat[] = "niiis";
char const BarberShopStyleFormat[] = "nissfiii";
char const BattlePetBreedQualityFormat[] = "nif";
char const BattlePetBreedStateFormat[] = "niii";
char const BattlePetSpeciesFormat[] = "niiiiiiss";
char const BattlePetSpeciesStateFormat[] = "niii";
char const BroadcastTextFormat[] = "nissiiiiiiiii";
char const CharStartOutfitFormat[] = "nbbbbiiiiiiiiiiiiiiiiiiiiiiiiii";
char const ChrClassesXPowerTypesFormat[] = "iii";
char const CinematicSequencesFormat[] = "niiiiiiiii";
char const CreatureDisplayInfoFormat[] = "niiiffissssiiiiiiiiiii";
char const CreatureTypeFormat[] = "nsi";
char const CriteriaFormat[] = "niiiiiiiiiii";
char const CriteriaTreeFormat[] = "niliiisi";
char const CurrencyTypesFormat[] = "nisssiiiiiis";
char const CurvePointFormat[] = "niiff";
char const DestructibleModelDataFormat[] = "niiiiiiiiiiiiiiiiiiiiiii";
char const DurabilityQualityFormat[] = "nf";
char const GameObjectsFormat[] = "niiffffffffiiiiiiiiiiiis";
char const GameTablesFormat[] = "nsii";
char const GarrAbilityFormat[] = "nissiiii";
char const GarrBuildingFormat[] = "niiiiissssiiiiiiiiiiiiii";
char const GarrBuildingPlotInstFormat[] = "niiiff";
char const GarrClassSpecFormat[] = "nsssii";
char const GarrFollowerFormat[] = "niiiiiiiiiiiiiiissiiiiii";
char const GarrFollowerXAbilityFormat[] = "niii";
char const GarrPlotBuildingFormat[] = "nii";
char const GarrPlotFormat[] = "niiisiiii";
char const GarrPlotInstanceFormat[] = "nis";
char const GarrSiteLevelFormat[] = "niiiiffiiii";
char const GarrSiteLevelPlotInstFormat[] = "niiffi";
char const GlyphSlotFormat[] = "nii";
char const HeirloomFormat[] = "niisiiiiiiii";
char const GuildPerkSpellsFormat[] = "nii";
char const HolidaysEntryFormat[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiisiii";
char const ImportPriceArmorFormat[] = "nffff";
char const ImportPriceQualityFormat[] = "nf";
char const ImportPriceShieldFormat[] = "nf";
char const ImportPriceWeaponFormat[] = "nf";
char const ItemAppearanceFormat[] = "nii";
char const ItemBonusFormat[] = "niiiii";
char const ItemBonusTreeNodeFormat[] = "niiii";
char const ItemClassFormat[] = "nifs";
char const ItemCurrencyCostFormat[] = "in";
char const ItemDisenchantLootFormat[] = "niiiiii";
char const ItemEffectFormat[] = "niiiiiiiii";
char const ItemExtendedCostFormat[] = "niiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const ItemFormat[] = "niiiiiiii";
char const ItemLimitCategoryFormat[] = "nsii";
char const ItemModifiedAppearanceFormat[] = "niiiii";
char const ItemPriceBaseFormat[] = "niff";
char const ItemRandomPropertiesFormat[] = "nsiiiiis";
char const ItemRandomSuffixFormat[] = "nssiiiiiiiiii";
char const ItemSparseFormat[] = "niiiiffiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiffffffffffiiifisssssiiiiiiiiiiiiiiiiiiifiiifiii";
char const ItemSpecFormat[] = "niiiiii";
char const ItemSpecOverrideFormat[] = "nii";
char const ItemToBattlePetSpeciesFormat[] = "ni";
char const ItemXBonusTreeFormat[] = "nii";
char const KeyChainFormat[] = "nbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
char const MailTemplateFormat[] = "ns";
char const ModifierTreeFormat[] = "niiiiii";
char const MountCapabilityFormat[] = "niiiiiii";
char const MountFormat[] = "niiiisssii";
char const MountTypeXCapabilityFormat[] = "niii";
char const NameGenFormat[] = "nsii";
char const NamesProfanityFormat[] = "nSi";
char const NamesReservedFormat[] = "nS";
char const NamesReservedLocaleFormat[] = "nSi";
char const OverrideSpellDataFormat[] = "niiiiiiiiiiii";
char const PhaseXPhaseGroupFormat[] = "nii";
char const QuestMoneyRewardFormat[] = "niiiiiiiiii";
char const QuestPackageItemfmt[] = "niiii";
char const QuestSortFormat[] = "ns";
char const QuestV2Format[] = "ni";
char const QuestXPFormat[] = "niiiiiiiiii";
char const ScalingStatDistributionFormat[] = "niii";
char const SoundEntriesFormat[] = "nisiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiififfiifffffii";
char const SpecializationSpellsFormat[] = "niiiis";
char const SpellAuraRestrictionsFormat[] = "niiiiiiii";
char const SpellCastTimesFormat[] = "niii";
char const SpellCastingRequirementsFormat[] = "niiiiii";
char const SpellClassOptionsFormat[] = "niiiiii";
char const SpellDurationFormat[] = "niii";
char const SpellItemEnchantmentConditionFormat[] = "nbbbbbiiiiibbbbbbbbbbiiiiibbbbb";
char const SpellLearnSpellFormat[] = "niii";
char const SpellMiscFormat[] = "niiiiiiiiiiiiiiiiifiiif";
char const SpellPowerDifficultyFormat[] = "nii";
char const SpellPowerFormat[] = "niiiiiiiiiffif";
char const SpellRadiusFormat[] = "nffff";
char const SpellRangeFormat[] = "nffffiss";
char const SpellReagentsFormat[] = "niiiiiiiiiiiiiiii";
char const SpellRuneCostFormat[] = "niiiii";
char const SpellTotemsFormat[] = "niiii";
char const SpellXSpellVisualFormat[] = "niiiifii";
char const TaxiNodesFormat[] = "nifffsiiiiiff";
char const TaxiPathFormat[] = "niii";
char const TaxiPathNodeFormat[] = "niiifffiiii";
char const TotemCategoryFormat[] = "nsii";
char const ToyFormat[] = "niisi";
char const TransportAnimationFormat[] = "niifffi";
char const TransportRotationFormat[] = "niiffff";
char const UnitPowerBarFormat[] = "niiiiffiiiiiiiiiiiiiissssff";
char const WorldMapOverlayFormat[] = "niiiiisiiiiiiiii";

#endif
