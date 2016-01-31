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

char const AchievementFormat[] = "nssishhhhhhhbbb";
char const AnimKitFormat[] = "dihh";
char const AreaGroupMemberFormat[] = "dhh";
char const ArmorLocationFormat[] = "dfffff";
char const AuctionHouseFormat[] = "dshbb";
char const BankBagSlotPricesFormat[] = "di";
char const BarberShopStyleFormat[] = "nssfbbbb";
char const BattlePetBreedQualityFormat[] = "dfb";
char const BattlePetBreedStateFormat[] = "nhbb";
char const BattlePetSpeciesFormat[] = "niiisshbb";
char const BattlePetSpeciesStateFormat[] = "nihb";
char const BroadcastTextFormat[] = "dsshhhhhhhhbb";
char const CharStartOutfitFormat[] = "diiiiiiiiiiiiiiiiiiiiiiiiibbbbb";
char const ChatChannelsFormat[] = "dissb";
char const ChrClassesXPowerTypesFormat[] = "dbb";
char const ChrRacesFormat[] = "niSSsssSSSiiffffffihhhhhhhhhhhhbbbbbbbbb";
char const ChrSpecializationFormat[] = "niiiisssShbbbbb";
char const CinematicSequencesFormat[] = "dhhhhhhhhh";
char const CreatureDisplayInfoFormat[] = "niffiiiSiiihhhhhhbbbbbb";
char const CreatureDisplayInfoExtraFormat[] = "diibbbbbbbbbbbb";
char const CreatureTypeFormat[] = "dsb";
char const CriteriaFormat[] = "diiihhhbbbbb";
char const CriteriaTreeFormat[] = "dishhhhb";
char const CurrencyTypesFormat[] = "nSSsiiisbbbb";
char const CurvePointFormat[] = "dffhb";
char const DestructibleModelDataFormat[] = "dhhhhhbbbbbbbbbbbbbbbbb";
char const DurabilityCostsFormat[] = "dhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
char const DurabilityQualityFormat[] = "df";
char const EmotesFormat[] = "dSiihhbb";
char const EmotesTextSoundFormat[] = "dhhbbb";
char const GameObjectsFormat[] = "nffffffffiiiiiiiishhhhbb";
char const GameObjectDisplayInfoFormat[] = "diffffffffh";
char const GameTablesFormat[] = "dshb";
char const GarrAbilityFormat[] = "nssihbbb";
char const GarrBuildingFormat[] = "diissssihhhhhhbbbbbbbbbbb";
char const GarrBuildingPlotInstFormat[] = "nffhhb";
char const GarrClassSpecFormat[] = "nssshbb";
char const GarrFollowerFormat[] = "diissiihhbbbbbbbbbbbbbbbb";
char const GarrFollowerXAbilityFormat[] = "dhhb";
char const GarrPlotFormat[] = "dsiibbbbb";
char const GarrPlotBuildingFormat[] = "dbb";
char const GarrPlotInstanceFormat[] = "dsb";
char const GarrSiteLevelFormat[] = "dffhhhbbbbb";
char const GarrSiteLevelPlotInstFormat[] = "dffhbb";
char const GemPropertiesFormat[] = "dihhbb";
char const GlyphPropertiesFormat[] = "dihbb";
char const GlyphSlotFormat[] = "dbb";
char const GuildColorBackgroundFormat[] = "dbbb";
char const GuildColorBorderFormat[] = "dbbb";
char const GuildColorEmblemFormat[] = "dbbb";
char const GuildPerkSpellsFormat[] = "dib";
char const HeirloomFormat[] = "nisiiiiihhbb";
char const HolidaysEntryFormat[] = "diiiiiiiiiiiiiiiiShhhhhhhhhhhbbbbbbbbbbbbbbbb";
char const ImportPriceArmorFormat[] = "dffff";
char const ImportPriceQualityFormat[] = "df";
char const ImportPriceShieldFormat[] = "df";
char const ImportPriceWeaponFormat[] = "df";
char const ItemFormat[] = "dibbbbbbb";
char const ItemAppearanceFormat[] = "diib";
char const ItemArmorQualityFormat[] = "dfffffffh";
char const ItemArmorShieldFormat[] = "dfffffffh";
char const ItemArmorTotalFormat[] = "dffffh";
char const ItemBagFamilyFormat[] = "ds";
char const ItemBonusFormat[] = "niihbb";
char const ItemBonusTreeNodeFormat[] = "dhhhb";
char const ItemClassFormat[] = "dfsb";
char const ItemCurrencyCostFormat[] = "di";
char const ItemDamageAmmoFormat[] = "dfffffffh";
char const ItemDamageOneHandFormat[] = "dfffffffh";
char const ItemDamageOneHandCasterFormat[] = "dfffffffh";
char const ItemDamageTwoHandFormat[] = "dfffffffh";
char const ItemDamageTwoHandCasterFormat[] = "dfffffffh";
char const ItemDisenchantLootFormat[] = "dhhhbbb";
char const ItemEffectFormat[] = "diiiihhhbb";
char const ItemExtendedCostFormat[] = "diiiiiiiiiiihhhhhhhhhhhbbbbb";
char const ItemLimitCategoryFormat[] = "dsbb";
char const ItemModifiedAppearanceFormat[] = "nihbb";
char const ItemPriceBaseFormat[] = "dffh";
char const ItemRandomPropertiesFormat[] = "dshhhhh";
char const ItemRandomSuffixFormat[] = "dsshhhhhhhhhh";
char const ItemSetFormat[] = "dsiiiiiiiiiiiiiiiiihb";
char const ItemSetSpellFormat[] = "dihhb";
char const ItemSparseFormat[] = "iiiffiiiiiiiiiiiiiiiiifffffffffffsssssififhhhhhhhhhhhhhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
char const ItemSpecFormat[] = "dhbbbbb";
char const ItemSpecOverrideFormat[] = "dih";
char const ItemToBattlePetSpeciesFormat[] = "dh";
char const ItemXBonusTreeFormat[] = "dih";
char const KeyChainFormat[] = "dbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
char const LockFormat[] = "diiiiiiiihhhhhhhhbbbbbbbbbbbbbbbb";
char const MailTemplateFormat[] = "ds";
char const ModifierTreeFormat[] = "diihbbbb";
char const MountFormat[] = "niissshhhb";
char const MountCapabilityFormat[] = "niihhhbb";
char const MountTypeXCapabilityFormat[] = "dhhb";
char const MovieFormat[] = "diibb";
char const NameGenFormat[] = "dsbb";
char const NamesProfanityFormat[] = "dSb";
char const NamesReservedFormat[] = "dS";
char const NamesReservedLocaleFormat[] = "dSb";
char const OverrideSpellDataFormat[] = "diiiiiiiiiiib";
char const PhaseXPhaseGroupFormat[] = "dhh";
char const PlayerConditionFormat[] = "diiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiisiihhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
char const PowerDisplayFormat[] = "dSbbbb";
char const PvpDifficultyFormat[] = "dhbbb";
char const QuestFactionRewardFormat[] = "dhhhhhhhhhh";
char const QuestMoneyRewardFormat[] = "diiiiiiiiii";
char const QuestPackageItemFormat[] = "dihbb";
char const QuestSortFormat[] = "ds";
char const QuestV2Format[] = "dh";
char const QuestXPFormat[] = "dhhhhhhhhhh";
char const RandPropPointsFormat[] = "dhhhhhhhhhhhhhhh";
char const ScalingStatDistributionFormat[] = "dhbb";
char const SkillLineFormat[] = "dssshhbbb";
char const SkillLineAbilityFormat[] = "diiiihhhhhhbb";
char const SkillRaceClassInfoFormat[] = "dihhhhbb";
char const SoundKitFormat[] = "nsffffffffhhbbbbb";
char const SpecializationSpellsFormat[] = "niishb";
char const SpellFormat[] = "nssssih";
char const SpellAuraOptionsFormat[] = "diiiihbbb";
char const SpellAuraRestrictionsFormat[] = "diiiiibbbbb";
char const SpellCastTimesFormat[] = "diih";
char const SpellCastingRequirementsFormat[] = "dihhhbbb";
char const SpellCategoriesFormat[] = "dihhhbbbbb";
char const SpellCategoryFormat[] = "dsibbb";
char const SpellClassOptionsFormat[] = "diiiiihb";
char const SpellCooldownsFormat[] = "diiiib";
char const SpellDurationFormat[] = "diih";
char const SpellEffectFormat[] = "nfiiffiiiiffiiiiifiifhhbbbbbbbb";
char const SpellEffectScalingFormat[] = "dfffi";
char const SpellEquippedItemsFormat[] = "diiib";
char const SpellFocusObjectFormat[] = "ds";
char const SpellInterruptsFormat[] = "diiiiihb";
char const SpellItemEnchantmentConditionFormat[] = "dbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
char const SpellLearnSpellFormat[] = "diii";
char const SpellLevelsFormat[] = "dihhhbb";
char const SpellMiscFormat[] = "diiiiiiiiiiiiiiffhhhhhb";
char const SpellPowerFormat[] = "niiffifhhhhbbb";
char const SpellPowerDifficultyFormat[] = "nbb";
char const SpellRadiusFormat[] = "dffff";
char const SpellRangeFormat[] = "dffffssb";
char const SpellReagentsFormat[] = "diiiiiiiiihhhhhhhh";
char const SpellScalingFormat[] = "dihbb";
char const SpellShapeshiftFormat[] = "diiiiib";
char const SpellShapeshiftFormFormat[] = "dsfihhhhhhhhhhhhhhbbb";
char const SpellTargetRestrictionsFormat[] = "diffihhbb";
char const SpellTotemsFormat[] = "diiibb";
char const SpellXSpellVisualFormat[] = "nifhhhbb";
char const SummonPropertiesFormat[] = "diiiii";
char const TaxiNodesFormat[] = "nfffsiiffhhhb";
char const TaxiPathFormat[] = "nhhh";
char const TaxiPathNodeFormat[] = "nfffihhhhbb";
char const TotemCategoryFormat[] = "dsib";
char const ToyFormat[] = "nisbb";
char const TransportAnimationFormat[] = "diifffb";
char const TransportRotationFormat[] = "diiffff";
char const UnitPowerBarFormat[] = "diffiiiiiiiiiiiissssffhhbbb";
char const VehicleSeatFormat[] = "diiiffffffffffffffffffffffffffffffffffihhhhhhhhhhhhhhhhhhhhhbbbbbb";
char const WorldMapOverlayFormat[] = "dShhhhhhhhhhhhhh";
char const WorldMapTransformsFormat[] = "dfffffffffhhhhb";

#endif
