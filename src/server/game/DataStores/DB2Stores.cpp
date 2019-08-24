/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "DB2Stores.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2LoadInfo.h"
#include "Hash.h"
#include "IteratorPair.h"
#include "Log.h"
#include "ObjectDefines.h"
#include "Regex.h"
#include "Timer.h"
#include "Util.h"
#include <array>
#include <numeric>
#include <sstream>
#include <cctype>

// temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

DB2Storage<AchievementEntry>                    sAchievementStore("Achievement.db2", AchievementLoadInfo::Instance());
DB2Storage<AnimationDataEntry>                  sAnimationDataStore("AnimationData.db2", AnimationDataLoadInfo::Instance());
DB2Storage<AnimKitEntry>                        sAnimKitStore("AnimKit.db2", AnimKitLoadInfo::Instance());
DB2Storage<AreaGroupMemberEntry>                sAreaGroupMemberStore("AreaGroupMember.db2", AreaGroupMemberLoadInfo::Instance());
DB2Storage<AreaTableEntry>                      sAreaTableStore("AreaTable.db2", AreaTableLoadInfo::Instance());
DB2Storage<AreaTriggerEntry>                    sAreaTriggerStore("AreaTrigger.db2", AreaTriggerLoadInfo::Instance());
DB2Storage<ArmorLocationEntry>                  sArmorLocationStore("ArmorLocation.db2", ArmorLocationLoadInfo::Instance());
DB2Storage<ArtifactEntry>                       sArtifactStore("Artifact.db2", ArtifactLoadInfo::Instance());
DB2Storage<ArtifactAppearanceEntry>             sArtifactAppearanceStore("ArtifactAppearance.db2", ArtifactAppearanceLoadInfo::Instance());
DB2Storage<ArtifactAppearanceSetEntry>          sArtifactAppearanceSetStore("ArtifactAppearanceSet.db2", ArtifactAppearanceSetLoadInfo::Instance());
DB2Storage<ArtifactCategoryEntry>               sArtifactCategoryStore("ArtifactCategory.db2", ArtifactCategoryLoadInfo::Instance());
DB2Storage<ArtifactPowerEntry>                  sArtifactPowerStore("ArtifactPower.db2", ArtifactPowerLoadInfo::Instance());
DB2Storage<ArtifactPowerLinkEntry>              sArtifactPowerLinkStore("ArtifactPowerLink.db2", ArtifactPowerLinkLoadInfo::Instance());
DB2Storage<ArtifactPowerPickerEntry>            sArtifactPowerPickerStore("ArtifactPowerPicker.db2", ArtifactPowerPickerLoadInfo::Instance());
DB2Storage<ArtifactPowerRankEntry>              sArtifactPowerRankStore("ArtifactPowerRank.db2", ArtifactPowerRankLoadInfo::Instance());
DB2Storage<ArtifactQuestXPEntry>                sArtifactQuestXPStore("ArtifactQuestXP.db2", ArtifactQuestXpLoadInfo::Instance());
DB2Storage<ArtifactTierEntry>                   sArtifactTierStore("ArtifactTier.db2", ArtifactTierLoadInfo::Instance());
DB2Storage<ArtifactUnlockEntry>                 sArtifactUnlockStore("ArtifactUnlock.db2", ArtifactUnlockLoadInfo::Instance());
DB2Storage<AuctionHouseEntry>                   sAuctionHouseStore("AuctionHouse.db2", AuctionHouseLoadInfo::Instance());
DB2Storage<BankBagSlotPricesEntry>              sBankBagSlotPricesStore("BankBagSlotPrices.db2", BankBagSlotPricesLoadInfo::Instance());
DB2Storage<BannedAddonsEntry>                   sBannedAddonsStore("BannedAddons.db2", BannedAddonsLoadInfo::Instance());
DB2Storage<BarberShopStyleEntry>                sBarberShopStyleStore("BarberShopStyle.db2", BarberShopStyleLoadInfo::Instance());
DB2Storage<BattlePetBreedQualityEntry>          sBattlePetBreedQualityStore("BattlePetBreedQuality.db2", BattlePetBreedQualityLoadInfo::Instance());
DB2Storage<BattlePetBreedStateEntry>            sBattlePetBreedStateStore("BattlePetBreedState.db2", BattlePetBreedStateLoadInfo::Instance());
DB2Storage<BattlePetSpeciesEntry>               sBattlePetSpeciesStore("BattlePetSpecies.db2", BattlePetSpeciesLoadInfo::Instance());
DB2Storage<BattlePetSpeciesStateEntry>          sBattlePetSpeciesStateStore("BattlePetSpeciesState.db2", BattlePetSpeciesStateLoadInfo::Instance());
DB2Storage<BattlemasterListEntry>               sBattlemasterListStore("BattlemasterList.db2", BattlemasterListLoadInfo::Instance());
DB2Storage<BroadcastTextEntry>                  sBroadcastTextStore("BroadcastText.db2", BroadcastTextLoadInfo::Instance());
DB2Storage<Cfg_RegionsEntry>                    sCfgRegionsStore("Cfg_Regions.db2", CfgRegionsLoadInfo::Instance());
DB2Storage<CharacterFacialHairStylesEntry>      sCharacterFacialHairStylesStore("CharacterFacialHairStyles.db2", CharacterFacialHairStylesLoadInfo::Instance());
DB2Storage<CharBaseSectionEntry>                sCharBaseSectionStore("CharBaseSection.db2", CharBaseSectionLoadInfo::Instance());
DB2Storage<CharSectionsEntry>                   sCharSectionsStore("CharSections.db2", CharSectionsLoadInfo::Instance());
DB2Storage<CharStartOutfitEntry>                sCharStartOutfitStore("CharStartOutfit.db2", CharStartOutfitLoadInfo::Instance());
DB2Storage<CharTitlesEntry>                     sCharTitlesStore("CharTitles.db2", CharTitlesLoadInfo::Instance());
DB2Storage<ChatChannelsEntry>                   sChatChannelsStore("ChatChannels.db2", ChatChannelsLoadInfo::Instance());
DB2Storage<ChrClassesEntry>                     sChrClassesStore("ChrClasses.db2", ChrClassesLoadInfo::Instance());
DB2Storage<ChrClassesXPowerTypesEntry>          sChrClassesXPowerTypesStore("ChrClassesXPowerTypes.db2", ChrClassesXPowerTypesLoadInfo::Instance());
DB2Storage<ChrRacesEntry>                       sChrRacesStore("ChrRaces.db2", ChrRacesLoadInfo::Instance());
DB2Storage<ChrSpecializationEntry>              sChrSpecializationStore("ChrSpecialization.db2", ChrSpecializationLoadInfo::Instance());
DB2Storage<CinematicCameraEntry>                sCinematicCameraStore("CinematicCamera.db2", CinematicCameraLoadInfo::Instance());
DB2Storage<CinematicSequencesEntry>             sCinematicSequencesStore("CinematicSequences.db2", CinematicSequencesLoadInfo::Instance());
DB2Storage<ContentTuningEntry>                  sContentTuningStore("ContentTuning.db2", ContentTuningLoadInfo::Instance());
DB2Storage<ContentTuningXExpectedEntry>         sContentTuningXExpectedStore("ContentTuningXExpected.db2", ContentTuningXExpectedLoadInfo::Instance());
DB2Storage<ConversationLineEntry>               sConversationLineStore("ConversationLine.db2", ConversationLineLoadInfo::Instance());
DB2Storage<CreatureDisplayInfoEntry>            sCreatureDisplayInfoStore("CreatureDisplayInfo.db2", CreatureDisplayInfoLoadInfo::Instance());
DB2Storage<CreatureDisplayInfoExtraEntry>       sCreatureDisplayInfoExtraStore("CreatureDisplayInfoExtra.db2", CreatureDisplayInfoExtraLoadInfo::Instance());
DB2Storage<CreatureFamilyEntry>                 sCreatureFamilyStore("CreatureFamily.db2", CreatureFamilyLoadInfo::Instance());
DB2Storage<CreatureModelDataEntry>              sCreatureModelDataStore("CreatureModelData.db2", CreatureModelDataLoadInfo::Instance());
DB2Storage<CreatureTypeEntry>                   sCreatureTypeStore("CreatureType.db2", CreatureTypeLoadInfo::Instance());
DB2Storage<CriteriaEntry>                       sCriteriaStore("Criteria.db2", CriteriaLoadInfo::Instance());
DB2Storage<CriteriaTreeEntry>                   sCriteriaTreeStore("CriteriaTree.db2", CriteriaTreeLoadInfo::Instance());
DB2Storage<CurrencyTypesEntry>                  sCurrencyTypesStore("CurrencyTypes.db2", CurrencyTypesLoadInfo::Instance());
DB2Storage<CurveEntry>                          sCurveStore("Curve.db2", CurveLoadInfo::Instance());
DB2Storage<CurvePointEntry>                     sCurvePointStore("CurvePoint.db2", CurvePointLoadInfo::Instance());
DB2Storage<DestructibleModelDataEntry>          sDestructibleModelDataStore("DestructibleModelData.db2", DestructibleModelDataLoadInfo::Instance());
DB2Storage<DifficultyEntry>                     sDifficultyStore("Difficulty.db2", DifficultyLoadInfo::Instance());
DB2Storage<DungeonEncounterEntry>               sDungeonEncounterStore("DungeonEncounter.db2", DungeonEncounterLoadInfo::Instance());
DB2Storage<DurabilityCostsEntry>                sDurabilityCostsStore("DurabilityCosts.db2", DurabilityCostsLoadInfo::Instance());
DB2Storage<DurabilityQualityEntry>              sDurabilityQualityStore("DurabilityQuality.db2", DurabilityQualityLoadInfo::Instance());
DB2Storage<EmotesEntry>                         sEmotesStore("Emotes.db2", EmotesLoadInfo::Instance());
DB2Storage<EmotesTextEntry>                     sEmotesTextStore("EmotesText.db2", EmotesTextLoadInfo::Instance());
DB2Storage<EmotesTextSoundEntry>                sEmotesTextSoundStore("EmotesTextSound.db2", EmotesTextSoundLoadInfo::Instance());
DB2Storage<ExpectedStatEntry>                   sExpectedStatStore("ExpectedStat.db2", ExpectedStatLoadInfo::Instance());
DB2Storage<ExpectedStatModEntry>                sExpectedStatModStore("ExpectedStatMod.db2", ExpectedStatModLoadInfo::Instance());
DB2Storage<FactionEntry>                        sFactionStore("Faction.db2", FactionLoadInfo::Instance());
DB2Storage<FactionTemplateEntry>                sFactionTemplateStore("FactionTemplate.db2", FactionTemplateLoadInfo::Instance());
DB2Storage<GameObjectDisplayInfoEntry>          sGameObjectDisplayInfoStore("GameObjectDisplayInfo.db2", GameobjectDisplayInfoLoadInfo::Instance());
DB2Storage<GameObjectsEntry>                    sGameObjectsStore("GameObjects.db2", GameobjectsLoadInfo::Instance());
DB2Storage<GarrAbilityEntry>                    sGarrAbilityStore("GarrAbility.db2", GarrAbilityLoadInfo::Instance());
DB2Storage<GarrBuildingEntry>                   sGarrBuildingStore("GarrBuilding.db2", GarrBuildingLoadInfo::Instance());
DB2Storage<GarrBuildingPlotInstEntry>           sGarrBuildingPlotInstStore("GarrBuildingPlotInst.db2", GarrBuildingPlotInstLoadInfo::Instance());
DB2Storage<GarrClassSpecEntry>                  sGarrClassSpecStore("GarrClassSpec.db2", GarrClassSpecLoadInfo::Instance());
DB2Storage<GarrFollowerEntry>                   sGarrFollowerStore("GarrFollower.db2", GarrFollowerLoadInfo::Instance());
DB2Storage<GarrFollowerXAbilityEntry>           sGarrFollowerXAbilityStore("GarrFollowerXAbility.db2", GarrFollowerXAbilityLoadInfo::Instance());
DB2Storage<GarrPlotEntry>                       sGarrPlotStore("GarrPlot.db2", GarrPlotLoadInfo::Instance());
DB2Storage<GarrPlotBuildingEntry>               sGarrPlotBuildingStore("GarrPlotBuilding.db2", GarrPlotBuildingLoadInfo::Instance());
DB2Storage<GarrPlotInstanceEntry>               sGarrPlotInstanceStore("GarrPlotInstance.db2", GarrPlotInstanceLoadInfo::Instance());
DB2Storage<GarrSiteLevelEntry>                  sGarrSiteLevelStore("GarrSiteLevel.db2", GarrSiteLevelLoadInfo::Instance());
DB2Storage<GarrSiteLevelPlotInstEntry>          sGarrSiteLevelPlotInstStore("GarrSiteLevelPlotInst.db2", GarrSiteLevelPlotInstLoadInfo::Instance());
DB2Storage<GemPropertiesEntry>                  sGemPropertiesStore("GemProperties.db2", GemPropertiesLoadInfo::Instance());
DB2Storage<GlyphBindableSpellEntry>             sGlyphBindableSpellStore("GlyphBindableSpell.db2", GlyphBindableSpellLoadInfo::Instance());
DB2Storage<GlyphPropertiesEntry>                sGlyphPropertiesStore("GlyphProperties.db2", GlyphPropertiesLoadInfo::Instance());
DB2Storage<GlyphRequiredSpecEntry>              sGlyphRequiredSpecStore("GlyphRequiredSpec.db2", GlyphRequiredSpecLoadInfo::Instance());
DB2Storage<GuildColorBackgroundEntry>           sGuildColorBackgroundStore("GuildColorBackground.db2", GuildColorBackgroundLoadInfo::Instance());
DB2Storage<GuildColorBorderEntry>               sGuildColorBorderStore("GuildColorBorder.db2", GuildColorBorderLoadInfo::Instance());
DB2Storage<GuildColorEmblemEntry>               sGuildColorEmblemStore("GuildColorEmblem.db2", GuildColorEmblemLoadInfo::Instance());
DB2Storage<GuildPerkSpellsEntry>                sGuildPerkSpellsStore("GuildPerkSpells.db2", GuildPerkSpellsLoadInfo::Instance());
DB2Storage<HeirloomEntry>                       sHeirloomStore("Heirloom.db2", HeirloomLoadInfo::Instance());
DB2Storage<HolidaysEntry>                       sHolidaysStore("Holidays.db2", HolidaysLoadInfo::Instance());
DB2Storage<ImportPriceArmorEntry>               sImportPriceArmorStore("ImportPriceArmor.db2", ImportPriceArmorLoadInfo::Instance());
DB2Storage<ImportPriceQualityEntry>             sImportPriceQualityStore("ImportPriceQuality.db2", ImportPriceQualityLoadInfo::Instance());
DB2Storage<ImportPriceShieldEntry>              sImportPriceShieldStore("ImportPriceShield.db2", ImportPriceShieldLoadInfo::Instance());
DB2Storage<ImportPriceWeaponEntry>              sImportPriceWeaponStore("ImportPriceWeapon.db2", ImportPriceWeaponLoadInfo::Instance());
DB2Storage<ItemAppearanceEntry>                 sItemAppearanceStore("ItemAppearance.db2", ItemAppearanceLoadInfo::Instance());
DB2Storage<ItemArmorQualityEntry>               sItemArmorQualityStore("ItemArmorQuality.db2", ItemArmorQualityLoadInfo::Instance());
DB2Storage<ItemArmorShieldEntry>                sItemArmorShieldStore("ItemArmorShield.db2", ItemArmorShieldLoadInfo::Instance());
DB2Storage<ItemArmorTotalEntry>                 sItemArmorTotalStore("ItemArmorTotal.db2", ItemArmorTotalLoadInfo::Instance());
DB2Storage<ItemBagFamilyEntry>                  sItemBagFamilyStore("ItemBagFamily.db2", ItemBagFamilyLoadInfo::Instance());
DB2Storage<ItemBonusEntry>                      sItemBonusStore("ItemBonus.db2", ItemBonusLoadInfo::Instance());
DB2Storage<ItemBonusListLevelDeltaEntry>        sItemBonusListLevelDeltaStore("ItemBonusListLevelDelta.db2", ItemBonusListLevelDeltaLoadInfo::Instance());
DB2Storage<ItemBonusTreeNodeEntry>              sItemBonusTreeNodeStore("ItemBonusTreeNode.db2", ItemBonusTreeNodeLoadInfo::Instance());
DB2Storage<ItemChildEquipmentEntry>             sItemChildEquipmentStore("ItemChildEquipment.db2", ItemChildEquipmentLoadInfo::Instance());
DB2Storage<ItemClassEntry>                      sItemClassStore("ItemClass.db2", ItemClassLoadInfo::Instance());
DB2Storage<ItemCurrencyCostEntry>               sItemCurrencyCostStore("ItemCurrencyCost.db2", ItemCurrencyCostLoadInfo::Instance());
DB2Storage<ItemDamageAmmoEntry>                 sItemDamageAmmoStore("ItemDamageAmmo.db2", ItemDamageAmmoLoadInfo::Instance());
DB2Storage<ItemDamageOneHandEntry>              sItemDamageOneHandStore("ItemDamageOneHand.db2", ItemDamageOneHandLoadInfo::Instance());
DB2Storage<ItemDamageOneHandCasterEntry>        sItemDamageOneHandCasterStore("ItemDamageOneHandCaster.db2", ItemDamageOneHandCasterLoadInfo::Instance());
DB2Storage<ItemDamageTwoHandEntry>              sItemDamageTwoHandStore("ItemDamageTwoHand.db2", ItemDamageTwoHandLoadInfo::Instance());
DB2Storage<ItemDamageTwoHandCasterEntry>        sItemDamageTwoHandCasterStore("ItemDamageTwoHandCaster.db2", ItemDamageTwoHandCasterLoadInfo::Instance());
DB2Storage<ItemDisenchantLootEntry>             sItemDisenchantLootStore("ItemDisenchantLoot.db2", ItemDisenchantLootLoadInfo::Instance());
DB2Storage<ItemEffectEntry>                     sItemEffectStore("ItemEffect.db2", ItemEffectLoadInfo::Instance());
DB2Storage<ItemEntry>                           sItemStore("Item.db2", ItemLoadInfo::Instance());
DB2Storage<ItemExtendedCostEntry>               sItemExtendedCostStore("ItemExtendedCost.db2", ItemExtendedCostLoadInfo::Instance());
DB2Storage<ItemLevelSelectorEntry>              sItemLevelSelectorStore("ItemLevelSelector.db2", ItemLevelSelectorLoadInfo::Instance());
DB2Storage<ItemLevelSelectorQualityEntry>       sItemLevelSelectorQualityStore("ItemLevelSelectorQuality.db2", ItemLevelSelectorQualityLoadInfo::Instance());
DB2Storage<ItemLevelSelectorQualitySetEntry>    sItemLevelSelectorQualitySetStore("ItemLevelSelectorQualitySet.db2", ItemLevelSelectorQualitySetLoadInfo::Instance());
DB2Storage<ItemLimitCategoryEntry>              sItemLimitCategoryStore("ItemLimitCategory.db2", ItemLimitCategoryLoadInfo::Instance());
DB2Storage<ItemLimitCategoryConditionEntry>     sItemLimitCategoryConditionStore("ItemLimitCategoryCondition.db2", ItemLimitCategoryConditionLoadInfo::Instance());
DB2Storage<ItemModifiedAppearanceEntry>         sItemModifiedAppearanceStore("ItemModifiedAppearance.db2", ItemModifiedAppearanceLoadInfo::Instance());
DB2Storage<ItemPriceBaseEntry>                  sItemPriceBaseStore("ItemPriceBase.db2", ItemPriceBaseLoadInfo::Instance());
DB2Storage<ItemSearchNameEntry>                 sItemSearchNameStore("ItemSearchName.db2", ItemSearchNameLoadInfo::Instance());
DB2Storage<ItemSetEntry>                        sItemSetStore("ItemSet.db2", ItemSetLoadInfo::Instance());
DB2Storage<ItemSetSpellEntry>                   sItemSetSpellStore("ItemSetSpell.db2", ItemSetSpellLoadInfo::Instance());
DB2Storage<ItemSparseEntry>                     sItemSparseStore("ItemSparse.db2", ItemSparseLoadInfo::Instance());
DB2Storage<ItemSpecEntry>                       sItemSpecStore("ItemSpec.db2", ItemSpecLoadInfo::Instance());
DB2Storage<ItemSpecOverrideEntry>               sItemSpecOverrideStore("ItemSpecOverride.db2", ItemSpecOverrideLoadInfo::Instance());
DB2Storage<ItemUpgradeEntry>                    sItemUpgradeStore("ItemUpgrade.db2", ItemUpgradeLoadInfo::Instance());
DB2Storage<ItemXBonusTreeEntry>                 sItemXBonusTreeStore("ItemXBonusTree.db2", ItemXBonusTreeLoadInfo::Instance());
DB2Storage<KeychainEntry>                       sKeychainStore("Keychain.db2", KeychainLoadInfo::Instance());
DB2Storage<LFGDungeonsEntry>                    sLFGDungeonsStore("LFGDungeons.db2", LfgDungeonsLoadInfo::Instance());
DB2Storage<LightEntry>                          sLightStore("Light.db2", LightLoadInfo::Instance());
DB2Storage<LiquidTypeEntry>                     sLiquidTypeStore("LiquidType.db2", LiquidTypeLoadInfo::Instance());
DB2Storage<LockEntry>                           sLockStore("Lock.db2", LockLoadInfo::Instance());
DB2Storage<MailTemplateEntry>                   sMailTemplateStore("MailTemplate.db2", MailTemplateLoadInfo::Instance());
DB2Storage<MapEntry>                            sMapStore("Map.db2", MapLoadInfo::Instance());
DB2Storage<MapDifficultyEntry>                  sMapDifficultyStore("MapDifficulty.db2", MapDifficultyLoadInfo::Instance());
DB2Storage<ModifierTreeEntry>                   sModifierTreeStore("ModifierTree.db2", ModifierTreeLoadInfo::Instance());
DB2Storage<MountCapabilityEntry>                sMountCapabilityStore("MountCapability.db2", MountCapabilityLoadInfo::Instance());
DB2Storage<MountEntry>                          sMountStore("Mount.db2", MountLoadInfo::Instance());
DB2Storage<MountTypeXCapabilityEntry>           sMountTypeXCapabilityStore("MountTypeXCapability.db2", MountTypeXCapabilityLoadInfo::Instance());
DB2Storage<MountXDisplayEntry>                  sMountXDisplayStore("MountXDisplay.db2", MountXDisplayLoadInfo::Instance());
DB2Storage<MovieEntry>                          sMovieStore("Movie.db2", MovieLoadInfo::Instance());
DB2Storage<NameGenEntry>                        sNameGenStore("NameGen.db2", NameGenLoadInfo::Instance());
DB2Storage<NamesProfanityEntry>                 sNamesProfanityStore("NamesProfanity.db2", NamesProfanityLoadInfo::Instance());
DB2Storage<NamesReservedEntry>                  sNamesReservedStore("NamesReserved.db2", NamesReservedLoadInfo::Instance());
DB2Storage<NamesReservedLocaleEntry>            sNamesReservedLocaleStore("NamesReservedLocale.db2", NamesReservedLocaleLoadInfo::Instance());
DB2Storage<NumTalentsAtLevelEntry>              sNumTalentsAtLevelStore("NumTalentsAtLevel.db2", NumTalentsAtLevelLoadInfo::Instance());
DB2Storage<OverrideSpellDataEntry>              sOverrideSpellDataStore("OverrideSpellData.db2", OverrideSpellDataLoadInfo::Instance());
DB2Storage<PhaseEntry>                          sPhaseStore("Phase.db2", PhaseLoadInfo::Instance());
DB2Storage<PhaseXPhaseGroupEntry>               sPhaseXPhaseGroupStore("PhaseXPhaseGroup.db2", PhaseXPhaseGroupLoadInfo::Instance());
DB2Storage<PlayerConditionEntry>                sPlayerConditionStore("PlayerCondition.db2", PlayerConditionLoadInfo::Instance());
DB2Storage<PowerDisplayEntry>                   sPowerDisplayStore("PowerDisplay.db2", PowerDisplayLoadInfo::Instance());
DB2Storage<PowerTypeEntry>                      sPowerTypeStore("PowerType.db2", PowerTypeLoadInfo::Instance());
DB2Storage<PrestigeLevelInfoEntry>              sPrestigeLevelInfoStore("PrestigeLevelInfo.db2", PrestigeLevelInfoLoadInfo::Instance());
DB2Storage<PVPDifficultyEntry>                  sPVPDifficultyStore("PVPDifficulty.db2", PvpDifficultyLoadInfo::Instance());
DB2Storage<PVPItemEntry>                        sPVPItemStore("PVPItem.db2", PvpItemLoadInfo::Instance());
DB2Storage<PvpTalentEntry>                      sPvpTalentStore("PvpTalent.db2", PvpTalentLoadInfo::Instance());
DB2Storage<PvpTalentCategoryEntry>              sPvpTalentCategoryStore("PvpTalentCategory.db2", PvpTalentCategoryLoadInfo::Instance());
DB2Storage<PvpTalentSlotUnlockEntry>            sPvpTalentSlotUnlockStore("PvpTalentSlotUnlock.db2", PvpTalentSlotUnlockLoadInfo::Instance());
DB2Storage<QuestFactionRewardEntry>             sQuestFactionRewardStore("QuestFactionReward.db2", QuestFactionRewardLoadInfo::Instance());
DB2Storage<QuestMoneyRewardEntry>               sQuestMoneyRewardStore("QuestMoneyReward.db2", QuestMoneyRewardLoadInfo::Instance());
DB2Storage<QuestPackageItemEntry>               sQuestPackageItemStore("QuestPackageItem.db2", QuestPackageItemLoadInfo::Instance());
DB2Storage<QuestSortEntry>                      sQuestSortStore("QuestSort.db2", QuestSortLoadInfo::Instance());
DB2Storage<QuestV2Entry>                        sQuestV2Store("QuestV2.db2", QuestV2LoadInfo::Instance());
DB2Storage<QuestXPEntry>                        sQuestXPStore("QuestXP.db2", QuestXpLoadInfo::Instance());
DB2Storage<RandPropPointsEntry>                 sRandPropPointsStore("RandPropPoints.db2", RandPropPointsLoadInfo::Instance());
DB2Storage<RewardPackEntry>                     sRewardPackStore("RewardPack.db2", RewardPackLoadInfo::Instance());
DB2Storage<RewardPackXCurrencyTypeEntry>        sRewardPackXCurrencyTypeStore("RewardPackXCurrencyType.db2", RewardPackXCurrencyTypeLoadInfo::Instance());
DB2Storage<RewardPackXItemEntry>                sRewardPackXItemStore("RewardPackXItem.db2", RewardPackXItemLoadInfo::Instance());
DB2Storage<RulesetItemUpgradeEntry>             sRulesetItemUpgradeStore("RulesetItemUpgrade.db2", RulesetItemUpgradeLoadInfo::Instance());
DB2Storage<ScalingStatDistributionEntry>        sScalingStatDistributionStore("ScalingStatDistribution.db2", ScalingStatDistributionLoadInfo::Instance());
DB2Storage<ScenarioEntry>                       sScenarioStore("Scenario.db2", ScenarioLoadInfo::Instance());
DB2Storage<ScenarioStepEntry>                   sScenarioStepStore("ScenarioStep.db2", ScenarioStepLoadInfo::Instance());
DB2Storage<SceneScriptEntry>                    sSceneScriptStore("SceneScript.db2", SceneScriptLoadInfo::Instance());
DB2Storage<SceneScriptGlobalTextEntry>          sSceneScriptGlobalTextStore("SceneScriptGlobalText.db2", SceneScriptGlobalTextLoadInfo::Instance());
DB2Storage<SceneScriptPackageEntry>             sSceneScriptPackageStore("SceneScriptPackage.db2", SceneScriptPackageLoadInfo::Instance());
DB2Storage<SceneScriptTextEntry>                sSceneScriptTextStore("SceneScriptText.db2", SceneScriptTextLoadInfo::Instance());
DB2Storage<SkillLineEntry>                      sSkillLineStore("SkillLine.db2", SkillLineLoadInfo::Instance());
DB2Storage<SkillLineAbilityEntry>               sSkillLineAbilityStore("SkillLineAbility.db2", SkillLineAbilityLoadInfo::Instance());
DB2Storage<SkillRaceClassInfoEntry>             sSkillRaceClassInfoStore("SkillRaceClassInfo.db2", SkillRaceClassInfoLoadInfo::Instance());
DB2Storage<SoundKitEntry>                       sSoundKitStore("SoundKit.db2", SoundKitLoadInfo::Instance());
DB2Storage<SpecializationSpellsEntry>           sSpecializationSpellsStore("SpecializationSpells.db2", SpecializationSpellsLoadInfo::Instance());
DB2Storage<SpellAuraOptionsEntry>               sSpellAuraOptionsStore("SpellAuraOptions.db2", SpellAuraOptionsLoadInfo::Instance());
DB2Storage<SpellAuraRestrictionsEntry>          sSpellAuraRestrictionsStore("SpellAuraRestrictions.db2", SpellAuraRestrictionsLoadInfo::Instance());
DB2Storage<SpellCastTimesEntry>                 sSpellCastTimesStore("SpellCastTimes.db2", SpellCastTimesLoadInfo::Instance());
DB2Storage<SpellCastingRequirementsEntry>       sSpellCastingRequirementsStore("SpellCastingRequirements.db2", SpellCastingRequirementsLoadInfo::Instance());
DB2Storage<SpellCategoriesEntry>                sSpellCategoriesStore("SpellCategories.db2", SpellCategoriesLoadInfo::Instance());
DB2Storage<SpellCategoryEntry>                  sSpellCategoryStore("SpellCategory.db2", SpellCategoryLoadInfo::Instance());
DB2Storage<SpellClassOptionsEntry>              sSpellClassOptionsStore("SpellClassOptions.db2", SpellClassOptionsLoadInfo::Instance());
DB2Storage<SpellCooldownsEntry>                 sSpellCooldownsStore("SpellCooldowns.db2", SpellCooldownsLoadInfo::Instance());
DB2Storage<SpellDurationEntry>                  sSpellDurationStore("SpellDuration.db2", SpellDurationLoadInfo::Instance());
DB2Storage<SpellEffectEntry>                    sSpellEffectStore("SpellEffect.db2", SpellEffectLoadInfo::Instance());
DB2Storage<SpellEquippedItemsEntry>             sSpellEquippedItemsStore("SpellEquippedItems.db2", SpellEquippedItemsLoadInfo::Instance());
DB2Storage<SpellFocusObjectEntry>               sSpellFocusObjectStore("SpellFocusObject.db2", SpellFocusObjectLoadInfo::Instance());
DB2Storage<SpellInterruptsEntry>                sSpellInterruptsStore("SpellInterrupts.db2", SpellInterruptsLoadInfo::Instance());
DB2Storage<SpellItemEnchantmentEntry>           sSpellItemEnchantmentStore("SpellItemEnchantment.db2", SpellItemEnchantmentLoadInfo::Instance());
DB2Storage<SpellItemEnchantmentConditionEntry>  sSpellItemEnchantmentConditionStore("SpellItemEnchantmentCondition.db2", SpellItemEnchantmentConditionLoadInfo::Instance());
DB2Storage<SpellLearnSpellEntry>                sSpellLearnSpellStore("SpellLearnSpell.db2", SpellLearnSpellLoadInfo::Instance());
DB2Storage<SpellLevelsEntry>                    sSpellLevelsStore("SpellLevels.db2", SpellLevelsLoadInfo::Instance());
DB2Storage<SpellMiscEntry>                      sSpellMiscStore("SpellMisc.db2", SpellMiscLoadInfo::Instance());
DB2Storage<SpellNameEntry>                      sSpellNameStore("SpellName.db2", SpellNameLoadInfo::Instance());
DB2Storage<SpellPowerEntry>                     sSpellPowerStore("SpellPower.db2", SpellPowerLoadInfo::Instance());
DB2Storage<SpellPowerDifficultyEntry>           sSpellPowerDifficultyStore("SpellPowerDifficulty.db2", SpellPowerDifficultyLoadInfo::Instance());
DB2Storage<SpellProcsPerMinuteEntry>            sSpellProcsPerMinuteStore("SpellProcsPerMinute.db2", SpellProcsPerMinuteLoadInfo::Instance());
DB2Storage<SpellProcsPerMinuteModEntry>         sSpellProcsPerMinuteModStore("SpellProcsPerMinuteMod.db2", SpellProcsPerMinuteModLoadInfo::Instance());
DB2Storage<SpellRadiusEntry>                    sSpellRadiusStore("SpellRadius.db2", SpellRadiusLoadInfo::Instance());
DB2Storage<SpellRangeEntry>                     sSpellRangeStore("SpellRange.db2", SpellRangeLoadInfo::Instance());
DB2Storage<SpellReagentsEntry>                  sSpellReagentsStore("SpellReagents.db2", SpellReagentsLoadInfo::Instance());
DB2Storage<SpellScalingEntry>                   sSpellScalingStore("SpellScaling.db2", SpellScalingLoadInfo::Instance());
DB2Storage<SpellShapeshiftEntry>                sSpellShapeshiftStore("SpellShapeshift.db2", SpellShapeshiftLoadInfo::Instance());
DB2Storage<SpellShapeshiftFormEntry>            sSpellShapeshiftFormStore("SpellShapeshiftForm.db2", SpellShapeshiftFormLoadInfo::Instance());
DB2Storage<SpellTargetRestrictionsEntry>        sSpellTargetRestrictionsStore("SpellTargetRestrictions.db2", SpellTargetRestrictionsLoadInfo::Instance());
DB2Storage<SpellTotemsEntry>                    sSpellTotemsStore("SpellTotems.db2", SpellTotemsLoadInfo::Instance());
DB2Storage<SpellXSpellVisualEntry>              sSpellXSpellVisualStore("SpellXSpellVisual.db2", SpellXSpellVisualLoadInfo::Instance());
DB2Storage<SummonPropertiesEntry>               sSummonPropertiesStore("SummonProperties.db2", SummonPropertiesLoadInfo::Instance());
DB2Storage<TactKeyEntry>                        sTactKeyStore("TactKey.db2", TactKeyLoadInfo::Instance());
DB2Storage<TalentEntry>                         sTalentStore("Talent.db2", TalentLoadInfo::Instance());
DB2Storage<TaxiNodesEntry>                      sTaxiNodesStore("TaxiNodes.db2", TaxiNodesLoadInfo::Instance());
DB2Storage<TaxiPathEntry>                       sTaxiPathStore("TaxiPath.db2", TaxiPathLoadInfo::Instance());
DB2Storage<TaxiPathNodeEntry>                   sTaxiPathNodeStore("TaxiPathNode.db2", TaxiPathNodeLoadInfo::Instance());
DB2Storage<TotemCategoryEntry>                  sTotemCategoryStore("TotemCategory.db2", TotemCategoryLoadInfo::Instance());
DB2Storage<ToyEntry>                            sToyStore("Toy.db2", ToyLoadInfo::Instance());
DB2Storage<TransmogHolidayEntry>                sTransmogHolidayStore("TransmogHoliday.db2", TransmogHolidayLoadInfo::Instance());
DB2Storage<TransmogSetEntry>                    sTransmogSetStore("TransmogSet.db2", TransmogSetLoadInfo::Instance());
DB2Storage<TransmogSetGroupEntry>               sTransmogSetGroupStore("TransmogSetGroup.db2", TransmogSetGroupLoadInfo::Instance());
DB2Storage<TransmogSetItemEntry>                sTransmogSetItemStore("TransmogSetItem.db2", TransmogSetItemLoadInfo::Instance());
DB2Storage<TransportAnimationEntry>             sTransportAnimationStore("TransportAnimation.db2", TransportAnimationLoadInfo::Instance());
DB2Storage<TransportRotationEntry>              sTransportRotationStore("TransportRotation.db2", TransportRotationLoadInfo::Instance());
DB2Storage<UiMapEntry>                          sUiMapStore("UiMap.db2", UiMapLoadInfo::Instance());
DB2Storage<UiMapAssignmentEntry>                sUiMapAssignmentStore("UiMapAssignment.db2", UiMapAssignmentLoadInfo::Instance());
DB2Storage<UiMapLinkEntry>                      sUiMapLinkStore("UiMapLink.db2", UiMapLinkLoadInfo::Instance());
DB2Storage<UiMapXMapArtEntry>                   sUiMapXMapArtStore("UiMapXMapArt.db2", UiMapXMapArtLoadInfo::Instance());
DB2Storage<UnitPowerBarEntry>                   sUnitPowerBarStore("UnitPowerBar.db2", UnitPowerBarLoadInfo::Instance());
DB2Storage<VehicleEntry>                        sVehicleStore("Vehicle.db2", VehicleLoadInfo::Instance());
DB2Storage<VehicleSeatEntry>                    sVehicleSeatStore("VehicleSeat.db2", VehicleSeatLoadInfo::Instance());
DB2Storage<WMOAreaTableEntry>                   sWMOAreaTableStore("WMOAreaTable.db2", WmoAreaTableLoadInfo::Instance());
DB2Storage<WorldEffectEntry>                    sWorldEffectStore("WorldEffect.db2", WorldEffectLoadInfo::Instance());
DB2Storage<WorldMapOverlayEntry>                sWorldMapOverlayStore("WorldMapOverlay.db2", WorldMapOverlayLoadInfo::Instance());
DB2Storage<WorldSafeLocsEntry>                  sWorldSafeLocsStore("WorldSafeLocs.db2", WorldSafeLocsLoadInfo::Instance());
DB2Storage<WorldStateExpressionEntry>           sWorldStateExpressionStore("WorldStateExpression.db2", WorldStateExpressionLoadInfo::Instance());

TaxiMask                                        sTaxiNodesMask;
TaxiMask                                        sOldContinentsNodesMask;
TaxiMask                                        sHordeTaxiNodesMask;
TaxiMask                                        sAllianceTaxiNodesMask;
TaxiPathSetBySource                             sTaxiPathSetBySource;
TaxiPathNodesByPath                             sTaxiPathNodesByPath;

DEFINE_DB2_SET_COMPARATOR(ChrClassesXPowerTypesEntry)

struct ItemLevelSelectorQualityEntryComparator
{
    bool operator()(ItemLevelSelectorQualityEntry const* left, ItemLevelSelectorQualityEntry const* right) const { return Compare(left, right); }
    bool operator()(ItemLevelSelectorQualityEntry const* left, ItemQualities quality) const { return left->Quality < quality; }
    static bool Compare(ItemLevelSelectorQualityEntry const* left, ItemLevelSelectorQualityEntry const* right);
};

typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;
typedef std::unordered_map<uint32 /*areaGroupId*/, std::vector<uint32/*areaId*/>> AreaGroupMemberContainer;
typedef std::unordered_map<uint32, std::vector<ArtifactPowerEntry const*>> ArtifactPowersContainer;
typedef std::unordered_map<uint32, std::unordered_set<uint32>> ArtifactPowerLinksContainer;
typedef std::unordered_map<std::pair<uint32, uint8>, ArtifactPowerRankEntry const*> ArtifactPowerRanksContainer;
typedef std::unordered_map<uint32, CharStartOutfitEntry const*> CharStartOutfitContainer;
typedef ChrSpecializationEntry const* ChrSpecializationByIndexContainer[MAX_CLASSES + 1][MAX_SPECIALIZATIONS];
typedef std::unordered_map<uint32, ChrSpecializationEntry const*> ChrSpecialzationByClassContainer;
typedef std::unordered_map<uint32 /*curveID*/, std::vector<CurvePointEntry const*>> CurvePointsContainer;
typedef std::map<std::tuple<uint32, uint8, uint8, uint8>, EmotesTextSoundEntry const*> EmotesTextSoundContainer;
typedef std::unordered_map<uint32, std::vector<uint32>> FactionTeamContainer;
typedef std::unordered_map<uint32, HeirloomEntry const*> HeirloomItemsContainer;
typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<uint32>> GlyphBindableSpellsContainer;
typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<uint32>> GlyphRequiredSpecsContainer;
typedef std::unordered_map<uint32 /*bonusListId*/, DB2Manager::ItemBonusList> ItemBonusListContainer;
typedef std::unordered_map<int16, uint32> ItemBonusListLevelDeltaContainer;
typedef std::unordered_multimap<uint32 /*itemId*/, uint32 /*bonusTreeId*/> ItemToBonusTreeContainer;
typedef std::unordered_map<uint32 /*itemId*/, ItemChildEquipmentEntry const*> ItemChildEquipmentContainer;
typedef std::array<ItemClassEntry const*, 19> ItemClassByOldEnumContainer;
typedef std::unordered_map<uint32, std::vector<ItemLimitCategoryConditionEntry const*>> ItemLimitCategoryConditionContainer;
typedef std::set<ItemLevelSelectorQualityEntry const*, ItemLevelSelectorQualityEntryComparator> ItemLevelSelectorQualities;
typedef std::unordered_map<uint32 /*itemId | appearanceMod << 24*/, ItemModifiedAppearanceEntry const*> ItemModifiedAppearanceByItemContainer;
typedef std::unordered_map<uint32, std::set<ItemBonusTreeNodeEntry const*>> ItemBonusTreeContainer;
typedef std::unordered_map<uint32, std::vector<ItemSetSpellEntry const*>> ItemSetSpellContainer;
typedef std::unordered_map<uint32, std::vector<ItemSpecOverrideEntry const*>> ItemSpecOverridesContainer;
typedef std::unordered_map<uint32, DB2Manager::MountTypeXCapabilitySet> MountCapabilitiesByTypeContainer;
typedef std::unordered_map<uint32, DB2Manager::MountXDisplayContainer> MountDisplaysCointainer;
typedef std::unordered_map<uint32, std::array<std::vector<NameGenEntry const*>, 2>> NameGenContainer;
typedef std::array<std::vector<Trinity::wregex>, TOTAL_LOCALES + 1> NameValidationRegexContainer;
typedef std::unordered_map<uint32, std::vector<uint32>> PhaseGroupContainer;
typedef std::array<PowerTypeEntry const*, MAX_POWERS> PowerTypesContainer;
typedef std::unordered_map<uint32, std::pair<std::vector<QuestPackageItemEntry const*>, std::vector<QuestPackageItemEntry const*>>> QuestPackageItemContainer;
typedef std::unordered_map<uint32, uint32> RulesetItemUpgradeContainer;
typedef std::unordered_multimap<uint32, SkillRaceClassInfoEntry const*> SkillRaceClassInfoContainer;
typedef std::unordered_map<uint32, std::vector<SpecializationSpellsEntry const*>> SpecializationSpellsContainer;
typedef std::unordered_map<uint32, std::vector<SpellPowerEntry const*>> SpellPowerContainer;
typedef std::unordered_map<uint32, std::unordered_map<uint32, std::vector<SpellPowerEntry const*>>> SpellPowerDifficultyContainer;
typedef std::unordered_map<uint32, std::vector<SpellProcsPerMinuteModEntry const*>> SpellProcsPerMinuteModContainer;
typedef std::vector<TalentEntry const*> TalentsByPosition[MAX_CLASSES][MAX_TALENT_TIERS][MAX_TALENT_COLUMNS];
typedef std::unordered_set<uint32> ToyItemIdsContainer;
typedef std::tuple<uint16, uint8, int32> WMOAreaTableKey;
typedef std::map<WMOAreaTableKey, WMOAreaTableEntry const*> WMOAreaTableLookupContainer;

namespace
{
    struct UiMapBounds
    {
        // these coords are mixed when calculated and used... its a mess
        float Bounds[4];
        bool IsUiAssignment;
        bool IsUiLink;
    };

    StorageMap _stores;
    uint32 _hotfixCount = 0;
    DB2Manager::HotfixContainer _hotfixData;
    std::map<std::pair<uint32 /*tableHash*/, int32 /*recordId*/>, std::vector<uint8>> _hotfixBlob;

    AreaGroupMemberContainer _areaGroupMembers;
    ArtifactPowersContainer _artifactPowers;
    ArtifactPowerLinksContainer _artifactPowerLinks;
    ArtifactPowerRanksContainer _artifactPowerRanks;
    std::set<std::tuple<uint8, uint8, uint32>> _characterFacialHairStyles;
    std::multimap<std::tuple<uint8, uint8, CharBaseSectionVariation>, CharSectionsEntry const*> _charSections;
    CharStartOutfitContainer _charStartOutfits;
    uint32 _powersByClass[MAX_CLASSES][MAX_POWERS];
    ChrSpecializationByIndexContainer _chrSpecializationsByIndex;
    ChrSpecialzationByClassContainer _defaultChrSpecializationsByClass;
    CurvePointsContainer _curvePoints;
    EmotesTextSoundContainer _emoteTextSounds;
    std::unordered_map<std::pair<uint32 /*level*/, int32 /*expansion*/>, ExpectedStatEntry const*> _expectedStatsByLevel;
    std::unordered_map<uint32 /*contentTuningId*/, std::vector<ExpectedStatModEntry const*>> _expectedStatModsByContentTuning;
    FactionTeamContainer _factionTeams;
    HeirloomItemsContainer _heirlooms;
    GlyphBindableSpellsContainer _glyphBindableSpells;
    GlyphRequiredSpecsContainer _glyphRequiredSpecs;
    ItemBonusListContainer _itemBonusLists;
    ItemBonusListLevelDeltaContainer _itemLevelDeltaToBonusListContainer;
    ItemBonusTreeContainer _itemBonusTrees;
    ItemChildEquipmentContainer _itemChildEquipment;
    ItemClassByOldEnumContainer _itemClassByOldEnum;
    std::unordered_set<uint32> _itemsWithCurrencyCost;
    ItemLimitCategoryConditionContainer _itemCategoryConditions;
    std::unordered_map<uint32 /*itemLevelSelectorQualitySetId*/, ItemLevelSelectorQualities> _itemLevelQualitySelectorQualities;
    ItemModifiedAppearanceByItemContainer _itemModifiedAppearancesByItem;
    ItemToBonusTreeContainer _itemToBonusTree;
    ItemSetSpellContainer _itemSetSpells;
    ItemSpecOverridesContainer _itemSpecOverrides;
    DB2Manager::MapDifficultyContainer _mapDifficulties;
    std::unordered_map<uint32, MountEntry const*> _mountsBySpellId;
    MountCapabilitiesByTypeContainer _mountCapabilitiesByType;
    MountDisplaysCointainer _mountDisplays;
    NameGenContainer _nameGenData;
    NameValidationRegexContainer _nameValidators;
    PhaseGroupContainer _phasesByGroup;
    PowerTypesContainer _powerTypes;
    std::unordered_map<uint32, uint8> _pvpItemBonus;
    PvpTalentSlotUnlockEntry const* _pvpTalentSlotUnlock[MAX_PVP_TALENT_SLOTS];
    QuestPackageItemContainer _questPackages;
    std::unordered_map<uint32, std::vector<RewardPackXCurrencyTypeEntry const*>> _rewardPackCurrencyTypes;
    std::unordered_map<uint32, std::vector<RewardPackXItemEntry const*>> _rewardPackItems;
    RulesetItemUpgradeContainer _rulesetItemUpgrade;
    std::unordered_map<uint32, std::vector<SkillLineEntry const*>> _skillLinesByParentSkillLine;
    std::unordered_map<uint32, std::vector<SkillLineAbilityEntry const*>> _skillLineAbilitiesBySkillupSkill;
    SkillRaceClassInfoContainer _skillRaceClassInfoBySkill;
    SpecializationSpellsContainer _specializationSpellsBySpec;
    std::unordered_set<uint8> _spellFamilyNames;
    SpellPowerContainer _spellPowers;
    SpellPowerDifficultyContainer _spellPowerDifficulties;
    SpellProcsPerMinuteModContainer _spellProcsPerMinuteMods;
    TalentsByPosition _talentsByPosition;
    ToyItemIdsContainer _toys;
    std::unordered_map<uint32, std::vector<TransmogSetEntry const*>> _transmogSetsByItemModifiedAppearance;
    std::unordered_map<uint32, std::vector<TransmogSetItemEntry const*>> _transmogSetItemsByTransmogSet;
    std::unordered_map<int32, UiMapBounds> _uiMapBounds;
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByMap[MAX_UI_MAP_SYSTEM];
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByArea[MAX_UI_MAP_SYSTEM];
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByWmoDoodadPlacement[MAX_UI_MAP_SYSTEM];
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByWmoGroup[MAX_UI_MAP_SYSTEM];
    std::unordered_set<int32> _uiMapPhases;
    WMOAreaTableLookupContainer _wmoAreaTableLookup;
}

template<class T, template<class> class DB2>
inline void LoadDB2(uint32& availableDb2Locales, std::vector<std::string>& errlist, StorageMap& stores, DB2StorageBase* storage, std::string const& db2Path, uint32 defaultLocale, DB2<T> const& /*hint*/)
{
    // validate structure
    DB2LoadInfo const* loadInfo = storage->GetLoadInfo();
    {
        std::string clientMetaString, ourMetaString;
        for (std::size_t i = 0; i < loadInfo->Meta->FieldCount; ++i)
            for (std::size_t j = 0; j < loadInfo->Meta->Fields[i].ArraySize; ++j)
                clientMetaString += loadInfo->Meta->Fields[i].Type;

        for (std::size_t i = loadInfo->Meta->HasIndexFieldInData() ? 0 : 1; i < loadInfo->FieldCount; ++i)
            ourMetaString += loadInfo->Fields[i].Type;

        ASSERT(clientMetaString == ourMetaString,
            "%s C++ structure fields %s do not match generated types from the client %s",
            storage->GetFileName().c_str(), ourMetaString.c_str(), clientMetaString.c_str());

        // compatibility format and C++ structure sizes
        ASSERT(loadInfo->Meta->GetRecordSize() == sizeof(T),
            "Size of '%s' set by format string (%u) not equal size of C++ structure (" SZFMTD ").",
            storage->GetFileName().c_str(), loadInfo->Meta->GetRecordSize(), sizeof(T));
    }

    if (storage->Load(db2Path + localeNames[defaultLocale] + '/', defaultLocale))
    {
       storage->LoadFromDB();
        // LoadFromDB() always loads strings into enUS locale, other locales are expected to have data in corresponding _locale tables
        // so we need to make additional call to load that data in case said locale is set as default by worldserver.conf (and we do not want to load all this data from .db2 file again)
        if (defaultLocale != LOCALE_enUS)
            storage->LoadStringsFromDB(defaultLocale);

        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (defaultLocale == i || i == LOCALE_none)
                continue;

            if (availableDb2Locales & (1 << i))
                if (!storage->LoadStringsFrom((db2Path + localeNames[i] + '/'), i))
                    availableDb2Locales &= ~(1 << i);             // mark as not available for speedup next checks

            storage->LoadStringsFromDB(i);
        }
    }
    else
    {
        // sort problematic db2 to (1) non compatible and (2) nonexistent
        if (FILE* f = fopen((db2Path + localeNames[defaultLocale] + '/' + storage->GetFileName()).c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << storage->GetFileName() << " exists, and has " << storage->GetFieldCount() << " field(s) (expected " << loadInfo->Meta->FieldCount
                << "). Extracted file might be from wrong client version.";
            std::string buf = stream.str();
            errlist.push_back(buf);
            fclose(f);
        }
        else
            errlist.push_back(storage->GetFileName());
    }

    stores[storage->GetTableHash()] = storage;
}

DB2Manager& DB2Manager::Instance()
{
    static DB2Manager instance;
    return instance;
}

void DB2Manager::LoadStores(std::string const& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string db2Path = dataPath + "dbc/";

    std::vector<std::string> bad_db2_files;
    uint32 availableDb2Locales = 0xFF;

#define LOAD_DB2(store) LoadDB2(availableDb2Locales, bad_db2_files, _stores, &store, db2Path, defaultLocale, store)

    LOAD_DB2(sAchievementStore);
    LOAD_DB2(sAnimationDataStore);
    LOAD_DB2(sAnimKitStore);
    LOAD_DB2(sAreaGroupMemberStore);
    LOAD_DB2(sAreaTableStore);
    LOAD_DB2(sAreaTriggerStore);
    LOAD_DB2(sArmorLocationStore);
    LOAD_DB2(sArtifactStore);
    LOAD_DB2(sArtifactAppearanceStore);
    LOAD_DB2(sArtifactAppearanceSetStore);
    LOAD_DB2(sArtifactCategoryStore);
    LOAD_DB2(sArtifactPowerStore);
    LOAD_DB2(sArtifactPowerLinkStore);
    LOAD_DB2(sArtifactPowerPickerStore);
    LOAD_DB2(sArtifactPowerRankStore);
    LOAD_DB2(sArtifactTierStore);
    LOAD_DB2(sArtifactUnlockStore);
    LOAD_DB2(sAuctionHouseStore);
    LOAD_DB2(sBankBagSlotPricesStore);
    LOAD_DB2(sBannedAddonsStore);
    LOAD_DB2(sBarberShopStyleStore);
    LOAD_DB2(sBattlePetBreedQualityStore);
    LOAD_DB2(sBattlePetBreedStateStore);
    LOAD_DB2(sBattlePetSpeciesStore);
    LOAD_DB2(sBattlePetSpeciesStateStore);
    LOAD_DB2(sBattlemasterListStore);
    LOAD_DB2(sBroadcastTextStore);
    LOAD_DB2(sCfgRegionsStore);
    LOAD_DB2(sCharacterFacialHairStylesStore);
    LOAD_DB2(sCharBaseSectionStore);
    LOAD_DB2(sCharSectionsStore);
    LOAD_DB2(sCharStartOutfitStore);
    LOAD_DB2(sCharTitlesStore);
    LOAD_DB2(sChatChannelsStore);
    LOAD_DB2(sChrClassesStore);
    LOAD_DB2(sChrClassesXPowerTypesStore);
    LOAD_DB2(sChrRacesStore);
    LOAD_DB2(sChrSpecializationStore);
    LOAD_DB2(sCinematicCameraStore);
    LOAD_DB2(sCinematicSequencesStore);
    LOAD_DB2(sContentTuningStore);
    LOAD_DB2(sContentTuningXExpectedStore);
    LOAD_DB2(sConversationLineStore);
    LOAD_DB2(sCreatureDisplayInfoStore);
    LOAD_DB2(sCreatureDisplayInfoExtraStore);
    LOAD_DB2(sCreatureFamilyStore);
    LOAD_DB2(sCreatureModelDataStore);
    LOAD_DB2(sCreatureTypeStore);
    LOAD_DB2(sCriteriaStore);
    LOAD_DB2(sCriteriaTreeStore);
    LOAD_DB2(sCurrencyTypesStore);
    LOAD_DB2(sCurveStore);
    LOAD_DB2(sCurvePointStore);
    LOAD_DB2(sDestructibleModelDataStore);
    LOAD_DB2(sDifficultyStore);
    LOAD_DB2(sDungeonEncounterStore);
    LOAD_DB2(sDurabilityCostsStore);
    LOAD_DB2(sDurabilityQualityStore);
    LOAD_DB2(sEmotesStore);
    LOAD_DB2(sEmotesTextStore);
    LOAD_DB2(sEmotesTextSoundStore);
    LOAD_DB2(sExpectedStatStore);
    LOAD_DB2(sExpectedStatModStore);
    LOAD_DB2(sFactionStore);
    LOAD_DB2(sFactionTemplateStore);
    LOAD_DB2(sGameObjectsStore);
    LOAD_DB2(sGameObjectDisplayInfoStore);
    LOAD_DB2(sGarrAbilityStore);
    LOAD_DB2(sGarrBuildingStore);
    LOAD_DB2(sGarrBuildingPlotInstStore);
    LOAD_DB2(sGarrClassSpecStore);
    LOAD_DB2(sGarrFollowerStore);
    LOAD_DB2(sGarrFollowerXAbilityStore);
    LOAD_DB2(sGarrPlotBuildingStore);
    LOAD_DB2(sGarrPlotStore);
    LOAD_DB2(sGarrPlotInstanceStore);
    LOAD_DB2(sGarrSiteLevelStore);
    LOAD_DB2(sGarrSiteLevelPlotInstStore);
    LOAD_DB2(sGemPropertiesStore);
    LOAD_DB2(sGlyphBindableSpellStore);
    LOAD_DB2(sGlyphPropertiesStore);
    LOAD_DB2(sGlyphRequiredSpecStore);
    LOAD_DB2(sGuildColorBackgroundStore);
    LOAD_DB2(sGuildColorBorderStore);
    LOAD_DB2(sGuildColorEmblemStore);
    LOAD_DB2(sGuildPerkSpellsStore);
    LOAD_DB2(sHeirloomStore);
    LOAD_DB2(sHolidaysStore);
    LOAD_DB2(sImportPriceArmorStore);
    LOAD_DB2(sImportPriceQualityStore);
    LOAD_DB2(sImportPriceShieldStore);
    LOAD_DB2(sImportPriceWeaponStore);
    LOAD_DB2(sItemAppearanceStore);
    LOAD_DB2(sItemArmorQualityStore);
    LOAD_DB2(sItemArmorShieldStore);
    LOAD_DB2(sItemArmorTotalStore);
    LOAD_DB2(sItemBagFamilyStore);
    LOAD_DB2(sItemBonusStore);
    LOAD_DB2(sItemBonusListLevelDeltaStore);
    LOAD_DB2(sItemBonusTreeNodeStore);
    LOAD_DB2(sItemChildEquipmentStore);
    LOAD_DB2(sItemClassStore);
    LOAD_DB2(sItemCurrencyCostStore);
    LOAD_DB2(sItemDamageAmmoStore);
    LOAD_DB2(sItemDamageOneHandStore);
    LOAD_DB2(sItemDamageOneHandCasterStore);
    LOAD_DB2(sItemDamageTwoHandStore);
    LOAD_DB2(sItemDamageTwoHandCasterStore);
    LOAD_DB2(sItemDisenchantLootStore);
    LOAD_DB2(sItemEffectStore);
    LOAD_DB2(sItemStore);
    LOAD_DB2(sItemExtendedCostStore);
    LOAD_DB2(sItemLevelSelectorStore);
    LOAD_DB2(sItemLevelSelectorQualityStore);
    LOAD_DB2(sItemLevelSelectorQualitySetStore);
    LOAD_DB2(sItemLimitCategoryStore);
    LOAD_DB2(sItemLimitCategoryConditionStore);
    LOAD_DB2(sItemModifiedAppearanceStore);
    LOAD_DB2(sItemPriceBaseStore);
    LOAD_DB2(sItemSearchNameStore);
    LOAD_DB2(sItemSetStore);
    LOAD_DB2(sItemSetSpellStore);
    LOAD_DB2(sItemSparseStore);
    LOAD_DB2(sItemSpecStore);
    LOAD_DB2(sItemSpecOverrideStore);
    LOAD_DB2(sItemUpgradeStore);
    LOAD_DB2(sItemXBonusTreeStore);
    LOAD_DB2(sKeychainStore);
    LOAD_DB2(sLFGDungeonsStore);
    LOAD_DB2(sLightStore);
    LOAD_DB2(sLiquidTypeStore);
    LOAD_DB2(sLockStore);
    LOAD_DB2(sMailTemplateStore);
    LOAD_DB2(sMapStore);
    LOAD_DB2(sMapDifficultyStore);
    LOAD_DB2(sModifierTreeStore);
    LOAD_DB2(sMountCapabilityStore);
    LOAD_DB2(sMountStore);
    LOAD_DB2(sMountTypeXCapabilityStore);
    LOAD_DB2(sMountXDisplayStore);
    LOAD_DB2(sMovieStore);
    LOAD_DB2(sNameGenStore);
    LOAD_DB2(sNamesProfanityStore);
    LOAD_DB2(sNamesReservedStore);
    LOAD_DB2(sNamesReservedLocaleStore);
    LOAD_DB2(sNumTalentsAtLevelStore);
    LOAD_DB2(sOverrideSpellDataStore);
    LOAD_DB2(sPhaseStore);
    LOAD_DB2(sPhaseXPhaseGroupStore);
    LOAD_DB2(sPlayerConditionStore);
    LOAD_DB2(sPowerDisplayStore);
    LOAD_DB2(sPowerTypeStore);
    LOAD_DB2(sPrestigeLevelInfoStore);
    LOAD_DB2(sPVPDifficultyStore);
    LOAD_DB2(sPVPItemStore);
    LOAD_DB2(sPvpTalentStore);
    LOAD_DB2(sPvpTalentCategoryStore);
    LOAD_DB2(sPvpTalentSlotUnlockStore);
    LOAD_DB2(sQuestFactionRewardStore);
    LOAD_DB2(sQuestMoneyRewardStore);
    LOAD_DB2(sQuestPackageItemStore);
    LOAD_DB2(sQuestSortStore);
    LOAD_DB2(sQuestV2Store);
    LOAD_DB2(sQuestXPStore);
    LOAD_DB2(sRandPropPointsStore);
    LOAD_DB2(sRewardPackStore);
    LOAD_DB2(sRewardPackXCurrencyTypeStore);
    LOAD_DB2(sRewardPackXItemStore);
    LOAD_DB2(sRulesetItemUpgradeStore);
    LOAD_DB2(sScalingStatDistributionStore);
    LOAD_DB2(sScenarioStore);
    LOAD_DB2(sScenarioStepStore);
    LOAD_DB2(sSceneScriptStore);
    LOAD_DB2(sSceneScriptGlobalTextStore);
    LOAD_DB2(sSceneScriptPackageStore);
    LOAD_DB2(sSceneScriptTextStore);
    LOAD_DB2(sSkillLineStore);
    LOAD_DB2(sSkillLineAbilityStore);
    LOAD_DB2(sSkillRaceClassInfoStore);
    LOAD_DB2(sSoundKitStore);
    LOAD_DB2(sSpecializationSpellsStore);
    LOAD_DB2(sSpellAuraOptionsStore);
    LOAD_DB2(sSpellAuraRestrictionsStore);
    LOAD_DB2(sSpellCastTimesStore);
    LOAD_DB2(sSpellCastingRequirementsStore);
    LOAD_DB2(sSpellCategoriesStore);
    LOAD_DB2(sSpellCategoryStore);
    LOAD_DB2(sSpellClassOptionsStore);
    LOAD_DB2(sSpellCooldownsStore);
    LOAD_DB2(sSpellDurationStore);
    LOAD_DB2(sSpellEffectStore);
    LOAD_DB2(sSpellEquippedItemsStore);
    LOAD_DB2(sSpellFocusObjectStore);
    LOAD_DB2(sSpellInterruptsStore);
    LOAD_DB2(sSpellItemEnchantmentStore);
    LOAD_DB2(sSpellItemEnchantmentConditionStore);
    LOAD_DB2(sSpellLearnSpellStore);
    LOAD_DB2(sSpellLevelsStore);
    LOAD_DB2(sSpellMiscStore);
    LOAD_DB2(sSpellNameStore);
    LOAD_DB2(sSpellPowerStore);
    LOAD_DB2(sSpellPowerDifficultyStore);
    LOAD_DB2(sSpellProcsPerMinuteStore);
    LOAD_DB2(sSpellProcsPerMinuteModStore);
    LOAD_DB2(sSpellRadiusStore);
    LOAD_DB2(sSpellRangeStore);
    LOAD_DB2(sSpellReagentsStore);
    LOAD_DB2(sSpellScalingStore);
    LOAD_DB2(sSpellShapeshiftStore);
    LOAD_DB2(sSpellShapeshiftFormStore);
    LOAD_DB2(sSpellTargetRestrictionsStore);
    LOAD_DB2(sSpellTotemsStore);
    LOAD_DB2(sSpellXSpellVisualStore);
    LOAD_DB2(sSummonPropertiesStore);
    LOAD_DB2(sTactKeyStore);
    LOAD_DB2(sTalentStore);
    LOAD_DB2(sTaxiNodesStore);
    LOAD_DB2(sTaxiPathStore);
    LOAD_DB2(sTaxiPathNodeStore);
    LOAD_DB2(sTotemCategoryStore);
    LOAD_DB2(sToyStore);
    LOAD_DB2(sTransmogHolidayStore);
    LOAD_DB2(sTransmogSetStore);
    LOAD_DB2(sTransmogSetGroupStore);
    LOAD_DB2(sTransmogSetItemStore);
    LOAD_DB2(sTransportAnimationStore);
    LOAD_DB2(sTransportRotationStore);
    LOAD_DB2(sUiMapStore);
    LOAD_DB2(sUiMapAssignmentStore);
    LOAD_DB2(sUiMapLinkStore);
    LOAD_DB2(sUiMapXMapArtStore);
    LOAD_DB2(sUnitPowerBarStore);
    LOAD_DB2(sVehicleStore);
    LOAD_DB2(sVehicleSeatStore);
    LOAD_DB2(sWMOAreaTableStore);
    LOAD_DB2(sWorldEffectStore);
    LOAD_DB2(sWorldMapOverlayStore);
    LOAD_DB2(sWorldSafeLocsStore);
    LOAD_DB2(sWorldStateExpressionStore);

#undef LOAD_DB2

    for (AreaGroupMemberEntry const* areaGroupMember : sAreaGroupMemberStore)
        _areaGroupMembers[areaGroupMember->AreaGroupID].push_back(areaGroupMember->AreaID);

    for (ArtifactPowerEntry const* artifactPower : sArtifactPowerStore)
        _artifactPowers[artifactPower->ArtifactID].push_back(artifactPower);

    for (ArtifactPowerLinkEntry const* artifactPowerLink : sArtifactPowerLinkStore)
    {
        _artifactPowerLinks[artifactPowerLink->PowerA].insert(artifactPowerLink->PowerB);
        _artifactPowerLinks[artifactPowerLink->PowerB].insert(artifactPowerLink->PowerA);
    }

    for (ArtifactPowerRankEntry const* artifactPowerRank : sArtifactPowerRankStore)
        _artifactPowerRanks[std::pair<uint32, uint8>{ artifactPowerRank->ArtifactPowerID, artifactPowerRank->RankIndex }] = artifactPowerRank;

    ASSERT(BATTLE_PET_SPECIES_MAX_ID >= sBattlePetSpeciesStore.GetNumRows(),
        "BATTLE_PET_SPECIES_MAX_ID (%d) must be equal to or greater than %u", BATTLE_PET_SPECIES_MAX_ID, sBattlePetSpeciesStore.GetNumRows());

    for (CharacterFacialHairStylesEntry const* characterFacialStyle : sCharacterFacialHairStylesStore)
        _characterFacialHairStyles.emplace(characterFacialStyle->RaceID, characterFacialStyle->SexID, characterFacialStyle->VariationID);

    std::array<CharBaseSectionVariation, SECTION_TYPE_MAX> sectionToBase = { {} };
    for (CharBaseSectionEntry const* charBaseSection : sCharBaseSectionStore)
    {
        ASSERT(charBaseSection->ResolutionVariationEnum < SECTION_TYPE_MAX,
            "SECTION_TYPE_MAX (%d) must be equal to or greater than %u", uint32(SECTION_TYPE_MAX), uint32(charBaseSection->ResolutionVariationEnum + 1));
        ASSERT(charBaseSection->VariationEnum < AsUnderlyingType(CharBaseSectionVariation::Count),
            "CharBaseSectionVariation::Count %u must be equal to or greater than %u", uint32(CharBaseSectionVariation::Count), uint32(charBaseSection->VariationEnum + 1));

        sectionToBase[charBaseSection->ResolutionVariationEnum] = static_cast<CharBaseSectionVariation>(charBaseSection->VariationEnum);
    }

    std::map<std::tuple<uint8, uint8, CharBaseSectionVariation>, std::set<std::pair<uint8, uint8>>> addedSections;
    for (CharSectionsEntry const* charSection : sCharSectionsStore)
    {
        ASSERT(charSection->BaseSection < SECTION_TYPE_MAX,
            "SECTION_TYPE_MAX (%d) must be equal to or greater than %u", uint32(SECTION_TYPE_MAX), uint32(charSection->BaseSection + 1));

        std::tuple<uint8, uint8, CharBaseSectionVariation> sectionKey{ charSection->RaceID, charSection->SexID, sectionToBase[charSection->BaseSection] };
        std::pair<uint8, uint8> sectionCombination{ charSection->VariationIndex, charSection->ColorIndex };
        if (addedSections[sectionKey].count(sectionCombination))
            continue;

        addedSections[sectionKey].insert(sectionCombination);
        _charSections.insert({ sectionKey, charSection });
    }

    for (CharStartOutfitEntry const* outfit : sCharStartOutfitStore)
        _charStartOutfits[outfit->RaceID | (outfit->ClassID << 8) | (outfit->SexID << 16)] = outfit;

    {
        std::set<ChrClassesXPowerTypesEntry const*, ChrClassesXPowerTypesEntryComparator> powers;
        for (ChrClassesXPowerTypesEntry const* power : sChrClassesXPowerTypesStore)
            powers.insert(power);

        for (uint32 i = 0; i < MAX_CLASSES; ++i)
            for (uint32 j = 0; j < MAX_POWERS; ++j)
                _powersByClass[i][j] = MAX_POWERS;

        for (ChrClassesXPowerTypesEntry const* power : powers)
        {
            uint32 index = 0;
            for (uint32 j = 0; j < MAX_POWERS; ++j)
                if (_powersByClass[power->ClassID][j] != MAX_POWERS)
                    ++index;

            ASSERT(power->ClassID < MAX_CLASSES);
            ASSERT(power->PowerType < MAX_POWERS);
            _powersByClass[power->ClassID][power->PowerType] = index;
        }
    }

    memset(_chrSpecializationsByIndex, 0, sizeof(_chrSpecializationsByIndex));
    for (ChrSpecializationEntry const* chrSpec : sChrSpecializationStore)
    {
        ASSERT(chrSpec->ClassID < MAX_CLASSES);
        ASSERT(chrSpec->OrderIndex < MAX_SPECIALIZATIONS);

        uint32 storageIndex = chrSpec->ClassID;
        if (chrSpec->Flags & CHR_SPECIALIZATION_FLAG_PET_OVERRIDE_SPEC)
        {
            ASSERT(!chrSpec->ClassID);
            storageIndex = PET_SPEC_OVERRIDE_CLASS_INDEX;
        }

        _chrSpecializationsByIndex[storageIndex][chrSpec->OrderIndex] = chrSpec;
        if (chrSpec->Flags & CHR_SPECIALIZATION_FLAG_RECOMMENDED)
            _defaultChrSpecializationsByClass[chrSpec->ClassID] = chrSpec;
    }

    for (ContentTuningXExpectedEntry const* contentTuningXExpectedStat : sContentTuningXExpectedStore)
        if (ExpectedStatModEntry const* expectedStatMod = sExpectedStatModStore.LookupEntry(contentTuningXExpectedStat->ExpectedStatModID))
            _expectedStatModsByContentTuning[contentTuningXExpectedStat->ContentTuningID].push_back(expectedStatMod);

    for (CurvePointEntry const* curvePoint : sCurvePointStore)
        if (sCurveStore.LookupEntry(curvePoint->CurveID))
            _curvePoints[curvePoint->CurveID].push_back(curvePoint);

    for (auto itr = _curvePoints.begin(); itr != _curvePoints.end(); ++itr)
        std::sort(itr->second.begin(), itr->second.end(), [](CurvePointEntry const* point1, CurvePointEntry const* point2) { return point1->OrderIndex < point2->OrderIndex; });

    ASSERT(MAX_DIFFICULTY >= sDifficultyStore.GetNumRows(),
        "MAX_DIFFICULTY is not large enough to contain all difficulties! (current value %d, required %d)",
        MAX_DIFFICULTY, sDifficultyStore.GetNumRows());

    for (EmotesTextSoundEntry const* emoteTextSound : sEmotesTextSoundStore)
        _emoteTextSounds[EmotesTextSoundContainer::key_type(emoteTextSound->EmotesTextID, emoteTextSound->RaceID, emoteTextSound->SexID, emoteTextSound->ClassID)] = emoteTextSound;

    for (ExpectedStatEntry const* expectedStat : sExpectedStatStore)
        _expectedStatsByLevel[std::make_pair(expectedStat->Lvl, expectedStat->ExpansionID)] = expectedStat;

    for (FactionEntry const* faction : sFactionStore)
        if (faction->ParentFactionID)
            _factionTeams[faction->ParentFactionID].push_back(faction->ID);

    for (GameObjectDisplayInfoEntry const* gameObjectDisplayInfo : sGameObjectDisplayInfoStore)
    {
        if (gameObjectDisplayInfo->GeoBoxMax.X < gameObjectDisplayInfo->GeoBoxMin.X)
            std::swap(*(float*)(&gameObjectDisplayInfo->GeoBoxMax.X), *(float*)(&gameObjectDisplayInfo->GeoBoxMin.X));
        if (gameObjectDisplayInfo->GeoBoxMax.Y < gameObjectDisplayInfo->GeoBoxMin.Y)
            std::swap(*(float*)(&gameObjectDisplayInfo->GeoBoxMax.Y), *(float*)(&gameObjectDisplayInfo->GeoBoxMin.Y));
        if (gameObjectDisplayInfo->GeoBoxMax.Z < gameObjectDisplayInfo->GeoBoxMin.Z)
            std::swap(*(float*)(&gameObjectDisplayInfo->GeoBoxMax.Z), *(float*)(&gameObjectDisplayInfo->GeoBoxMin.Z));
    }

    for (HeirloomEntry const* heirloom : sHeirloomStore)
        _heirlooms[heirloom->ItemID] = heirloom;

    for (GlyphBindableSpellEntry const* glyphBindableSpell : sGlyphBindableSpellStore)
        _glyphBindableSpells[glyphBindableSpell->GlyphPropertiesID].push_back(glyphBindableSpell->SpellID);

    for (GlyphRequiredSpecEntry const* glyphRequiredSpec : sGlyphRequiredSpecStore)
        _glyphRequiredSpecs[glyphRequiredSpec->GlyphPropertiesID].push_back(glyphRequiredSpec->ChrSpecializationID);

    for (ItemBonusEntry const* bonus : sItemBonusStore)
        _itemBonusLists[bonus->ParentItemBonusListID].push_back(bonus);

    for (ItemBonusListLevelDeltaEntry const* itemBonusListLevelDelta : sItemBonusListLevelDeltaStore)
        _itemLevelDeltaToBonusListContainer[itemBonusListLevelDelta->ItemLevelDelta] = itemBonusListLevelDelta->ID;

    for (ItemBonusTreeNodeEntry const* bonusTreeNode : sItemBonusTreeNodeStore)
    {
        uint32 bonusTreeId = bonusTreeNode->ParentItemBonusTreeID;
        while (bonusTreeNode)
        {
            _itemBonusTrees[bonusTreeId].insert(bonusTreeNode);
            bonusTreeNode = sItemBonusTreeNodeStore.LookupEntry(bonusTreeNode->ChildItemBonusTreeID);
        }
    }

    for (ItemChildEquipmentEntry const* itemChildEquipment : sItemChildEquipmentStore)
    {
        ASSERT(_itemChildEquipment.find(itemChildEquipment->ParentItemID) == _itemChildEquipment.end(), "Item must have max 1 child item.");
        _itemChildEquipment[itemChildEquipment->ParentItemID] = itemChildEquipment;
    }

    for (ItemClassEntry const* itemClass : sItemClassStore)
    {
        ASSERT(itemClass->ClassID < int32(_itemClassByOldEnum.size()));
        ASSERT(!_itemClassByOldEnum[itemClass->ClassID]);
        _itemClassByOldEnum[itemClass->ClassID] = itemClass;
    }

    for (ItemCurrencyCostEntry const* itemCurrencyCost : sItemCurrencyCostStore)
        _itemsWithCurrencyCost.insert(itemCurrencyCost->ItemID);

    for (ItemLimitCategoryConditionEntry const* condition : sItemLimitCategoryConditionStore)
        _itemCategoryConditions[condition->ParentItemLimitCategoryID].push_back(condition);

    for (ItemLevelSelectorQualityEntry const* itemLevelSelectorQuality : sItemLevelSelectorQualityStore)
        _itemLevelQualitySelectorQualities[itemLevelSelectorQuality->ParentILSQualitySetID].insert(itemLevelSelectorQuality);

    for (ItemModifiedAppearanceEntry const* appearanceMod : sItemModifiedAppearanceStore)
    {
        ASSERT(appearanceMod->ItemID <= 0xFFFFFF);
        _itemModifiedAppearancesByItem[appearanceMod->ItemID | (appearanceMod->ItemAppearanceModifierID << 24)] = appearanceMod;
    }

    for (ItemSetSpellEntry const* itemSetSpell : sItemSetSpellStore)
        _itemSetSpells[itemSetSpell->ItemSetID].push_back(itemSetSpell);

    for (ItemSpecOverrideEntry const* itemSpecOverride : sItemSpecOverrideStore)
        _itemSpecOverrides[itemSpecOverride->ItemID].push_back(itemSpecOverride);

    for (ItemXBonusTreeEntry const* itemBonusTreeAssignment : sItemXBonusTreeStore)
        _itemToBonusTree.insert({ itemBonusTreeAssignment->ItemID, itemBonusTreeAssignment->ItemBonusTreeID });

    for (MapDifficultyEntry const* entry : sMapDifficultyStore)
        _mapDifficulties[entry->MapID][entry->DifficultyID] = entry;
    _mapDifficulties[0][0] = _mapDifficulties[1][0]; // map 0 is missing from MapDifficulty.dbc so we cheat a bit

    for (MountEntry const* mount : sMountStore)
        _mountsBySpellId[mount->SourceSpellID] = mount;

    for (MountTypeXCapabilityEntry const* mountTypeCapability : sMountTypeXCapabilityStore)
        _mountCapabilitiesByType[mountTypeCapability->MountTypeID].insert(mountTypeCapability);

    for (MountXDisplayEntry const* mountDisplay : sMountXDisplayStore)
        _mountDisplays[mountDisplay->MountID].push_back(mountDisplay);

    for (NameGenEntry const* nameGen : sNameGenStore)
        _nameGenData[nameGen->RaceID][nameGen->Sex].push_back(nameGen);

    for (NamesProfanityEntry const* namesProfanity : sNamesProfanityStore)
    {
        ASSERT(namesProfanity->Language < TOTAL_LOCALES || namesProfanity->Language == -1);
        std::wstring name;
        ASSERT(Utf8toWStr(namesProfanity->Name, name));
        if (namesProfanity->Language != -1)
            _nameValidators[namesProfanity->Language].emplace_back(name, Trinity::regex::icase | Trinity::regex::optimize);
        else
        {
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
            {
                if (i == LOCALE_none)
                    continue;

                _nameValidators[i].emplace_back(name, Trinity::regex::icase | Trinity::regex::optimize);
            }
        }
    }

    for (NamesReservedEntry const* namesReserved : sNamesReservedStore)
    {
        std::wstring name;
        ASSERT(Utf8toWStr(namesReserved->Name, name));
        _nameValidators[TOTAL_LOCALES].emplace_back(name, Trinity::regex::icase | Trinity::regex::optimize);
    }

    for (NamesReservedLocaleEntry const* namesReserved : sNamesReservedLocaleStore)
    {
        ASSERT(!(namesReserved->LocaleMask & ~((1u << TOTAL_LOCALES) - 1)));
        std::wstring name;
        ASSERT(Utf8toWStr(namesReserved->Name, name));
        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (i == LOCALE_none)
                continue;

            if (namesReserved->LocaleMask & (1 << i))
                _nameValidators[i].emplace_back(name, Trinity::regex::icase | Trinity::regex::optimize);
        }
    }

    for (PhaseXPhaseGroupEntry const* group : sPhaseXPhaseGroupStore)
        if (PhaseEntry const* phase = sPhaseStore.LookupEntry(group->PhaseID))
            _phasesByGroup[group->PhaseGroupID].push_back(phase->ID);

    for (PowerTypeEntry const* powerType : sPowerTypeStore)
    {
        ASSERT(powerType->PowerTypeEnum < MAX_POWERS);
        ASSERT(!_powerTypes[powerType->PowerTypeEnum]);

        _powerTypes[powerType->PowerTypeEnum] = powerType;
    }

    for (PVPDifficultyEntry const* entry : sPVPDifficultyStore)
    {
        ASSERT(entry->RangeIndex < MAX_BATTLEGROUND_BRACKETS, "PvpDifficulty bracket (%d) exceeded max allowed value (%d)", entry->RangeIndex, MAX_BATTLEGROUND_BRACKETS);
    }

    for (PVPItemEntry const* pvpItem : sPVPItemStore)
        _pvpItemBonus[pvpItem->ItemID] = pvpItem->ItemLevelDelta;

    for (PvpTalentSlotUnlockEntry const* talentUnlock : sPvpTalentSlotUnlockStore)
    {
        ASSERT(talentUnlock->Slot < (1 << MAX_PVP_TALENT_SLOTS));
        for (int8 i = 0; i < MAX_PVP_TALENT_SLOTS; ++i)
        {
            if (talentUnlock->Slot & (1 << i))
            {
                ASSERT(!_pvpTalentSlotUnlock[i]);
                _pvpTalentSlotUnlock[i] = talentUnlock;
            }
        }
    }

    for (QuestPackageItemEntry const* questPackageItem : sQuestPackageItemStore)
    {
        if (questPackageItem->DisplayType != QUEST_PACKAGE_FILTER_UNMATCHED)
            _questPackages[questPackageItem->PackageID].first.push_back(questPackageItem);
        else
            _questPackages[questPackageItem->PackageID].second.push_back(questPackageItem);
    }

    for (RewardPackXCurrencyTypeEntry const* rewardPackXCurrencyType : sRewardPackXCurrencyTypeStore)
        _rewardPackCurrencyTypes[rewardPackXCurrencyType->RewardPackID].push_back(rewardPackXCurrencyType);

    for (RewardPackXItemEntry const* rewardPackXItem : sRewardPackXItemStore)
        _rewardPackItems[rewardPackXItem->RewardPackID].push_back(rewardPackXItem);

    for (RulesetItemUpgradeEntry const* rulesetItemUpgrade : sRulesetItemUpgradeStore)
        _rulesetItemUpgrade[rulesetItemUpgrade->ItemID] = rulesetItemUpgrade->ItemUpgradeID;

    for (SkillLineEntry const* skill : sSkillLineStore)
        if (skill->ParentSkillLineID)
            _skillLinesByParentSkillLine[skill->ParentSkillLineID].push_back(skill);

    for (SkillLineAbilityEntry const* skillLineAbility : sSkillLineAbilityStore)
        _skillLineAbilitiesBySkillupSkill[skillLineAbility->SkillupSkillLineID ? skillLineAbility->SkillupSkillLineID : skillLineAbility->SkillLine].push_back(skillLineAbility);

    for (SkillRaceClassInfoEntry const* entry : sSkillRaceClassInfoStore)
        if (sSkillLineStore.LookupEntry(entry->SkillID))
            _skillRaceClassInfoBySkill.insert(SkillRaceClassInfoContainer::value_type(entry->SkillID, entry));

    for (SpecializationSpellsEntry const* specSpells : sSpecializationSpellsStore)
        _specializationSpellsBySpec[specSpells->SpecID].push_back(specSpells);

    for (SpellClassOptionsEntry const* classOption : sSpellClassOptionsStore)
        _spellFamilyNames.insert(classOption->SpellClassSet);

    for (SpellPowerEntry const* power : sSpellPowerStore)
    {
        if (SpellPowerDifficultyEntry const* powerDifficulty = sSpellPowerDifficultyStore.LookupEntry(power->ID))
        {
            std::vector<SpellPowerEntry const*>& powers = _spellPowerDifficulties[power->SpellID][powerDifficulty->DifficultyID];
            if (powers.size() <= powerDifficulty->OrderIndex)
                powers.resize(powerDifficulty->OrderIndex + 1);

            powers[powerDifficulty->OrderIndex] = power;
        }
        else
        {
            std::vector<SpellPowerEntry const*>& powers = _spellPowers[power->SpellID];
            if (powers.size() <= power->OrderIndex)
                powers.resize(power->OrderIndex + 1);

            powers[power->OrderIndex] = power;
        }
    }

    for (SpellProcsPerMinuteModEntry const* ppmMod : sSpellProcsPerMinuteModStore)
        _spellProcsPerMinuteMods[ppmMod->SpellProcsPerMinuteID].push_back(ppmMod);

    for (TalentEntry const* talentInfo : sTalentStore)
    {
        ASSERT(talentInfo->ClassID < MAX_CLASSES);
        ASSERT(talentInfo->TierID < MAX_TALENT_TIERS, "MAX_TALENT_TIERS must be at least %u", talentInfo->TierID + 1);
        ASSERT(talentInfo->ColumnIndex < MAX_TALENT_COLUMNS, "MAX_TALENT_COLUMNS must be at least %u", talentInfo->ColumnIndex + 1);

        _talentsByPosition[talentInfo->ClassID][talentInfo->TierID][talentInfo->ColumnIndex].push_back(talentInfo);
    }

    for (TaxiPathEntry const* entry : sTaxiPathStore)
        sTaxiPathSetBySource[entry->FromTaxiNode][entry->ToTaxiNode] = TaxiPathBySourceAndDestination(entry->ID, entry->Cost);

    uint32 pathCount = sTaxiPathStore.GetNumRows();

    // Calculate path nodes count
    std::vector<uint32> pathLength;
    pathLength.resize(pathCount);                           // 0 and some other indexes not used
    for (TaxiPathNodeEntry const* entry : sTaxiPathNodeStore)
        if (pathLength[entry->PathID] < entry->NodeIndex + 1u)
            pathLength[entry->PathID] = entry->NodeIndex + 1u;

    // Set path length
    sTaxiPathNodesByPath.resize(pathCount);                 // 0 and some other indexes not used
    for (uint32 i = 0; i < sTaxiPathNodesByPath.size(); ++i)
        sTaxiPathNodesByPath[i].resize(pathLength[i]);

    // fill data
    for (TaxiPathNodeEntry const* entry : sTaxiPathNodeStore)
        sTaxiPathNodesByPath[entry->PathID][entry->NodeIndex] = entry;

    for (ToyEntry const* toy : sToyStore)
        _toys.insert(toy->ItemID);

    for (TransmogSetItemEntry const* transmogSetItem : sTransmogSetItemStore)
    {
        TransmogSetEntry const* set = sTransmogSetStore.LookupEntry(transmogSetItem->TransmogSetID);
        if (!set)
            continue;

        _transmogSetsByItemModifiedAppearance[transmogSetItem->ItemModifiedAppearanceID].push_back(set);
        _transmogSetItemsByTransmogSet[transmogSetItem->TransmogSetID].push_back(transmogSetItem);
    }

    std::unordered_multimap<int32, UiMapAssignmentEntry const*> uiMapAssignmentByUiMap;
    for (UiMapAssignmentEntry const* uiMapAssignment : sUiMapAssignmentStore)
    {
        uiMapAssignmentByUiMap.emplace(uiMapAssignment->UiMapID, uiMapAssignment);
        if (UiMapEntry const* uiMap = sUiMapStore.LookupEntry(uiMapAssignment->UiMapID))
        {
            ASSERT(uiMap->System < MAX_UI_MAP_SYSTEM, "MAX_TALENT_TIERS must be at least %u", uiMap->System + 1);
            if (uiMapAssignment->MapID >= 0)
                _uiMapAssignmentByMap[uiMap->System].emplace(uiMapAssignment->MapID, uiMapAssignment);
            if (uiMapAssignment->AreaID)
                _uiMapAssignmentByArea[uiMap->System].emplace(uiMapAssignment->AreaID, uiMapAssignment);
            if (uiMapAssignment->WmoDoodadPlacementID)
                _uiMapAssignmentByWmoDoodadPlacement[uiMap->System].emplace(uiMapAssignment->WmoDoodadPlacementID, uiMapAssignment);
            if (uiMapAssignment->WmoGroupID)
                _uiMapAssignmentByWmoGroup[uiMap->System].emplace(uiMapAssignment->WmoGroupID, uiMapAssignment);
        }
    }

    std::unordered_map<std::pair<int32, uint32>, UiMapLinkEntry const*> uiMapLinks;
    for (UiMapLinkEntry const* uiMapLink : sUiMapLinkStore)
        uiMapLinks[std::make_pair(uiMapLink->ParentUiMapID, uint32(uiMapLink->ChildUiMapID))] = uiMapLink;

    for (UiMapEntry const* uiMap : sUiMapStore)
    {
        UiMapBounds& bounds = _uiMapBounds[uiMap->ID];
        memset(&bounds, 0, sizeof(bounds));
        if (UiMapEntry const* parentUiMap = sUiMapStore.LookupEntry(uiMap->ParentUiMapID))
        {
            if (parentUiMap->Flags & 0x80)
                continue;

            UiMapAssignmentEntry const* uiMapAssignment = nullptr;
            UiMapAssignmentEntry const* parentUiMapAssignment = nullptr;
            for (auto uiMapAssignmentForMap : Trinity::Containers::MapEqualRange(uiMapAssignmentByUiMap, uiMap->ID))
            {
                if (uiMapAssignmentForMap.second->MapID >= 0 &&
                    uiMapAssignmentForMap.second->Region[1].X - uiMapAssignmentForMap.second->Region[0].X > 0 &&
                    uiMapAssignmentForMap.second->Region[1].Y - uiMapAssignmentForMap.second->Region[0].Y > 0)
                {
                    uiMapAssignment = uiMapAssignmentForMap.second;
                    break;
                }
            }

            if (!uiMapAssignment)
                continue;

            for (auto uiMapAssignmentForMap : Trinity::Containers::MapEqualRange(uiMapAssignmentByUiMap, uiMap->ParentUiMapID))
            {
                if (uiMapAssignmentForMap.second->MapID == uiMapAssignment->MapID &&
                    uiMapAssignmentForMap.second->Region[1].X - uiMapAssignmentForMap.second->Region[0].X > 0 &&
                    uiMapAssignmentForMap.second->Region[1].Y - uiMapAssignmentForMap.second->Region[0].Y > 0)
                {
                    parentUiMapAssignment = uiMapAssignmentForMap.second;
                    break;
                }
            }

            if (!parentUiMapAssignment)
                continue;

            float parentXsize = parentUiMapAssignment->Region[1].X - parentUiMapAssignment->Region[0].X;
            float parentYsize = parentUiMapAssignment->Region[1].Y - parentUiMapAssignment->Region[0].Y;
            float bound0scale = (uiMapAssignment->Region[1].X - parentUiMapAssignment->Region[0].X) / parentXsize;
            float bound0 = ((1.0f - bound0scale) * parentUiMapAssignment->UiMax.Y) + (bound0scale * parentUiMapAssignment->UiMin.Y);
            float bound2scale = (uiMapAssignment->Region[0].X - parentUiMapAssignment->Region[0].X) / parentXsize;
            float bound2 = ((1.0f - bound2scale) * parentUiMapAssignment->UiMax.Y) + (bound2scale * parentUiMapAssignment->UiMin.Y);
            float bound1scale = (uiMapAssignment->Region[1].Y - parentUiMapAssignment->Region[0].Y) / parentYsize;
            float bound1 = ((1.0f - bound1scale) * parentUiMapAssignment->UiMax.X) + (bound1scale * parentUiMapAssignment->UiMin.X);
            float bound3scale = (uiMapAssignment->Region[0].Y - parentUiMapAssignment->Region[0].Y) / parentYsize;
            float bound3 = ((1.0f - bound3scale) * parentUiMapAssignment->UiMax.X) + (bound3scale * parentUiMapAssignment->UiMin.X);
            if ((bound3 - bound1) > 0.0f || (bound2 - bound0) > 0.0f)
            {
                bounds.Bounds[0] = bound0;
                bounds.Bounds[1] = bound1;
                bounds.Bounds[2] = bound2;
                bounds.Bounds[3] = bound3;
                bounds.IsUiAssignment = true;
            }
        }

        if (UiMapLinkEntry const* uiMapLink = Trinity::Containers::MapGetValuePtr(uiMapLinks, std::make_pair(uiMap->ParentUiMapID, uiMap->ID)))
        {
            bounds.IsUiAssignment = false;
            bounds.IsUiLink = true;
            bounds.Bounds[0] = uiMapLink->UiMin.Y;
            bounds.Bounds[1] = uiMapLink->UiMin.X;
            bounds.Bounds[2] = uiMapLink->UiMax.Y;
            bounds.Bounds[3] = uiMapLink->UiMax.X;
        }
    }

    for (UiMapXMapArtEntry const* uiMapArt : sUiMapXMapArtStore)
        if (uiMapArt->PhaseID)
            _uiMapPhases.insert(uiMapArt->PhaseID);

    for (WMOAreaTableEntry const* entry : sWMOAreaTableStore)
        _wmoAreaTableLookup[WMOAreaTableKey(entry->WmoID, entry->NameSetID, entry->WmoGroupID)] = entry;

    // Initialize global taxinodes mask
    // include existed nodes that have at least single not spell base (scripted) path
    {
        if (sTaxiNodesStore.GetNumRows())
        {
            ASSERT(TaxiMaskSize >= ((sTaxiNodesStore.GetNumRows() - 1) / 8) + 1,
                "TaxiMaskSize is not large enough to contain all taxi nodes! (current value %d, required %d)",
                TaxiMaskSize, (((sTaxiNodesStore.GetNumRows() - 1) / 8) + 1));
        }

        sTaxiNodesMask.fill(0);
        sOldContinentsNodesMask.fill(0);
        sHordeTaxiNodesMask.fill(0);
        sAllianceTaxiNodesMask.fill(0);
        for (TaxiNodesEntry const* node : sTaxiNodesStore)
        {
            if (!(node->Flags & (TAXI_NODE_FLAG_ALLIANCE | TAXI_NODE_FLAG_HORDE)))
                continue;

            // valid taxi network node
            uint32 field = uint32((node->ID - 1) / 8);
            uint32 submask = 1 << ((node->ID - 1) % 8);

            sTaxiNodesMask[field] |= submask;
            if (node->Flags & TAXI_NODE_FLAG_HORDE)
                sHordeTaxiNodesMask[field] |= submask;
            if (node->Flags & TAXI_NODE_FLAG_ALLIANCE)
                sAllianceTaxiNodesMask[field] |= submask;

            int32 uiMapId = -1;
            if (!GetUiMapPosition(node->Pos.X, node->Pos.Y, node->Pos.Z, node->ContinentID, 0, 0, 0, UI_MAP_SYSTEM_ADVENTURE, false, &uiMapId))
                GetUiMapPosition(node->Pos.X, node->Pos.Y, node->Pos.Z, node->ContinentID, 0, 0, 0, UI_MAP_SYSTEM_TAXI, false, &uiMapId);

            if (uiMapId == 985 || uiMapId == 986)
                sOldContinentsNodesMask[field] |= submask;
        }
    }

    // error checks
    if (bad_db2_files.size() == _stores.size())
    {
        TC_LOG_ERROR("misc", "\nIncorrect DataDir value in worldserver.conf or ALL required *.db2 files (" SZFMTD ") not found by path: %sdbc/%s/", _stores.size(), dataPath.c_str(), localeNames[defaultLocale]);
        exit(1);
    }
    else if (!bad_db2_files.empty())
    {
        std::string str;
        for (auto const& bad_db2_file : bad_db2_files)
            str += bad_db2_file + "\n";

        TC_LOG_ERROR("misc", "\nSome required *.db2 files (" SZFMTD " from " SZFMTD ") not found or not compatible:\n%s", bad_db2_files.size(), _stores.size(), str.c_str());
        exit(1);
    }

    // Check loaded DB2 files proper version
    if (!sAreaTableStore.LookupEntry(10521) ||               // last area added in 8.1.5 (30706)
        !sCharTitlesStore.LookupEntry(649) ||                // last char title added in 8.1.5 (30706)
        !sGemPropertiesStore.LookupEntry(3746) ||            // last gem property added in 8.1.5 (30706)
        !sItemStore.LookupEntry(168279) ||                   // last item added in 8.1.5 (30706)
        !sItemExtendedCostStore.LookupEntry(6545) ||         // last item extended cost added in 8.1.5 (30706)
        !sMapStore.LookupEntry(2178) ||                      // last map added in 8.1.5 (30706)
        !sSpellNameStore.LookupEntry(296952))                // last spell added in 8.1.5 (30706)
    {
        TC_LOG_ERROR("misc", "You have _outdated_ DB2 files. Please extract correct versions from current using client.");
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized " SZFMTD " DB2 data stores in %u ms", _stores.size(), GetMSTimeDiffToNow(oldMSTime));
}

DB2StorageBase const* DB2Manager::GetStorage(uint32 type) const
{
    auto itr = _stores.find(type);
    if (itr != _stores.end())
        return itr->second;

    return nullptr;
}

void DB2Manager::LoadHotfixData()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = HotfixDatabase.Query("SELECT Id, TableHash, RecordId, Deleted FROM hotfix_data ORDER BY Id");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 hotfix info entries.");
        return;
    }

    uint32 count = 0;

    std::map<std::pair<uint32, int32>, bool> deletedRecords;

    do
    {
        Field* fields = result->Fetch();

        int32 id = fields[0].GetInt32();
        uint32 tableHash = fields[1].GetUInt32();
        int32 recordId = fields[2].GetInt32();
        bool deleted = fields[3].GetBool();
        if (_stores.find(tableHash) == _stores.end() && _hotfixBlob.find(std::make_pair(tableHash, recordId)) == _hotfixBlob.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `hotfix_data` references unknown DB2 store by hash 0x%X and has no reference to `hotfix_blob` in hotfix id %d", tableHash, id);
            continue;
        }

        _maxHotfixId = std::max(_maxHotfixId, id);
        _hotfixData[id].emplace_back(tableHash, recordId);
        ++_hotfixCount;
        deletedRecords[std::make_pair(tableHash, recordId)] = deleted;
        ++count;
    } while (result->NextRow());

    for (auto itr = deletedRecords.begin(); itr != deletedRecords.end(); ++itr)
        if (itr->second)
            if (DB2StorageBase* store = Trinity::Containers::MapGetValuePtr(_stores, itr->first.first))
                store->EraseRecord(itr->first.second);

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " hotfix records in %u ms", _hotfixData.size(), GetMSTimeDiffToNow(oldMSTime));
}

void DB2Manager::LoadHotfixBlob()
{
    uint32 oldMSTime = getMSTime();
    _hotfixBlob.clear();

    QueryResult result = HotfixDatabase.Query("SELECT TableHash, RecordId, `Blob` FROM hotfix_blob ORDER BY TableHash");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 hotfix blob entries.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 tableHash = fields[0].GetUInt32();
        auto storeItr = _stores.find(tableHash);
        if (storeItr != _stores.end())
        {
            TC_LOG_ERROR("server.loading", "Table hash 0x%X points to a loaded DB2 store %s, fill related table instead of hotfix_blob",
                tableHash, storeItr->second->GetFileName().c_str());
            continue;
        }

        int32 recordId = fields[1].GetInt32();
        _hotfixBlob[std::make_pair(tableHash, recordId)] = fields[2].GetBinary();
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " hotfix blob records in %u ms", _hotfixBlob.size(), GetMSTimeDiffToNow(oldMSTime));
}

uint32 DB2Manager::GetHotfixCount() const
{
    return _hotfixCount;
}

DB2Manager::HotfixContainer const& DB2Manager::GetHotfixData() const
{
    return _hotfixData;
}

std::vector<uint8> const* DB2Manager::GetHotfixBlobData(uint32 tableHash, int32 recordId)
{
    return Trinity::Containers::MapGetValuePtr(_hotfixBlob, std::make_pair(tableHash, recordId));
}

void DB2Manager::InsertNewHotfix(uint32 tableHash, uint32 recordId)
{
    _hotfixData[++_maxHotfixId].emplace_back(tableHash, recordId);
    ++_hotfixCount;
}

std::vector<uint32> DB2Manager::GetAreasForGroup(uint32 areaGroupId) const
{
    auto itr = _areaGroupMembers.find(areaGroupId);
    if (itr != _areaGroupMembers.end())
        return itr->second;

    return std::vector<uint32>();
}

bool DB2Manager::IsInArea(uint32 objectAreaId, uint32 areaId)
{
    do
    {
        if (objectAreaId == areaId)
            return true;

        AreaTableEntry const* objectArea = sAreaTableStore.LookupEntry(objectAreaId);
        if (!objectArea)
            break;

        objectAreaId = objectArea->ParentAreaID;
    } while (objectAreaId);

    return false;
}

std::vector<ArtifactPowerEntry const*> DB2Manager::GetArtifactPowers(uint8 artifactId) const
{
    auto itr = _artifactPowers.find(artifactId);
    if (itr != _artifactPowers.end())
        return itr->second;

    return std::vector<ArtifactPowerEntry const*>{};
}

std::unordered_set<uint32> const* DB2Manager::GetArtifactPowerLinks(uint32 artifactPowerId) const
{
    auto itr = _artifactPowerLinks.find(artifactPowerId);
    if (itr != _artifactPowerLinks.end())
        return &itr->second;

    return nullptr;
}

ArtifactPowerRankEntry const* DB2Manager::GetArtifactPowerRank(uint32 artifactPowerId, uint8 rank) const
{
    auto itr = _artifactPowerRanks.find({ artifactPowerId, rank });
    if (itr != _artifactPowerRanks.end())
        return itr->second;

    return nullptr;
}

char const* DB2Manager::GetBroadcastTextValue(BroadcastTextEntry const* broadcastText, LocaleConstant locale /*= DEFAULT_LOCALE*/, uint8 gender /*= GENDER_MALE*/, bool forceGender /*= false*/)
{
    if ((gender == GENDER_FEMALE || gender == GENDER_NONE) && (forceGender || broadcastText->Text1->Str[DEFAULT_LOCALE][0] != '\0'))
    {
        if (broadcastText->Text1->Str[locale][0] != '\0')
            return broadcastText->Text1->Str[locale];

        return broadcastText->Text1->Str[DEFAULT_LOCALE];
    }

    if (broadcastText->Text->Str[locale][0] != '\0')
        return broadcastText->Text->Str[locale];

    return broadcastText->Text->Str[DEFAULT_LOCALE];
}

bool DB2Manager::HasCharacterFacialHairStyle(uint8 race, uint8 gender, uint8 variationId) const
{
    return _characterFacialHairStyles.find(std::make_tuple(race, gender, variationId)) != _characterFacialHairStyles.end();
}

bool DB2Manager::HasCharSections(uint8 race, uint8 gender, CharBaseSectionVariation variation) const
{
    auto range = Trinity::Containers::MapEqualRange(_charSections, std::make_tuple(race, gender, variation));
    return range.begin() != range.end();
}

CharSectionsEntry const* DB2Manager::GetCharSectionEntry(uint8 race, uint8 gender, CharBaseSectionVariation variation, uint8 variationIndex, uint8 colorIndex) const
{
    for (auto const& section : Trinity::Containers::MapEqualRange(_charSections, std::make_tuple(race, gender, variation)))
        if (section.second->VariationIndex == variationIndex && section.second->ColorIndex == colorIndex)
            return section.second;

    return nullptr;
}

CharStartOutfitEntry const* DB2Manager::GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender) const
{
    auto itr = _charStartOutfits.find(race | (class_ << 8) | (gender << 16));
    if (itr == _charStartOutfits.end())
        return nullptr;

    return itr->second;
}

char const* DB2Manager::GetClassName(uint8 class_, LocaleConstant locale /*= DEFAULT_LOCALE*/)
{
    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);
    if (!classEntry)
        return "";

    if (classEntry->Name->Str[locale][0] != '\0')
        return classEntry->Name->Str[locale];

    return classEntry->Name->Str[DEFAULT_LOCALE];
}

uint32 DB2Manager::GetPowerIndexByClass(Powers power, uint32 classId) const
{
    return _powersByClass[classId][power];
}

char const* DB2Manager::GetChrRaceName(uint8 race, LocaleConstant locale /*= DEFAULT_LOCALE*/)
{
    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
    if (!raceEntry)
        return "";

    if (raceEntry->Name->Str[locale][0] != '\0')
        return raceEntry->Name->Str[locale];

    return raceEntry->Name->Str[DEFAULT_LOCALE];
}

ChrSpecializationEntry const* DB2Manager::GetChrSpecializationByIndex(uint32 class_, uint32 index) const
{
    return _chrSpecializationsByIndex[class_][index];
}

ChrSpecializationEntry const* DB2Manager::GetDefaultChrSpecializationForClass(uint32 class_) const
{
    auto itr = _defaultChrSpecializationsByClass.find(class_);
    if (itr != _defaultChrSpecializationsByClass.end())
        return itr->second;

    return nullptr;
}

char const* DB2Manager::GetCreatureFamilyPetName(uint32 petfamily, uint32 locale)
{
    if (!petfamily)
        return nullptr;

    CreatureFamilyEntry const* petFamily = sCreatureFamilyStore.LookupEntry(petfamily);
    if (!petFamily)
        return nullptr;

    return petFamily->Name->Str[locale][0] != '\0' ? petFamily->Name->Str[locale] : nullptr;
}

enum class CurveInterpolationMode : uint8
{
    Linear = 0,
    Cosine = 1,
    CatmullRom = 2,
    Bezier3 = 3,
    Bezier4 = 4,
    Bezier = 5,
    Constant = 6,
};

static CurveInterpolationMode DetermineCurveType(CurveEntry const* curve, std::vector<CurvePointEntry const*> const& points)
{
    switch (curve->Type)
    {
        case 1:
            return points.size() < 4 ? CurveInterpolationMode::Cosine : CurveInterpolationMode::CatmullRom;
        case 2:
        {
            switch (points.size())
            {
                case 1:
                    return CurveInterpolationMode::Constant;
                case 2:
                    return CurveInterpolationMode::Linear;
                case 3:
                    return CurveInterpolationMode::Bezier3;
                case 4:
                    return CurveInterpolationMode::Bezier4;
                default:
                    break;
            }
            return CurveInterpolationMode::Bezier;
        }
        case 3:
            return CurveInterpolationMode::Cosine;
        default:
            break;
    }

    return points.size() != 1 ? CurveInterpolationMode::Linear : CurveInterpolationMode::Constant;
}

float DB2Manager::GetCurveValueAt(uint32 curveId, float x) const
{
    auto itr = _curvePoints.find(curveId);
    if (itr == _curvePoints.end())
        return 0.0f;

    CurveEntry const* curve = sCurveStore.AssertEntry(curveId);
    std::vector<CurvePointEntry const*> const& points = itr->second;
    if (points.empty())
        return 0.0f;

    switch (DetermineCurveType(curve, points))
    {
        case CurveInterpolationMode::Linear:
        {
            std::size_t pointIndex = 0;
            while (pointIndex < points.size() && points[pointIndex]->Pos.X <= x)
                ++pointIndex;
            if (!pointIndex)
                return points[0]->Pos.Y;
            if (pointIndex >= points.size())
                return points.back()->Pos.Y;
            float xDiff = points[pointIndex]->Pos.X - points[pointIndex - 1]->Pos.X;
            if (xDiff == 0.0)
                return points[pointIndex]->Pos.Y;
            return (((x - points[pointIndex - 1]->Pos.X) / xDiff) * (points[pointIndex]->Pos.Y - points[pointIndex - 1]->Pos.Y)) + points[pointIndex - 1]->Pos.Y;
        }
        case CurveInterpolationMode::Cosine:
        {
            std::size_t pointIndex = 0;
            while (pointIndex < points.size() && points[pointIndex]->Pos.X <= x)
                ++pointIndex;
            if (!pointIndex)
                return points[0]->Pos.Y;
            if (pointIndex >= points.size())
                return points.back()->Pos.Y;
            float xDiff = points[pointIndex]->Pos.X - points[pointIndex - 1]->Pos.X;
            if (xDiff == 0.0)
                return points[pointIndex]->Pos.Y;
            return ((points[pointIndex]->Pos.Y - points[pointIndex - 1]->Pos.Y) * (1.0f - std::cos((x - points[pointIndex - 1]->Pos.X) / xDiff * float(M_PI))) * 0.5f) + points[pointIndex - 1]->Pos.Y;
        }
        case CurveInterpolationMode::CatmullRom:
        {
            std::size_t pointIndex = 1;
            while (pointIndex < points.size() && points[pointIndex]->Pos.X <= x)
                ++pointIndex;
            if (pointIndex == 1)
                return points[1]->Pos.Y;
            if (pointIndex >= points.size() - 1)
                return points[points.size() - 2]->Pos.Y;
            float xDiff = points[pointIndex]->Pos.X - points[pointIndex - 1]->Pos.X;
            if (xDiff == 0.0)
                return points[pointIndex]->Pos.Y;

            float mu = (x - points[pointIndex - 1]->Pos.X) / xDiff;
            float a0 = -0.5f * points[pointIndex - 2]->Pos.Y + 1.5f * points[pointIndex - 1]->Pos.Y - 1.5f * points[pointIndex]->Pos.Y + 0.5f * points[pointIndex + 1]->Pos.Y;
            float a1 = points[pointIndex - 2]->Pos.Y - 2.5f * points[pointIndex - 1]->Pos.Y + 2.0f * points[pointIndex]->Pos.Y - 0.5f * points[pointIndex + 1]->Pos.Y;
            float a2 = -0.5f * points[pointIndex - 2]->Pos.Y + 0.5f * points[pointIndex]->Pos.Y;
            float a3 = points[pointIndex - 1]->Pos.Y;

            return a0 * mu * mu * mu + a1 * mu * mu + a2 * mu + a3;
        }
        case CurveInterpolationMode::Bezier3:
        {
            float xDiff = points[2]->Pos.X - points[0]->Pos.X;
            if (xDiff == 0.0)
                return points[1]->Pos.Y;
            float mu = (x - points[0]->Pos.X) / xDiff;
            return ((1.0f - mu) * (1.0f - mu) * points[0]->Pos.Y) + (1.0f - mu) * 2.0f * mu * points[1]->Pos.Y + mu * mu * points[2]->Pos.Y;
        }
        case CurveInterpolationMode::Bezier4:
        {
            float xDiff = points[3]->Pos.X - points[0]->Pos.X;
            if (xDiff == 0.0)
                return points[1]->Pos.Y;
            float mu = (x - points[0]->Pos.X) / xDiff;
            return (1.0f - mu) * (1.0f - mu) * (1.0f - mu) * points[0]->Pos.Y
                + 3.0f * mu * (1.0f - mu) * (1.0f - mu) * points[1]->Pos.Y
                + 3.0f * mu * mu * (1.0f - mu) * points[2]->Pos.Y
                + mu * mu * mu * points[3]->Pos.Y;
        }
        case CurveInterpolationMode::Bezier:
        {
            float xDiff = points.back()->Pos.X - points[0]->Pos.X;
            if (xDiff == 0.0f)
                return points.back()->Pos.Y;

            std::vector<float> tmp(points.size());
            for (std::size_t i = 0; i < points.size(); ++i)
                tmp[i] = points[i]->Pos.Y;

            float mu = (x - points[0]->Pos.X) / xDiff;
            int32 i = int32(points.size()) - 1;
            while (i > 0)
            {
                for (int32 k = 0; k < i; ++k)
                {
                    float val = tmp[k] + mu * (tmp[k + 1] - tmp[k]);
                    tmp[k] = val;
                }
                --i;
            }
            return tmp[0];
        }
        case CurveInterpolationMode::Constant:
            return points[0]->Pos.Y;
        default:
            break;
    }

    return 0.0f;
}

EmotesTextSoundEntry const* DB2Manager::GetTextSoundEmoteFor(uint32 emote, uint8 race, uint8 gender, uint8 class_) const
{
    auto itr = _emoteTextSounds.find(EmotesTextSoundContainer::key_type(emote, race, gender, class_));
    if (itr != _emoteTextSounds.end())
        return itr->second;

    itr = _emoteTextSounds.find(EmotesTextSoundContainer::key_type(emote, race, gender, uint8(0)));
    if (itr != _emoteTextSounds.end())
        return itr->second;

    return nullptr;
}

template<float(ExpectedStatModEntry::*field)>
struct ExpectedStatModReducer
{
    float operator()(float mod, ExpectedStatModEntry const* expectedStatMod)
    {
        return mod * (expectedStatMod ? expectedStatMod->*field : 1.0f);
    }
};

float DB2Manager::EvaluateExpectedStat(ExpectedStatType stat, uint32 level, int32 expansion, uint32 contentTuningId, Classes unitClass) const
{
    auto expectedStatItr = _expectedStatsByLevel.find(std::make_pair(level, expansion));
    if (expectedStatItr == _expectedStatsByLevel.end())
        expectedStatItr = _expectedStatsByLevel.find(std::make_pair(level, -2));

    if (expectedStatItr == _expectedStatsByLevel.end())
        return 1.0f;

    ExpectedStatModEntry const* classMod = nullptr;
    switch (unitClass)
    {
        case CLASS_WARRIOR:
            classMod = sExpectedStatModStore.LookupEntry(4);
            break;
        case CLASS_PALADIN:
            classMod = sExpectedStatModStore.LookupEntry(2);
            break;
        case CLASS_ROGUE:
            classMod = sExpectedStatModStore.LookupEntry(3);
            break;
        case CLASS_MAGE:
            classMod = sExpectedStatModStore.LookupEntry(1);
            break;
        default:
            break;
    }

    std::vector<ExpectedStatModEntry const*> const* contentTuningMods = Trinity::Containers::MapGetValuePtr(_expectedStatModsByContentTuning, contentTuningId);
    float value = 0.0f;
    switch (stat)
    {
        case ExpectedStatType::CreatureHealth:
            value = expectedStatItr->second->CreatureHealth;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::CreatureHealthMod>());
            if (classMod)
                value *= classMod->CreatureHealthMod;
            break;
        case ExpectedStatType::PlayerHealth:
            value = expectedStatItr->second->PlayerHealth;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::PlayerHealthMod>());
            if (classMod)
                value *= classMod->PlayerHealthMod;
            break;
        case ExpectedStatType::CreatureAutoAttackDps:
            value = expectedStatItr->second->CreatureAutoAttackDps;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::CreatureAutoAttackDPSMod>());
            if (classMod)
                value *= classMod->CreatureAutoAttackDPSMod;
            break;
        case ExpectedStatType::CreatureArmor:
            value = expectedStatItr->second->CreatureArmor;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::CreatureArmorMod>());
            if (classMod)
                value *= classMod->CreatureArmorMod;
            break;
        case ExpectedStatType::PlayerMana:
            value = expectedStatItr->second->PlayerMana;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::PlayerManaMod>());
            if (classMod)
                value *= classMod->PlayerManaMod;
            break;
        case ExpectedStatType::PlayerPrimaryStat:
            value = expectedStatItr->second->PlayerPrimaryStat;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::PlayerPrimaryStatMod>());
            if (classMod)
                value *= classMod->PlayerPrimaryStatMod;
            break;
        case ExpectedStatType::PlayerSecondaryStat:
            value = expectedStatItr->second->PlayerSecondaryStat;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::PlayerSecondaryStatMod>());
            if (classMod)
                value *= classMod->PlayerSecondaryStatMod;
            break;
        case ExpectedStatType::ArmorConstant:
            value = expectedStatItr->second->ArmorConstant;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::ArmorConstantMod>());
            if (classMod)
                value *= classMod->ArmorConstantMod;
            break;
        case ExpectedStatType::None:
            break;
        case ExpectedStatType::CreatureSpellDamage:
            value = expectedStatItr->second->CreatureSpellDamage;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f, ExpectedStatModReducer<&ExpectedStatModEntry::CreatureSpellDamageMod>());
            if (classMod)
                value *= classMod->CreatureSpellDamageMod;
            break;
        default:
            break;
    }

    return value;
}

std::vector<uint32> const* DB2Manager::GetFactionTeamList(uint32 faction) const
{
    auto itr = _factionTeams.find(faction);
    if (itr != _factionTeams.end())
        return &itr->second;

    return nullptr;
}

HeirloomEntry const* DB2Manager::GetHeirloomByItemId(uint32 itemId) const
{
    auto itr = _heirlooms.find(itemId);
    if (itr != _heirlooms.end())
        return itr->second;

    return nullptr;
}

std::vector<uint32> const* DB2Manager::GetGlyphBindableSpells(uint32 glyphPropertiesId) const
{
    auto itr = _glyphBindableSpells.find(glyphPropertiesId);
    if (itr != _glyphBindableSpells.end())
        return &itr->second;

    return nullptr;
}

std::vector<uint32> const* DB2Manager::GetGlyphRequiredSpecs(uint32 glyphPropertiesId) const
{
    auto itr = _glyphRequiredSpecs.find(glyphPropertiesId);
    if (itr != _glyphRequiredSpecs.end())
        return &itr->second;

    return nullptr;
}

DB2Manager::ItemBonusList const* DB2Manager::GetItemBonusList(uint32 bonusListId) const
{
    auto itr = _itemBonusLists.find(bonusListId);
    if (itr != _itemBonusLists.end())
        return &itr->second;

    return nullptr;
}

uint32 DB2Manager::GetItemBonusListForItemLevelDelta(int16 delta) const
{
    auto itr = _itemLevelDeltaToBonusListContainer.find(delta);
    if (itr != _itemLevelDeltaToBonusListContainer.end())
        return itr->second;

    return 0;
}

std::set<uint32> DB2Manager::GetItemBonusTree(uint32 itemId, uint32 itemContext) const
{
    std::set<uint32> bonusListIDs;

    ItemSparseEntry const* proto = sItemSparseStore.LookupEntry(itemId);
    if (!proto)
        return bonusListIDs;

    auto itemIdRange = _itemToBonusTree.equal_range(itemId);
    if (itemIdRange.first == itemIdRange.second)
        return bonusListIDs;

    for (auto itemTreeItr = itemIdRange.first; itemTreeItr != itemIdRange.second; ++itemTreeItr)
    {
        auto treeItr = _itemBonusTrees.find(itemTreeItr->second);
        if (treeItr == _itemBonusTrees.end())
            continue;

        for (ItemBonusTreeNodeEntry const* bonusTreeNode : treeItr->second)
        {
            if (bonusTreeNode->ItemContext != itemContext)
                continue;

            if (bonusTreeNode->ChildItemBonusListID)
            {
                bonusListIDs.insert(bonusTreeNode->ChildItemBonusListID);
            }
            else if (bonusTreeNode->ChildItemLevelSelectorID)
            {
                ItemLevelSelectorEntry const* selector = sItemLevelSelectorStore.LookupEntry(bonusTreeNode->ChildItemLevelSelectorID);
                if (!selector)
                    continue;

                int16 delta = int16(selector->MinItemLevel) - proto->ItemLevel;

                if (uint32 bonus = GetItemBonusListForItemLevelDelta(delta))
                    bonusListIDs.insert(bonus);

                if (ItemLevelSelectorQualitySetEntry const* selectorQualitySet = sItemLevelSelectorQualitySetStore.LookupEntry(selector->ItemLevelSelectorQualitySetID))
                {
                    auto itemSelectorQualities = _itemLevelQualitySelectorQualities.find(selector->ItemLevelSelectorQualitySetID);
                    if (itemSelectorQualities != _itemLevelQualitySelectorQualities.end())
                    {
                        ItemQualities quality = ITEM_QUALITY_UNCOMMON;
                        if (selector->MinItemLevel >= selectorQualitySet->IlvlEpic)
                            quality = ITEM_QUALITY_EPIC;
                        else if (selector->MinItemLevel >= selectorQualitySet->IlvlRare)
                            quality = ITEM_QUALITY_RARE;

                        auto itemSelectorQuality = std::lower_bound(itemSelectorQualities->second.begin(), itemSelectorQualities->second.end(),
                            quality, ItemLevelSelectorQualityEntryComparator{});

                        if (itemSelectorQuality != itemSelectorQualities->second.end())
                            bonusListIDs.insert((*itemSelectorQuality)->QualityItemBonusListID);
                    }
                }
            }
        }
    }

    return bonusListIDs;
}

ItemChildEquipmentEntry const* DB2Manager::GetItemChildEquipment(uint32 itemId) const
{
    auto itr = _itemChildEquipment.find(itemId);
    if (itr != _itemChildEquipment.end())
        return itr->second;

    return nullptr;
}

ItemClassEntry const* DB2Manager::GetItemClassByOldEnum(uint32 itemClass) const
{
    return _itemClassByOldEnum[itemClass];
}

bool DB2Manager::HasItemCurrencyCost(uint32 itemId) const
{
    return _itemsWithCurrencyCost.count(itemId) > 0;
}

std::vector<ItemLimitCategoryConditionEntry const*> const* DB2Manager::GetItemLimitCategoryConditions(uint32 categoryId) const
{
    auto itr = _itemCategoryConditions.find(categoryId);
    if (itr != _itemCategoryConditions.end())
        return &itr->second;

    return nullptr;
}

uint32 DB2Manager::GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const
{
    if (ItemModifiedAppearanceEntry const* modifiedAppearance = GetItemModifiedAppearance(itemId, appearanceModId))
        if (ItemAppearanceEntry const* itemAppearance = sItemAppearanceStore.LookupEntry(modifiedAppearance->ItemAppearanceID))
            return itemAppearance->ItemDisplayInfoID;

    return 0;
}

ItemModifiedAppearanceEntry const* DB2Manager::GetItemModifiedAppearance(uint32 itemId, uint32 appearanceModId) const
{
    auto itr = _itemModifiedAppearancesByItem.find(itemId | (appearanceModId << 24));
    if (itr != _itemModifiedAppearancesByItem.end())
        return itr->second;

    // Fall back to unmodified appearance
    if (appearanceModId)
    {
        itr = _itemModifiedAppearancesByItem.find(itemId);
        if (itr != _itemModifiedAppearancesByItem.end())
            return itr->second;
    }

    return nullptr;
}

ItemModifiedAppearanceEntry const* DB2Manager::GetDefaultItemModifiedAppearance(uint32 itemId) const
{
    auto itr = _itemModifiedAppearancesByItem.find(itemId);
    if (itr != _itemModifiedAppearancesByItem.end())
        return itr->second;

    return nullptr;
}

std::vector<ItemSetSpellEntry const*> const* DB2Manager::GetItemSetSpells(uint32 itemSetId) const
{
    auto itr = _itemSetSpells.find(itemSetId);
    if (itr != _itemSetSpells.end())
        return &itr->second;

    return nullptr;
}

std::vector<ItemSpecOverrideEntry const*> const* DB2Manager::GetItemSpecOverrides(uint32 itemId) const
{
    auto itr = _itemSpecOverrides.find(itemId);
    if (itr != _itemSpecOverrides.end())
        return &itr->second;

    return nullptr;
}

LFGDungeonsEntry const* DB2Manager::GetLfgDungeon(uint32 mapId, Difficulty difficulty)
{
    for (LFGDungeonsEntry const* dungeon : sLFGDungeonsStore)
        if (dungeon->MapID == int32(mapId) && Difficulty(dungeon->DifficultyID) == difficulty)
            return dungeon;

    return nullptr;
}

uint32 DB2Manager::GetDefaultMapLight(uint32 mapId)
{
    for (int32 i = sLightStore.GetNumRows(); i >= 0; --i)
    {
        LightEntry const* light = sLightStore.LookupEntry(uint32(i));
        if (!light)
            continue;

        if (light->ContinentID == int32(mapId) && light->GameCoords.X == 0.0f && light->GameCoords.Y == 0.0f && light->GameCoords.Z == 0.0f)
            return uint32(i);
    }

    return 0;
}

uint32 DB2Manager::GetLiquidFlags(uint32 liquidType)
{
    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquidType))
        return 1 << liq->SoundBank;

    return 0;
}

DB2Manager::MapDifficultyContainer const& DB2Manager::GetMapDifficulties() const
{
    return _mapDifficulties;
}

MapDifficultyEntry const* DB2Manager::GetDefaultMapDifficulty(uint32 mapId, Difficulty* difficulty /*= nullptr*/) const
{
    auto itr = _mapDifficulties.find(mapId);
    if (itr == _mapDifficulties.end())
        return nullptr;

    if (itr->second.empty())
        return nullptr;

    for (auto& p : itr->second)
    {
        DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(p.first);
        if (!difficultyEntry)
            continue;

        if (difficultyEntry->Flags & DIFFICULTY_FLAG_DEFAULT)
        {
            if (difficulty)
                *difficulty = Difficulty(p.first);

            return p.second;
        }
    }

    if (difficulty)
        *difficulty = Difficulty(itr->second.begin()->first);

    return itr->second.begin()->second;
}

MapDifficultyEntry const* DB2Manager::GetMapDifficultyData(uint32 mapId, Difficulty difficulty) const
{
    auto itr = _mapDifficulties.find(mapId);
    if (itr == _mapDifficulties.end())
        return nullptr;

    auto diffItr = itr->second.find(difficulty);
    if (diffItr == itr->second.end())
        return nullptr;

    return diffItr->second;
}

MapDifficultyEntry const* DB2Manager::GetDownscaledMapDifficultyData(uint32 mapId, Difficulty& difficulty) const
{
    DifficultyEntry const* diffEntry = sDifficultyStore.LookupEntry(difficulty);
    if (!diffEntry)
        return GetDefaultMapDifficulty(mapId, &difficulty);

    uint32 tmpDiff = difficulty;
    MapDifficultyEntry const* mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff));
    while (!mapDiff)
    {
        tmpDiff = diffEntry->FallbackDifficultyID;
        diffEntry = sDifficultyStore.LookupEntry(tmpDiff);
        if (!diffEntry)
            return GetDefaultMapDifficulty(mapId, &difficulty);

        // pull new data
        mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // we are 10 normal or 25 normal
    }

    difficulty = Difficulty(tmpDiff);
    return mapDiff;
}

MountEntry const* DB2Manager::GetMount(uint32 spellId) const
{
    auto itr = _mountsBySpellId.find(spellId);
    if (itr != _mountsBySpellId.end())
        return itr->second;

    return nullptr;
}

MountEntry const* DB2Manager::GetMountById(uint32 id) const
{
    return sMountStore.LookupEntry(id);
}

DB2Manager::MountTypeXCapabilitySet const* DB2Manager::GetMountCapabilities(uint32 mountType) const
{
    auto itr = _mountCapabilitiesByType.find(mountType);
    if (itr != _mountCapabilitiesByType.end())
        return &itr->second;

    return nullptr;
}

DB2Manager::MountXDisplayContainer const* DB2Manager::GetMountDisplays(uint32 mountId) const
{
    return Trinity::Containers::MapGetValuePtr(_mountDisplays, mountId);
}

std::string DB2Manager::GetNameGenEntry(uint8 race, uint8 gender) const
{
    ASSERT(gender < GENDER_NONE);
    auto ritr = _nameGenData.find(race);
    if (ritr == _nameGenData.end())
        return "";

    if (ritr->second[gender].empty())
        return "";

    return Trinity::Containers::SelectRandomContainerElement(ritr->second[gender])->Name;
}

ResponseCodes DB2Manager::ValidateName(std::wstring const& name, LocaleConstant locale) const
{
    for (Trinity::wregex const& regex : _nameValidators[locale])
        if (Trinity::regex_search(name, regex))
            return CHAR_NAME_PROFANE;

    // regexes at TOTAL_LOCALES are loaded from NamesReserved which is not locale specific
    for (Trinity::wregex const& regex : _nameValidators[TOTAL_LOCALES])
        if (Trinity::regex_search(name, regex))
            return CHAR_NAME_RESERVED;

    return CHAR_NAME_SUCCESS;
}

int32 DB2Manager::GetNumTalentsAtLevel(uint32 level, Classes playerClass)
{
    NumTalentsAtLevelEntry const* numTalentsAtLevel = sNumTalentsAtLevelStore.LookupEntry(level);
    if (!numTalentsAtLevel)
        numTalentsAtLevel = sNumTalentsAtLevelStore.LookupEntry(sNumTalentsAtLevelStore.GetNumRows() - 1);

    if (numTalentsAtLevel)
    {
        switch (playerClass)
        {
            case CLASS_DEATH_KNIGHT:
                return numTalentsAtLevel->NumTalentsDeathKnight;
            case CLASS_DEMON_HUNTER:
                return numTalentsAtLevel->NumTalentsDemonHunter;
            default:
                return numTalentsAtLevel->NumTalents;
        }
    }

    return 0;
}

PVPDifficultyEntry const* DB2Manager::GetBattlegroundBracketByLevel(uint32 mapid, uint32 level)
{
    PVPDifficultyEntry const* maxEntry = nullptr;           // used for level > max listed level case
    for (PVPDifficultyEntry const* entry : sPVPDifficultyStore)
    {
        // skip unrelated and too-high brackets
        if (entry->MapID != mapid || entry->MinLevel > level)
            continue;

        // exactly fit
        if (entry->MaxLevel >= level)
            return entry;

        // remember for possible out-of-range case (search higher from existed)
        if (!maxEntry || maxEntry->MaxLevel < entry->MaxLevel)
            maxEntry = entry;
    }

    return maxEntry;
}

PVPDifficultyEntry const* DB2Manager::GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id)
{
    for (PVPDifficultyEntry const* entry : sPVPDifficultyStore)
        if (entry->MapID == mapid && entry->GetBracketId() == id)
            return entry;

    return nullptr;
}

uint32 DB2Manager::GetRequiredLevelForPvpTalentSlot(uint8 slot, Classes class_) const
{
    ASSERT(slot < MAX_PVP_TALENT_SLOTS);
    if (_pvpTalentSlotUnlock[slot])
    {
        switch (class_)
        {
            case CLASS_DEATH_KNIGHT:
                return _pvpTalentSlotUnlock[slot]->DeathKnightLevelRequired;
            case CLASS_DEMON_HUNTER:
                return _pvpTalentSlotUnlock[slot]->DemonHunterLevelRequired;
            default:
                break;
        }
        return _pvpTalentSlotUnlock[slot]->LevelRequired;
    }

    return 0;
}

int32 DB2Manager::GetPvpTalentNumSlotsAtLevel(uint32 level, Classes class_) const
{
    int32 slots = 0;
    for (uint8 slot = 0; slot < MAX_PVP_TALENT_SLOTS; ++slot)
        if (level >= GetRequiredLevelForPvpTalentSlot(slot, class_))
            ++slots;

    return slots;
}

std::vector<QuestPackageItemEntry const*> const* DB2Manager::GetQuestPackageItems(uint32 questPackageID) const
{
    auto itr = _questPackages.find(questPackageID);
    if (itr != _questPackages.end())
        return &itr->second.first;

    return nullptr;
}

std::vector<QuestPackageItemEntry const*> const* DB2Manager::GetQuestPackageItemsFallback(uint32 questPackageID) const
{
    auto itr = _questPackages.find(questPackageID);
    if (itr != _questPackages.end())
        return &itr->second.second;

    return nullptr;
}

uint32 DB2Manager::GetQuestUniqueBitFlag(uint32 questId)
{
    QuestV2Entry const* v2 = sQuestV2Store.LookupEntry(questId);
    if (!v2)
        return 0;

    return v2->UniqueBitFlag;
}

std::vector<uint32> const* DB2Manager::GetPhasesForGroup(uint32 group) const
{
    auto itr = _phasesByGroup.find(group);
    if (itr != _phasesByGroup.end())
        return &itr->second;

    return nullptr;
}

PowerTypeEntry const* DB2Manager::GetPowerTypeEntry(Powers power) const
{
    ASSERT(power < MAX_POWERS);
    return _powerTypes[power];
}

PowerTypeEntry const* DB2Manager::GetPowerTypeByName(std::string const& name) const
{
    for (PowerTypeEntry const* powerType : sPowerTypeStore)
    {
        std::string powerName = powerType->NameGlobalStringTag;
        std::transform(powerName.begin(), powerName.end(), powerName.begin(), [](char c) { return char(::tolower(c)); });
        if (powerName == name)
            return powerType;

        powerName.erase(std::remove(powerName.begin(), powerName.end(), '_'), powerName.end());
        if (powerName == name)
            return powerType;
    }

    return nullptr;
}

uint8 DB2Manager::GetPvpItemLevelBonus(uint32 itemId) const
{
    auto itr = _pvpItemBonus.find(itemId);
    if (itr != _pvpItemBonus.end())
        return itr->second;

    return 0;
}

std::vector<RewardPackXCurrencyTypeEntry const*> const* DB2Manager::GetRewardPackCurrencyTypesByRewardID(uint32 rewardPackID) const
{
    auto itr = _rewardPackCurrencyTypes.find(rewardPackID);
    if (itr != _rewardPackCurrencyTypes.end())
        return &itr->second;

    return nullptr;
}

std::vector<RewardPackXItemEntry const*> const* DB2Manager::GetRewardPackItemsByRewardID(uint32 rewardPackID) const
{
    auto itr = _rewardPackItems.find(rewardPackID);
    if (itr != _rewardPackItems.end())
        return &itr->second;

    return nullptr;
}

uint32 DB2Manager::GetRulesetItemUpgrade(uint32 itemId) const
{
    auto itr = _rulesetItemUpgrade.find(itemId);
    if (itr != _rulesetItemUpgrade.end())
        return itr->second;

    return 0;
}

std::vector<SkillLineEntry const*> const* DB2Manager::GetSkillLinesForParentSkill(uint32 parentSkillId) const
{
    return Trinity::Containers::MapGetValuePtr(_skillLinesByParentSkillLine, parentSkillId);
}

std::vector<SkillLineAbilityEntry const*> const* DB2Manager::GetSkillLineAbilitiesBySkill(uint32 skillId) const
{
    return Trinity::Containers::MapGetValuePtr(_skillLineAbilitiesBySkillupSkill, skillId);
}

SkillRaceClassInfoEntry const* DB2Manager::GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_)
{
    auto bounds = _skillRaceClassInfoBySkill.equal_range(skill);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
    {
        if (itr->second->RaceMask && !(itr->second->RaceMask & (UI64LIT(1) << (race - 1))))
            continue;
        if (itr->second->ClassMask && !(itr->second->ClassMask & (1 << (class_ - 1))))
            continue;

        return itr->second;
    }

    return nullptr;
}

std::vector<SpecializationSpellsEntry const*> const* DB2Manager::GetSpecializationSpells(uint32 specId) const
{
    auto itr = _specializationSpellsBySpec.find(specId);
    if (itr != _specializationSpellsBySpec.end())
        return &itr->second;

    return nullptr;
}

bool DB2Manager::IsValidSpellFamiliyName(SpellFamilyNames family)
{
    return _spellFamilyNames.count(family) > 0;
}

std::vector<SpellPowerEntry const*> DB2Manager::GetSpellPowers(uint32 spellId, Difficulty difficulty /*= DIFFICULTY_NONE*/, bool* hasDifficultyPowers /*= nullptr*/) const
{
    std::vector<SpellPowerEntry const*> powers;

    auto difficultyItr = _spellPowerDifficulties.find(spellId);
    if (difficultyItr != _spellPowerDifficulties.end())
    {
        if (hasDifficultyPowers)
            *hasDifficultyPowers = true;

        DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(difficulty);
        while (difficultyEntry)
        {
            auto powerDifficultyItr = difficultyItr->second.find(difficultyEntry->ID);
            if (powerDifficultyItr != difficultyItr->second.end())
            {
                if (powerDifficultyItr->second.size() > powers.size())
                    powers.resize(powerDifficultyItr->second.size());

                for (SpellPowerEntry const* difficultyPower : powerDifficultyItr->second)
                    if (!powers[difficultyPower->OrderIndex])
                        powers[difficultyPower->OrderIndex] = difficultyPower;
            }

            difficultyEntry = sDifficultyStore.LookupEntry(difficultyEntry->FallbackDifficultyID);
        }
    }

    auto itr = _spellPowers.find(spellId);
    if (itr != _spellPowers.end())
    {
        if (itr->second.size() > powers.size())
            powers.resize(itr->second.size());

        for (SpellPowerEntry const* power : itr->second)
            if (!powers[power->OrderIndex])
                powers[power->OrderIndex] = power;
    }

    return powers;
}

std::vector<SpellProcsPerMinuteModEntry const*> DB2Manager::GetSpellProcsPerMinuteMods(uint32 spellprocsPerMinuteId) const
{
    auto itr = _spellProcsPerMinuteMods.find(spellprocsPerMinuteId);
    if (itr != _spellProcsPerMinuteMods.end())
        return itr->second;

    return std::vector<SpellProcsPerMinuteModEntry const*>();
}

std::vector<TalentEntry const*> const& DB2Manager::GetTalentsByPosition(uint32 class_, uint32 tier, uint32 column) const
{
    return _talentsByPosition[class_][tier][column];
}

bool DB2Manager::IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId)
{
    if (requiredTotemCategoryId == 0)
        return true;
    if (itemTotemCategoryId == 0)
        return false;

    TotemCategoryEntry const* itemEntry = sTotemCategoryStore.LookupEntry(itemTotemCategoryId);
    if (!itemEntry)
        return false;
    TotemCategoryEntry const* reqEntry = sTotemCategoryStore.LookupEntry(requiredTotemCategoryId);
    if (!reqEntry)
        return false;

    if (itemEntry->TotemCategoryType != reqEntry->TotemCategoryType)
        return false;

    return (itemEntry->TotemCategoryMask & reqEntry->TotemCategoryMask) == reqEntry->TotemCategoryMask;
}

bool DB2Manager::IsToyItem(uint32 toy) const
{
    return _toys.count(toy) > 0;
}

std::vector<TransmogSetEntry const*> const* DB2Manager::GetTransmogSetsForItemModifiedAppearance(uint32 itemModifiedAppearanceId) const
{
    return Trinity::Containers::MapGetValuePtr(_transmogSetsByItemModifiedAppearance, itemModifiedAppearanceId);
}

std::vector<TransmogSetItemEntry const*> const* DB2Manager::GetTransmogSetItems(uint32 transmogSetId) const
{
    return Trinity::Containers::MapGetValuePtr(_transmogSetItemsByTransmogSet, transmogSetId);
}

struct UiMapAssignmentStatus
{
    UiMapAssignmentEntry const* UiMapAssignment = nullptr;
    // distances if inside
    struct
    {
        float DistanceToRegionCenterSquared = std::numeric_limits<float>::max();
        float DistanceToRegionBottom = std::numeric_limits<float>::max();
    } Inside;

    // distances if outside
    struct
    {
        float DistanceToRegionEdgeSquared = std::numeric_limits<float>::max();
        float DistanceToRegionTop = std::numeric_limits<float>::max();
        float DistanceToRegionBottom = std::numeric_limits<float>::max();
    } Outside;

    int8 MapPriority = 3;
    int8 AreaPriority = -1;
    int8 WmoPriority = 3;

    bool IsInside() const
    {
        return Outside.DistanceToRegionEdgeSquared < std::numeric_limits<float>::epsilon() &&
            std::abs(Outside.DistanceToRegionTop) < std::numeric_limits<float>::epsilon() &&
            std::abs(Outside.DistanceToRegionBottom) < std::numeric_limits<float>::epsilon();
    }
};

static bool operator<(UiMapAssignmentStatus const& left, UiMapAssignmentStatus const& right)
{
    bool leftInside = left.IsInside();
    bool rightInside = right.IsInside();
    if (leftInside != rightInside)
        return leftInside;

    if (left.UiMapAssignment && right.UiMapAssignment &&
        left.UiMapAssignment->UiMapID == right.UiMapAssignment->UiMapID &&
        left.UiMapAssignment->OrderIndex != right.UiMapAssignment->OrderIndex)
        return left.UiMapAssignment->OrderIndex < right.UiMapAssignment->OrderIndex;

    if (left.WmoPriority != right.WmoPriority)
        return left.WmoPriority < right.WmoPriority;

    if (left.AreaPriority != right.AreaPriority)
        return left.AreaPriority < right.AreaPriority;

    if (left.MapPriority != right.MapPriority)
        return left.MapPriority < right.MapPriority;

    if (leftInside)
    {
        if (left.Inside.DistanceToRegionBottom != right.Inside.DistanceToRegionBottom)
            return left.Inside.DistanceToRegionBottom < right.Inside.DistanceToRegionBottom;

        float leftUiSizeX = left.UiMapAssignment ? (left.UiMapAssignment->UiMax.X - left.UiMapAssignment->UiMin.X) : 0.0f;
        float rightUiSizeX = right.UiMapAssignment ? (right.UiMapAssignment->UiMax.X - right.UiMapAssignment->UiMin.X) : 0.0f;

        if (leftUiSizeX > std::numeric_limits<float>::epsilon() && rightUiSizeX > std::numeric_limits<float>::epsilon())
        {
            float leftScale = (left.UiMapAssignment->Region[1].X - left.UiMapAssignment->Region[0].X) / leftUiSizeX;
            float rightScale = (right.UiMapAssignment->Region[1].X - right.UiMapAssignment->Region[0].X) / rightUiSizeX;
            if (leftScale != rightScale)
                return leftScale < rightScale;
        }

        if (left.Inside.DistanceToRegionCenterSquared != right.Inside.DistanceToRegionCenterSquared)
            return left.Inside.DistanceToRegionCenterSquared < right.Inside.DistanceToRegionCenterSquared;
    }
    else
    {
        if (left.Outside.DistanceToRegionTop != right.Outside.DistanceToRegionTop)
            return left.Outside.DistanceToRegionTop < right.Outside.DistanceToRegionTop;

        if (left.Outside.DistanceToRegionBottom != right.Outside.DistanceToRegionBottom)
            return left.Outside.DistanceToRegionBottom < right.Outside.DistanceToRegionBottom;

        if (left.Outside.DistanceToRegionEdgeSquared != right.Outside.DistanceToRegionEdgeSquared)
            return left.Outside.DistanceToRegionEdgeSquared < right.Outside.DistanceToRegionEdgeSquared;
    }

    return true;
}

static bool CheckUiMapAssignmentStatus(float x, float y, float z, int32 mapId, int32 areaId, int32 wmoDoodadPlacementId, int32 wmoGroupId,
    UiMapAssignmentEntry const* uiMapAssignment, UiMapAssignmentStatus* status)
{
    status->UiMapAssignment = uiMapAssignment;
    // x,y not in region
    if (x < uiMapAssignment->Region[0].X || x > uiMapAssignment->Region[1].X || y < uiMapAssignment->Region[0].Y || y > uiMapAssignment->Region[1].Y)
    {
        float xDiff, yDiff;
        if (x >= uiMapAssignment->Region[0].X)
        {
            xDiff = 0.0f;
            if (x > uiMapAssignment->Region[1].X)
                xDiff = x - uiMapAssignment->Region[0].X;
        }
        else
            xDiff = uiMapAssignment->Region[0].X - x;

        if (y >= uiMapAssignment->Region[0].Y)
        {
            yDiff = 0.0f;
            if (y > uiMapAssignment->Region[1].Y)
                yDiff = y - uiMapAssignment->Region[0].Y;
        }
        else
            yDiff = uiMapAssignment->Region[0].Y - y;

        status->Outside.DistanceToRegionEdgeSquared = xDiff * xDiff + yDiff * yDiff;
    }
    else
    {
        status->Inside.DistanceToRegionCenterSquared =
            (x - (uiMapAssignment->Region[0].X + uiMapAssignment->Region[1].X) * 0.5f) * (x - (uiMapAssignment->Region[0].X + uiMapAssignment->Region[1].X) * 0.5f)
            + (y - (uiMapAssignment->Region[0].Y + uiMapAssignment->Region[1].Y) * 0.5f) * (y - (uiMapAssignment->Region[0].Y + uiMapAssignment->Region[1].Y) * 0.5f);
        status->Outside.DistanceToRegionEdgeSquared = 0.0f;
    }

    // z not in region
    if (z < uiMapAssignment->Region[0].Z || z > uiMapAssignment->Region[1].Z)
    {
        if (z < uiMapAssignment->Region[1].Z)
        {
            if (z < uiMapAssignment->Region[0].Z)
                status->Outside.DistanceToRegionBottom = std::min(uiMapAssignment->Region[0].Z - z, 10000.0f);
        }
        else
            status->Outside.DistanceToRegionTop = std::min(z - uiMapAssignment->Region[1].Z, 10000.0f);
    }
    else
    {
        status->Outside.DistanceToRegionTop = 0.0f;
        status->Outside.DistanceToRegionBottom = 0.0f;
        status->Inside.DistanceToRegionBottom = std::min(uiMapAssignment->Region[0].Z - z, 10000.0f);
    }

    if (areaId && uiMapAssignment->AreaID)
    {
        int8 areaPriority = 0;
        while (areaId != uiMapAssignment->AreaID)
        {
            if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId))
            {
                areaId = areaEntry->ParentAreaID;
                ++areaPriority;
            }
            else
                return false;
        }

        status->AreaPriority = areaPriority;
    }

    if (mapId >= 0 && uiMapAssignment->MapID >= 0)
    {
        if (mapId != uiMapAssignment->MapID)
        {
            if (MapEntry const* mapEntry = sMapStore.LookupEntry(mapId))
            {
                if (mapEntry->ParentMapID == uiMapAssignment->MapID)
                    status->MapPriority = 1;
                else if (mapEntry->CosmeticParentMapID == uiMapAssignment->MapID)
                    status->MapPriority = 2;
                else
                    return false;
            }
            else
                return false;
        }
        else
            status->MapPriority = 0;
    }

    if (wmoGroupId || wmoDoodadPlacementId)
    {
        if (uiMapAssignment->WmoGroupID || uiMapAssignment->WmoDoodadPlacementID)
        {
            bool hasDoodadPlacement = false;
            if (wmoDoodadPlacementId && uiMapAssignment->WmoDoodadPlacementID)
            {
                if (wmoDoodadPlacementId != uiMapAssignment->WmoDoodadPlacementID)
                    return false;

                hasDoodadPlacement = true;
            }

            if (wmoGroupId && uiMapAssignment->WmoGroupID)
            {
                if (wmoGroupId != uiMapAssignment->WmoGroupID)
                    return false;

                if (hasDoodadPlacement)
                    status->WmoPriority = 0;
                else
                    status->WmoPriority = 2;
            }
            else if (hasDoodadPlacement)
                status->WmoPriority = 1;
        }
    }

    return true;
}

static UiMapAssignmentEntry const* FindNearestMapAssignment(float x, float y, float z, int32 mapId, int32 areaId, int32 wmoDoodadPlacementId, int32 wmoGroupId, UiMapSystem system)
{
    UiMapAssignmentStatus nearestMapAssignment;
    auto iterateUiMapAssignments = [&](std::unordered_multimap<int32, UiMapAssignmentEntry const*> const& assignments, int32 id)
    {
        for (auto assignment : Trinity::Containers::MapEqualRange(assignments, id))
        {
            UiMapAssignmentStatus status;
            if (CheckUiMapAssignmentStatus(x, y, z, mapId, areaId, wmoDoodadPlacementId, wmoGroupId, assignment.second, &status))
                if (status < nearestMapAssignment)
                    nearestMapAssignment = status;
        }
    };

    iterateUiMapAssignments(_uiMapAssignmentByWmoGroup[system], wmoGroupId);
    iterateUiMapAssignments(_uiMapAssignmentByWmoDoodadPlacement[system], wmoDoodadPlacementId);

    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);
    while (areaEntry)
    {
        iterateUiMapAssignments(_uiMapAssignmentByArea[system], areaEntry->ID);
        areaEntry = sAreaTableStore.LookupEntry(areaEntry->ParentAreaID);
    }

    if (MapEntry const* mapEntry = sMapStore.LookupEntry(mapId))
    {
        iterateUiMapAssignments(_uiMapAssignmentByMap[system], mapEntry->ID);
        if (mapEntry->ParentMapID >= 0)
            iterateUiMapAssignments(_uiMapAssignmentByMap[system], mapEntry->ParentMapID);
        if (mapEntry->CosmeticParentMapID >= 0)
            iterateUiMapAssignments(_uiMapAssignmentByMap[system], mapEntry->CosmeticParentMapID);
    }

    return nearestMapAssignment.UiMapAssignment;
}

static DBCPosition2D CalculateGlobalUiMapPosition(int32 uiMapID, DBCPosition2D uiPosition)
{
    UiMapEntry const* uiMap = sUiMapStore.LookupEntry(uiMapID);
    while (uiMap)
    {
        if (uiMap->Type <= UI_MAP_TYPE_CONTINENT)
            break;

        UiMapBounds const* bounds = Trinity::Containers::MapGetValuePtr(_uiMapBounds, uiMap->ID);
        if (!bounds || !bounds->IsUiAssignment)
            break;

        uiPosition.X = ((1.0 - uiPosition.X) * bounds->Bounds[1]) + (bounds->Bounds[3] * uiPosition.X);
        uiPosition.Y = ((1.0 - uiPosition.Y) * bounds->Bounds[0]) + (bounds->Bounds[2] * uiPosition.Y);

        uiMap = sUiMapStore.LookupEntry(uiMap->ParentUiMapID);
    }

    return uiPosition;
}

bool DB2Manager::GetUiMapPosition(float x, float y, float z, int32 mapId, int32 areaId, int32 wmoDoodadPlacementId, int32 wmoGroupId, UiMapSystem system, bool local,
    int32* uiMapId /*= nullptr*/, DBCPosition2D* newPos /*= nullptr*/)
{
    if (uiMapId)
        *uiMapId = -1;

    if (newPos)
    {
        newPos->X = 0.0f;
        newPos->Y = 0.0f;
    }

    UiMapAssignmentEntry const* uiMapAssignment = FindNearestMapAssignment(x, y, z, mapId, areaId, wmoDoodadPlacementId, wmoGroupId, system);
    if (!uiMapAssignment)
        return false;

    if (uiMapId)
        *uiMapId = uiMapAssignment->UiMapID;

    DBCPosition2D relativePosition{ 0.5f, 0.5f };
    DBCPosition2D regionSize{ uiMapAssignment->Region[1].X - uiMapAssignment->Region[0].X, uiMapAssignment->Region[1].Y - uiMapAssignment->Region[0].Y };
    if (regionSize.X > 0.0f)
        relativePosition.X = (x - uiMapAssignment->Region[0].X) / regionSize.X;
    if (regionSize.Y > 0.0f)
        relativePosition.Y = (y - uiMapAssignment->Region[0].Y) / regionSize.Y;

    DBCPosition2D uiPosition
    {
        // x any y are swapped
        ((1.0f - (1.0f - relativePosition.Y)) * uiMapAssignment->UiMin.X) + ((1.0f - relativePosition.Y) * uiMapAssignment->UiMax.X),
        ((1.0f - (1.0f - relativePosition.X)) * uiMapAssignment->UiMin.Y) + ((1.0f - relativePosition.X) * uiMapAssignment->UiMax.Y)
    };

    if (!local)
        uiPosition = CalculateGlobalUiMapPosition(uiMapAssignment->UiMapID, uiPosition);

    if (newPos)
        *newPos = uiPosition;

    return true;
}

void DB2Manager::Zone2MapCoordinates(uint32 areaId, float& x, float& y) const
{
    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);
    if (!areaEntry)
        return;

    for (auto assignment : Trinity::Containers::MapEqualRange(_uiMapAssignmentByArea[UI_MAP_SYSTEM_WORLD], areaId))
    {
        if (assignment.second->MapID >= 0 && assignment.second->MapID != areaEntry->ContinentID)
            continue;

        float tmpY = 1.0 - ((y - assignment.second->UiMin.Y) / (assignment.second->UiMax.Y - assignment.second->UiMin.Y));
        float tmpX = 1.0 - ((x - assignment.second->UiMin.X) / (assignment.second->UiMax.X - assignment.second->UiMin.X));
        y = ((1.0 - tmpY) * assignment.second->Region[0].X) + (tmpY * assignment.second->Region[1].X);
        x = ((1.0 - tmpX) * assignment.second->Region[0].Y) + (tmpX * assignment.second->Region[1].Y);
        break;
    }
}

void DB2Manager::Map2ZoneCoordinates(uint32 areaId, float& x, float& y) const
{
    DBCPosition2D zoneCoords;
    if (!GetUiMapPosition(x, y, 0.0f, -1, areaId, 0, 0, UI_MAP_SYSTEM_WORLD, true, nullptr, &zoneCoords))
        return;

    x = zoneCoords.Y * 100.0f;
    y = zoneCoords.X * 100.0f;
}

bool DB2Manager::IsUiMapPhase(uint32 phaseId) const
{
    return _uiMapPhases.find(phaseId) != _uiMapPhases.end();
}

WMOAreaTableEntry const* DB2Manager::GetWMOAreaTable(int32 rootId, int32 adtId, int32 groupId) const
{
    return Trinity::Containers::MapGetValuePtr(_wmoAreaTableLookup, WMOAreaTableKey(int16(rootId), int8(adtId), groupId));
}

bool ChrClassesXPowerTypesEntryComparator::Compare(ChrClassesXPowerTypesEntry const* left, ChrClassesXPowerTypesEntry const* right)
{
    if (left->ClassID != right->ClassID)
        return left->ClassID < right->ClassID;
    return left->PowerType < right->PowerType;
}

bool ItemLevelSelectorQualityEntryComparator::Compare(ItemLevelSelectorQualityEntry const* left, ItemLevelSelectorQualityEntry const* right)
{
    return left->Quality > right->Quality;
}

bool DB2Manager::MountTypeXCapabilityEntryComparator::Compare(MountTypeXCapabilityEntry const* left, MountTypeXCapabilityEntry const* right)
{
    if (left->MountTypeID == right->MountTypeID)
        return left->OrderIndex < right->OrderIndex;
    return left->MountTypeID < right->MountTypeID;
}
