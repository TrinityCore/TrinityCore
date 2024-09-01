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

#include "DB2Stores.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2LoadInfo.h"
#include "Hash.h"
#include "ItemTemplate.h"
#include "IteratorPair.h"
#include "Log.h"
#include "Random.h"
#include "Regex.h"
#include "Timer.h"
#include "Util.h"
#include "World.h"
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <array>
#include <bitset>
#include <numeric>
#include <sstream>
#include <cctype>

// temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

DB2Storage<AchievementEntry>                    sAchievementStore("Achievement.db2", &AchievementLoadInfo::Instance);
DB2Storage<Achievement_CategoryEntry>           sAchievementCategoryStore("Achievement_Category.db2", &AchievementCategoryLoadInfo::Instance);
DB2Storage<AdventureJournalEntry>               sAdventureJournalStore("AdventureJournal.db2", &AdventureJournalLoadInfo::Instance);
DB2Storage<AdventureMapPOIEntry>                sAdventureMapPOIStore("AdventureMapPOI.db2", &AdventureMapPoiLoadInfo::Instance);
DB2Storage<AnimationDataEntry>                  sAnimationDataStore("AnimationData.db2", &AnimationDataLoadInfo::Instance);
DB2Storage<AnimKitEntry>                        sAnimKitStore("AnimKit.db2", &AnimKitLoadInfo::Instance);
DB2Storage<AreaGroupMemberEntry>                sAreaGroupMemberStore("AreaGroupMember.db2", &AreaGroupMemberLoadInfo::Instance);
DB2Storage<AreaTableEntry>                      sAreaTableStore("AreaTable.db2", &AreaTableLoadInfo::Instance);
DB2Storage<AreaTriggerEntry>                    sAreaTriggerStore("AreaTrigger.db2", &AreaTriggerLoadInfo::Instance);
DB2Storage<AreaTriggerActionSetEntry>           sAreaTriggerActionSetStore("AreaTriggerActionSet.db2", &AreaTriggerActionSetLoadInfo::Instance);
DB2Storage<ArmorLocationEntry>                  sArmorLocationStore("ArmorLocation.db2", &ArmorLocationLoadInfo::Instance);
DB2Storage<ArtifactEntry>                       sArtifactStore("Artifact.db2", &ArtifactLoadInfo::Instance);
DB2Storage<ArtifactAppearanceEntry>             sArtifactAppearanceStore("ArtifactAppearance.db2", &ArtifactAppearanceLoadInfo::Instance);
DB2Storage<ArtifactAppearanceSetEntry>          sArtifactAppearanceSetStore("ArtifactAppearanceSet.db2", &ArtifactAppearanceSetLoadInfo::Instance);
DB2Storage<ArtifactCategoryEntry>               sArtifactCategoryStore("ArtifactCategory.db2", &ArtifactCategoryLoadInfo::Instance);
DB2Storage<ArtifactPowerEntry>                  sArtifactPowerStore("ArtifactPower.db2", &ArtifactPowerLoadInfo::Instance);
DB2Storage<ArtifactPowerLinkEntry>              sArtifactPowerLinkStore("ArtifactPowerLink.db2", &ArtifactPowerLinkLoadInfo::Instance);
DB2Storage<ArtifactPowerPickerEntry>            sArtifactPowerPickerStore("ArtifactPowerPicker.db2", &ArtifactPowerPickerLoadInfo::Instance);
DB2Storage<ArtifactPowerRankEntry>              sArtifactPowerRankStore("ArtifactPowerRank.db2", &ArtifactPowerRankLoadInfo::Instance);
DB2Storage<ArtifactQuestXPEntry>                sArtifactQuestXPStore("ArtifactQuestXP.db2", &ArtifactQuestXpLoadInfo::Instance);
DB2Storage<ArtifactTierEntry>                   sArtifactTierStore("ArtifactTier.db2", &ArtifactTierLoadInfo::Instance);
DB2Storage<ArtifactUnlockEntry>                 sArtifactUnlockStore("ArtifactUnlock.db2", &ArtifactUnlockLoadInfo::Instance);
DB2Storage<AuctionHouseEntry>                   sAuctionHouseStore("AuctionHouse.db2", &AuctionHouseLoadInfo::Instance);
DB2Storage<AzeriteEmpoweredItemEntry>           sAzeriteEmpoweredItemStore("AzeriteEmpoweredItem.db2", &AzeriteEmpoweredItemLoadInfo::Instance);
DB2Storage<AzeriteEssenceEntry>                 sAzeriteEssenceStore("AzeriteEssence.db2", &AzeriteEssenceLoadInfo::Instance);
DB2Storage<AzeriteEssencePowerEntry>            sAzeriteEssencePowerStore("AzeriteEssencePower.db2", &AzeriteEssencePowerLoadInfo::Instance);
DB2Storage<AzeriteItemEntry>                    sAzeriteItemStore("AzeriteItem.db2", &AzeriteItemLoadInfo::Instance);
DB2Storage<AzeriteItemMilestonePowerEntry>      sAzeriteItemMilestonePowerStore("AzeriteItemMilestonePower.db2", &AzeriteItemMilestonePowerLoadInfo::Instance);
DB2Storage<AzeriteKnowledgeMultiplierEntry>     sAzeriteKnowledgeMultiplierStore("AzeriteKnowledgeMultiplier.db2", &AzeriteKnowledgeMultiplierLoadInfo::Instance);
DB2Storage<AzeriteLevelInfoEntry>               sAzeriteLevelInfoStore("AzeriteLevelInfo.db2", &AzeriteLevelInfoLoadInfo::Instance);
DB2Storage<AzeritePowerEntry>                   sAzeritePowerStore("AzeritePower.db2", &AzeritePowerLoadInfo::Instance);
DB2Storage<AzeritePowerSetMemberEntry>          sAzeritePowerSetMemberStore("AzeritePowerSetMember.db2", &AzeritePowerSetMemberLoadInfo::Instance);
DB2Storage<AzeriteTierUnlockEntry>              sAzeriteTierUnlockStore("AzeriteTierUnlock.db2", &AzeriteTierUnlockLoadInfo::Instance);
DB2Storage<AzeriteTierUnlockSetEntry>           sAzeriteTierUnlockSetStore("AzeriteTierUnlockSet.db2", &AzeriteTierUnlockSetLoadInfo::Instance);
DB2Storage<AzeriteUnlockMappingEntry>           sAzeriteUnlockMappingStore("AzeriteUnlockMapping.db2", &AzeriteUnlockMappingLoadInfo::Instance);
DB2Storage<BankBagSlotPricesEntry>              sBankBagSlotPricesStore("BankBagSlotPrices.db2", &BankBagSlotPricesLoadInfo::Instance);
DB2Storage<BannedAddonsEntry>                   sBannedAddonsStore("BannedAddons.db2", &BannedAddonsLoadInfo::Instance);
DB2Storage<BarberShopStyleEntry>                sBarberShopStyleStore("BarberShopStyle.db2", &BarberShopStyleLoadInfo::Instance);
DB2Storage<BattlePetAbilityEntry>               sBattlePetAbilityStore("BattlePetAbility.db2", &BattlePetAbilityLoadInfo::Instance);
DB2Storage<BattlePetBreedQualityEntry>          sBattlePetBreedQualityStore("BattlePetBreedQuality.db2", &BattlePetBreedQualityLoadInfo::Instance);
DB2Storage<BattlePetBreedStateEntry>            sBattlePetBreedStateStore("BattlePetBreedState.db2", &BattlePetBreedStateLoadInfo::Instance);
DB2Storage<BattlePetSpeciesEntry>               sBattlePetSpeciesStore("BattlePetSpecies.db2", &BattlePetSpeciesLoadInfo::Instance);
DB2Storage<BattlePetSpeciesStateEntry>          sBattlePetSpeciesStateStore("BattlePetSpeciesState.db2", &BattlePetSpeciesStateLoadInfo::Instance);
DB2Storage<BattlemasterListEntry>               sBattlemasterListStore("BattlemasterList.db2", &BattlemasterListLoadInfo::Instance);
DB2Storage<BattlemasterListXMapEntry>           sBattlemasterListXMapStore("BattlemasterListXMap.db2", &BattlemasterListXMapLoadInfo::Instance);
DB2Storage<BroadcastTextEntry>                  sBroadcastTextStore("BroadcastText.db2", &BroadcastTextLoadInfo::Instance);
DB2Storage<BroadcastTextDurationEntry>          sBroadcastTextDurationStore("BroadcastTextDuration.db2", &BroadcastTextDurationLoadInfo::Instance);
DB2Storage<Cfg_CategoriesEntry>                 sCfgCategoriesStore("Cfg_Categories.db2", &CfgCategoriesLoadInfo::Instance);
DB2Storage<Cfg_RegionsEntry>                    sCfgRegionsStore("Cfg_Regions.db2", &CfgRegionsLoadInfo::Instance);
DB2Storage<ChallengeModeItemBonusOverrideEntry> sChallengeModeItemBonusOverrideStore("ChallengeModeItemBonusOverride.db2", &ChallengeModeItemBonusOverrideLoadInfo::Instance);
DB2Storage<CharBaseInfoEntry>                   sCharBaseInfoStore("CharBaseInfo.db2", &CharBaseInfoLoadInfo::Instance);
DB2Storage<CharTitlesEntry>                     sCharTitlesStore("CharTitles.db2", &CharTitlesLoadInfo::Instance);
DB2Storage<CharacterLoadoutEntry>               sCharacterLoadoutStore("CharacterLoadout.db2", &CharacterLoadoutLoadInfo::Instance);
DB2Storage<CharacterLoadoutItemEntry>           sCharacterLoadoutItemStore("CharacterLoadoutItem.db2", &CharacterLoadoutItemLoadInfo::Instance);
DB2Storage<ChatChannelsEntry>                   sChatChannelsStore("ChatChannels.db2", &ChatChannelsLoadInfo::Instance);
DB2Storage<ChrClassUIDisplayEntry>              sChrClassUIDisplayStore("ChrClassUIDisplay.db2", &ChrClassUiDisplayLoadInfo::Instance);
DB2Storage<ChrClassesEntry>                     sChrClassesStore("ChrClasses.db2", &ChrClassesLoadInfo::Instance);
DB2Storage<ChrClassesXPowerTypesEntry>          sChrClassesXPowerTypesStore("ChrClassesXPowerTypes.db2", &ChrClassesXPowerTypesLoadInfo::Instance);
DB2Storage<ChrCustomizationChoiceEntry>         sChrCustomizationChoiceStore("ChrCustomizationChoice.db2", &ChrCustomizationChoiceLoadInfo::Instance);
DB2Storage<ChrCustomizationDisplayInfoEntry>    sChrCustomizationDisplayInfoStore("ChrCustomizationDisplayInfo.db2", &ChrCustomizationDisplayInfoLoadInfo::Instance);
DB2Storage<ChrCustomizationElementEntry>        sChrCustomizationElementStore("ChrCustomizationElement.db2", &ChrCustomizationElementLoadInfo::Instance);
DB2Storage<ChrCustomizationOptionEntry>         sChrCustomizationOptionStore("ChrCustomizationOption.db2", &ChrCustomizationOptionLoadInfo::Instance);
DB2Storage<ChrCustomizationReqEntry>            sChrCustomizationReqStore("ChrCustomizationReq.db2", &ChrCustomizationReqLoadInfo::Instance);
DB2Storage<ChrCustomizationReqChoiceEntry>      sChrCustomizationReqChoiceStore("ChrCustomizationReqChoice.db2", &ChrCustomizationReqChoiceLoadInfo::Instance);
DB2Storage<ChrModelEntry>                       sChrModelStore("ChrModel.db2", &ChrModelLoadInfo::Instance);
DB2Storage<ChrRaceXChrModelEntry>               sChrRaceXChrModelStore("ChrRaceXChrModel.db2", &ChrRaceXChrModelLoadInfo::Instance);
DB2Storage<ChrRacesEntry>                       sChrRacesStore("ChrRaces.db2", &ChrRacesLoadInfo::Instance);
DB2Storage<ChrSpecializationEntry>              sChrSpecializationStore("ChrSpecialization.db2", &ChrSpecializationLoadInfo::Instance);
DB2Storage<CinematicCameraEntry>                sCinematicCameraStore("CinematicCamera.db2", &CinematicCameraLoadInfo::Instance);
DB2Storage<CinematicSequencesEntry>             sCinematicSequencesStore("CinematicSequences.db2", &CinematicSequencesLoadInfo::Instance);
DB2Storage<ConditionalChrModelEntry>            sConditionalChrModelStore("ConditionalChrModel.db2", &ConditionalChrModelLoadInfo::Instance);
DB2Storage<ConditionalContentTuningEntry>       sConditionalContentTuningStore("ConditionalContentTuning.db2", &ConditionalContentTuningLoadInfo::Instance);
DB2Storage<ContentTuningEntry>                  sContentTuningStore("ContentTuning.db2", &ContentTuningLoadInfo::Instance);
DB2Storage<ContentTuningXExpectedEntry>         sContentTuningXExpectedStore("ContentTuningXExpected.db2", &ContentTuningXExpectedLoadInfo::Instance);
DB2Storage<ContentTuningXLabelEntry>            sContentTuningXLabelStore("ContentTuningXLabel.db2", &ContentTuningXLabelLoadInfo::Instance);
DB2Storage<ConversationLineEntry>               sConversationLineStore("ConversationLine.db2", &ConversationLineLoadInfo::Instance);
DB2Storage<CorruptionEffectsEntry>              sCorruptionEffectsStore("CorruptionEffects.db2", &CorruptionEffectsLoadInfo::Instance);
DB2Storage<CreatureDisplayInfoEntry>            sCreatureDisplayInfoStore("CreatureDisplayInfo.db2", &CreatureDisplayInfoLoadInfo::Instance);
DB2Storage<CreatureDisplayInfoExtraEntry>       sCreatureDisplayInfoExtraStore("CreatureDisplayInfoExtra.db2", &CreatureDisplayInfoExtraLoadInfo::Instance);
DB2Storage<CreatureFamilyEntry>                 sCreatureFamilyStore("CreatureFamily.db2", &CreatureFamilyLoadInfo::Instance);
DB2Storage<CreatureModelDataEntry>              sCreatureModelDataStore("CreatureModelData.db2", &CreatureModelDataLoadInfo::Instance);
DB2Storage<CreatureTypeEntry>                   sCreatureTypeStore("CreatureType.db2", &CreatureTypeLoadInfo::Instance);
DB2Storage<CriteriaEntry>                       sCriteriaStore("Criteria.db2", &CriteriaLoadInfo::Instance);
DB2Storage<CriteriaTreeEntry>                   sCriteriaTreeStore("CriteriaTree.db2", &CriteriaTreeLoadInfo::Instance);
DB2Storage<CurrencyContainerEntry>              sCurrencyContainerStore("CurrencyContainer.db2", &CurrencyContainerLoadInfo::Instance);
DB2Storage<CurrencyTypesEntry>                  sCurrencyTypesStore("CurrencyTypes.db2", &CurrencyTypesLoadInfo::Instance);
DB2Storage<CurveEntry>                          sCurveStore("Curve.db2", &CurveLoadInfo::Instance);
DB2Storage<CurvePointEntry>                     sCurvePointStore("CurvePoint.db2", &CurvePointLoadInfo::Instance);
DB2Storage<DestructibleModelDataEntry>          sDestructibleModelDataStore("DestructibleModelData.db2", &DestructibleModelDataLoadInfo::Instance);
DB2Storage<DifficultyEntry>                     sDifficultyStore("Difficulty.db2", &DifficultyLoadInfo::Instance);
DB2Storage<DungeonEncounterEntry>               sDungeonEncounterStore("DungeonEncounter.db2", &DungeonEncounterLoadInfo::Instance);
DB2Storage<DurabilityCostsEntry>                sDurabilityCostsStore("DurabilityCosts.db2", &DurabilityCostsLoadInfo::Instance);
DB2Storage<DurabilityQualityEntry>              sDurabilityQualityStore("DurabilityQuality.db2", &DurabilityQualityLoadInfo::Instance);
DB2Storage<EmotesEntry>                         sEmotesStore("Emotes.db2", &EmotesLoadInfo::Instance);
DB2Storage<EmotesTextEntry>                     sEmotesTextStore("EmotesText.db2", &EmotesTextLoadInfo::Instance);
DB2Storage<EmotesTextSoundEntry>                sEmotesTextSoundStore("EmotesTextSound.db2", &EmotesTextSoundLoadInfo::Instance);
DB2Storage<ExpectedStatEntry>                   sExpectedStatStore("ExpectedStat.db2", &ExpectedStatLoadInfo::Instance);
DB2Storage<ExpectedStatModEntry>                sExpectedStatModStore("ExpectedStatMod.db2", &ExpectedStatModLoadInfo::Instance);
DB2Storage<FactionEntry>                        sFactionStore("Faction.db2", &FactionLoadInfo::Instance);
DB2Storage<FactionTemplateEntry>                sFactionTemplateStore("FactionTemplate.db2", &FactionTemplateLoadInfo::Instance);
DB2Storage<FriendshipRepReactionEntry>          sFriendshipRepReactionStore("FriendshipRepReaction.db2", &FriendshipRepReactionLoadInfo::Instance);
DB2Storage<FriendshipReputationEntry>           sFriendshipReputationStore("FriendshipReputation.db2", &FriendshipReputationLoadInfo::Instance);
DB2Storage<GameObjectArtKitEntry>               sGameObjectArtKitStore("GameObjectArtKit.db2", &GameobjectArtKitLoadInfo::Instance);
DB2Storage<GameObjectDisplayInfoEntry>          sGameObjectDisplayInfoStore("GameObjectDisplayInfo.db2", &GameobjectDisplayInfoLoadInfo::Instance);
DB2Storage<GameObjectsEntry>                    sGameObjectsStore("GameObjects.db2", &GameobjectsLoadInfo::Instance);
DB2Storage<GarrAbilityEntry>                    sGarrAbilityStore("GarrAbility.db2", &GarrAbilityLoadInfo::Instance);
DB2Storage<GarrBuildingEntry>                   sGarrBuildingStore("GarrBuilding.db2", &GarrBuildingLoadInfo::Instance);
DB2Storage<GarrBuildingPlotInstEntry>           sGarrBuildingPlotInstStore("GarrBuildingPlotInst.db2", &GarrBuildingPlotInstLoadInfo::Instance);
DB2Storage<GarrClassSpecEntry>                  sGarrClassSpecStore("GarrClassSpec.db2", &GarrClassSpecLoadInfo::Instance);
DB2Storage<GarrFollowerEntry>                   sGarrFollowerStore("GarrFollower.db2", &GarrFollowerLoadInfo::Instance);
DB2Storage<GarrFollowerXAbilityEntry>           sGarrFollowerXAbilityStore("GarrFollowerXAbility.db2", &GarrFollowerXAbilityLoadInfo::Instance);
DB2Storage<GarrMissionEntry>                    sGarrMissionStore("GarrMission.db2", &GarrMissionLoadInfo::Instance);
DB2Storage<GarrPlotEntry>                       sGarrPlotStore("GarrPlot.db2", &GarrPlotLoadInfo::Instance);
DB2Storage<GarrPlotBuildingEntry>               sGarrPlotBuildingStore("GarrPlotBuilding.db2", &GarrPlotBuildingLoadInfo::Instance);
DB2Storage<GarrPlotInstanceEntry>               sGarrPlotInstanceStore("GarrPlotInstance.db2", &GarrPlotInstanceLoadInfo::Instance);
DB2Storage<GarrSiteLevelEntry>                  sGarrSiteLevelStore("GarrSiteLevel.db2", &GarrSiteLevelLoadInfo::Instance);
DB2Storage<GarrSiteLevelPlotInstEntry>          sGarrSiteLevelPlotInstStore("GarrSiteLevelPlotInst.db2", &GarrSiteLevelPlotInstLoadInfo::Instance);
DB2Storage<GarrTalentTreeEntry>                 sGarrTalentTreeStore("GarrTalentTree.db2", &GarrTalentTreeLoadInfo::Instance);
DB2Storage<GemPropertiesEntry>                  sGemPropertiesStore("GemProperties.db2", &GemPropertiesLoadInfo::Instance);
DB2Storage<GlobalCurveEntry>                    sGlobalCurveStore("GlobalCurve.db2", &GlobalCurveLoadInfo::Instance);
DB2Storage<GlyphBindableSpellEntry>             sGlyphBindableSpellStore("GlyphBindableSpell.db2", &GlyphBindableSpellLoadInfo::Instance);
DB2Storage<GlyphPropertiesEntry>                sGlyphPropertiesStore("GlyphProperties.db2", &GlyphPropertiesLoadInfo::Instance);
DB2Storage<GlyphRequiredSpecEntry>              sGlyphRequiredSpecStore("GlyphRequiredSpec.db2", &GlyphRequiredSpecLoadInfo::Instance);
DB2Storage<GossipNPCOptionEntry>                sGossipNPCOptionStore("GossipNPCOption.db2", &GossipNpcOptionLoadInfo::Instance);
DB2Storage<GuildColorBackgroundEntry>           sGuildColorBackgroundStore("GuildColorBackground.db2", &GuildColorBackgroundLoadInfo::Instance);
DB2Storage<GuildColorBorderEntry>               sGuildColorBorderStore("GuildColorBorder.db2", &GuildColorBorderLoadInfo::Instance);
DB2Storage<GuildColorEmblemEntry>               sGuildColorEmblemStore("GuildColorEmblem.db2", &GuildColorEmblemLoadInfo::Instance);
DB2Storage<GuildPerkSpellsEntry>                sGuildPerkSpellsStore("GuildPerkSpells.db2", &GuildPerkSpellsLoadInfo::Instance);
DB2Storage<HeirloomEntry>                       sHeirloomStore("Heirloom.db2", &HeirloomLoadInfo::Instance);
DB2Storage<HolidaysEntry>                       sHolidaysStore("Holidays.db2", &HolidaysLoadInfo::Instance);
DB2Storage<ImportPriceArmorEntry>               sImportPriceArmorStore("ImportPriceArmor.db2", &ImportPriceArmorLoadInfo::Instance);
DB2Storage<ImportPriceQualityEntry>             sImportPriceQualityStore("ImportPriceQuality.db2", &ImportPriceQualityLoadInfo::Instance);
DB2Storage<ImportPriceShieldEntry>              sImportPriceShieldStore("ImportPriceShield.db2", &ImportPriceShieldLoadInfo::Instance);
DB2Storage<ImportPriceWeaponEntry>              sImportPriceWeaponStore("ImportPriceWeapon.db2", &ImportPriceWeaponLoadInfo::Instance);
DB2Storage<ItemAppearanceEntry>                 sItemAppearanceStore("ItemAppearance.db2", &ItemAppearanceLoadInfo::Instance);
DB2Storage<ItemArmorQualityEntry>               sItemArmorQualityStore("ItemArmorQuality.db2", &ItemArmorQualityLoadInfo::Instance);
DB2Storage<ItemArmorShieldEntry>                sItemArmorShieldStore("ItemArmorShield.db2", &ItemArmorShieldLoadInfo::Instance);
DB2Storage<ItemArmorTotalEntry>                 sItemArmorTotalStore("ItemArmorTotal.db2", &ItemArmorTotalLoadInfo::Instance);
DB2Storage<ItemBagFamilyEntry>                  sItemBagFamilyStore("ItemBagFamily.db2", &ItemBagFamilyLoadInfo::Instance);
DB2Storage<ItemBonusEntry>                      sItemBonusStore("ItemBonus.db2", &ItemBonusLoadInfo::Instance);
DB2Storage<ItemBonusListGroupEntryEntry>        sItemBonusListGroupEntryStore("ItemBonusListGroupEntry.db2", &ItemBonusListGroupEntryLoadInfo::Instance);
DB2Storage<ItemBonusListLevelDeltaEntry>        sItemBonusListLevelDeltaStore("ItemBonusListLevelDelta.db2", &ItemBonusListLevelDeltaLoadInfo::Instance);
DB2Storage<ItemBonusTreeEntry>                  sItemBonusTreeStore("ItemBonusTree.db2", &ItemBonusTreeLoadInfo::Instance);
DB2Storage<ItemBonusTreeNodeEntry>              sItemBonusTreeNodeStore("ItemBonusTreeNode.db2", &ItemBonusTreeNodeLoadInfo::Instance);
DB2Storage<ItemChildEquipmentEntry>             sItemChildEquipmentStore("ItemChildEquipment.db2", &ItemChildEquipmentLoadInfo::Instance);
DB2Storage<ItemClassEntry>                      sItemClassStore("ItemClass.db2", &ItemClassLoadInfo::Instance);
DB2Storage<ItemContextPickerEntryEntry>         sItemContextPickerEntryStore("ItemContextPickerEntry.db2", &ItemContextPickerEntryLoadInfo::Instance);
DB2Storage<ItemCurrencyCostEntry>               sItemCurrencyCostStore("ItemCurrencyCost.db2", &ItemCurrencyCostLoadInfo::Instance);
DB2Storage<ItemDamageAmmoEntry>                 sItemDamageAmmoStore("ItemDamageAmmo.db2", &ItemDamageAmmoLoadInfo::Instance);
DB2Storage<ItemDamageOneHandEntry>              sItemDamageOneHandStore("ItemDamageOneHand.db2", &ItemDamageOneHandLoadInfo::Instance);
DB2Storage<ItemDamageOneHandCasterEntry>        sItemDamageOneHandCasterStore("ItemDamageOneHandCaster.db2", &ItemDamageOneHandCasterLoadInfo::Instance);
DB2Storage<ItemDamageTwoHandEntry>              sItemDamageTwoHandStore("ItemDamageTwoHand.db2", &ItemDamageTwoHandLoadInfo::Instance);
DB2Storage<ItemDamageTwoHandCasterEntry>        sItemDamageTwoHandCasterStore("ItemDamageTwoHandCaster.db2", &ItemDamageTwoHandCasterLoadInfo::Instance);
DB2Storage<ItemDisenchantLootEntry>             sItemDisenchantLootStore("ItemDisenchantLoot.db2", &ItemDisenchantLootLoadInfo::Instance);
DB2Storage<ItemEffectEntry>                     sItemEffectStore("ItemEffect.db2", &ItemEffectLoadInfo::Instance);
DB2Storage<ItemEntry>                           sItemStore("Item.db2", &ItemLoadInfo::Instance);
DB2Storage<ItemExtendedCostEntry>               sItemExtendedCostStore("ItemExtendedCost.db2", &ItemExtendedCostLoadInfo::Instance);
DB2Storage<ItemLevelSelectorEntry>              sItemLevelSelectorStore("ItemLevelSelector.db2", &ItemLevelSelectorLoadInfo::Instance);
DB2Storage<ItemLevelSelectorQualityEntry>       sItemLevelSelectorQualityStore("ItemLevelSelectorQuality.db2", &ItemLevelSelectorQualityLoadInfo::Instance);
DB2Storage<ItemLevelSelectorQualitySetEntry>    sItemLevelSelectorQualitySetStore("ItemLevelSelectorQualitySet.db2", &ItemLevelSelectorQualitySetLoadInfo::Instance);
DB2Storage<ItemLimitCategoryEntry>              sItemLimitCategoryStore("ItemLimitCategory.db2", &ItemLimitCategoryLoadInfo::Instance);
DB2Storage<ItemLimitCategoryConditionEntry>     sItemLimitCategoryConditionStore("ItemLimitCategoryCondition.db2", &ItemLimitCategoryConditionLoadInfo::Instance);
DB2Storage<ItemModifiedAppearanceEntry>         sItemModifiedAppearanceStore("ItemModifiedAppearance.db2", &ItemModifiedAppearanceLoadInfo::Instance);
DB2Storage<ItemModifiedAppearanceExtraEntry>    sItemModifiedAppearanceExtraStore("ItemModifiedAppearanceExtra.db2", &ItemModifiedAppearanceExtraLoadInfo::Instance);
DB2Storage<ItemNameDescriptionEntry>            sItemNameDescriptionStore("ItemNameDescription.db2", &ItemNameDescriptionLoadInfo::Instance);
DB2Storage<ItemPriceBaseEntry>                  sItemPriceBaseStore("ItemPriceBase.db2", &ItemPriceBaseLoadInfo::Instance);
DB2Storage<ItemSearchNameEntry>                 sItemSearchNameStore("ItemSearchName.db2", &ItemSearchNameLoadInfo::Instance);
DB2Storage<ItemSetEntry>                        sItemSetStore("ItemSet.db2", &ItemSetLoadInfo::Instance);
DB2Storage<ItemSetSpellEntry>                   sItemSetSpellStore("ItemSetSpell.db2", &ItemSetSpellLoadInfo::Instance);
DB2Storage<ItemSparseEntry>                     sItemSparseStore("ItemSparse.db2", &ItemSparseLoadInfo::Instance);
DB2Storage<ItemSpecEntry>                       sItemSpecStore("ItemSpec.db2", &ItemSpecLoadInfo::Instance);
DB2Storage<ItemSpecOverrideEntry>               sItemSpecOverrideStore("ItemSpecOverride.db2", &ItemSpecOverrideLoadInfo::Instance);
DB2Storage<ItemXBonusTreeEntry>                 sItemXBonusTreeStore("ItemXBonusTree.db2", &ItemXBonusTreeLoadInfo::Instance);
DB2Storage<ItemXItemEffectEntry>                sItemXItemEffectStore("ItemXItemEffect.db2", &ItemXItemEffectLoadInfo::Instance);
DB2Storage<JournalEncounterEntry>               sJournalEncounterStore("JournalEncounter.db2", &JournalEncounterLoadInfo::Instance);
DB2Storage<JournalEncounterSectionEntry>        sJournalEncounterSectionStore("JournalEncounterSection.db2", &JournalEncounterSectionLoadInfo::Instance);
DB2Storage<JournalInstanceEntry>                sJournalInstanceStore("JournalInstance.db2", &JournalInstanceLoadInfo::Instance);
DB2Storage<JournalTierEntry>                    sJournalTierStore("JournalTier.db2", &JournalTierLoadInfo::Instance);
DB2Storage<KeychainEntry>                       sKeychainStore("Keychain.db2", &KeychainLoadInfo::Instance);
DB2Storage<KeystoneAffixEntry>                  sKeystoneAffixStore("KeystoneAffix.db2", &KeystoneAffixLoadInfo::Instance);
DB2Storage<LanguageWordsEntry>                  sLanguageWordsStore("LanguageWords.db2", &LanguageWordsLoadInfo::Instance);
DB2Storage<LanguagesEntry>                      sLanguagesStore("Languages.db2", &LanguagesLoadInfo::Instance);
DB2Storage<LFGDungeonsEntry>                    sLFGDungeonsStore("LFGDungeons.db2", &LfgDungeonsLoadInfo::Instance);
DB2Storage<LightEntry>                          sLightStore("Light.db2", &LightLoadInfo::Instance);
DB2Storage<LiquidTypeEntry>                     sLiquidTypeStore("LiquidType.db2", &LiquidTypeLoadInfo::Instance);
DB2Storage<LocationEntry>                       sLocationStore("Location.db2", &LocationLoadInfo::Instance);
DB2Storage<LockEntry>                           sLockStore("Lock.db2", &LockLoadInfo::Instance);
DB2Storage<MailTemplateEntry>                   sMailTemplateStore("MailTemplate.db2", &MailTemplateLoadInfo::Instance);
DB2Storage<MapEntry>                            sMapStore("Map.db2", &MapLoadInfo::Instance);
DB2Storage<MapChallengeModeEntry>               sMapChallengeModeStore("MapChallengeMode.db2", &MapChallengeModeLoadInfo::Instance);
DB2Storage<MapDifficultyEntry>                  sMapDifficultyStore("MapDifficulty.db2", &MapDifficultyLoadInfo::Instance);
DB2Storage<MapDifficultyXConditionEntry>        sMapDifficultyXConditionStore("MapDifficultyXCondition.db2", &MapDifficultyXConditionLoadInfo::Instance);
DB2Storage<MawPowerEntry>                       sMawPowerStore("MawPower.db2", &MawPowerLoadInfo::Instance);
DB2Storage<ModifierTreeEntry>                   sModifierTreeStore("ModifierTree.db2", &ModifierTreeLoadInfo::Instance);
DB2Storage<MountCapabilityEntry>                sMountCapabilityStore("MountCapability.db2", &MountCapabilityLoadInfo::Instance);
DB2Storage<MountEntry>                          sMountStore("Mount.db2", &MountLoadInfo::Instance);
DB2Storage<MountTypeXCapabilityEntry>           sMountTypeXCapabilityStore("MountTypeXCapability.db2", &MountTypeXCapabilityLoadInfo::Instance);
DB2Storage<MountXDisplayEntry>                  sMountXDisplayStore("MountXDisplay.db2", &MountXDisplayLoadInfo::Instance);
DB2Storage<MovieEntry>                          sMovieStore("Movie.db2", &MovieLoadInfo::Instance);
DB2Storage<MythicPlusSeasonEntry>               sMythicPlusSeasonStore("MythicPlusSeason.db2", &MythicPlusSeasonLoadInfo::Instance);
DB2Storage<NameGenEntry>                        sNameGenStore("NameGen.db2", &NameGenLoadInfo::Instance);
DB2Storage<NamesProfanityEntry>                 sNamesProfanityStore("NamesProfanity.db2", &NamesProfanityLoadInfo::Instance);
DB2Storage<NamesReservedEntry>                  sNamesReservedStore("NamesReserved.db2", &NamesReservedLoadInfo::Instance);
DB2Storage<NamesReservedLocaleEntry>            sNamesReservedLocaleStore("NamesReservedLocale.db2", &NamesReservedLocaleLoadInfo::Instance);
DB2Storage<NumTalentsAtLevelEntry>              sNumTalentsAtLevelStore("NumTalentsAtLevel.db2", &NumTalentsAtLevelLoadInfo::Instance);
DB2Storage<OverrideSpellDataEntry>              sOverrideSpellDataStore("OverrideSpellData.db2", &OverrideSpellDataLoadInfo::Instance);
DB2Storage<ParagonReputationEntry>              sParagonReputationStore("ParagonReputation.db2", &ParagonReputationLoadInfo::Instance);
DB2Storage<PathEntry>                           sPathStore("Path.db2", &PathLoadInfo::Instance);
DB2Storage<PathNodeEntry>                       sPathNodeStore("PathNode.db2", &PathNodeLoadInfo::Instance);
DB2Storage<PathPropertyEntry>                   sPathPropertyStore("PathProperty.db2", &PathPropertyLoadInfo::Instance);
DB2Storage<PhaseEntry>                          sPhaseStore("Phase.db2", &PhaseLoadInfo::Instance);
DB2Storage<PhaseXPhaseGroupEntry>               sPhaseXPhaseGroupStore("PhaseXPhaseGroup.db2", &PhaseXPhaseGroupLoadInfo::Instance);
DB2Storage<PlayerConditionEntry>                sPlayerConditionStore("PlayerCondition.db2", &PlayerConditionLoadInfo::Instance);
DB2Storage<PowerDisplayEntry>                   sPowerDisplayStore("PowerDisplay.db2", &PowerDisplayLoadInfo::Instance);
DB2Storage<PowerTypeEntry>                      sPowerTypeStore("PowerType.db2", &PowerTypeLoadInfo::Instance);
DB2Storage<PrestigeLevelInfoEntry>              sPrestigeLevelInfoStore("PrestigeLevelInfo.db2", &PrestigeLevelInfoLoadInfo::Instance);
DB2Storage<PVPDifficultyEntry>                  sPVPDifficultyStore("PVPDifficulty.db2", &PvpDifficultyLoadInfo::Instance);
DB2Storage<PVPItemEntry>                        sPVPItemStore("PVPItem.db2", &PvpItemLoadInfo::Instance);
DB2Storage<PVPStatEntry>                        sPVPStatStore("PVPStat.db2", &PvpStatLoadInfo::Instance);
DB2Storage<PvpSeasonEntry>                      sPvpSeasonStore("PvpSeason.db2", &PvpSeasonLoadInfo::Instance);
DB2Storage<PvpTalentEntry>                      sPvpTalentStore("PvpTalent.db2", &PvpTalentLoadInfo::Instance);
DB2Storage<PvpTalentCategoryEntry>              sPvpTalentCategoryStore("PvpTalentCategory.db2", &PvpTalentCategoryLoadInfo::Instance);
DB2Storage<PvpTalentSlotUnlockEntry>            sPvpTalentSlotUnlockStore("PvpTalentSlotUnlock.db2", &PvpTalentSlotUnlockLoadInfo::Instance);
DB2Storage<PvpTierEntry>                        sPvpTierStore("PvpTier.db2", &PvpTierLoadInfo::Instance);
DB2Storage<QuestFactionRewardEntry>             sQuestFactionRewardStore("QuestFactionReward.db2", &QuestFactionRewardLoadInfo::Instance);
DB2Storage<QuestInfoEntry>                      sQuestInfoStore("QuestInfo.db2", &QuestInfoLoadInfo::Instance);
DB2Storage<QuestLineXQuestEntry>                sQuestLineXQuestStore("QuestLineXQuest.db2", &QuestLineXQuestLoadInfo::Instance);
DB2Storage<QuestMoneyRewardEntry>               sQuestMoneyRewardStore("QuestMoneyReward.db2", &QuestMoneyRewardLoadInfo::Instance);
DB2Storage<QuestPackageItemEntry>               sQuestPackageItemStore("QuestPackageItem.db2", &QuestPackageItemLoadInfo::Instance);
DB2Storage<QuestSortEntry>                      sQuestSortStore("QuestSort.db2", &QuestSortLoadInfo::Instance);
DB2Storage<QuestV2Entry>                        sQuestV2Store("QuestV2.db2", &QuestV2LoadInfo::Instance);
DB2Storage<QuestXPEntry>                        sQuestXPStore("QuestXP.db2", &QuestXpLoadInfo::Instance);
DB2Storage<RandPropPointsEntry>                 sRandPropPointsStore("RandPropPoints.db2", &RandPropPointsLoadInfo::Instance);
DB2Storage<RewardPackEntry>                     sRewardPackStore("RewardPack.db2", &RewardPackLoadInfo::Instance);
DB2Storage<RewardPackXCurrencyTypeEntry>        sRewardPackXCurrencyTypeStore("RewardPackXCurrencyType.db2", &RewardPackXCurrencyTypeLoadInfo::Instance);
DB2Storage<RewardPackXItemEntry>                sRewardPackXItemStore("RewardPackXItem.db2", &RewardPackXItemLoadInfo::Instance);
DB2Storage<ScenarioEntry>                       sScenarioStore("Scenario.db2", &ScenarioLoadInfo::Instance);
DB2Storage<ScenarioStepEntry>                   sScenarioStepStore("ScenarioStep.db2", &ScenarioStepLoadInfo::Instance);
DB2Storage<SceneScriptEntry>                    sSceneScriptStore("SceneScript.db2", &SceneScriptLoadInfo::Instance);
DB2Storage<SceneScriptGlobalTextEntry>          sSceneScriptGlobalTextStore("SceneScriptGlobalText.db2", &SceneScriptGlobalTextLoadInfo::Instance);
DB2Storage<SceneScriptPackageEntry>             sSceneScriptPackageStore("SceneScriptPackage.db2", &SceneScriptPackageLoadInfo::Instance);
DB2Storage<SceneScriptTextEntry>                sSceneScriptTextStore("SceneScriptText.db2", &SceneScriptTextLoadInfo::Instance);
DB2Storage<ServerMessagesEntry>                 sServerMessagesStore("ServerMessages.db2", &ServerMessagesLoadInfo::Instance);
DB2Storage<SkillLineEntry>                      sSkillLineStore("SkillLine.db2", &SkillLineLoadInfo::Instance);
DB2Storage<SkillLineAbilityEntry>               sSkillLineAbilityStore("SkillLineAbility.db2", &SkillLineAbilityLoadInfo::Instance);
DB2Storage<SkillLineXTraitTreeEntry>            sSkillLineXTraitTreeStore("SkillLineXTraitTree.db2", &SkillLineXTraitTreeLoadInfo::Instance);
DB2Storage<SkillRaceClassInfoEntry>             sSkillRaceClassInfoStore("SkillRaceClassInfo.db2", &SkillRaceClassInfoLoadInfo::Instance);
DB2Storage<SoulbindConduitRankEntry>            sSoulbindConduitRankStore("SoulbindConduitRank.db2", &SoulbindConduitRankLoadInfo::Instance);
DB2Storage<SoundKitEntry>                       sSoundKitStore("SoundKit.db2", &SoundKitLoadInfo::Instance);
DB2Storage<SpecializationSpellsEntry>           sSpecializationSpellsStore("SpecializationSpells.db2", &SpecializationSpellsLoadInfo::Instance);
DB2Storage<SpecSetMemberEntry>                  sSpecSetMemberStore("SpecSetMember.db2", &SpecSetMemberLoadInfo::Instance);
DB2Storage<SpellAuraOptionsEntry>               sSpellAuraOptionsStore("SpellAuraOptions.db2", &SpellAuraOptionsLoadInfo::Instance);
DB2Storage<SpellAuraRestrictionsEntry>          sSpellAuraRestrictionsStore("SpellAuraRestrictions.db2", &SpellAuraRestrictionsLoadInfo::Instance);
DB2Storage<SpellCastTimesEntry>                 sSpellCastTimesStore("SpellCastTimes.db2", &SpellCastTimesLoadInfo::Instance);
DB2Storage<SpellCastingRequirementsEntry>       sSpellCastingRequirementsStore("SpellCastingRequirements.db2", &SpellCastingRequirementsLoadInfo::Instance);
DB2Storage<SpellCategoriesEntry>                sSpellCategoriesStore("SpellCategories.db2", &SpellCategoriesLoadInfo::Instance);
DB2Storage<SpellCategoryEntry>                  sSpellCategoryStore("SpellCategory.db2", &SpellCategoryLoadInfo::Instance);
DB2Storage<SpellClassOptionsEntry>              sSpellClassOptionsStore("SpellClassOptions.db2", &SpellClassOptionsLoadInfo::Instance);
DB2Storage<SpellCooldownsEntry>                 sSpellCooldownsStore("SpellCooldowns.db2", &SpellCooldownsLoadInfo::Instance);
DB2Storage<SpellDurationEntry>                  sSpellDurationStore("SpellDuration.db2", &SpellDurationLoadInfo::Instance);
DB2Storage<SpellEffectEntry>                    sSpellEffectStore("SpellEffect.db2", &SpellEffectLoadInfo::Instance);
DB2Storage<SpellEquippedItemsEntry>             sSpellEquippedItemsStore("SpellEquippedItems.db2", &SpellEquippedItemsLoadInfo::Instance);
DB2Storage<SpellEmpowerEntry>                   sSpellEmpowerStore("SpellEmpower.db2", &SpellEmpowerLoadInfo::Instance);
DB2Storage<SpellEmpowerStageEntry>              sSpellEmpowerStageStore("SpellEmpowerStage.db2", &SpellEmpowerStageLoadInfo::Instance);
DB2Storage<SpellFocusObjectEntry>               sSpellFocusObjectStore("SpellFocusObject.db2", &SpellFocusObjectLoadInfo::Instance);
DB2Storage<SpellInterruptsEntry>                sSpellInterruptsStore("SpellInterrupts.db2", &SpellInterruptsLoadInfo::Instance);
DB2Storage<SpellItemEnchantmentEntry>           sSpellItemEnchantmentStore("SpellItemEnchantment.db2", &SpellItemEnchantmentLoadInfo::Instance);
DB2Storage<SpellItemEnchantmentConditionEntry>  sSpellItemEnchantmentConditionStore("SpellItemEnchantmentCondition.db2", &SpellItemEnchantmentConditionLoadInfo::Instance);
DB2Storage<SpellKeyboundOverrideEntry>          sSpellKeyboundOverrideStore("SpellKeyboundOverride.db2", &SpellKeyboundOverrideLoadInfo::Instance);
DB2Storage<SpellLabelEntry>                     sSpellLabelStore("SpellLabel.db2", &SpellLabelLoadInfo::Instance);
DB2Storage<SpellLearnSpellEntry>                sSpellLearnSpellStore("SpellLearnSpell.db2", &SpellLearnSpellLoadInfo::Instance);
DB2Storage<SpellLevelsEntry>                    sSpellLevelsStore("SpellLevels.db2", &SpellLevelsLoadInfo::Instance);
DB2Storage<SpellMiscEntry>                      sSpellMiscStore("SpellMisc.db2", &SpellMiscLoadInfo::Instance);
DB2Storage<SpellNameEntry>                      sSpellNameStore("SpellName.db2", &SpellNameLoadInfo::Instance);
DB2Storage<SpellPowerEntry>                     sSpellPowerStore("SpellPower.db2", &SpellPowerLoadInfo::Instance);
DB2Storage<SpellPowerDifficultyEntry>           sSpellPowerDifficultyStore("SpellPowerDifficulty.db2", &SpellPowerDifficultyLoadInfo::Instance);
DB2Storage<SpellProcsPerMinuteEntry>            sSpellProcsPerMinuteStore("SpellProcsPerMinute.db2", &SpellProcsPerMinuteLoadInfo::Instance);
DB2Storage<SpellProcsPerMinuteModEntry>         sSpellProcsPerMinuteModStore("SpellProcsPerMinuteMod.db2", &SpellProcsPerMinuteModLoadInfo::Instance);
DB2Storage<SpellRadiusEntry>                    sSpellRadiusStore("SpellRadius.db2", &SpellRadiusLoadInfo::Instance);
DB2Storage<SpellRangeEntry>                     sSpellRangeStore("SpellRange.db2", &SpellRangeLoadInfo::Instance);
DB2Storage<SpellReagentsEntry>                  sSpellReagentsStore("SpellReagents.db2", &SpellReagentsLoadInfo::Instance);
DB2Storage<SpellReagentsCurrencyEntry>          sSpellReagentsCurrencyStore("SpellReagentsCurrency.db2", &SpellReagentsCurrencyLoadInfo::Instance);
DB2Storage<SpellScalingEntry>                   sSpellScalingStore("SpellScaling.db2", &SpellScalingLoadInfo::Instance);
DB2Storage<SpellShapeshiftEntry>                sSpellShapeshiftStore("SpellShapeshift.db2", &SpellShapeshiftLoadInfo::Instance);
DB2Storage<SpellShapeshiftFormEntry>            sSpellShapeshiftFormStore("SpellShapeshiftForm.db2", &SpellShapeshiftFormLoadInfo::Instance);
DB2Storage<SpellTargetRestrictionsEntry>        sSpellTargetRestrictionsStore("SpellTargetRestrictions.db2", &SpellTargetRestrictionsLoadInfo::Instance);
DB2Storage<SpellTotemsEntry>                    sSpellTotemsStore("SpellTotems.db2", &SpellTotemsLoadInfo::Instance);
DB2Storage<SpellVisualEntry>                    sSpellVisualStore("SpellVisual.db2", &SpellVisualLoadInfo::Instance);
DB2Storage<SpellVisualEffectNameEntry>          sSpellVisualEffectNameStore("SpellVisualEffectName.db2", &SpellVisualEffectNameLoadInfo::Instance);
DB2Storage<SpellVisualMissileEntry>             sSpellVisualMissileStore("SpellVisualMissile.db2", &SpellVisualMissileLoadInfo::Instance);
DB2Storage<SpellVisualKitEntry>                 sSpellVisualKitStore("SpellVisualKit.db2", &SpellVisualKitLoadInfo::Instance);
DB2Storage<SpellXSpellVisualEntry>              sSpellXSpellVisualStore("SpellXSpellVisual.db2", &SpellXSpellVisualLoadInfo::Instance);
DB2Storage<SummonPropertiesEntry>               sSummonPropertiesStore("SummonProperties.db2", &SummonPropertiesLoadInfo::Instance);
DB2Storage<TactKeyEntry>                        sTactKeyStore("TactKey.db2", &TactKeyLoadInfo::Instance);
DB2Storage<TalentEntry>                         sTalentStore("Talent.db2", &TalentLoadInfo::Instance);
DB2Storage<TaxiNodesEntry>                      sTaxiNodesStore("TaxiNodes.db2", &TaxiNodesLoadInfo::Instance);
DB2Storage<TaxiPathEntry>                       sTaxiPathStore("TaxiPath.db2", &TaxiPathLoadInfo::Instance);
DB2Storage<TaxiPathNodeEntry>                   sTaxiPathNodeStore("TaxiPathNode.db2", &TaxiPathNodeLoadInfo::Instance);
DB2Storage<TotemCategoryEntry>                  sTotemCategoryStore("TotemCategory.db2", &TotemCategoryLoadInfo::Instance);
DB2Storage<ToyEntry>                            sToyStore("Toy.db2", &ToyLoadInfo::Instance);
DB2Storage<TraitCondEntry>                      sTraitCondStore("TraitCond.db2", &TraitCondLoadInfo::Instance);
DB2Storage<TraitCostEntry>                      sTraitCostStore("TraitCost.db2", &TraitCostLoadInfo::Instance);
DB2Storage<TraitCurrencyEntry>                  sTraitCurrencyStore("TraitCurrency.db2", &TraitCurrencyLoadInfo::Instance);
DB2Storage<TraitCurrencySourceEntry>            sTraitCurrencySourceStore("TraitCurrencySource.db2", &TraitCurrencySourceLoadInfo::Instance);
DB2Storage<TraitDefinitionEntry>                sTraitDefinitionStore("TraitDefinition.db2", &TraitDefinitionLoadInfo::Instance);
DB2Storage<TraitDefinitionEffectPointsEntry>    sTraitDefinitionEffectPointsStore("TraitDefinitionEffectPoints.db2", &TraitDefinitionEffectPointsLoadInfo::Instance);
DB2Storage<TraitEdgeEntry>                      sTraitEdgeStore("TraitEdge.db2", &TraitEdgeLoadInfo::Instance);
DB2Storage<TraitNodeEntry>                      sTraitNodeStore("TraitNode.db2", &TraitNodeLoadInfo::Instance);
DB2Storage<TraitNodeEntryEntry>                 sTraitNodeEntryStore("TraitNodeEntry.db2", &TraitNodeEntryLoadInfo::Instance);
DB2Storage<TraitNodeEntryXTraitCondEntry>       sTraitNodeEntryXTraitCondStore("TraitNodeEntryXTraitCond.db2", &TraitNodeEntryXTraitCondLoadInfo::Instance);
DB2Storage<TraitNodeEntryXTraitCostEntry>       sTraitNodeEntryXTraitCostStore("TraitNodeEntryXTraitCost.db2", &TraitNodeEntryXTraitCostLoadInfo::Instance);
DB2Storage<TraitNodeGroupEntry>                 sTraitNodeGroupStore("TraitNodeGroup.db2", &TraitNodeGroupLoadInfo::Instance);
DB2Storage<TraitNodeGroupXTraitCondEntry>       sTraitNodeGroupXTraitCondStore("TraitNodeGroupXTraitCond.db2", &TraitNodeGroupXTraitCondLoadInfo::Instance);
DB2Storage<TraitNodeGroupXTraitCostEntry>       sTraitNodeGroupXTraitCostStore("TraitNodeGroupXTraitCost.db2", &TraitNodeGroupXTraitCostLoadInfo::Instance);
DB2Storage<TraitNodeGroupXTraitNodeEntry>       sTraitNodeGroupXTraitNodeStore("TraitNodeGroupXTraitNode.db2", &TraitNodeGroupXTraitNodeLoadInfo::Instance);
DB2Storage<TraitNodeXTraitCondEntry>            sTraitNodeXTraitCondStore("TraitNodeXTraitCond.db2", &TraitNodeXTraitCondLoadInfo::Instance);
DB2Storage<TraitNodeXTraitCostEntry>            sTraitNodeXTraitCostStore("TraitNodeXTraitCost.db2", &TraitNodeXTraitCostLoadInfo::Instance);
DB2Storage<TraitNodeXTraitNodeEntryEntry>       sTraitNodeXTraitNodeEntryStore("TraitNodeXTraitNodeEntry.db2", &TraitNodeXTraitNodeEntryLoadInfo::Instance);
DB2Storage<TraitSubTreeEntry>                   sTraitSubTreeStore("TraitSubTree.db2", &TraitSubTreeLoadInfo::Instance);
DB2Storage<TraitTreeEntry>                      sTraitTreeStore("TraitTree.db2", &TraitTreeLoadInfo::Instance);
DB2Storage<TraitTreeLoadoutEntry>               sTraitTreeLoadoutStore("TraitTreeLoadout.db2", &TraitTreeLoadoutLoadInfo::Instance);
DB2Storage<TraitTreeLoadoutEntryEntry>          sTraitTreeLoadoutEntryStore("TraitTreeLoadoutEntry.db2", &TraitTreeLoadoutEntryLoadInfo::Instance);
DB2Storage<TraitTreeXTraitCostEntry>            sTraitTreeXTraitCostStore("TraitTreeXTraitCost.db2", &TraitTreeXTraitCostLoadInfo::Instance);
DB2Storage<TraitTreeXTraitCurrencyEntry>        sTraitTreeXTraitCurrencyStore("TraitTreeXTraitCurrency.db2", &TraitTreeXTraitCurrencyLoadInfo::Instance);
DB2Storage<TransmogHolidayEntry>                sTransmogHolidayStore("TransmogHoliday.db2", &TransmogHolidayLoadInfo::Instance);
DB2Storage<TransmogIllusionEntry>               sTransmogIllusionStore("TransmogIllusion.db2", &TransmogIllusionLoadInfo::Instance);
DB2Storage<TransmogSetEntry>                    sTransmogSetStore("TransmogSet.db2", &TransmogSetLoadInfo::Instance);
DB2Storage<TransmogSetGroupEntry>               sTransmogSetGroupStore("TransmogSetGroup.db2", &TransmogSetGroupLoadInfo::Instance);
DB2Storage<TransmogSetItemEntry>                sTransmogSetItemStore("TransmogSetItem.db2", &TransmogSetItemLoadInfo::Instance);
DB2Storage<TransportAnimationEntry>             sTransportAnimationStore("TransportAnimation.db2", &TransportAnimationLoadInfo::Instance);
DB2Storage<TransportRotationEntry>              sTransportRotationStore("TransportRotation.db2", &TransportRotationLoadInfo::Instance);
DB2Storage<UiMapEntry>                          sUiMapStore("UiMap.db2", &UiMapLoadInfo::Instance);
DB2Storage<UiMapAssignmentEntry>                sUiMapAssignmentStore("UiMapAssignment.db2", &UiMapAssignmentLoadInfo::Instance);
DB2Storage<UiMapLinkEntry>                      sUiMapLinkStore("UiMapLink.db2", &UiMapLinkLoadInfo::Instance);
DB2Storage<UiMapXMapArtEntry>                   sUiMapXMapArtStore("UiMapXMapArt.db2", &UiMapXMapArtLoadInfo::Instance);
DB2Storage<UISplashScreenEntry>                 sUISplashScreenStore("UISplashScreen.db2", &UiSplashScreenLoadInfo::Instance);
DB2Storage<UnitConditionEntry>                  sUnitConditionStore("UnitCondition.db2", &UnitConditionLoadInfo::Instance);
DB2Storage<UnitPowerBarEntry>                   sUnitPowerBarStore("UnitPowerBar.db2", &UnitPowerBarLoadInfo::Instance);
DB2Storage<VehicleEntry>                        sVehicleStore("Vehicle.db2", &VehicleLoadInfo::Instance);
DB2Storage<VehicleSeatEntry>                    sVehicleSeatStore("VehicleSeat.db2", &VehicleSeatLoadInfo::Instance);
DB2Storage<VignetteEntry>                       sVignetteStore("Vignette.db2", &VignetteLoadInfo::Instance);
DB2Storage<WMOAreaTableEntry>                   sWMOAreaTableStore("WMOAreaTable.db2", &WmoAreaTableLoadInfo::Instance);
DB2Storage<WorldEffectEntry>                    sWorldEffectStore("WorldEffect.db2", &WorldEffectLoadInfo::Instance);
DB2Storage<WorldMapOverlayEntry>                sWorldMapOverlayStore("WorldMapOverlay.db2", &WorldMapOverlayLoadInfo::Instance);
DB2Storage<WorldStateExpressionEntry>           sWorldStateExpressionStore("WorldStateExpression.db2", &WorldStateExpressionLoadInfo::Instance);

TaxiMask                                        sTaxiNodesMask;
TaxiMask                                        sOldContinentsNodesMask;
TaxiMask                                        sHordeTaxiNodesMask;
TaxiMask                                        sAllianceTaxiNodesMask;
TaxiPathNodesByPath                             sTaxiPathNodesByPath;

DEFINE_DB2_SET_COMPARATOR(ChrClassesXPowerTypesEntry)

typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;
typedef std::unordered_map<uint32 /*areaGroupId*/, std::vector<uint32/*areaId*/>> AreaGroupMemberContainer;
typedef std::unordered_map<uint32, std::vector<ArtifactPowerEntry const*>> ArtifactPowersContainer;
typedef std::unordered_map<uint32, std::vector<uint32>> ArtifactPowerLinksContainer;
typedef std::unordered_map<std::pair<uint32, uint8>, ArtifactPowerRankEntry const*> ArtifactPowerRanksContainer;
typedef ChrSpecializationEntry const* ChrSpecializationByIndexContainer[MAX_CLASSES + 1][MAX_SPECIALIZATIONS];
typedef std::unordered_map<uint32 /*curveID*/, std::vector<DBCPosition2D>> CurvePointsContainer;
typedef std::map<std::tuple<uint32, uint8, uint8, uint8>, EmotesTextSoundEntry const*> EmotesTextSoundContainer;
typedef std::unordered_map<uint32, std::vector<uint32>> FactionTeamContainer;
typedef std::unordered_map<uint32, HeirloomEntry const*> HeirloomItemsContainer;
typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<uint32>> GlyphBindableSpellsContainer;
typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<ChrSpecialization>> GlyphRequiredSpecsContainer;
typedef std::unordered_map<uint32 /*itemId*/, ItemChildEquipmentEntry const*> ItemChildEquipmentContainer;
typedef std::array<ItemClassEntry const*, 20> ItemClassByOldEnumContainer;
typedef std::unordered_map<uint32, std::vector<ItemLimitCategoryConditionEntry const*>> ItemLimitCategoryConditionContainer;
typedef std::unordered_map<uint32 /*itemId | appearanceMod << 24*/, ItemModifiedAppearanceEntry const*> ItemModifiedAppearanceByItemContainer;
typedef std::unordered_map<uint32, std::vector<ItemSetSpellEntry const*>> ItemSetSpellContainer;
typedef std::unordered_map<uint32, std::vector<ItemSpecOverrideEntry const*>> ItemSpecOverridesContainer;
typedef std::unordered_map<uint32, std::unordered_map<uint32, MapDifficultyEntry const*>> MapDifficultyContainer;
typedef std::unordered_map<uint32, DB2Manager::MountTypeXCapabilitySet> MountCapabilitiesByTypeContainer;
typedef std::unordered_map<uint32, DB2Manager::MountXDisplayContainer> MountDisplaysCointainer;
typedef std::unordered_map<uint32, std::array<std::vector<NameGenEntry const*>, 2>> NameGenContainer;
typedef std::array<std::vector<Trinity::wregex>, TOTAL_LOCALES + 1> NameValidationRegexContainer;
typedef std::unordered_map<uint32, std::vector<uint32>> PhaseGroupContainer;
typedef std::array<PowerTypeEntry const*, MAX_POWERS> PowerTypesContainer;
typedef std::unordered_map<uint32, std::pair<std::vector<QuestPackageItemEntry const*>, std::vector<QuestPackageItemEntry const*>>> QuestPackageItemContainer;
typedef std::unordered_multimap<uint32, SkillRaceClassInfoEntry const*> SkillRaceClassInfoContainer;
typedef std::unordered_map<uint32, std::vector<SpecializationSpellsEntry const*>> SpecializationSpellsContainer;
typedef std::unordered_map<uint32, std::vector<SpellPowerEntry const*>> SpellPowerContainer;
typedef std::unordered_map<uint32, std::unordered_map<uint32, std::vector<SpellPowerEntry const*>>> SpellPowerDifficultyContainer;
typedef std::unordered_map<uint32, std::vector<SpellProcsPerMinuteModEntry const*>> SpellProcsPerMinuteModContainer;
typedef std::vector<TalentEntry const*> TalentsByPosition[MAX_CLASSES][MAX_TALENT_TIERS][MAX_TALENT_COLUMNS];
typedef std::unordered_set<uint32> ToyItemIdsContainer;
typedef std::tuple<uint16, uint8, int32> WMOAreaTableKey;
typedef std::map<WMOAreaTableKey, WMOAreaTableEntry const*> WMOAreaTableLookupContainer;
typedef std::pair<uint32 /*tableHash*/, int32 /*recordId*/> HotfixBlobKey;
typedef std::map<HotfixBlobKey, std::vector<uint8>> HotfixBlobMap;
using AllowedHotfixOptionalData = std::pair<uint32 /*optional data key*/, bool(*)(std::vector<uint8> const& data) /*validator*/>;

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
    DB2Manager::HotfixContainer _hotfixData;
    std::array<HotfixBlobMap, TOTAL_LOCALES> _hotfixBlob;
    std::unordered_multimap<uint32 /*tableHash*/, AllowedHotfixOptionalData> _allowedHotfixOptionalData;
    std::array<std::map<HotfixBlobKey, std::vector<DB2Manager::HotfixOptionalData>>, TOTAL_LOCALES> _hotfixOptionalData;

    AreaGroupMemberContainer _areaGroupMembers;
    ArtifactPowersContainer _artifactPowers;
    ArtifactPowerLinksContainer _artifactPowerLinks;
    ArtifactPowerRanksContainer _artifactPowerRanks;
    std::unordered_map<uint32 /*itemId*/, AzeriteEmpoweredItemEntry const*> _azeriteEmpoweredItems;
    std::unordered_map<std::pair<uint32 /*azeriteEssenceId*/, uint32 /*rank*/>, AzeriteEssencePowerEntry const*> _azeriteEssencePowersByIdAndRank;
    std::vector<AzeriteItemMilestonePowerEntry const*> _azeriteItemMilestonePowers;
    std::array<AzeriteItemMilestonePowerEntry const*, MAX_AZERITE_ESSENCE_SLOT> _azeriteItemMilestonePowerByEssenceSlot;
    std::unordered_map<uint32 /*azeritePowerSetId*/, std::vector<AzeritePowerSetMemberEntry const*>> _azeritePowers;
    std::unordered_map<std::pair<uint32 /*azeriteUnlockSetId*/, ItemContext>, std::array<uint8, MAX_AZERITE_EMPOWERED_TIER>> _azeriteTierUnlockLevels;
    std::unordered_map<std::pair<int32 /*broadcastTextId*/, CascLocaleBit /*cascLocaleBit*/>, int32> _broadcastTextDurations;
    std::unordered_map<std::pair<uint8, uint8>, CharBaseInfoEntry const*> _charBaseInfoByRaceAndClass;
    std::array<ChrClassUIDisplayEntry const*, MAX_CLASSES> _uiDisplayByClass;
    std::array<std::array<uint32, MAX_POWERS>, MAX_CLASSES> _powersByClass;
    std::unordered_map<uint32 /*chrCustomizationOptionId*/, std::vector<ChrCustomizationChoiceEntry const*>> _chrCustomizationChoicesByOption;
    std::unordered_map<std::pair<uint8, uint8>, ChrModelEntry const*> _chrModelsByRaceAndGender;
    std::map<std::tuple<uint8 /*race*/, uint8/*gender*/, uint8/*shapeshift*/>, ShapeshiftFormModelData> _chrCustomizationChoicesForShapeshifts;
    std::unordered_map<std::pair<uint8 /*race*/, uint8/*gender*/>, std::vector<ChrCustomizationOptionEntry const*>> _chrCustomizationOptionsByRaceAndGender;
    std::unordered_map<uint32 /*chrCustomizationReqId*/, std::vector<std::pair<uint32 /*chrCustomizationOptionId*/, std::vector<uint32>>>> _chrCustomizationRequiredChoices;
    ChrSpecializationByIndexContainer _chrSpecializationsByIndex;
    std::unordered_map<int32, ConditionalChrModelEntry const*> _conditionalChrModelsByChrModelId;
    std::unordered_map<uint32 /*contentTuningId*/, std::vector<ConditionalContentTuningEntry const*>> _conditionalContentTuning;
    std::unordered_set<std::pair<uint32, int32>> _contentTuningLabels;
    std::unordered_multimap<uint32, CurrencyContainerEntry const*> _currencyContainers;
    CurvePointsContainer _curvePoints;
    EmotesTextSoundContainer _emoteTextSounds;
    std::unordered_map<std::pair<uint32 /*level*/, int32 /*expansion*/>, ExpectedStatEntry const*> _expectedStatsByLevel;
    std::unordered_map<uint32 /*contentTuningId*/, std::vector<ContentTuningXExpectedEntry const*>> _expectedStatModsByContentTuning;
    FactionTeamContainer _factionTeams;
    std::unordered_map<uint32, std::set<FriendshipRepReactionEntry const*, DB2Manager::FriendshipRepReactionEntryComparator>> _friendshipRepReactions;
    HeirloomItemsContainer _heirlooms;
    GlyphBindableSpellsContainer _glyphBindableSpells;
    GlyphRequiredSpecsContainer _glyphRequiredSpecs;
    ItemChildEquipmentContainer _itemChildEquipment;
    ItemClassByOldEnumContainer _itemClassByOldEnum;
    std::unordered_set<uint32> _itemsWithCurrencyCost;
    ItemLimitCategoryConditionContainer _itemCategoryConditions;
    ItemModifiedAppearanceByItemContainer _itemModifiedAppearancesByItem;
    ItemSetSpellContainer _itemSetSpells;
    ItemSpecOverridesContainer _itemSpecOverrides;
    std::vector<JournalTierEntry const*> _journalTiersByIndex;
    MapDifficultyContainer _mapDifficulties;
    std::unordered_map<uint32, DB2Manager::MapDifficultyConditionsContainer> _mapDifficultyConditions;
    std::unordered_map<uint32, MountEntry const*> _mountsBySpellId;
    MountCapabilitiesByTypeContainer _mountCapabilitiesByType;
    MountDisplaysCointainer _mountDisplays;
    NameGenContainer _nameGenData;
    NameValidationRegexContainer _nameValidators;
    std::unordered_map<uint32, ParagonReputationEntry const*> _paragonReputations;
    std::unordered_map<uint32 /*pathID*/, PathDb2> _paths;
    PhaseGroupContainer _phasesByGroup;
    PowerTypesContainer _powerTypes;
    std::unordered_map<uint32, uint8> _pvpItemBonus;
    PvpTalentSlotUnlockEntry const* _pvpTalentSlotUnlock[MAX_PVP_TALENT_SLOTS];
    std::unordered_map<uint32, std::vector<QuestLineXQuestEntry const*>> _questsByQuestLine;
    QuestPackageItemContainer _questPackages;
    std::unordered_map<uint32, std::vector<RewardPackXCurrencyTypeEntry const*>> _rewardPackCurrencyTypes;
    std::unordered_map<uint32, std::vector<RewardPackXItemEntry const*>> _rewardPackItems;
    std::unordered_map<uint32, std::vector<SkillLineEntry const*>> _skillLinesByParentSkillLine;
    std::unordered_map<uint32, std::vector<SkillLineAbilityEntry const*>> _skillLineAbilitiesBySkillupSkill;
    SkillRaceClassInfoContainer _skillRaceClassInfoBySkill;
    std::unordered_map<std::pair<int32, int32>, SoulbindConduitRankEntry const*> _soulbindConduitRanks;
    SpecializationSpellsContainer _specializationSpellsBySpec;
    std::unordered_set<std::pair<int32, uint32>> _specsBySpecSet;
    std::unordered_set<uint8> _spellFamilyNames;
    SpellProcsPerMinuteModContainer _spellProcsPerMinuteMods;
    std::unordered_map<int32, std::vector<SpellVisualMissileEntry const*>> _spellVisualMissilesBySet;
    TalentsByPosition _talentsByPosition;
    std::unordered_map<std::pair<uint32, uint32>, TaxiPathEntry const*> _taxiPaths;
    ToyItemIdsContainer _toys;
    std::unordered_map<uint32, TransmogIllusionEntry const*> _transmogIllusionsByEnchantmentId;
    std::unordered_map<uint32, std::vector<TransmogSetEntry const*>> _transmogSetsByItemModifiedAppearance;
    std::unordered_map<uint32, std::vector<TransmogSetItemEntry const*>> _transmogSetItemsByTransmogSet;
    std::unordered_map<int32, UiMapBounds> _uiMapBounds;
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByMap[MAX_UI_MAP_SYSTEM];
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByArea[MAX_UI_MAP_SYSTEM];
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByWmoDoodadPlacement[MAX_UI_MAP_SYSTEM];
    std::unordered_multimap<int32, UiMapAssignmentEntry const*> _uiMapAssignmentByWmoGroup[MAX_UI_MAP_SYSTEM];
    std::unordered_set<int32> _uiMapPhases;
    WMOAreaTableLookupContainer _wmoAreaTableLookup;
    std::unordered_map<uint32, std::unordered_set<uint32>> _pvpStatIdsByMap;
}

void LoadDB2(std::bitset<TOTAL_LOCALES>& availableDb2Locales, std::vector<std::string>& errlist, StorageMap& stores, DB2StorageBase* storage, std::string const& db2Path,
    LocaleConstant defaultLocale, std::size_t cppRecordSize)
{
    // validate structure
    {
        DB2LoadInfo const* loadInfo = storage->GetLoadInfo();
        std::string clientMetaString, ourMetaString;
        for (std::size_t i = 0; i < loadInfo->Meta->FieldCount; ++i)
        {
            for (std::size_t j = 0; j < loadInfo->Meta->Fields[i].ArraySize; ++j)
            {
                if (i >= loadInfo->Meta->FileFieldCount && int32(i) == loadInfo->Meta->ParentIndexField)
                {
                    clientMetaString += char(FT_INT);
                    continue;
                }

                clientMetaString += char(loadInfo->Meta->Fields[i].Type);
            }
        }

        for (std::size_t i = loadInfo->Meta->HasIndexFieldInData() ? 0 : 1; i < loadInfo->FieldCount; ++i)
            ourMetaString += char(loadInfo->Fields[i].Type);

        ASSERT(clientMetaString == ourMetaString,
            "%s C++ structure fields %s do not match generated types from the client %s",
            storage->GetFileName().c_str(), ourMetaString.c_str(), clientMetaString.c_str());

        // compatibility format and C++ structure sizes
        ASSERT(loadInfo->Meta->GetRecordSize() == cppRecordSize,
            "Size of '%s' set by format string (%u) not equal size of C++ structure (" SZFMTD ").",
            storage->GetFileName().c_str(), loadInfo->Meta->GetRecordSize(), cppRecordSize);
    }

    try
    {
        storage->Load(db2Path + localeNames[defaultLocale] + '/', defaultLocale);
    }
    catch (std::system_error const& e)
    {
        if (e.code() == std::errc::no_such_file_or_directory)
        {
            errlist.push_back(Trinity::StringFormat("File {}{}/{} does not exist", db2Path, localeNames[defaultLocale], storage->GetFileName()));
        }
        else
            throw;
    }
    catch (std::exception const& e)
    {
        errlist.emplace_back(e.what());
        return;
    }

    // load additional data and enUS strings from db
    storage->LoadFromDB();

    for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
    {
        if (defaultLocale == i || !availableDb2Locales[i])
            continue;

        try
        {
            storage->LoadStringsFrom((db2Path + localeNames[i] + '/'), i);
        }
        catch (std::system_error const& e)
        {
            if (e.code() != std::errc::no_such_file_or_directory)
                throw;

            // locale db2 files are optional, do not error if nothing is found
        }
        catch (std::exception const& e)
        {
            errlist.emplace_back(e.what());
        }
    }

    for (LocaleConstant i = LOCALE_koKR; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
        if (availableDb2Locales[i])
            storage->LoadStringsFromDB(i);

    stores[storage->GetTableHash()] = storage;
}

DB2Manager& DB2Manager::Instance()
{
    static DB2Manager instance;
    return instance;
}

uint32 DB2Manager::LoadStores(std::string const& dataPath, LocaleConstant defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string db2Path = dataPath + "dbc/";

    std::vector<std::string> loadErrors;
    std::bitset<TOTAL_LOCALES> availableDb2Locales = [&]()
    {
        std::bitset<TOTAL_LOCALES> foundLocales;
        boost::filesystem::directory_iterator db2PathItr(db2Path), end;
        while (db2PathItr != end)
        {
            LocaleConstant locale = GetLocaleByName(db2PathItr->path().filename().string());
            if (IsValidLocale(locale) && (sWorld->getBoolConfig(CONFIG_LOAD_LOCALES) || locale == defaultLocale))
                foundLocales[locale] = true;

            ++db2PathItr;
        }
        return foundLocales;
    }();

    if (!availableDb2Locales[defaultLocale])
        return 0;

    auto LOAD_DB2 = [&]<typename T>(DB2Storage<T>& store)
    {
        LoadDB2(availableDb2Locales, loadErrors, _stores, &store, db2Path, defaultLocale, sizeof(T));
    };

    LOAD_DB2(sAchievementStore);
    LOAD_DB2(sAchievementCategoryStore);
    LOAD_DB2(sAdventureJournalStore);
    LOAD_DB2(sAdventureMapPOIStore);
    LOAD_DB2(sAnimationDataStore);
    LOAD_DB2(sAnimKitStore);
    LOAD_DB2(sAreaGroupMemberStore);
    LOAD_DB2(sAreaTableStore);
    LOAD_DB2(sAreaTriggerStore);
    LOAD_DB2(sAreaTriggerActionSetStore);
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
    LOAD_DB2(sAzeriteEmpoweredItemStore);
    LOAD_DB2(sAzeriteEssenceStore);
    LOAD_DB2(sAzeriteEssencePowerStore);
    LOAD_DB2(sAzeriteItemStore);
    LOAD_DB2(sAzeriteItemMilestonePowerStore);
    LOAD_DB2(sAzeriteKnowledgeMultiplierStore);
    LOAD_DB2(sAzeriteLevelInfoStore);
    LOAD_DB2(sAzeritePowerStore);
    LOAD_DB2(sAzeritePowerSetMemberStore);
    LOAD_DB2(sAzeriteTierUnlockStore);
    LOAD_DB2(sAzeriteTierUnlockSetStore);
    LOAD_DB2(sAzeriteUnlockMappingStore);
    LOAD_DB2(sBankBagSlotPricesStore);
    LOAD_DB2(sBannedAddonsStore);
    LOAD_DB2(sBarberShopStyleStore);
    LOAD_DB2(sBattlePetAbilityStore);
    LOAD_DB2(sBattlePetBreedQualityStore);
    LOAD_DB2(sBattlePetBreedStateStore);
    LOAD_DB2(sBattlePetSpeciesStore);
    LOAD_DB2(sBattlePetSpeciesStateStore);
    LOAD_DB2(sBattlemasterListStore);
    LOAD_DB2(sBattlemasterListXMapStore);
    LOAD_DB2(sBroadcastTextStore);
    LOAD_DB2(sBroadcastTextDurationStore);
    LOAD_DB2(sCfgCategoriesStore);
    LOAD_DB2(sCfgRegionsStore);
    LOAD_DB2(sChallengeModeItemBonusOverrideStore);
    LOAD_DB2(sCharBaseInfoStore);
    LOAD_DB2(sCharTitlesStore);
    LOAD_DB2(sCharacterLoadoutStore);
    LOAD_DB2(sCharacterLoadoutItemStore);
    LOAD_DB2(sChatChannelsStore);
    LOAD_DB2(sChrClassUIDisplayStore);
    LOAD_DB2(sChrClassesStore);
    LOAD_DB2(sChrClassesXPowerTypesStore);
    LOAD_DB2(sChrCustomizationChoiceStore);
    LOAD_DB2(sChrCustomizationDisplayInfoStore);
    LOAD_DB2(sChrCustomizationElementStore);
    LOAD_DB2(sChrCustomizationOptionStore);
    LOAD_DB2(sChrCustomizationReqStore);
    LOAD_DB2(sChrCustomizationReqChoiceStore);
    LOAD_DB2(sChrModelStore);
    LOAD_DB2(sChrRaceXChrModelStore);
    LOAD_DB2(sChrRacesStore);
    LOAD_DB2(sChrSpecializationStore);
    LOAD_DB2(sCinematicCameraStore);
    LOAD_DB2(sCinematicSequencesStore);
    LOAD_DB2(sConditionalChrModelStore);
    LOAD_DB2(sConditionalContentTuningStore);
    LOAD_DB2(sContentTuningStore);
    LOAD_DB2(sContentTuningXExpectedStore);
    LOAD_DB2(sContentTuningXLabelStore);
    LOAD_DB2(sConversationLineStore);
    LOAD_DB2(sCorruptionEffectsStore);
    LOAD_DB2(sCreatureDisplayInfoStore);
    LOAD_DB2(sCreatureDisplayInfoExtraStore);
    LOAD_DB2(sCreatureFamilyStore);
    LOAD_DB2(sCreatureModelDataStore);
    LOAD_DB2(sCreatureTypeStore);
    LOAD_DB2(sCriteriaStore);
    LOAD_DB2(sCriteriaTreeStore);
    LOAD_DB2(sCurrencyContainerStore);
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
    LOAD_DB2(sFriendshipRepReactionStore);
    LOAD_DB2(sFriendshipReputationStore);
    LOAD_DB2(sGameObjectsStore);
    LOAD_DB2(sGameObjectArtKitStore);
    LOAD_DB2(sGameObjectDisplayInfoStore);
    LOAD_DB2(sGarrAbilityStore);
    LOAD_DB2(sGarrBuildingStore);
    LOAD_DB2(sGarrBuildingPlotInstStore);
    LOAD_DB2(sGarrClassSpecStore);
    LOAD_DB2(sGarrFollowerStore);
    LOAD_DB2(sGarrFollowerXAbilityStore);
    LOAD_DB2(sGarrMissionStore);
    LOAD_DB2(sGarrPlotStore);
    LOAD_DB2(sGarrPlotBuildingStore);
    LOAD_DB2(sGarrPlotInstanceStore);
    LOAD_DB2(sGarrSiteLevelStore);
    LOAD_DB2(sGarrSiteLevelPlotInstStore);
    LOAD_DB2(sGarrTalentTreeStore);
    LOAD_DB2(sGemPropertiesStore);
    LOAD_DB2(sGlobalCurveStore);
    LOAD_DB2(sGlyphBindableSpellStore);
    LOAD_DB2(sGlyphPropertiesStore);
    LOAD_DB2(sGlyphRequiredSpecStore);
    LOAD_DB2(sGossipNPCOptionStore);
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
    LOAD_DB2(sItemBonusListGroupEntryStore);
    LOAD_DB2(sItemBonusListLevelDeltaStore);
    LOAD_DB2(sItemBonusTreeStore);
    LOAD_DB2(sItemBonusTreeNodeStore);
    LOAD_DB2(sItemChildEquipmentStore);
    LOAD_DB2(sItemClassStore);
    LOAD_DB2(sItemContextPickerEntryStore);
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
    LOAD_DB2(sItemModifiedAppearanceExtraStore);
    LOAD_DB2(sItemNameDescriptionStore);
    LOAD_DB2(sItemPriceBaseStore);
    LOAD_DB2(sItemSearchNameStore);
    LOAD_DB2(sItemSetStore);
    LOAD_DB2(sItemSetSpellStore);
    LOAD_DB2(sItemSparseStore);
    LOAD_DB2(sItemSpecStore);
    LOAD_DB2(sItemSpecOverrideStore);
    LOAD_DB2(sItemXBonusTreeStore);
    LOAD_DB2(sItemXItemEffectStore);
    LOAD_DB2(sJournalEncounterStore);
    LOAD_DB2(sJournalEncounterSectionStore);
    LOAD_DB2(sJournalInstanceStore);
    LOAD_DB2(sJournalTierStore);
    LOAD_DB2(sKeychainStore);
    LOAD_DB2(sKeystoneAffixStore);
    LOAD_DB2(sLanguageWordsStore);
    LOAD_DB2(sLanguagesStore);
    LOAD_DB2(sLFGDungeonsStore);
    LOAD_DB2(sLightStore);
    LOAD_DB2(sLiquidTypeStore);
    LOAD_DB2(sLocationStore);
    LOAD_DB2(sLockStore);
    LOAD_DB2(sMailTemplateStore);
    LOAD_DB2(sMapStore);
    LOAD_DB2(sMapChallengeModeStore);
    LOAD_DB2(sMapDifficultyStore);
    LOAD_DB2(sMapDifficultyXConditionStore);
    LOAD_DB2(sMawPowerStore);
    LOAD_DB2(sModifierTreeStore);
    LOAD_DB2(sMountCapabilityStore);
    LOAD_DB2(sMountStore);
    LOAD_DB2(sMountTypeXCapabilityStore);
    LOAD_DB2(sMountXDisplayStore);
    LOAD_DB2(sMovieStore);
    LOAD_DB2(sMythicPlusSeasonStore);
    LOAD_DB2(sNameGenStore);
    LOAD_DB2(sNamesProfanityStore);
    LOAD_DB2(sNamesReservedStore);
    LOAD_DB2(sNamesReservedLocaleStore);
    LOAD_DB2(sNumTalentsAtLevelStore);
    LOAD_DB2(sOverrideSpellDataStore);
    LOAD_DB2(sParagonReputationStore);
    LOAD_DB2(sPathStore);
    LOAD_DB2(sPathNodeStore);
    LOAD_DB2(sPathPropertyStore);
    LOAD_DB2(sPhaseStore);
    LOAD_DB2(sPhaseXPhaseGroupStore);
    LOAD_DB2(sPlayerConditionStore);
    LOAD_DB2(sPowerDisplayStore);
    LOAD_DB2(sPowerTypeStore);
    LOAD_DB2(sPrestigeLevelInfoStore);
    LOAD_DB2(sPVPDifficultyStore);
    LOAD_DB2(sPVPItemStore);
    LOAD_DB2(sPVPStatStore);
    LOAD_DB2(sPvpSeasonStore);
    LOAD_DB2(sPvpTalentStore);
    LOAD_DB2(sPvpTalentCategoryStore);
    LOAD_DB2(sPvpTalentSlotUnlockStore);
    LOAD_DB2(sPvpTierStore);
    LOAD_DB2(sQuestFactionRewardStore);
    LOAD_DB2(sQuestInfoStore);
    LOAD_DB2(sQuestLineXQuestStore);
    LOAD_DB2(sQuestMoneyRewardStore);
    LOAD_DB2(sQuestPackageItemStore);
    LOAD_DB2(sQuestSortStore);
    LOAD_DB2(sQuestV2Store);
    LOAD_DB2(sQuestXPStore);
    LOAD_DB2(sRandPropPointsStore);
    LOAD_DB2(sRewardPackStore);
    LOAD_DB2(sRewardPackXCurrencyTypeStore);
    LOAD_DB2(sRewardPackXItemStore);
    LOAD_DB2(sScenarioStore);
    LOAD_DB2(sScenarioStepStore);
    LOAD_DB2(sSceneScriptStore);
    LOAD_DB2(sSceneScriptGlobalTextStore);
    LOAD_DB2(sSceneScriptPackageStore);
    LOAD_DB2(sSceneScriptTextStore);
    LOAD_DB2(sServerMessagesStore);
    LOAD_DB2(sSkillLineStore);
    LOAD_DB2(sSkillLineAbilityStore);
    LOAD_DB2(sSkillLineXTraitTreeStore);
    LOAD_DB2(sSkillRaceClassInfoStore);
    LOAD_DB2(sSoulbindConduitRankStore);
    LOAD_DB2(sSoundKitStore);
    LOAD_DB2(sSpecializationSpellsStore);
    LOAD_DB2(sSpecSetMemberStore);
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
    LOAD_DB2(sSpellEmpowerStore);
    LOAD_DB2(sSpellEmpowerStageStore);
    LOAD_DB2(sSpellFocusObjectStore);
    LOAD_DB2(sSpellInterruptsStore);
    LOAD_DB2(sSpellItemEnchantmentStore);
    LOAD_DB2(sSpellItemEnchantmentConditionStore);
    LOAD_DB2(sSpellKeyboundOverrideStore);
    LOAD_DB2(sSpellLabelStore);
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
    LOAD_DB2(sSpellReagentsCurrencyStore);
    LOAD_DB2(sSpellScalingStore);
    LOAD_DB2(sSpellShapeshiftStore);
    LOAD_DB2(sSpellShapeshiftFormStore);
    LOAD_DB2(sSpellTargetRestrictionsStore);
    LOAD_DB2(sSpellTotemsStore);
    LOAD_DB2(sSpellVisualStore);
    LOAD_DB2(sSpellVisualEffectNameStore);
    LOAD_DB2(sSpellVisualMissileStore);
    LOAD_DB2(sSpellVisualKitStore);
    LOAD_DB2(sSpellXSpellVisualStore);
    LOAD_DB2(sSummonPropertiesStore);
    LOAD_DB2(sTactKeyStore);
    LOAD_DB2(sTalentStore);
    LOAD_DB2(sTaxiNodesStore);
    LOAD_DB2(sTaxiPathStore);
    LOAD_DB2(sTaxiPathNodeStore);
    LOAD_DB2(sTotemCategoryStore);
    LOAD_DB2(sToyStore);
    LOAD_DB2(sTraitCondStore);
    LOAD_DB2(sTraitCostStore);
    LOAD_DB2(sTraitCurrencyStore);
    LOAD_DB2(sTraitCurrencySourceStore);
    LOAD_DB2(sTraitDefinitionStore);
    LOAD_DB2(sTraitDefinitionEffectPointsStore);
    LOAD_DB2(sTraitEdgeStore);
    LOAD_DB2(sTraitNodeStore);
    LOAD_DB2(sTraitNodeEntryStore);
    LOAD_DB2(sTraitNodeEntryXTraitCondStore);
    LOAD_DB2(sTraitNodeEntryXTraitCostStore);
    LOAD_DB2(sTraitNodeGroupStore);
    LOAD_DB2(sTraitNodeGroupXTraitCondStore);
    LOAD_DB2(sTraitNodeGroupXTraitCostStore);
    LOAD_DB2(sTraitNodeGroupXTraitNodeStore);
    LOAD_DB2(sTraitNodeXTraitCondStore);
    LOAD_DB2(sTraitNodeXTraitCostStore);
    LOAD_DB2(sTraitNodeXTraitNodeEntryStore);
    LOAD_DB2(sTraitSubTreeStore);
    LOAD_DB2(sTraitTreeStore);
    LOAD_DB2(sTraitTreeLoadoutStore);
    LOAD_DB2(sTraitTreeLoadoutEntryStore);
    LOAD_DB2(sTraitTreeXTraitCostStore);
    LOAD_DB2(sTraitTreeXTraitCurrencyStore);
    LOAD_DB2(sTransmogHolidayStore);
    LOAD_DB2(sTransmogIllusionStore);
    LOAD_DB2(sTransmogSetStore);
    LOAD_DB2(sTransmogSetGroupStore);
    LOAD_DB2(sTransmogSetItemStore);
    LOAD_DB2(sTransportAnimationStore);
    LOAD_DB2(sTransportRotationStore);
    LOAD_DB2(sUiMapStore);
    LOAD_DB2(sUiMapAssignmentStore);
    LOAD_DB2(sUiMapLinkStore);
    LOAD_DB2(sUiMapXMapArtStore);
    LOAD_DB2(sUISplashScreenStore);
    LOAD_DB2(sUnitConditionStore);
    LOAD_DB2(sUnitPowerBarStore);
    LOAD_DB2(sVehicleStore);
    LOAD_DB2(sVehicleSeatStore);
    LOAD_DB2(sVignetteStore);
    LOAD_DB2(sWMOAreaTableStore);
    LOAD_DB2(sWorldEffectStore);
    LOAD_DB2(sWorldMapOverlayStore);
    LOAD_DB2(sWorldStateExpressionStore);

    // error checks
    if (!loadErrors.empty())
    {
        sLog->SetSynchronous(); // server will shut down after this, so set sync logging to prevent messages from getting lost

        for (std::string const& error : loadErrors)
            TC_LOG_FATAL("misc", "{}", error);

        return 0;
    }

    // Check loaded DB2 files proper version
    if (!sAreaTableStore.LookupEntry(15151) ||               // last area added in 10.2.5 (53007)
        !sCharTitlesStore.LookupEntry(805) ||                // last char title added in 10.2.5 (53007)
        !sGemPropertiesStore.LookupEntry(4081) ||            // last gem property added in 10.2.5 (53007)
        !sItemStore.LookupEntry(215160) ||                   // last item added in 10.2.5 (53007)
        !sItemExtendedCostStore.LookupEntry(8510) ||         // last item extended cost added in 10.2.5 (53007)
        !sMapStore.LookupEntry(2708) ||                      // last map added in 10.2.5 (53007)
        !sSpellNameStore.LookupEntry(438878))                // last spell added in 10.2.5 (53007)
    {
        TC_LOG_FATAL("misc", "You have _outdated_ DB2 files. Please extract correct versions from current using client.");
        return 0;
    }

    for (AreaGroupMemberEntry const* areaGroupMember : sAreaGroupMemberStore)
        _areaGroupMembers[areaGroupMember->AreaGroupID].push_back(areaGroupMember->AreaID);

    for (AreaTableEntry const* areaTable : sAreaTableStore)
    {
        ASSERT(areaTable->AreaBit <= 0 || (size_t(areaTable->AreaBit / 64) < PLAYER_EXPLORED_ZONES_SIZE),
            "PLAYER_EXPLORED_ZONES_SIZE must be at least %d", (areaTable->AreaBit + 63) / 64);
    }

    for (ArtifactPowerEntry const* artifactPower : sArtifactPowerStore)
        _artifactPowers[artifactPower->ArtifactID].push_back(artifactPower);

    for (ArtifactPowerLinkEntry const* artifactPowerLink : sArtifactPowerLinkStore)
    {
        _artifactPowerLinks[artifactPowerLink->PowerA].push_back(artifactPowerLink->PowerB);
        _artifactPowerLinks[artifactPowerLink->PowerB].push_back(artifactPowerLink->PowerA);
    }

    for (ArtifactPowerRankEntry const* artifactPowerRank : sArtifactPowerRankStore)
        _artifactPowerRanks[std::pair<uint32, uint8>{ artifactPowerRank->ArtifactPowerID, artifactPowerRank->RankIndex }] = artifactPowerRank;

    for (AzeriteEmpoweredItemEntry const* azeriteEmpoweredItem : sAzeriteEmpoweredItemStore)
        _azeriteEmpoweredItems[azeriteEmpoweredItem->ItemID] = azeriteEmpoweredItem;

    for (AzeriteEssencePowerEntry const* azeriteEssencePower : sAzeriteEssencePowerStore)
        _azeriteEssencePowersByIdAndRank[std::pair<uint32, uint32>{ azeriteEssencePower->AzeriteEssenceID, azeriteEssencePower->Tier }] = azeriteEssencePower;

    for (AzeriteItemMilestonePowerEntry const* azeriteItemMilestonePower : sAzeriteItemMilestonePowerStore)
        _azeriteItemMilestonePowers.push_back(azeriteItemMilestonePower);

    std::sort(_azeriteItemMilestonePowers.begin(), _azeriteItemMilestonePowers.end(), [](AzeriteItemMilestonePowerEntry const* a1, AzeriteItemMilestonePowerEntry const* a2)
    {
        return a1->RequiredLevel < a2->RequiredLevel;
    });

    {
        uint32 azeriteEssenceSlot = 0;
        for (AzeriteItemMilestonePowerEntry const* azeriteItemMilestonePower : _azeriteItemMilestonePowers)
        {
            AzeriteItemMilestoneType type = AzeriteItemMilestoneType(azeriteItemMilestonePower->Type);
            if (type == AzeriteItemMilestoneType::MajorEssence || type == AzeriteItemMilestoneType::MinorEssence)
            {
                ASSERT(azeriteEssenceSlot < MAX_AZERITE_ESSENCE_SLOT);
                _azeriteItemMilestonePowerByEssenceSlot[azeriteEssenceSlot] = azeriteItemMilestonePower;
                ++azeriteEssenceSlot;
            }
        }
    }

    for (AzeritePowerSetMemberEntry const* azeritePowerSetMember : sAzeritePowerSetMemberStore)
        if (sAzeritePowerStore.LookupEntry(azeritePowerSetMember->AzeritePowerID))
            _azeritePowers[azeritePowerSetMember->AzeritePowerSetID].push_back(azeritePowerSetMember);

    for (AzeriteTierUnlockEntry const* azeriteTierUnlock : sAzeriteTierUnlockStore)
        _azeriteTierUnlockLevels[std::pair<uint32, ItemContext>{ azeriteTierUnlock->AzeriteTierUnlockSetID, ItemContext(azeriteTierUnlock->ItemCreationContext) }][azeriteTierUnlock->Tier] = azeriteTierUnlock->AzeriteLevel;

    for (BattlemasterListEntry const* battlemaster : sBattlemasterListStore)
    {
        if (battlemaster->MaxLevel < battlemaster->MinLevel)
        {
            TC_LOG_ERROR("db2.hotfix.battlemaster_list", "Battlemaster ({}) contains bad values for MinLevel ({}) and MaxLevel ({}). Swapping values.", battlemaster->ID, battlemaster->MinLevel, battlemaster->MaxLevel);
            std::swap(const_cast<BattlemasterListEntry*>(battlemaster)->MaxLevel, const_cast<BattlemasterListEntry*>(battlemaster)->MinLevel);
        }
        if (battlemaster->MaxPlayers < battlemaster->MinPlayers)
        {
            TC_LOG_ERROR("db2.hotfix.battlemaster_list", "Battlemaster ({}) contains bad values for MinPlayers ({}) and MaxPlayers ({}). Swapping values.", battlemaster->ID, battlemaster->MinPlayers, battlemaster->MaxPlayers);
            int8 minPlayers = battlemaster->MinPlayers;
            const_cast<BattlemasterListEntry*>(battlemaster)->MinPlayers = battlemaster->MaxPlayers;
            const_cast<BattlemasterListEntry*>(battlemaster)->MaxPlayers = minPlayers;
        }
    }

    _broadcastTextDurations.reserve(sBroadcastTextDurationStore.GetNumRows());
    for (BroadcastTextDurationEntry const* broadcastTextDuration : sBroadcastTextDurationStore)
        _broadcastTextDurations[{ broadcastTextDuration->BroadcastTextID, CascLocaleBit(broadcastTextDuration->Locale) }] = broadcastTextDuration->Duration;

    for (CharBaseInfoEntry const* charBaseInfo : sCharBaseInfoStore)
        _charBaseInfoByRaceAndClass[{ charBaseInfo->RaceID, charBaseInfo->ClassID }] = charBaseInfo;

    for (ChrClassUIDisplayEntry const* uiDisplay : sChrClassUIDisplayStore)
    {
        ASSERT(uiDisplay->ChrClassesID < MAX_CLASSES);
        _uiDisplayByClass[uiDisplay->ChrClassesID] = uiDisplay;
    }

    {
        std::set<ChrClassesXPowerTypesEntry const*, ChrClassesXPowerTypesEntryComparator> powers;
        for (ChrClassesXPowerTypesEntry const* power : sChrClassesXPowerTypesStore)
            powers.insert(power);

        for (std::size_t i = 0; i < _powersByClass.size(); ++i)
            _powersByClass[i].fill(MAX_POWERS);

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

    for (ChrCustomizationChoiceEntry const* customizationChoice : sChrCustomizationChoiceStore)
        _chrCustomizationChoicesByOption[customizationChoice->ChrCustomizationOptionID].push_back(customizationChoice);

    std::unordered_multimap<uint32, std::pair<uint32, uint8>> shapeshiftFormByModel;
    std::unordered_map<uint32, ChrCustomizationDisplayInfoEntry const*> displayInfoByCustomizationChoice;

    // build shapeshift form model lookup
    for (ChrCustomizationElementEntry const* customizationElement : sChrCustomizationElementStore)
    {
        if (ChrCustomizationDisplayInfoEntry const* customizationDisplayInfo = sChrCustomizationDisplayInfoStore.LookupEntry(customizationElement->ChrCustomizationDisplayInfoID))
        {
            if (ChrCustomizationChoiceEntry const* customizationChoice = sChrCustomizationChoiceStore.LookupEntry(customizationElement->ChrCustomizationChoiceID))
            {
                displayInfoByCustomizationChoice[customizationElement->ChrCustomizationChoiceID] = customizationDisplayInfo;
                if (ChrCustomizationOptionEntry const* customizationOption = sChrCustomizationOptionStore.LookupEntry(customizationChoice->ChrCustomizationOptionID))
                    shapeshiftFormByModel.emplace(customizationOption->ChrModelID, std::make_pair(customizationOption->ID, uint8(customizationDisplayInfo->ShapeshiftFormID)));
            }
        }
    }

    std::unordered_map<uint32, std::vector<ChrCustomizationOptionEntry const*>> customizationOptionsByModel;
    for (ChrCustomizationOptionEntry const* customizationOption : sChrCustomizationOptionStore)
        customizationOptionsByModel[customizationOption->ChrModelID].push_back(customizationOption);

    for (ChrCustomizationReqChoiceEntry const* reqChoice : sChrCustomizationReqChoiceStore)
    {
        if (ChrCustomizationChoiceEntry const* customizationChoice = sChrCustomizationChoiceStore.LookupEntry(reqChoice->ChrCustomizationChoiceID))
        {
            std::vector<std::pair<uint32, std::vector<uint32>>>& requiredChoicesForReq = _chrCustomizationRequiredChoices[reqChoice->ChrCustomizationReqID];
            std::vector<uint32>* choices = nullptr;
            for (std::pair<uint32, std::vector<uint32>>& choicesForOption : requiredChoicesForReq)
            {
                if (int32(choicesForOption.first) == customizationChoice->ChrCustomizationOptionID)
                {
                    choices = &choicesForOption.second;
                    break;
                }
            }
            if (!choices)
            {
                std::pair<uint32, std::vector<uint32>>& choicesForReq = requiredChoicesForReq.emplace_back();
                choicesForReq.first = customizationChoice->ChrCustomizationOptionID;
                choices = &choicesForReq.second;
            }
            choices->push_back(reqChoice->ChrCustomizationChoiceID);
        }
    }

    std::unordered_map<uint32, uint32> parentRaces;
    for (ChrRacesEntry const* chrRace : sChrRacesStore)
        if (chrRace->UnalteredVisualRaceID)
            parentRaces[chrRace->UnalteredVisualRaceID] = chrRace->ID;

    for (ChrRaceXChrModelEntry const* raceModel : sChrRaceXChrModelStore)
    {
        if (ChrModelEntry const* model = sChrModelStore.LookupEntry(raceModel->ChrModelID))
        {
            _chrModelsByRaceAndGender[{ uint8(raceModel->ChrRacesID), uint8(raceModel->Sex) }] = model;

            if (std::vector<ChrCustomizationOptionEntry const*> const* customizationOptionsForModel = Trinity::Containers::MapGetValuePtr(customizationOptionsByModel, model->ID))
            {
                std::vector<ChrCustomizationOptionEntry const*>& raceOptions = _chrCustomizationOptionsByRaceAndGender[{ uint8(raceModel->ChrRacesID), uint8(raceModel->Sex) }];
                raceOptions.insert(raceOptions.end(), customizationOptionsForModel->begin(), customizationOptionsForModel->end());

                if (uint32 const* parentRace = Trinity::Containers::MapGetValuePtr(parentRaces, raceModel->ChrRacesID))
                {
                    std::vector<ChrCustomizationOptionEntry const*>& parentRaceOptions = _chrCustomizationOptionsByRaceAndGender[{ uint8(*parentRace), uint8(raceModel->Sex) }];
                    parentRaceOptions.insert(parentRaceOptions.end(), customizationOptionsForModel->begin(), customizationOptionsForModel->end());
                }
            }

            // link shapeshift displays to race/gender/form
            for (std::pair<uint32 const, std::pair<uint32, uint8>> const& shapeshiftOptionsForModel : Trinity::Containers::MapEqualRange(shapeshiftFormByModel, model->ID))
            {
                ShapeshiftFormModelData& data = _chrCustomizationChoicesForShapeshifts[{ uint8(raceModel->ChrRacesID), uint8(raceModel->Sex), shapeshiftOptionsForModel.second.second }];
                data.OptionID = shapeshiftOptionsForModel.second.first;
                data.Choices = Trinity::Containers::MapGetValuePtr(_chrCustomizationChoicesByOption, shapeshiftOptionsForModel.second.first);
                if (data.Choices)
                {
                    data.Displays.resize(data.Choices->size());
                    for (std::size_t i = 0; i < data.Choices->size(); ++i)
                        data.Displays[i] = Trinity::Containers::MapGetValuePtr(displayInfoByCustomizationChoice, (*data.Choices)[i]->ID);
                }
            }
        }
    }

    memset(_chrSpecializationsByIndex, 0, sizeof(_chrSpecializationsByIndex));
    for (ChrSpecializationEntry const* chrSpec : sChrSpecializationStore)
    {
        ASSERT(chrSpec->ClassID < MAX_CLASSES);
        ASSERT(chrSpec->OrderIndex < MAX_SPECIALIZATIONS);

        uint32 storageIndex = chrSpec->ClassID;
        if (chrSpec->GetFlags().HasFlag(ChrSpecializationFlag::PetOverrideSpec))
        {
            ASSERT(!chrSpec->ClassID);
            storageIndex = PET_SPEC_OVERRIDE_CLASS_INDEX;
        }

        _chrSpecializationsByIndex[storageIndex][chrSpec->OrderIndex] = chrSpec;
    }

    for (ConditionalChrModelEntry const* conditionalChrModel : sConditionalChrModelStore)
        _conditionalChrModelsByChrModelId[conditionalChrModel->ChrModelID] = conditionalChrModel;

    {
        for (ConditionalContentTuningEntry const* conditionalContentTuning : sConditionalContentTuningStore)
            _conditionalContentTuning[conditionalContentTuning->ParentContentTuningID].push_back(conditionalContentTuning);

        for (auto& [parentContentTuningId, conditionalContentTunings] : _conditionalContentTuning)
            std::ranges::sort(conditionalContentTunings, std::greater(), &ConditionalContentTuningEntry::OrderIndex);
    }

    for (ContentTuningXExpectedEntry const* contentTuningXExpectedStat : sContentTuningXExpectedStore)
        if (sExpectedStatModStore.LookupEntry(contentTuningXExpectedStat->ExpectedStatModID))
            _expectedStatModsByContentTuning[contentTuningXExpectedStat->ContentTuningID].push_back(contentTuningXExpectedStat);

    for (ContentTuningXLabelEntry const* contentTuningXLabel : sContentTuningXLabelStore)
        _contentTuningLabels.emplace(contentTuningXLabel->ContentTuningID, contentTuningXLabel->LabelID);

    for (CurrencyContainerEntry const* currencyContainer : sCurrencyContainerStore)
        _currencyContainers.emplace(currencyContainer->CurrencyTypesID, currencyContainer);

    {
        std::unordered_map<uint32 /*curveID*/, std::vector<CurvePointEntry const*>> unsortedPoints;
        for (CurvePointEntry const* curvePoint : sCurvePointStore)
            if (sCurveStore.LookupEntry(curvePoint->CurveID))
                unsortedPoints[curvePoint->CurveID].push_back(curvePoint);

        for (auto& [curveId, curvePoints] : unsortedPoints)
        {
            std::sort(curvePoints.begin(), curvePoints.end(), [](CurvePointEntry const* point1, CurvePointEntry const* point2) { return point1->OrderIndex < point2->OrderIndex; });
            std::vector<DBCPosition2D>& points = _curvePoints[curveId];
            points.resize(curvePoints.size());
            std::transform(curvePoints.begin(), curvePoints.end(), points.begin(), [](CurvePointEntry const* point) { return point->Pos; });
        }
    }

    for (EmotesTextSoundEntry const* emoteTextSound : sEmotesTextSoundStore)
        _emoteTextSounds[EmotesTextSoundContainer::key_type(emoteTextSound->EmotesTextID, emoteTextSound->RaceID, emoteTextSound->SexID, emoteTextSound->ClassID)] = emoteTextSound;

    for (ExpectedStatEntry const* expectedStat : sExpectedStatStore)
        _expectedStatsByLevel[std::make_pair(expectedStat->Lvl, expectedStat->ExpansionID)] = expectedStat;

    for (FactionEntry const* faction : sFactionStore)
        if (faction->ParentFactionID)
            _factionTeams[faction->ParentFactionID].push_back(faction->ID);

    for (FriendshipRepReactionEntry const* friendshipRepReaction : sFriendshipRepReactionStore)
        _friendshipRepReactions[friendshipRepReaction->FriendshipRepID].insert(friendshipRepReaction);

    for (GameObjectDisplayInfoEntry const* gameObjectDisplayInfo : sGameObjectDisplayInfoStore)
    {
        if (gameObjectDisplayInfo->GeoBoxMax.X < gameObjectDisplayInfo->GeoBoxMin.X)
            std::swap(const_cast<GameObjectDisplayInfoEntry*>(gameObjectDisplayInfo)->GeoBoxMax.X, const_cast<GameObjectDisplayInfoEntry*>(gameObjectDisplayInfo)->GeoBoxMin.X);
        if (gameObjectDisplayInfo->GeoBoxMax.Y < gameObjectDisplayInfo->GeoBoxMin.Y)
            std::swap(const_cast<GameObjectDisplayInfoEntry*>(gameObjectDisplayInfo)->GeoBoxMax.Y, const_cast<GameObjectDisplayInfoEntry*>(gameObjectDisplayInfo)->GeoBoxMin.Y);
        if (gameObjectDisplayInfo->GeoBoxMax.Z < gameObjectDisplayInfo->GeoBoxMin.Z)
            std::swap(const_cast<GameObjectDisplayInfoEntry*>(gameObjectDisplayInfo)->GeoBoxMax.Z, const_cast<GameObjectDisplayInfoEntry*>(gameObjectDisplayInfo)->GeoBoxMin.Z);
    }

    for (HeirloomEntry const* heirloom : sHeirloomStore)
        _heirlooms[heirloom->ItemID] = heirloom;

    for (GlyphBindableSpellEntry const* glyphBindableSpell : sGlyphBindableSpellStore)
        _glyphBindableSpells[glyphBindableSpell->GlyphPropertiesID].push_back(glyphBindableSpell->SpellID);

    for (GlyphRequiredSpecEntry const* glyphRequiredSpec : sGlyphRequiredSpecStore)
        _glyphRequiredSpecs[glyphRequiredSpec->GlyphPropertiesID].push_back(ChrSpecialization(glyphRequiredSpec->ChrSpecializationID));

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

    for (ItemModifiedAppearanceEntry const* appearanceMod : sItemModifiedAppearanceStore)
    {
        ASSERT(appearanceMod->ItemID <= 0xFFFFFF);
        _itemModifiedAppearancesByItem[appearanceMod->ItemID | (appearanceMod->ItemAppearanceModifierID << 24)] = appearanceMod;
    }

    for (ItemSetSpellEntry const* itemSetSpell : sItemSetSpellStore)
        _itemSetSpells[itemSetSpell->ItemSetID].push_back(itemSetSpell);

    for (ItemSpecOverrideEntry const* itemSpecOverride : sItemSpecOverrideStore)
        _itemSpecOverrides[itemSpecOverride->ItemID].push_back(itemSpecOverride);

    for (JournalTierEntry const* journalTier : sJournalTierStore)
        _journalTiersByIndex.push_back(journalTier);

    for (MapDifficultyEntry const* entry : sMapDifficultyStore)
        _mapDifficulties[entry->MapID][entry->DifficultyID] = entry;

    std::vector<MapDifficultyXConditionEntry const*> mapDifficultyConditions;
    mapDifficultyConditions.reserve(sMapDifficultyXConditionStore.GetNumRows());
    for (MapDifficultyXConditionEntry const* mapDifficultyCondition : sMapDifficultyXConditionStore)
        mapDifficultyConditions.push_back(mapDifficultyCondition);

    std::sort(mapDifficultyConditions.begin(), mapDifficultyConditions.end(), [](MapDifficultyXConditionEntry const* left, MapDifficultyXConditionEntry const* right)
    {
        return left->OrderIndex < right->OrderIndex;
    });

    for (MapDifficultyXConditionEntry const* mapDifficultyCondition : mapDifficultyConditions)
        if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(mapDifficultyCondition->PlayerConditionID))
            _mapDifficultyConditions[mapDifficultyCondition->MapDifficultyID].emplace_back(mapDifficultyCondition->ID, playerCondition);

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
        bool conversionResult = Utf8toWStr(namesProfanity->Name, name);
        ASSERT(conversionResult);
        if (namesProfanity->Language != -1)
            _nameValidators[namesProfanity->Language].emplace_back(name, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
        else
        {
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
            {
                if (i == LOCALE_none)
                    continue;

                _nameValidators[i].emplace_back(name, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
            }
        }
    }

    for (NamesReservedEntry const* namesReserved : sNamesReservedStore)
    {
        std::wstring name;
        bool conversionResult = Utf8toWStr(namesReserved->Name, name);
        ASSERT(conversionResult);
        _nameValidators[TOTAL_LOCALES].emplace_back(name, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
    }

    for (NamesReservedLocaleEntry const* namesReserved : sNamesReservedLocaleStore)
    {
        ASSERT(!(namesReserved->LocaleMask & ~((1u << TOTAL_LOCALES) - 1)));
        std::wstring name;
        bool conversionResult = Utf8toWStr(namesReserved->Name, name);
        ASSERT(conversionResult);
        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (i == LOCALE_none)
                continue;

            if (namesReserved->LocaleMask & (1 << i))
                _nameValidators[i].emplace_back(name, Trinity::regex::perl | Trinity::regex::icase | Trinity::regex::optimize);
        }
    }

    for (ParagonReputationEntry const* paragonReputation : sParagonReputationStore)
        if (sFactionStore.HasRecord(paragonReputation->FactionID))
            _paragonReputations[paragonReputation->FactionID] = paragonReputation;

    {
        std::unordered_map<uint32 /*pathID*/, std::vector<PathNodeEntry const*>> unsortedNodes;
        for (PathNodeEntry const* pathNode : sPathNodeStore)
            if (sPathStore.HasRecord(pathNode->PathID) && sLocationStore.HasRecord(pathNode->LocationID))
                unsortedNodes[pathNode->PathID].push_back(pathNode);

        for (auto&& [pathId, pathNodes] : unsortedNodes)
        {
            PathDb2& path = _paths[pathId];

            path.Locations.resize(pathNodes.size());
            std::ranges::sort(pathNodes, std::ranges::less(), &PathNodeEntry::Sequence);
            std::ranges::transform(pathNodes, path.Locations.begin(), [](PathNodeEntry const* node)
            {
                return sLocationStore.AssertEntry(node->LocationID)->Pos;
            });
        }

        for (PathPropertyEntry const* pathProperty : sPathPropertyStore)
            if (sPathStore.HasRecord(pathProperty->PathID))
                _paths[pathProperty->PathID].Properties.push_back(pathProperty);
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

    {
        for (QuestLineXQuestEntry const* questLineQuest : sQuestLineXQuestStore)
            _questsByQuestLine[questLineQuest->QuestLineID].push_back(questLineQuest);

        for (auto& [questLineId, questLineQuests] : _questsByQuestLine)
            std::ranges::sort(questLineQuests, std::ranges::less(), &QuestLineXQuestEntry::OrderIndex);
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

    for (SkillLineEntry const* skill : sSkillLineStore)
        if (skill->ParentSkillLineID)
            _skillLinesByParentSkillLine[skill->ParentSkillLineID].push_back(skill);

    for (SkillLineAbilityEntry const* skillLineAbility : sSkillLineAbilityStore)
        _skillLineAbilitiesBySkillupSkill[skillLineAbility->SkillupSkillLineID ? skillLineAbility->SkillupSkillLineID : skillLineAbility->SkillLine].push_back(skillLineAbility);

    for (SkillRaceClassInfoEntry const* entry : sSkillRaceClassInfoStore)
        if (sSkillLineStore.LookupEntry(entry->SkillID))
            _skillRaceClassInfoBySkill.insert(SkillRaceClassInfoContainer::value_type(entry->SkillID, entry));

    for (SoulbindConduitRankEntry const* soulbindConduitRank : sSoulbindConduitRankStore)
        _soulbindConduitRanks[{ soulbindConduitRank->SoulbindConduitID, soulbindConduitRank->RankIndex }] = soulbindConduitRank;

    for (SpecializationSpellsEntry const* specSpells : sSpecializationSpellsStore)
        _specializationSpellsBySpec[specSpells->SpecID].push_back(specSpells);

    for (SpecSetMemberEntry const* specSetMember : sSpecSetMemberStore)
        _specsBySpecSet.insert(std::make_pair(specSetMember->SpecSetID, uint32(specSetMember->ChrSpecializationID)));

    for (SpellClassOptionsEntry const* classOption : sSpellClassOptionsStore)
        _spellFamilyNames.insert(classOption->SpellClassSet);

    for (SpellProcsPerMinuteModEntry const* ppmMod : sSpellProcsPerMinuteModStore)
        _spellProcsPerMinuteMods[ppmMod->SpellProcsPerMinuteID].push_back(ppmMod);

    for (SpellVisualMissileEntry const* spellVisualMissile : sSpellVisualMissileStore)
        _spellVisualMissilesBySet[spellVisualMissile->SpellVisualMissileSetID].push_back(spellVisualMissile);

    for (TalentEntry const* talentInfo : sTalentStore)
    {
        ASSERT(talentInfo->ClassID < MAX_CLASSES);
        ASSERT(talentInfo->TierID < MAX_TALENT_TIERS, "MAX_TALENT_TIERS must be at least %u", talentInfo->TierID + 1);
        ASSERT(talentInfo->ColumnIndex < MAX_TALENT_COLUMNS, "MAX_TALENT_COLUMNS must be at least %u", talentInfo->ColumnIndex + 1);

        _talentsByPosition[talentInfo->ClassID][talentInfo->TierID][talentInfo->ColumnIndex].push_back(talentInfo);
    }

    for (TaxiPathEntry const* entry : sTaxiPathStore)
        _taxiPaths[{ entry->FromTaxiNode, entry->ToTaxiNode }] = entry;

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

    for (TransmogIllusionEntry const* transmogIllusion : sTransmogIllusionStore)
        _transmogIllusionsByEnchantmentId[transmogIllusion->SpellItemEnchantmentID] = transmogIllusion;

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
            ASSERT(uiMap->System < MAX_UI_MAP_SYSTEM, "MAX_UI_MAP_SYSTEM must be at least %u", uiMap->System + 1);
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
            if (parentUiMap->GetFlags().HasFlag(UiMapFlag::NoWorldPositions))
                continue;

            UiMapAssignmentEntry const* uiMapAssignment = nullptr;
            UiMapAssignmentEntry const* parentUiMapAssignment = nullptr;
            for (std::pair<int32 const, UiMapAssignmentEntry const*> const& uiMapAssignmentForMap : Trinity::Containers::MapEqualRange(uiMapAssignmentByUiMap, uiMap->ID))
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

            for (std::pair<int32 const, UiMapAssignmentEntry const*> const& uiMapAssignmentForMap : Trinity::Containers::MapEqualRange(uiMapAssignmentByUiMap, uiMap->ParentUiMapID))
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
    // reinitialize internal storage for globals after loading TaxiNodes.db2
    sTaxiNodesMask = {};
    sHordeTaxiNodesMask = {};
    sAllianceTaxiNodesMask = {};
    sOldContinentsNodesMask = {};
    // include existed nodes that have at least single not spell base (scripted) path
    for (TaxiNodesEntry const* node : sTaxiNodesStore)
    {
        if (!node->IsPartOfTaxiNetwork())
            continue;

        // valid taxi network node
        uint32 field = uint32((node->ID - 1) / (sizeof(TaxiMask::value_type) * 8));
        TaxiMask::value_type submask = TaxiMask::value_type(1 << ((node->ID - 1) % (sizeof(TaxiMask::value_type) * 8)));

        sTaxiNodesMask[field] |= submask;
        if (node->GetFlags().HasFlag(TaxiNodeFlags::ShowOnHordeMap))
            sHordeTaxiNodesMask[field] |= submask;
        if (node->GetFlags().HasFlag(TaxiNodeFlags::ShowOnAllianceMap))
            sAllianceTaxiNodesMask[field] |= submask;

        int32 uiMapId = -1;
        if (!GetUiMapPosition(node->Pos.X, node->Pos.Y, node->Pos.Z, node->ContinentID, 0, 0, 0, UI_MAP_SYSTEM_ADVENTURE, false, &uiMapId))
            GetUiMapPosition(node->Pos.X, node->Pos.Y, node->Pos.Z, node->ContinentID, 0, 0, 0, UI_MAP_SYSTEM_TAXI, false, &uiMapId);

        if (uiMapId == 985 || uiMapId == 986)
            sOldContinentsNodesMask[field] |= submask;
    }

    for (PVPStatEntry const* pvpStat : sPVPStatStore)
        _pvpStatIdsByMap[pvpStat->MapID].insert(pvpStat->ID);

    TC_LOG_INFO("server.loading", ">> Initialized {} DB2 data stores in {} ms", _stores.size(), GetMSTimeDiffToNow(oldMSTime));

    return availableDb2Locales.to_ulong();
}

DB2StorageBase const* DB2Manager::GetStorage(uint32 type) const
{
    auto itr = _stores.find(type);
    if (itr != _stores.end())
        return itr->second;

    return nullptr;
}

void DB2Manager::LoadHotfixData(uint32 localeMask)
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = HotfixDatabase.Query("SELECT Id, UniqueId, TableHash, RecordId, Status FROM hotfix_data ORDER BY Id");

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
        uint32 uniqueId = fields[1].GetUInt32();
        uint32 tableHash = fields[2].GetUInt32();
        int32 recordId = fields[3].GetInt32();
        HotfixRecord::Status status = static_cast<HotfixRecord::Status>(fields[4].GetUInt8());
        std::bitset<TOTAL_LOCALES> availableDb2Locales = localeMask;
        if (status == HotfixRecord::Status::Valid && !_stores.contains(tableHash))
        {
            HotfixBlobKey key = std::make_pair(tableHash, recordId);
            for (std::size_t locale = 0; locale < TOTAL_LOCALES; ++locale)
            {
                if (!availableDb2Locales[locale])
                    continue;

                if (!_hotfixBlob[locale].contains(key))
                    availableDb2Locales[locale] = false;
            }

            if (availableDb2Locales.none())
            {
                TC_LOG_ERROR("sql.sql", "Table `hotfix_data` references unknown DB2 store by hash 0x{:X} and has no reference to `hotfix_blob` in hotfix id {} with RecordID: {}", tableHash, id, recordId);
                continue;
            }
        }

        HotfixRecord hotfixRecord;
        hotfixRecord.TableHash = tableHash;
        hotfixRecord.RecordID = recordId;
        hotfixRecord.ID.PushID = id;
        hotfixRecord.ID.UniqueID = uniqueId;
        hotfixRecord.HotfixStatus = status;
        hotfixRecord.AvailableLocalesMask = availableDb2Locales.to_ulong();

        HotfixPush& push = _hotfixData[id];
        push.Records.push_back(hotfixRecord);
        push.AvailableLocalesMask |= hotfixRecord.AvailableLocalesMask;

        _maxHotfixId = std::max(_maxHotfixId, id);
        deletedRecords[std::make_pair(tableHash, recordId)] = status == HotfixRecord::Status::RecordRemoved;
        ++count;
    } while (result->NextRow());

    for (auto itr = deletedRecords.begin(); itr != deletedRecords.end(); ++itr)
        if (itr->second)
            if (DB2StorageBase* store = Trinity::Containers::MapGetValuePtr(_stores, itr->first.first))
                store->EraseRecord(itr->first.second);

    TC_LOG_INFO("server.loading", ">> Loaded {} hotfix records in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void DB2Manager::LoadHotfixBlob(uint32 localeMask)
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = HotfixDatabase.Query("SELECT TableHash, RecordId, locale, `Blob` FROM hotfix_blob ORDER BY TableHash");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 hotfix blob entries.");
        return;
    }

    std::bitset<TOTAL_LOCALES> availableDb2Locales = localeMask;
    uint32 hotfixBlobCount = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 tableHash = fields[0].GetUInt32();
        auto storeItr = _stores.find(tableHash);
        if (storeItr != _stores.end())
        {
            TC_LOG_ERROR("sql.sql", "Table hash 0x{:X} points to a loaded DB2 store {}, fill related table instead of hotfix_blob",
                tableHash, storeItr->second->GetFileName());
            continue;
        }

        int32 recordId = fields[1].GetInt32();
        std::string localeName = fields[2].GetString();
        LocaleConstant locale = GetLocaleByName(localeName);

        if (!IsValidLocale(locale))
        {
            TC_LOG_ERROR("sql.sql", "`hotfix_blob` contains invalid locale: {} at TableHash: 0x{:X} and RecordID: {}", localeName, tableHash, recordId);
            continue;
        }

        if (!availableDb2Locales[locale])
            continue;

        _hotfixBlob[locale][std::make_pair(tableHash, recordId)] = fields[3].GetBinary();
        hotfixBlobCount++;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} hotfix blob records in {} ms", hotfixBlobCount, GetMSTimeDiffToNow(oldMSTime));
}

bool ValidateBroadcastTextTactKeyOptionalData(std::vector<uint8> const& data)
{
    return data.size() == 8 + 16;
}

void DB2Manager::LoadHotfixOptionalData(uint32 localeMask)
{
    // Register allowed optional data keys
    _allowedHotfixOptionalData.emplace(sBroadcastTextStore.GetTableHash(), std::make_pair(sTactKeyStore.GetTableHash(), &ValidateBroadcastTextTactKeyOptionalData));

    uint32 oldMSTime = getMSTime();

    QueryResult result = HotfixDatabase.Query("SELECT TableHash, RecordId, locale, `Key`, `Data` FROM hotfix_optional_data ORDER BY TableHash");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 hotfix optional data records.");
        return;
    }

    std::bitset<TOTAL_LOCALES> availableDb2Locales = localeMask;
    uint32 hotfixOptionalDataCount = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 tableHash = fields[0].GetUInt32();
        auto allowedHotfixes = Trinity::Containers::MapEqualRange(_allowedHotfixOptionalData, tableHash);
        if (allowedHotfixes.begin() == allowedHotfixes.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `hotfix_optional_data` references DB2 store by hash 0x{:X} that is not allowed to have optional data", tableHash);
            continue;
        }

        uint32 recordId = fields[1].GetInt32();
        auto storeItr = _stores.find(tableHash);
        if (storeItr == _stores.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `hotfix_optional_data` references unknown DB2 store by hash 0x{:X} with RecordID: {}", tableHash, recordId);
            continue;
        }

        std::string localeName = fields[2].GetString();
        LocaleConstant locale = GetLocaleByName(localeName);

        if (!IsValidLocale(locale))
        {
            TC_LOG_ERROR("sql.sql", "`hotfix_optional_data` contains invalid locale: {} at TableHash: 0x{:X} and RecordID: {}", localeName, tableHash, recordId);
            continue;
        }

        if (!availableDb2Locales[locale])
            continue;

        DB2Manager::HotfixOptionalData optionalData;
        optionalData.Key = fields[3].GetUInt32();
        auto allowedHotfixItr = std::find_if(allowedHotfixes.begin(), allowedHotfixes.end(), [&](std::pair<uint32 const, AllowedHotfixOptionalData> const& v)
        {
            return v.second.first == optionalData.Key;
        });
        if (allowedHotfixItr == allowedHotfixes.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `hotfix_optional_data` references non-allowed optional data key 0x{:X} for DB2 store by hash 0x{:X} and RecordID: {}",
                optionalData.Key, tableHash, recordId);
            continue;
        }

        optionalData.Data = fields[4].GetBinary();
        if (!allowedHotfixItr->second.second(optionalData.Data))
        {
            TC_LOG_ERROR("sql.sql", "Table `hotfix_optional_data` contains invalid data for DB2 store 0x{:X}, RecordID: {} and Key: 0x{:X}",
                tableHash, recordId, optionalData.Key);
            continue;
        }

        _hotfixOptionalData[locale][std::make_pair(tableHash, recordId)].push_back(std::move(optionalData));
        hotfixOptionalDataCount++;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} hotfix optional data records in {} ms", hotfixOptionalDataCount, GetMSTimeDiffToNow(oldMSTime));
}

uint32 DB2Manager::GetHotfixCount() const
{
    return _hotfixData.size();
}

DB2Manager::HotfixContainer const& DB2Manager::GetHotfixData() const
{
    return _hotfixData;
}

std::vector<uint8> const* DB2Manager::GetHotfixBlobData(uint32 tableHash, int32 recordId, LocaleConstant locale) const
{
    ASSERT(IsValidLocale(locale), "Locale %u is invalid locale", uint32(locale));

    return Trinity::Containers::MapGetValuePtr(_hotfixBlob[locale], std::make_pair(tableHash, recordId));
}

std::vector<DB2Manager::HotfixOptionalData> const* DB2Manager::GetHotfixOptionalData(uint32 tableHash, int32 recordId, LocaleConstant locale) const
{
    ASSERT(IsValidLocale(locale), "Locale %u is invalid locale", uint32(locale));

    return Trinity::Containers::MapGetValuePtr(_hotfixOptionalData[locale], std::make_pair(tableHash, recordId));
}

uint32 DB2Manager::GetEmptyAnimStateID() const
{
    return sAnimationDataStore.GetNumRows();
}

void DB2Manager::InsertNewHotfix(uint32 tableHash, uint32 recordId)
{
    HotfixRecord hotfixRecord;
    hotfixRecord.TableHash = tableHash;
    hotfixRecord.RecordID = recordId;
    hotfixRecord.ID.PushID = ++_maxHotfixId;
    hotfixRecord.ID.UniqueID = rand32();
    hotfixRecord.AvailableLocalesMask = 0xDFF;

    HotfixPush& push = _hotfixData[hotfixRecord.ID.PushID];
    push.Records.push_back(hotfixRecord);
    push.AvailableLocalesMask |= hotfixRecord.AvailableLocalesMask;
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

ContentTuningEntry const* DB2Manager::GetContentTuningForArea(AreaTableEntry const* areaEntry)
{
    if (!areaEntry)
        return nullptr;

    // Get ContentTuning for the area
    if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(areaEntry->ContentTuningID))
        return contentTuning;

    // If there is no data for the current area and it has a parent area, get data from the last (recursive)
    if (AreaTableEntry const* parentAreaEntry = sAreaTableStore.LookupEntry(areaEntry->ParentAreaID))
        return GetContentTuningForArea(parentAreaEntry);

    return nullptr;
}

std::vector<ArtifactPowerEntry const*> DB2Manager::GetArtifactPowers(uint8 artifactId) const
{
    auto itr = _artifactPowers.find(artifactId);
    if (itr != _artifactPowers.end())
        return itr->second;

    return std::vector<ArtifactPowerEntry const*>{};
}

std::vector<uint32> const* DB2Manager::GetArtifactPowerLinks(uint32 artifactPowerId) const
{
    return Trinity::Containers::MapGetValuePtr(_artifactPowerLinks, artifactPowerId);
}

ArtifactPowerRankEntry const* DB2Manager::GetArtifactPowerRank(uint32 artifactPowerId, uint8 rank) const
{
    return Trinity::Containers::MapGetValuePtr(_artifactPowerRanks, { artifactPowerId, rank });
}

AzeriteEmpoweredItemEntry const* DB2Manager::GetAzeriteEmpoweredItem(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_azeriteEmpoweredItems, itemId);
}

bool DB2Manager::IsAzeriteItem(uint32 itemId) const
{
    return std::find_if(sAzeriteItemStore.begin(), sAzeriteItemStore.end(),
        [&](AzeriteItemEntry const* azeriteItem) { return azeriteItem->ItemID == int32(itemId); }) != sAzeriteItemStore.end();
}

AzeriteEssencePowerEntry const* DB2Manager::GetAzeriteEssencePower(uint32 azeriteEssenceId, uint32 rank) const
{
    return Trinity::Containers::MapGetValuePtr(_azeriteEssencePowersByIdAndRank, std::make_pair(azeriteEssenceId, rank));
}

std::vector<AzeriteItemMilestonePowerEntry const*> const& DB2Manager::GetAzeriteItemMilestonePowers() const
{
    return _azeriteItemMilestonePowers;
}

AzeriteItemMilestonePowerEntry const* DB2Manager::GetAzeriteItemMilestonePower(uint8 slot) const
{
    ASSERT(slot < MAX_AZERITE_ESSENCE_SLOT, "Slot %u must be lower than MAX_AZERITE_ESSENCE_SLOT (%u)", uint32(slot), MAX_AZERITE_ESSENCE_SLOT);
    return _azeriteItemMilestonePowerByEssenceSlot[slot];
}

std::vector<AzeritePowerSetMemberEntry const*> const* DB2Manager::GetAzeritePowers(uint32 itemId) const
{
    if (AzeriteEmpoweredItemEntry const* azeriteEmpoweredItem = GetAzeriteEmpoweredItem(itemId))
        return Trinity::Containers::MapGetValuePtr(_azeritePowers, azeriteEmpoweredItem->AzeritePowerSetID);

    return nullptr;
}

uint32 DB2Manager::GetRequiredAzeriteLevelForAzeritePowerTier(uint32 azeriteUnlockSetId, ItemContext context, uint32 tier) const
{
    ASSERT(tier < MAX_AZERITE_EMPOWERED_TIER);
    if (std::array<uint8, MAX_AZERITE_EMPOWERED_TIER> const* levels = Trinity::Containers::MapGetValuePtr(_azeriteTierUnlockLevels, std::make_pair(azeriteUnlockSetId, context)))
        return (*levels)[tier];

    AzeriteTierUnlockSetEntry const* azeriteTierUnlockSet = sAzeriteTierUnlockSetStore.LookupEntry(azeriteUnlockSetId);
    if (azeriteTierUnlockSet && azeriteTierUnlockSet->Flags & AZERITE_TIER_UNLOCK_SET_FLAG_DEFAULT)
        if (std::array<uint8, MAX_AZERITE_EMPOWERED_TIER> const* levels = Trinity::Containers::MapGetValuePtr(_azeriteTierUnlockLevels, std::make_pair(azeriteUnlockSetId, ItemContext::NONE)))
            return (*levels)[tier];

    return sAzeriteLevelInfoStore.GetNumRows();
}

char const* DB2Manager::GetBroadcastTextValue(BroadcastTextEntry const* broadcastText, LocaleConstant locale /*= DEFAULT_LOCALE*/, uint8 gender /*= GENDER_MALE*/, bool forceGender /*= false*/)
{
    if ((gender == GENDER_FEMALE || gender == GENDER_NONE) && (forceGender || broadcastText->Text1[DEFAULT_LOCALE][0] != '\0'))
    {
        if (broadcastText->Text1[locale][0] != '\0')
            return broadcastText->Text1[locale];

        return broadcastText->Text1[DEFAULT_LOCALE];
    }

    if (broadcastText->Text[locale][0] != '\0')
        return broadcastText->Text[locale];

    return broadcastText->Text[DEFAULT_LOCALE];
}

int32 const* DB2Manager::GetBroadcastTextDuration(int32 broadcastTextId, LocaleConstant locale /*= DEFAULT_LOCALE*/) const
{
    return Trinity::Containers::MapGetValuePtr(_broadcastTextDurations, { broadcastTextId, WowLocaleToCascLocaleBit[locale] });
}

CharBaseInfoEntry const* DB2Manager::GetCharBaseInfo(Races race, Classes class_)
{
    return Trinity::Containers::MapGetValuePtr(_charBaseInfoByRaceAndClass, { race, class_ });
}

ChrClassUIDisplayEntry const* DB2Manager::GetUiDisplayForClass(Classes unitClass) const
{
    ASSERT(unitClass < MAX_CLASSES);
    return _uiDisplayByClass[unitClass];
}

char const* DB2Manager::GetClassName(uint8 class_, LocaleConstant locale /*= DEFAULT_LOCALE*/)
{
    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);
    if (!classEntry)
        return "";

    if (classEntry->Name[locale][0] != '\0')
        return classEntry->Name[locale];

    return classEntry->Name[DEFAULT_LOCALE];
}

uint32 DB2Manager::GetPowerIndexByClass(Powers power, uint32 classId) const
{
    return _powersByClass[classId][power];
}

std::vector<ChrCustomizationChoiceEntry const*> const* DB2Manager::GetCustomiztionChoices(uint32 chrCustomizationOptionId) const
{
    return Trinity::Containers::MapGetValuePtr(_chrCustomizationChoicesByOption, chrCustomizationOptionId);
}

std::vector<ChrCustomizationOptionEntry const*> const* DB2Manager::GetCustomiztionOptions(uint8 race, uint8 gender) const
{
    return Trinity::Containers::MapGetValuePtr(_chrCustomizationOptionsByRaceAndGender, { race,gender });
}

std::vector<std::pair<uint32, std::vector<uint32>>> const* DB2Manager::GetRequiredCustomizationChoices(uint32 chrCustomizationReqId) const
{
    return Trinity::Containers::MapGetValuePtr(_chrCustomizationRequiredChoices, chrCustomizationReqId);
}

ChrModelEntry const* DB2Manager::GetChrModel(uint8 race, uint8 gender) const
{
    return Trinity::Containers::MapGetValuePtr(_chrModelsByRaceAndGender, { race, gender });
}

ConditionalChrModelEntry const* DB2Manager::GetConditionalChrModel(int32 chrModelId)
{
    return Trinity::Containers::MapGetValuePtr(_conditionalChrModelsByChrModelId, chrModelId);
}

char const* DB2Manager::GetChrRaceName(uint8 race, LocaleConstant locale /*= DEFAULT_LOCALE*/)
{
    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
    if (!raceEntry)
        return "";

    if (raceEntry->Name[locale][0] != '\0')
        return raceEntry->Name[locale];

    return raceEntry->Name[DEFAULT_LOCALE];
}

ChrSpecializationEntry const* DB2Manager::GetChrSpecializationByIndex(uint32 class_, uint32 index) const
{
    return _chrSpecializationsByIndex[class_][index];
}

ChrSpecializationEntry const* DB2Manager::GetDefaultChrSpecializationForClass(uint32 class_) const
{
    return GetChrSpecializationByIndex(class_, INITIAL_SPECIALIZATION_INDEX);
}

uint32 DB2Manager::GetRedirectedContentTuningId(uint32 contentTuningId, uint32 redirectFlag) const
{
    if (std::vector<ConditionalContentTuningEntry const*> const* conditionalContentTunings = Trinity::Containers::MapGetValuePtr(_conditionalContentTuning, contentTuningId))
        for (ConditionalContentTuningEntry const* conditionalContentTuning : *conditionalContentTunings)
            if (conditionalContentTuning->RedirectFlag & redirectFlag)
                return conditionalContentTuning->RedirectContentTuningID;

    return contentTuningId;
}

Optional<ContentTuningLevels> DB2Manager::GetContentTuningData(uint32 contentTuningId, uint32 redirectFlag, bool forItem /*= false*/) const
{
    ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(GetRedirectedContentTuningId(contentTuningId, redirectFlag));
    if (!contentTuning)
        return {};

    if (forItem && contentTuning->GetFlags().HasFlag(ContentTuningFlag::DisabledForItem))
        return {};

    auto getLevelAdjustment = [](ContentTuningCalcType type) -> int32
    {
        switch (type)
        {
            case ContentTuningCalcType::MinLevel:
                return 1;
            case ContentTuningCalcType::MaxLevel:
                return GetMaxLevelForExpansion(sWorld->getIntConfig(CONFIG_EXPANSION));
            case ContentTuningCalcType::PrevExpansionMaxLevel:
                return GetMaxLevelForExpansion(std::max<int32>(sWorld->getIntConfig(CONFIG_EXPANSION) - 1, 0));
            default:
                break;
        }

        return 0;
    };

    ContentTuningLevels levels;
    levels.MinLevel = contentTuning->MinLevel + getLevelAdjustment(static_cast<ContentTuningCalcType>(contentTuning->MinLevelType));
    levels.MaxLevel = contentTuning->MaxLevel + getLevelAdjustment(static_cast<ContentTuningCalcType>(contentTuning->MaxLevelType));
    levels.MinLevelWithDelta = std::clamp<int32>(levels.MinLevel + contentTuning->TargetLevelDelta, 1, MAX_LEVEL);
    levels.MaxLevelWithDelta = std::clamp<int32>(levels.MaxLevel + contentTuning->TargetLevelMaxDelta, 1, MAX_LEVEL);

    // clamp after calculating levels with delta (delta can bring "overflown" level back into correct range)
    levels.MinLevel = std::clamp<int32>(levels.MinLevel, 1, MAX_LEVEL);
    levels.MaxLevel = std::clamp<int32>(levels.MaxLevel, 1, MAX_LEVEL);

    if (contentTuning->TargetLevelMin)
        levels.TargetLevelMin = contentTuning->TargetLevelMin;
    else
        levels.TargetLevelMin = levels.MinLevelWithDelta;

    if (contentTuning->TargetLevelMax)
        levels.TargetLevelMax = contentTuning->TargetLevelMax;
    else
        levels.TargetLevelMax = levels.MaxLevelWithDelta;

    return levels;
}

bool DB2Manager::HasContentTuningLabel(uint32 contentTuningId, int32 label) const
{
    return _contentTuningLabels.contains({ contentTuningId, label });
}

char const* DB2Manager::GetCreatureFamilyPetName(uint32 petfamily, LocaleConstant locale)
{
    if (!petfamily)
        return nullptr;

    CreatureFamilyEntry const* petFamily = sCreatureFamilyStore.LookupEntry(petfamily);
    if (!petFamily)
        return nullptr;

    return petFamily->Name[locale][0] != '\0' ? petFamily->Name[locale] : nullptr;
}

CurrencyContainerEntry const* DB2Manager::GetCurrencyContainerForCurrencyQuantity(uint32 currencyId, int32 quantity) const
{
    for (std::pair<uint32 const, CurrencyContainerEntry const*> const& p : Trinity::Containers::MapEqualRange(_currencyContainers, currencyId))
        if (quantity >= p.second->MinAmount && (!p.second->MaxAmount || quantity <= p.second->MaxAmount))
            return p.second;

    return nullptr;
}

std::pair<float, float> DB2Manager::GetCurveXAxisRange(uint32 curveId) const
{
    if (std::vector<DBCPosition2D> const* points = Trinity::Containers::MapGetValuePtr(_curvePoints, curveId))
        return { points->front().X, points->back().X };

    return { 0.0f, 0.0f };
}

static CurveInterpolationMode DetermineCurveType(CurveEntry const* curve, std::vector<DBCPosition2D> const& points)
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
    std::vector<DBCPosition2D> const& points = itr->second;
    if (points.empty())
        return 0.0f;

    return GetCurveValueAt(DetermineCurveType(curve, points), points, x);
}

float DB2Manager::GetCurveValueAt(CurveInterpolationMode mode, std::span<DBCPosition2D const> points, float x) const
{
    switch (mode)
    {
        case CurveInterpolationMode::Linear:
        {
            std::size_t pointIndex = 0;
            while (pointIndex < points.size() && points[pointIndex].X <= x)
                ++pointIndex;
            if (!pointIndex)
                return points[0].Y;
            if (pointIndex >= points.size())
                return points.back().Y;
            float xDiff = points[pointIndex].X - points[pointIndex - 1].X;
            if (xDiff == 0.0)
                return points[pointIndex].Y;
            return (((x - points[pointIndex - 1].X) / xDiff) * (points[pointIndex].Y - points[pointIndex - 1].Y)) + points[pointIndex - 1].Y;
        }
        case CurveInterpolationMode::Cosine:
        {
            std::size_t pointIndex = 0;
            while (pointIndex < points.size() && points[pointIndex].X <= x)
                ++pointIndex;
            if (!pointIndex)
                return points[0].Y;
            if (pointIndex >= points.size())
                return points.back().Y;
            float xDiff = points[pointIndex].X - points[pointIndex - 1].X;
            if (xDiff == 0.0)
                return points[pointIndex].Y;
            return ((points[pointIndex].Y - points[pointIndex - 1].Y) * (1.0f - std::cos((x - points[pointIndex - 1].X) / xDiff * float(M_PI))) * 0.5f) + points[pointIndex - 1].Y;
        }
        case CurveInterpolationMode::CatmullRom:
        {
            std::size_t pointIndex = 1;
            while (pointIndex < points.size() && points[pointIndex].X <= x)
                ++pointIndex;
            if (pointIndex == 1)
                return points[1].Y;
            if (pointIndex >= points.size() - 1)
                return points[points.size() - 2].Y;
            float xDiff = points[pointIndex].X - points[pointIndex - 1].X;
            if (xDiff == 0.0)
                return points[pointIndex].Y;

            float mu = (x - points[pointIndex - 1].X) / xDiff;
            float a0 = -0.5f * points[pointIndex - 2].Y + 1.5f * points[pointIndex - 1].Y - 1.5f * points[pointIndex].Y + 0.5f * points[pointIndex + 1].Y;
            float a1 = points[pointIndex - 2].Y - 2.5f * points[pointIndex - 1].Y + 2.0f * points[pointIndex].Y - 0.5f * points[pointIndex + 1].Y;
            float a2 = -0.5f * points[pointIndex - 2].Y + 0.5f * points[pointIndex].Y;
            float a3 = points[pointIndex - 1].Y;

            return a0 * mu * mu * mu + a1 * mu * mu + a2 * mu + a3;
        }
        case CurveInterpolationMode::Bezier3:
        {
            float xDiff = points[2].X - points[0].X;
            if (xDiff == 0.0)
                return points[1].Y;
            float mu = (x - points[0].X) / xDiff;
            return ((1.0f - mu) * (1.0f - mu) * points[0].Y) + (1.0f - mu) * 2.0f * mu * points[1].Y + mu * mu * points[2].Y;
        }
        case CurveInterpolationMode::Bezier4:
        {
            float xDiff = points[3].X - points[0].X;
            if (xDiff == 0.0)
                return points[1].Y;
            float mu = (x - points[0].X) / xDiff;
            return (1.0f - mu) * (1.0f - mu) * (1.0f - mu) * points[0].Y
                + 3.0f * mu * (1.0f - mu) * (1.0f - mu) * points[1].Y
                + 3.0f * mu * mu * (1.0f - mu) * points[2].Y
                + mu * mu * mu * points[3].Y;
        }
        case CurveInterpolationMode::Bezier:
        {
            float xDiff = points.back().X - points[0].X;
            if (xDiff == 0.0f)
                return points.back().Y;

            std::vector<float> tmp(points.size());
            for (std::size_t i = 0; i < points.size(); ++i)
                tmp[i] = points[i].Y;

            float mu = (x - points[0].X) / xDiff;
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
            return points[0].Y;
        default:
            break;
    }

    return 0.0f;
}

EmotesTextSoundEntry const* DB2Manager::GetTextSoundEmoteFor(uint32 emote, uint8 race, uint8 gender, uint8 class_) const
{
    if (EmotesTextSoundEntry const* emotesTextSound = Trinity::Containers::MapGetValuePtr(_emoteTextSounds, { emote, race, gender, class_ }))
        return emotesTextSound;

    if (EmotesTextSoundEntry const* emotesTextSound = Trinity::Containers::MapGetValuePtr(_emoteTextSounds, { emote, race, gender, uint8(0) }))
        return emotesTextSound;

    return nullptr;
}

template<float(ExpectedStatModEntry::*field)>
struct ExpectedStatModReducer
{
    explicit ExpectedStatModReducer(int32 mythicPlusMilestoneSeason) : ActiveMilestoneSeason(mythicPlusMilestoneSeason) { }

    float operator()(float mod, ContentTuningXExpectedEntry const* contentTuningXExpected) const
    {
        if (!contentTuningXExpected)
            return mod;

        if (contentTuningXExpected->MinMythicPlusSeasonID)
            if (MythicPlusSeasonEntry const* mythicPlusSeason = sMythicPlusSeasonStore.LookupEntry(contentTuningXExpected->MinMythicPlusSeasonID))
                if (ActiveMilestoneSeason < mythicPlusSeason->MilestoneSeason)
                    return mod;

        if (contentTuningXExpected->MaxMythicPlusSeasonID)
            if (MythicPlusSeasonEntry const* mythicPlusSeason = sMythicPlusSeasonStore.LookupEntry(contentTuningXExpected->MaxMythicPlusSeasonID))
                if (ActiveMilestoneSeason >= mythicPlusSeason->MilestoneSeason)
                    return mod;

        return mod * sExpectedStatModStore.AssertEntry(contentTuningXExpected->ExpectedStatModID)->*field;
    }

    int32 ActiveMilestoneSeason = 0;
};

float DB2Manager::EvaluateExpectedStat(ExpectedStatType stat, uint32 level, int32 expansion, uint32 contentTuningId, Classes unitClass, int32 mythicPlusMilestoneSeason) const
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

    std::vector<ContentTuningXExpectedEntry const*> const* contentTuningMods = Trinity::Containers::MapGetValuePtr(_expectedStatModsByContentTuning, contentTuningId);
    float value = 0.0f;
    switch (stat)
    {
        case ExpectedStatType::CreatureHealth:
            value = expectedStatItr->second->CreatureHealth;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::CreatureHealthMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->CreatureHealthMod;
            break;
        case ExpectedStatType::PlayerHealth:
            value = expectedStatItr->second->PlayerHealth;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::PlayerHealthMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->PlayerHealthMod;
            break;
        case ExpectedStatType::CreatureAutoAttackDps:
            value = expectedStatItr->second->CreatureAutoAttackDps;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::CreatureAutoAttackDPSMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->CreatureAutoAttackDPSMod;
            break;
        case ExpectedStatType::CreatureArmor:
            value = expectedStatItr->second->CreatureArmor;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::CreatureArmorMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->CreatureArmorMod;
            break;
        case ExpectedStatType::PlayerMana:
            value = expectedStatItr->second->PlayerMana;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::PlayerManaMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->PlayerManaMod;
            break;
        case ExpectedStatType::PlayerPrimaryStat:
            value = expectedStatItr->second->PlayerPrimaryStat;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::PlayerPrimaryStatMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->PlayerPrimaryStatMod;
            break;
        case ExpectedStatType::PlayerSecondaryStat:
            value = expectedStatItr->second->PlayerSecondaryStat;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::PlayerSecondaryStatMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->PlayerSecondaryStatMod;
            break;
        case ExpectedStatType::ArmorConstant:
            value = expectedStatItr->second->ArmorConstant;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::ArmorConstantMod>(mythicPlusMilestoneSeason));
            if (classMod)
                value *= classMod->ArmorConstantMod;
            break;
        case ExpectedStatType::None:
            break;
        case ExpectedStatType::CreatureSpellDamage:
            value = expectedStatItr->second->CreatureSpellDamage;
            if (contentTuningMods)
                value *= std::accumulate(contentTuningMods->begin(), contentTuningMods->end(), 1.0f,
                    ExpectedStatModReducer<&ExpectedStatModEntry::CreatureSpellDamageMod>(mythicPlusMilestoneSeason));
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
    return Trinity::Containers::MapGetValuePtr(_factionTeams, faction);
}

DB2Manager::FriendshipRepReactionSet const* DB2Manager::GetFriendshipRepReactions(uint32 friendshipRepID) const
{
    return Trinity::Containers::MapGetValuePtr(_friendshipRepReactions, friendshipRepID);
}

uint32 DB2Manager::GetGlobalCurveId(GlobalCurve globalCurveType) const
{
    for (GlobalCurveEntry const* globalCurveEntry : sGlobalCurveStore)
        if (GlobalCurve(globalCurveEntry->Type) == globalCurveType)
            return globalCurveEntry->CurveID;

    return 0;
}

std::vector<uint32> const* DB2Manager::GetGlyphBindableSpells(uint32 glyphPropertiesId) const
{
    return Trinity::Containers::MapGetValuePtr(_glyphBindableSpells, glyphPropertiesId);
}

std::vector<ChrSpecialization> const* DB2Manager::GetGlyphRequiredSpecs(uint32 glyphPropertiesId) const
{
    return Trinity::Containers::MapGetValuePtr(_glyphRequiredSpecs, glyphPropertiesId);
}

HeirloomEntry const* DB2Manager::GetHeirloomByItemId(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_heirlooms, itemId);
}

ItemChildEquipmentEntry const* DB2Manager::GetItemChildEquipment(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_itemChildEquipment, itemId);
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
    return Trinity::Containers::MapGetValuePtr(_itemCategoryConditions, categoryId);
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
    return Trinity::Containers::MapGetValuePtr(_itemModifiedAppearancesByItem, itemId);
}

std::vector<ItemSetSpellEntry const*> const* DB2Manager::GetItemSetSpells(uint32 itemSetId) const
{
    return Trinity::Containers::MapGetValuePtr(_itemSetSpells, itemSetId);
}

std::vector<ItemSpecOverrideEntry const*> const* DB2Manager::GetItemSpecOverrides(uint32 itemId) const
{
    return Trinity::Containers::MapGetValuePtr(_itemSpecOverrides, itemId);
}

JournalTierEntry const* DB2Manager::GetJournalTier(uint32 index) const
{
    if (index < _journalTiersByIndex.size())
        return _journalTiersByIndex[index];
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

DB2Manager::MapDifficultyConditionsContainer const* DB2Manager::GetMapDifficultyConditions(uint32 mapDifficultyId) const
{
    return Trinity::Containers::MapGetValuePtr(_mapDifficultyConditions, mapDifficultyId);
}

MountEntry const* DB2Manager::GetMount(uint32 spellId) const
{
    return Trinity::Containers::MapGetValuePtr(_mountsBySpellId, spellId);
}

MountEntry const* DB2Manager::GetMountById(uint32 id) const
{
    return sMountStore.LookupEntry(id);
}

DB2Manager::MountTypeXCapabilitySet const* DB2Manager::GetMountCapabilities(uint32 mountType) const
{
    return Trinity::Containers::MapGetValuePtr(_mountCapabilitiesByType, mountType);
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

ParagonReputationEntry const* DB2Manager::GetParagonReputation(uint32 factionId) const
{
    return Trinity::Containers::MapGetValuePtr(_paragonReputations, factionId);
}

PathDb2 const* DB2Manager::GetPath(uint32 pathId) const
{
    return Trinity::Containers::MapGetValuePtr(_paths, pathId);
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

std::vector<QuestLineXQuestEntry const*> const* DB2Manager::GetQuestsForQuestLine(uint32 questLineId) const
{
    return Trinity::Containers::MapGetValuePtr(_questsByQuestLine, questLineId);
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
    return Trinity::Containers::MapGetValuePtr(_phasesByGroup, group);
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
        strToLower(powerName);
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
    return Trinity::Containers::MapGetValuePtr(_rewardPackCurrencyTypes, rewardPackID);
}

std::vector<RewardPackXItemEntry const*> const* DB2Manager::GetRewardPackItemsByRewardID(uint32 rewardPackID) const
{
    return Trinity::Containers::MapGetValuePtr(_rewardPackItems, rewardPackID);
}

ShapeshiftFormModelData const* DB2Manager::GetShapeshiftFormModelData(uint8 race, uint8 gender, uint8 form) const
{
    return Trinity::Containers::MapGetValuePtr(_chrCustomizationChoicesForShapeshifts, { race, gender, form });
}

std::vector<SkillLineEntry const*> const* DB2Manager::GetSkillLinesForParentSkill(uint32 parentSkillId) const
{
    return Trinity::Containers::MapGetValuePtr(_skillLinesByParentSkillLine, parentSkillId);
}

std::vector<SkillLineAbilityEntry const*> const* DB2Manager::GetSkillLineAbilitiesBySkill(uint32 skillId) const
{
    return Trinity::Containers::MapGetValuePtr(_skillLineAbilitiesBySkillupSkill, skillId);
}

SkillRaceClassInfoEntry const* DB2Manager::GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_) const
{
    for (auto&& [_, skllRaceClassInfo] : Trinity::Containers::MapEqualRange(_skillRaceClassInfoBySkill, skill))
    {
        if (!skllRaceClassInfo->RaceMask.IsEmpty() && !(skllRaceClassInfo->RaceMask.HasRace(race)))
            continue;
        if (skllRaceClassInfo->ClassMask && !(skllRaceClassInfo->ClassMask & (1 << (class_ - 1))))
            continue;

        return skllRaceClassInfo;
    }

    return nullptr;
}

std::vector<SkillRaceClassInfoEntry const*> DB2Manager::GetSkillRaceClassInfo(uint32 skill) const
{
    std::vector<SkillRaceClassInfoEntry const*> result;
    for (auto const& [_, skillRaceClassInfo] : Trinity::Containers::MapEqualRange(_skillRaceClassInfoBySkill, skill))
        result.push_back(skillRaceClassInfo);

    return result;
}

SoulbindConduitRankEntry const* DB2Manager::GetSoulbindConduitRank(int32 soulbindConduitId, int32 rank) const
{
    return Trinity::Containers::MapGetValuePtr(_soulbindConduitRanks, { soulbindConduitId, rank });
}

std::vector<SpecializationSpellsEntry const*> const* DB2Manager::GetSpecializationSpells(uint32 specId) const
{
    return Trinity::Containers::MapGetValuePtr(_specializationSpellsBySpec, specId);
}

bool DB2Manager::IsSpecSetMember(int32 specSetId, uint32 specId) const
{
    return _specsBySpecSet.count(std::make_pair(specSetId, specId)) > 0;
}

bool DB2Manager::IsValidSpellFamiliyName(SpellFamilyNames family)
{
    return _spellFamilyNames.count(family) > 0;
}

std::vector<SpellProcsPerMinuteModEntry const*> DB2Manager::GetSpellProcsPerMinuteMods(uint32 spellprocsPerMinuteId) const
{
    auto itr = _spellProcsPerMinuteMods.find(spellprocsPerMinuteId);
    if (itr != _spellProcsPerMinuteMods.end())
        return itr->second;

    return std::vector<SpellProcsPerMinuteModEntry const*>();
}

std::vector<SpellVisualMissileEntry const*> const* DB2Manager::GetSpellVisualMissiles(int32 spellVisualMissileSetId) const
{
    return Trinity::Containers::MapGetValuePtr(_spellVisualMissilesBySet, spellVisualMissileSetId);
}

std::vector<TalentEntry const*> const& DB2Manager::GetTalentsByPosition(uint32 class_, uint32 tier, uint32 column) const
{
    return _talentsByPosition[class_][tier][column];
}

TaxiPathEntry const* DB2Manager::GetTaxiPath(uint32 from, uint32 to) const
{
    return Trinity::Containers::MapGetValuePtr(_taxiPaths, { from, to });
}

bool DB2Manager::IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId, bool requireAllTotems /*= true*/)
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

    int32 sharedMask = itemEntry->TotemCategoryMask & reqEntry->TotemCategoryMask;
    return requireAllTotems ? sharedMask == reqEntry->TotemCategoryMask : sharedMask != 0;
}

bool DB2Manager::IsToyItem(uint32 toy) const
{
    return _toys.count(toy) > 0;
}

TransmogIllusionEntry const* DB2Manager::GetTransmogIllusionForEnchantment(uint32 spellItemEnchantmentId) const
{
    return Trinity::Containers::MapGetValuePtr(_transmogIllusionsByEnchantmentId, spellItemEnchantmentId);
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
        // x and y are swapped
        ((1.0f - (1.0f - relativePosition.Y)) * uiMapAssignment->UiMin.X) + ((1.0f - relativePosition.Y) * uiMapAssignment->UiMax.X),
        ((1.0f - (1.0f - relativePosition.X)) * uiMapAssignment->UiMin.Y) + ((1.0f - relativePosition.X) * uiMapAssignment->UiMax.Y)
    };

    if (!local)
        uiPosition = CalculateGlobalUiMapPosition(uiMapAssignment->UiMapID, uiPosition);

    if (newPos)
        *newPos = uiPosition;

    return true;
}

bool DB2Manager::Zone2MapCoordinates(uint32 areaId, float& x, float& y) const
{
    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);
    if (!areaEntry)
        return false;

    for (auto assignment : Trinity::Containers::MapEqualRange(_uiMapAssignmentByArea[UI_MAP_SYSTEM_WORLD], areaId))
    {
        if (assignment.second->MapID >= 0 && assignment.second->MapID != areaEntry->ContinentID)
            continue;

        float tmpY = (y - assignment.second->UiMax.Y) / (assignment.second->UiMin.Y - assignment.second->UiMax.Y);
        float tmpX = (x - assignment.second->UiMax.X) / (assignment.second->UiMin.X - assignment.second->UiMax.X);
        x = assignment.second->Region[0].X + tmpY * (assignment.second->Region[1].X - assignment.second->Region[0].X);
        y = assignment.second->Region[0].Y + tmpX * (assignment.second->Region[1].Y - assignment.second->Region[0].Y);

        return true;
    }

    return false;
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

std::unordered_set<uint32> const* DB2Manager::GetPVPStatIDsForMap(uint32 mapId) const
{
    return Trinity::Containers::MapGetValuePtr(_pvpStatIdsByMap, mapId);
}

bool ChrClassesXPowerTypesEntryComparator::Compare(ChrClassesXPowerTypesEntry const* left, ChrClassesXPowerTypesEntry const* right)
{
    if (left->ClassID != right->ClassID)
        return left->ClassID < right->ClassID;
    return left->PowerType < right->PowerType;
}

TaxiMask::TaxiMask()
{
    if (sTaxiNodesStore.GetNumRows())
    {
        _data.resize((sTaxiNodesStore.GetNumRows() + (8 * sizeof(uint64) - 1)) / (8 * sizeof(uint64)) * (sizeof(uint64) / sizeof(value_type)), 0);
        ASSERT((_data.size() % 8) == 0, "TaxiMask size must be aligned to a multiple of uint64");
    }
}

bool DB2Manager::FriendshipRepReactionEntryComparator::Compare(FriendshipRepReactionEntry const* left, FriendshipRepReactionEntry const* right)
{
    return left->ReactionThreshold < right->ReactionThreshold;
}

bool DB2Manager::MountTypeXCapabilityEntryComparator::Compare(MountTypeXCapabilityEntry const* left, MountTypeXCapabilityEntry const* right)
{
    if (left->MountTypeID == right->MountTypeID)
        return left->OrderIndex < right->OrderIndex;
    return left->MountTypeID < right->MountTypeID;
}
