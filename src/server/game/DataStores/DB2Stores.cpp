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

#include "DB2Stores.h"
#include "Common.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Metadata.h"
#include "Log.h"
#include "TransportMgr.h"
#include "World.h"

DB2Storage<AchievementEntry>                    sAchievementStore("Achievement.db2", AchievementMeta::Instance(), HOTFIX_SEL_ACHIEVEMENT);
DB2Storage<AnimKitEntry>                        sAnimKitStore("AnimKit.db2", AnimKitMeta::Instance(), HOTFIX_SEL_ANIM_KIT);
DB2Storage<AreaGroupMemberEntry>                sAreaGroupMemberStore("AreaGroupMember.db2", AreaGroupMemberMeta::Instance(), HOTFIX_SEL_AREA_GROUP_MEMBER);
DB2Storage<AreaTableEntry>                      sAreaTableStore("AreaTable.db2", AreaTableMeta::Instance(), HOTFIX_SEL_AREA_TABLE);
DB2Storage<AreaTriggerEntry>                    sAreaTriggerStore("AreaTrigger.db2", AreaTriggerMeta::Instance(), HOTFIX_SEL_AREA_TRIGGER);
DB2Storage<ArmorLocationEntry>                  sArmorLocationStore("ArmorLocation.db2", ArmorLocationMeta::Instance(), HOTFIX_SEL_ARMOR_LOCATION);
DB2Storage<ArtifactEntry>                       sArtifactStore("Artifact.db2", ArtifactMeta::Instance(), HOTFIX_SEL_ARTIFACT);
DB2Storage<ArtifactAppearanceEntry>             sArtifactAppearanceStore("ArtifactAppearance.db2", ArtifactAppearanceMeta::Instance(), HOTFIX_SEL_ARTIFACT_APPEARANCE);
DB2Storage<ArtifactAppearanceSetEntry>          sArtifactAppearanceSetStore("ArtifactAppearanceSet.db2", ArtifactAppearanceSetMeta::Instance(), HOTFIX_SEL_ARTIFACT_APPEARANCE_SET);
DB2Storage<ArtifactCategoryEntry>               sArtifactCategoryStore("ArtifactCategory.db2", ArtifactCategoryMeta::Instance(), HOTFIX_SEL_ARTIFACT_CATEGORY);
DB2Storage<ArtifactPowerEntry>                  sArtifactPowerStore("ArtifactPower.db2", ArtifactPowerMeta::Instance(), HOTFIX_SEL_ARTIFACT_POWER);
DB2Storage<ArtifactPowerLinkEntry>              sArtifactPowerLinkStore("ArtifactPowerLink.db2", ArtifactPowerLinkMeta::Instance(), HOTFIX_SEL_ARTIFACT_POWER_LINK);
DB2Storage<ArtifactPowerRankEntry>              sArtifactPowerRankStore("ArtifactPowerRank.db2", ArtifactPowerRankMeta::Instance(), HOTFIX_SEL_ARTIFACT_POWER_RANK);
DB2Storage<ArtifactQuestXPEntry>                sArtifactQuestXPStore("ArtifactQuestXP.db2", ArtifactQuestXPMeta::Instance(), HOTFIX_SEL_ARTIFACT_QUEST_XP);
DB2Storage<AuctionHouseEntry>                   sAuctionHouseStore("AuctionHouse.db2", AuctionHouseMeta::Instance(), HOTFIX_SEL_AUCTION_HOUSE);
DB2Storage<BankBagSlotPricesEntry>              sBankBagSlotPricesStore("BankBagSlotPrices.db2", BankBagSlotPricesMeta::Instance(), HOTFIX_SEL_BANK_BAG_SLOT_PRICES);
DB2Storage<BannedAddOnsEntry>                   sBannedAddOnsStore("BannedAddOns.db2", BannedAddOnsMeta::Instance(), HOTFIX_SEL_BANNED_ADDONS);
DB2Storage<BarberShopStyleEntry>                sBarberShopStyleStore("BarberShopStyle.db2", BarberShopStyleMeta::Instance(), HOTFIX_SEL_BARBER_SHOP_STYLE);
DB2Storage<BattlePetBreedQualityEntry>          sBattlePetBreedQualityStore("BattlePetBreedQuality.db2", BattlePetBreedQualityMeta::Instance(), HOTFIX_SEL_BATTLE_PET_BREED_QUALITY);
DB2Storage<BattlePetBreedStateEntry>            sBattlePetBreedStateStore("BattlePetBreedState.db2", BattlePetBreedStateMeta::Instance(), HOTFIX_SEL_BATTLE_PET_BREED_STATE);
DB2Storage<BattlePetSpeciesEntry>               sBattlePetSpeciesStore("BattlePetSpecies.db2", BattlePetSpeciesMeta::Instance(), HOTFIX_SEL_BATTLE_PET_SPECIES);
DB2Storage<BattlePetSpeciesStateEntry>          sBattlePetSpeciesStateStore("BattlePetSpeciesState.db2", BattlePetSpeciesStateMeta::Instance(), HOTFIX_SEL_BATTLE_PET_SPECIES_STATE);
DB2Storage<BattlemasterListEntry>               sBattlemasterListStore("BattlemasterList.db2", BattlemasterListMeta::Instance(), HOTFIX_SEL_BATTLEMASTER_LIST);
DB2Storage<BroadcastTextEntry>                  sBroadcastTextStore("BroadcastText.db2", BroadcastTextMeta::Instance(), HOTFIX_SEL_BROADCAST_TEXT);
DB2Storage<CharSectionsEntry>                   sCharSectionsStore("CharSections.db2", CharSectionsMeta::Instance(), HOTFIX_SEL_CHAR_SECTIONS);
DB2Storage<CharStartOutfitEntry>                sCharStartOutfitStore("CharStartOutfit.db2", CharStartOutfitMeta::Instance(), HOTFIX_SEL_CHAR_START_OUTFIT);
DB2Storage<CharTitlesEntry>                     sCharTitlesStore("CharTitles.db2", CharTitlesMeta::Instance(), HOTFIX_SEL_CHAR_TITLES);
DB2Storage<ChatChannelsEntry>                   sChatChannelsStore("ChatChannels.db2", ChatChannelsMeta::Instance(), HOTFIX_SEL_CHAT_CHANNELS);
DB2Storage<ChrClassesEntry>                     sChrClassesStore("ChrClasses.db2", ChrClassesMeta::Instance(), HOTFIX_SEL_CHR_CLASSES);
DB2Storage<ChrClassesXPowerTypesEntry>          sChrClassesXPowerTypesStore("ChrClassesXPowerTypes.db2", ChrClassesXPowerTypesMeta::Instance(), HOTFIX_SEL_CHR_CLASSES_X_POWER_TYPES);
DB2Storage<ChrRacesEntry>                       sChrRacesStore("ChrRaces.db2", ChrRacesMeta::Instance(), HOTFIX_SEL_CHR_RACES);
DB2Storage<ChrSpecializationEntry>              sChrSpecializationStore("ChrSpecialization.db2", ChrSpecializationMeta::Instance(), HOTFIX_SEL_CHR_SPECIALIZATION);
DB2Storage<CinematicSequencesEntry>             sCinematicSequencesStore("CinematicSequences.db2", CinematicSequencesMeta::Instance(), HOTFIX_SEL_CINEMATIC_SEQUENCES);
DB2Storage<CreatureDisplayInfoEntry>            sCreatureDisplayInfoStore("CreatureDisplayInfo.db2", CreatureDisplayInfoMeta::Instance(), HOTFIX_SEL_CREATURE_DISPLAY_INFO);
DB2Storage<CreatureDisplayInfoExtraEntry>       sCreatureDisplayInfoExtraStore("CreatureDisplayInfoExtra.db2", CreatureDisplayInfoExtraMeta::Instance(), HOTFIX_SEL_CREATURE_DISPLAY_INFO_EXTRA);
DB2Storage<CreatureFamilyEntry>                 sCreatureFamilyStore("CreatureFamily.db2", CreatureFamilyMeta::Instance(), HOTFIX_SEL_CREATURE_FAMILY);
DB2Storage<CreatureModelDataEntry>              sCreatureModelDataStore("CreatureModelData.db2", CreatureModelDataMeta::Instance(), HOTFIX_SEL_CREATURE_MODEL_DATA);
DB2Storage<CreatureTypeEntry>                   sCreatureTypeStore("CreatureType.db2", CreatureTypeMeta::Instance(), HOTFIX_SEL_CREATURE_TYPE);
DB2Storage<CriteriaEntry>                       sCriteriaStore("Criteria.db2", CriteriaMeta::Instance(), HOTFIX_SEL_CRITERIA);
DB2Storage<CriteriaTreeEntry>                   sCriteriaTreeStore("CriteriaTree.db2", CriteriaTreeMeta::Instance(), HOTFIX_SEL_CRITERIA_TREE);
DB2Storage<CurrencyTypesEntry>                  sCurrencyTypesStore("CurrencyTypes.db2", CurrencyTypesMeta::Instance(), HOTFIX_SEL_CURRENCY_TYPES);
DB2Storage<CurveEntry>                          sCurveStore("Curve.db2", CurveMeta::Instance(), HOTFIX_SEL_CURVE);
DB2Storage<CurvePointEntry>                     sCurvePointStore("CurvePoint.db2", CurvePointMeta::Instance(), HOTFIX_SEL_CURVE_POINT);
DB2Storage<DestructibleModelDataEntry>          sDestructibleModelDataStore("DestructibleModelData.db2", DestructibleModelDataMeta::Instance(), HOTFIX_SEL_DESTRUCTIBLE_MODEL_DATA);
DB2Storage<DifficultyEntry>                     sDifficultyStore("Difficulty.db2", DifficultyMeta::Instance(), HOTFIX_SEL_DIFFICULTY);
DB2Storage<DungeonEncounterEntry>               sDungeonEncounterStore("DungeonEncounter.db2", DungeonEncounterMeta::Instance(), HOTFIX_SEL_DUNGEON_ENCOUNTER);
DB2Storage<DurabilityCostsEntry>                sDurabilityCostsStore("DurabilityCosts.db2", DurabilityCostsMeta::Instance(), HOTFIX_SEL_DURABILITY_COSTS);
DB2Storage<DurabilityQualityEntry>              sDurabilityQualityStore("DurabilityQuality.db2", DurabilityQualityMeta::Instance(), HOTFIX_SEL_DURABILITY_QUALITY);
DB2Storage<EmotesEntry>                         sEmotesStore("Emotes.db2", EmotesMeta::Instance(), HOTFIX_SEL_EMOTES);
DB2Storage<EmotesTextEntry>                     sEmotesTextStore("EmotesText.db2", EmotesTextMeta::Instance(), HOTFIX_SEL_EMOTES_TEXT);
DB2Storage<EmotesTextSoundEntry>                sEmotesTextSoundStore("EmotesTextSound.db2", EmotesTextSoundMeta::Instance(), HOTFIX_SEL_EMOTES_TEXT_SOUND);
DB2Storage<FactionEntry>                        sFactionStore("Faction.db2", FactionMeta::Instance(), HOTFIX_SEL_FACTION);
DB2Storage<FactionTemplateEntry>                sFactionTemplateStore("FactionTemplate.db2", FactionTemplateMeta::Instance(), HOTFIX_SEL_FACTION_TEMPLATE);
DB2Storage<GameObjectsEntry>                    sGameObjectsStore("GameObjects.db2", GameObjectsMeta::Instance(), HOTFIX_SEL_GAMEOBJECTS);
DB2Storage<GameObjectDisplayInfoEntry>          sGameObjectDisplayInfoStore("GameObjectDisplayInfo.db2", GameObjectDisplayInfoMeta::Instance(), HOTFIX_SEL_GAMEOBJECT_DISPLAY_INFO);
DB2Storage<GarrAbilityEntry>                    sGarrAbilityStore("GarrAbility.db2", GarrAbilityMeta::Instance(), HOTFIX_SEL_GARR_ABILITY);
DB2Storage<GarrBuildingEntry>                   sGarrBuildingStore("GarrBuilding.db2", GarrBuildingMeta::Instance(), HOTFIX_SEL_GARR_BUILDING);
DB2Storage<GarrBuildingPlotInstEntry>           sGarrBuildingPlotInstStore("GarrBuildingPlotInst.db2", GarrBuildingPlotInstMeta::Instance(), HOTFIX_SEL_GARR_BUILDING_PLOT_INST);
DB2Storage<GarrClassSpecEntry>                  sGarrClassSpecStore("GarrClassSpec.db2", GarrClassSpecMeta::Instance(), HOTFIX_SEL_GARR_CLASS_SPEC);
DB2Storage<GarrFollowerEntry>                   sGarrFollowerStore("GarrFollower.db2", GarrFollowerMeta::Instance(), HOTFIX_SEL_GARR_FOLLOWER);
DB2Storage<GarrFollowerXAbilityEntry>           sGarrFollowerXAbilityStore("GarrFollowerXAbility.db2", GarrFollowerXAbilityMeta::Instance(), HOTFIX_SEL_GARR_FOLLOWER_X_ABILITY);
DB2Storage<GarrPlotBuildingEntry>               sGarrPlotBuildingStore("GarrPlotBuilding.db2", GarrPlotBuildingMeta::Instance(), HOTFIX_SEL_GARR_PLOT_BUILDING);
DB2Storage<GarrPlotEntry>                       sGarrPlotStore("GarrPlot.db2", GarrPlotMeta::Instance(), HOTFIX_SEL_GARR_PLOT);
DB2Storage<GarrPlotInstanceEntry>               sGarrPlotInstanceStore("GarrPlotInstance.db2", GarrPlotInstanceMeta::Instance(), HOTFIX_SEL_GARR_PLOT_INSTANCE);
DB2Storage<GarrSiteLevelEntry>                  sGarrSiteLevelStore("GarrSiteLevel.db2", GarrSiteLevelMeta::Instance(), HOTFIX_SEL_GARR_SITE_LEVEL);
DB2Storage<GarrSiteLevelPlotInstEntry>          sGarrSiteLevelPlotInstStore("GarrSiteLevelPlotInst.db2", GarrSiteLevelPlotInstMeta::Instance(), HOTFIX_SEL_GARR_SITE_LEVEL_PLOT_INST);
DB2Storage<GemPropertiesEntry>                  sGemPropertiesStore("GemProperties.db2", GemPropertiesMeta::Instance(), HOTFIX_SEL_GEM_PROPERTIES);
DB2Storage<GlyphBindableSpellEntry>             sGlyphBindableSpellStore("GlyphBindableSpell.db2", GlyphBindableSpellMeta::Instance(), HOTFIX_SEL_GLYPH_BINDABLE_SPELL);
DB2Storage<GlyphPropertiesEntry>                sGlyphPropertiesStore("GlyphProperties.db2", GlyphPropertiesMeta::Instance(), HOTFIX_SEL_GLYPH_PROPERTIES);
DB2Storage<GlyphRequiredSpecEntry>              sGlyphRequiredSpecStore("GlyphRequiredSpec.db2", GlyphRequiredSpecMeta::Instance(), HOTFIX_SEL_GLYPH_REQUIRED_SPEC);
DB2Storage<GuildColorBackgroundEntry>           sGuildColorBackgroundStore("GuildColorBackground.db2", GuildColorBackgroundMeta::Instance(), HOTFIX_SEL_GUILD_COLOR_BACKGROUND);
DB2Storage<GuildColorBorderEntry>               sGuildColorBorderStore("GuildColorBorder.db2", GuildColorBorderMeta::Instance(), HOTFIX_SEL_GUILD_COLOR_BORDER);
DB2Storage<GuildColorEmblemEntry>               sGuildColorEmblemStore("GuildColorEmblem.db2", GuildColorEmblemMeta::Instance(), HOTFIX_SEL_GUILD_COLOR_EMBLEM);
DB2Storage<GuildPerkSpellsEntry>                sGuildPerkSpellsStore("GuildPerkSpells.db2", GuildPerkSpellsMeta::Instance(), HOTFIX_SEL_GUILD_PERK_SPELLS);
DB2Storage<HeirloomEntry>                       sHeirloomStore("Heirloom.db2", HeirloomMeta::Instance(), HOTFIX_SEL_HEIRLOOM);
DB2Storage<HolidaysEntry>                       sHolidaysStore("Holidays.db2", HolidaysMeta::Instance(), HOTFIX_SEL_HOLIDAYS);
DB2Storage<ImportPriceArmorEntry>               sImportPriceArmorStore("ImportPriceArmor.db2", ImportPriceArmorMeta::Instance(), HOTFIX_SEL_IMPORT_PRICE_ARMOR);
DB2Storage<ImportPriceQualityEntry>             sImportPriceQualityStore("ImportPriceQuality.db2", ImportPriceQualityMeta::Instance(), HOTFIX_SEL_IMPORT_PRICE_QUALITY);
DB2Storage<ImportPriceShieldEntry>              sImportPriceShieldStore("ImportPriceShield.db2", ImportPriceShieldMeta::Instance(), HOTFIX_SEL_IMPORT_PRICE_SHIELD);
DB2Storage<ImportPriceWeaponEntry>              sImportPriceWeaponStore("ImportPriceWeapon.db2", ImportPriceWeaponMeta::Instance(), HOTFIX_SEL_IMPORT_PRICE_WEAPON);
DB2Storage<ItemAppearanceEntry>                 sItemAppearanceStore("ItemAppearance.db2", ItemAppearanceMeta::Instance(), HOTFIX_SEL_ITEM_APPEARANCE);
DB2Storage<ItemArmorQualityEntry>               sItemArmorQualityStore("ItemArmorQuality.db2", ItemArmorQualityMeta::Instance(), HOTFIX_SEL_ITEM_ARMOR_QUALITY);
DB2Storage<ItemArmorShieldEntry>                sItemArmorShieldStore("ItemArmorShield.db2", ItemArmorShieldMeta::Instance(), HOTFIX_SEL_ITEM_ARMOR_SHIELD);
DB2Storage<ItemArmorTotalEntry>                 sItemArmorTotalStore("ItemArmorTotal.db2", ItemArmorTotalMeta::Instance(), HOTFIX_SEL_ITEM_ARMOR_TOTAL);
DB2Storage<ItemBagFamilyEntry>                  sItemBagFamilyStore("ItemBagFamily.db2", ItemBagFamilyMeta::Instance(), HOTFIX_SEL_ITEM_BAG_FAMILY);
DB2Storage<ItemBonusEntry>                      sItemBonusStore("ItemBonus.db2", ItemBonusMeta::Instance(), HOTFIX_SEL_ITEM_BONUS);
DB2Storage<ItemBonusListLevelDeltaEntry>        sItemBonusListLevelDeltaStore("ItemBonusListLevelDelta.db2", ItemBonusListLevelDeltaMeta::Instance(), HOTFIX_SEL_ITEM_BONUS_LIST_LEVEL_DELTA);
DB2Storage<ItemBonusTreeNodeEntry>              sItemBonusTreeNodeStore("ItemBonusTreeNode.db2", ItemBonusTreeNodeMeta::Instance(), HOTFIX_SEL_ITEM_BONUS_TREE_NODE);
DB2Storage<ItemChildEquipmentEntry>             sItemChildEquipmentStore("ItemChildEquipment.db2", ItemChildEquipmentMeta::Instance(), HOTFIX_SEL_ITEM_CHILD_EQUIPMENT);
DB2Storage<ItemClassEntry>                      sItemClassStore("ItemClass.db2", ItemClassMeta::Instance(), HOTFIX_SEL_ITEM_CLASS);
DB2Storage<ItemCurrencyCostEntry>               sItemCurrencyCostStore("ItemCurrencyCost.db2", ItemCurrencyCostMeta::Instance(), HOTFIX_SEL_ITEM_CURRENCY_COST);
DB2Storage<ItemDamageAmmoEntry>                 sItemDamageAmmoStore("ItemDamageAmmo.db2", ItemDamageAmmoMeta::Instance(), HOTFIX_SEL_ITEM_DAMAGE_AMMO);
DB2Storage<ItemDamageOneHandEntry>              sItemDamageOneHandStore("ItemDamageOneHand.db2", ItemDamageOneHandMeta::Instance(), HOTFIX_SEL_ITEM_DAMAGE_ONE_HAND);
DB2Storage<ItemDamageOneHandCasterEntry>        sItemDamageOneHandCasterStore("ItemDamageOneHandCaster.db2", ItemDamageOneHandCasterMeta::Instance(), HOTFIX_SEL_ITEM_DAMAGE_ONE_HAND_CASTER);
DB2Storage<ItemDamageTwoHandEntry>              sItemDamageTwoHandStore("ItemDamageTwoHand.db2", ItemDamageTwoHandMeta::Instance(), HOTFIX_SEL_ITEM_DAMAGE_TWO_HAND);
DB2Storage<ItemDamageTwoHandCasterEntry>        sItemDamageTwoHandCasterStore("ItemDamageTwoHandCaster.db2", ItemDamageTwoHandCasterMeta::Instance(), HOTFIX_SEL_ITEM_DAMAGE_TWO_HAND_CASTER);
DB2Storage<ItemDisenchantLootEntry>             sItemDisenchantLootStore("ItemDisenchantLoot.db2", ItemDisenchantLootMeta::Instance(), HOTFIX_SEL_ITEM_DISENCHANT_LOOT);
DB2Storage<ItemEffectEntry>                     sItemEffectStore("ItemEffect.db2", ItemEffectMeta::Instance(), HOTFIX_SEL_ITEM_EFFECT);
DB2Storage<ItemEntry>                           sItemStore("Item.db2", ItemMeta::Instance(), HOTFIX_SEL_ITEM);
DB2Storage<ItemExtendedCostEntry>               sItemExtendedCostStore("ItemExtendedCost.db2", ItemExtendedCostMeta::Instance(), HOTFIX_SEL_ITEM_EXTENDED_COST);
DB2Storage<ItemLimitCategoryEntry>              sItemLimitCategoryStore("ItemLimitCategory.db2", ItemLimitCategoryMeta::Instance(), HOTFIX_SEL_ITEM_LIMIT_CATEGORY);
DB2Storage<ItemModifiedAppearanceEntry>         sItemModifiedAppearanceStore("ItemModifiedAppearance.db2", ItemModifiedAppearanceMeta::Instance(), HOTFIX_SEL_ITEM_MODIFIED_APPEARANCE);
DB2Storage<ItemPriceBaseEntry>                  sItemPriceBaseStore("ItemPriceBase.db2", ItemPriceBaseMeta::Instance(), HOTFIX_SEL_ITEM_PRICE_BASE);
DB2Storage<ItemRandomPropertiesEntry>           sItemRandomPropertiesStore("ItemRandomProperties.db2", ItemRandomPropertiesMeta::Instance(), HOTFIX_SEL_ITEM_RANDOM_PROPERTIES);
DB2Storage<ItemRandomSuffixEntry>               sItemRandomSuffixStore("ItemRandomSuffix.db2", ItemRandomSuffixMeta::Instance(), HOTFIX_SEL_ITEM_RANDOM_SUFFIX);
DB2Storage<ItemSearchNameEntry>                 sItemSearchNameStore("ItemSearchName.db2", ItemSearchNameMeta::Instance(), HOTFIX_SEL_ITEM_SEARCH_NAME);
DB2Storage<ItemSetEntry>                        sItemSetStore("ItemSet.db2", ItemSetMeta::Instance(), HOTFIX_SEL_ITEM_SET);
DB2Storage<ItemSetSpellEntry>                   sItemSetSpellStore("ItemSetSpell.db2", ItemSetSpellMeta::Instance(), HOTFIX_SEL_ITEM_SET_SPELL);
DB2Storage<ItemSparseEntry>                     sItemSparseStore("Item-sparse.db2", ItemSparseMeta::Instance(), HOTFIX_SEL_ITEM_SPARSE);
DB2Storage<ItemSpecEntry>                       sItemSpecStore("ItemSpec.db2", ItemSpecMeta::Instance(), HOTFIX_SEL_ITEM_SPEC);
DB2Storage<ItemSpecOverrideEntry>               sItemSpecOverrideStore("ItemSpecOverride.db2", ItemSpecOverrideMeta::Instance(), HOTFIX_SEL_ITEM_SPEC_OVERRIDE);
DB2Storage<ItemUpgradeEntry>                    sItemUpgradeStore("ItemUpgrade.db2", ItemUpgradeMeta::Instance(), HOTFIX_SEL_ITEM_UPGRADE);
DB2Storage<ItemXBonusTreeEntry>                 sItemXBonusTreeStore("ItemXBonusTree.db2", ItemXBonusTreeMeta::Instance(), HOTFIX_SEL_ITEM_X_BONUS_TREE);
DB2Storage<KeyChainEntry>                       sKeyChainStore("KeyChain.db2", KeyChainMeta::Instance(), HOTFIX_SEL_KEY_CHAIN);
DB2Storage<LfgDungeonsEntry>                    sLfgDungeonsStore("LfgDungeons.db2", LfgDungeonsMeta::Instance(), HOTFIX_SEL_LFG_DUNGEONS);
DB2Storage<LightEntry>                          sLightStore("Light.db2", LightMeta::Instance(), HOTFIX_SEL_LIGHT);
DB2Storage<LiquidTypeEntry>                     sLiquidTypeStore("LiquidType.db2", LiquidTypeMeta::Instance(), HOTFIX_SEL_LIQUID_TYPE);
DB2Storage<LockEntry>                           sLockStore("Lock.db2", LockMeta::Instance(), HOTFIX_SEL_LOCK);
DB2Storage<MailTemplateEntry>                   sMailTemplateStore("MailTemplate.db2", MailTemplateMeta::Instance(), HOTFIX_SEL_MAIL_TEMPLATE);
DB2Storage<MapEntry>                            sMapStore("Map.db2", MapMeta::Instance(), HOTFIX_SEL_MAP);
DB2Storage<MapDifficultyEntry>                  sMapDifficultyStore("MapDifficulty.db2", MapDifficultyMeta::Instance(), HOTFIX_SEL_MAP_DIFFICULTY);
DB2Storage<ModifierTreeEntry>                   sModifierTreeStore("ModifierTree.db2", ModifierTreeMeta::Instance(), HOTFIX_SEL_MODIFIER_TREE);
DB2Storage<MountCapabilityEntry>                sMountCapabilityStore("MountCapability.db2", MountCapabilityMeta::Instance(), HOTFIX_SEL_MOUNT_CAPABILITY);
DB2Storage<MountEntry>                          sMountStore("Mount.db2", MountMeta::Instance(), HOTFIX_SEL_MOUNT);
DB2Storage<MountTypeXCapabilityEntry>           sMountTypeXCapabilityStore("MountTypeXCapability.db2", MountTypeXCapabilityMeta::Instance(), HOTFIX_SEL_MOUNT_TYPE_X_CAPABILITY);
DB2Storage<MovieEntry>                          sMovieStore("Movie.db2", MovieMeta::Instance(), HOTFIX_SEL_MOVIE);
DB2Storage<NameGenEntry>                        sNameGenStore("NameGen.db2", NameGenMeta::Instance(), HOTFIX_SEL_NAME_GEN);
DB2Storage<NamesProfanityEntry>                 sNamesProfanityStore("NamesProfanity.db2", NamesProfanityMeta::Instance(), HOTFIX_SEL_NAMES_PROFANITY);
DB2Storage<NamesReservedEntry>                  sNamesReservedStore("NamesReserved.db2", NamesReservedMeta::Instance(), HOTFIX_SEL_NAMES_RESERVED);
DB2Storage<NamesReservedLocaleEntry>            sNamesReservedLocaleStore("NamesReservedLocale.db2", NamesReservedLocaleMeta::Instance(), HOTFIX_SEL_NAMES_RESERVED_LOCALE);
DB2Storage<OverrideSpellDataEntry>              sOverrideSpellDataStore("OverrideSpellData.db2", OverrideSpellDataMeta::Instance(), HOTFIX_SEL_OVERRIDE_SPELL_DATA);
DB2Storage<PhaseEntry>                          sPhaseStore("Phase.db2", PhaseMeta::Instance(), HOTFIX_SEL_PHASE);
DB2Storage<PhaseXPhaseGroupEntry>               sPhaseXPhaseGroupStore("PhaseXPhaseGroup.db2", PhaseXPhaseGroupMeta::Instance(), HOTFIX_SEL_PHASE_X_PHASE_GROUP);
DB2Storage<PlayerConditionEntry>                sPlayerConditionStore("PlayerCondition.db2", PlayerConditionMeta::Instance(), HOTFIX_SEL_PLAYER_CONDITION);
DB2Storage<PowerDisplayEntry>                   sPowerDisplayStore("PowerDisplay.db2", PowerDisplayMeta::Instance(), HOTFIX_SEL_POWER_DISPLAY);
DB2Storage<PvPDifficultyEntry>                  sPvpDifficultyStore("PvpDifficulty.db2", PvpDifficultyMeta::Instance(), HOTFIX_SEL_PVP_DIFFICULTY);
DB2Storage<QuestFactionRewardEntry>             sQuestFactionRewardStore("QuestFactionReward.db2", QuestFactionRewardMeta::Instance(), HOTFIX_SEL_QUEST_FACTION_REWARD);
DB2Storage<QuestMoneyRewardEntry>               sQuestMoneyRewardStore("QuestMoneyReward.db2", QuestMoneyRewardMeta::Instance(), HOTFIX_SEL_QUEST_MONEY_REWARD);
DB2Storage<QuestPackageItemEntry>               sQuestPackageItemStore("QuestPackageItem.db2", QuestPackageItemMeta::Instance(), HOTFIX_SEL_QUEST_PACKAGE_ITEM);
DB2Storage<QuestSortEntry>                      sQuestSortStore("QuestSort.db2", QuestSortMeta::Instance(), HOTFIX_SEL_QUEST_SORT);
DB2Storage<QuestV2Entry>                        sQuestV2Store("QuestV2.db2", QuestV2Meta::Instance(), HOTFIX_SEL_QUEST_V2);
DB2Storage<QuestXPEntry>                        sQuestXPStore("QuestXP.db2", QuestXPMeta::Instance(), HOTFIX_SEL_QUEST_XP);
DB2Storage<RandPropPointsEntry>                 sRandPropPointsStore("RandPropPoints.db2", RandPropPointsMeta::Instance(), HOTFIX_SEL_RAND_PROP_POINTS);
DB2Storage<RulesetItemUpgradeEntry>             sRulesetItemUpgradeStore("RulesetItemUpgrade.db2", RulesetItemUpgradeMeta::Instance(), HOTFIX_SEL_RULESET_ITEM_UPGRADE);
DB2Storage<ScalingStatDistributionEntry>        sScalingStatDistributionStore("ScalingStatDistribution.db2", ScalingStatDistributionMeta::Instance(), HOTFIX_SEL_SCALING_STAT_DISTRIBUTION);
DB2Storage<SkillLineEntry>                      sSkillLineStore("SkillLine.db2", SkillLineMeta::Instance(), HOTFIX_SEL_SKILL_LINE);
DB2Storage<SkillLineAbilityEntry>               sSkillLineAbilityStore("SkillLineAbility.db2", SkillLineAbilityMeta::Instance(), HOTFIX_SEL_SKILL_LINE_ABILITY);
DB2Storage<SkillRaceClassInfoEntry>             sSkillRaceClassInfoStore("SkillRaceClassInfo.db2", SkillRaceClassInfoMeta::Instance(), HOTFIX_SEL_SKILL_RACE_CLASS_INFO);
DB2Storage<SoundKitEntry>                       sSoundKitStore("SoundKit.db2", SoundKitMeta::Instance(), HOTFIX_SEL_SOUND_KIT);
DB2Storage<SpecializationSpellsEntry>           sSpecializationSpellsStore("SpecializationSpells.db2", SpecializationSpellsMeta::Instance(), HOTFIX_SEL_SPECIALIZATION_SPELLS);
DB2Storage<SpellEntry>                          sSpellStore("Spell.db2", SpellMeta::Instance(), HOTFIX_SEL_SPELL);
DB2Storage<SpellAuraOptionsEntry>               sSpellAuraOptionsStore("SpellAuraOptions.db2", SpellAuraOptionsMeta::Instance(), HOTFIX_SEL_SPELL_AURA_OPTIONS);
DB2Storage<SpellAuraRestrictionsEntry>          sSpellAuraRestrictionsStore("SpellAuraRestrictions.db2", SpellAuraRestrictionsMeta::Instance(), HOTFIX_SEL_SPELL_AURA_RESTRICTIONS);
DB2Storage<SpellCastTimesEntry>                 sSpellCastTimesStore("SpellCastTimes.db2", SpellCastTimesMeta::Instance(), HOTFIX_SEL_SPELL_CAST_TIMES);
DB2Storage<SpellCastingRequirementsEntry>       sSpellCastingRequirementsStore("SpellCastingRequirements.db2", SpellCastingRequirementsMeta::Instance(), HOTFIX_SEL_SPELL_CASTING_REQUIREMENTS);
DB2Storage<SpellCategoriesEntry>                sSpellCategoriesStore("SpellCategories.db2", SpellCategoriesMeta::Instance(), HOTFIX_SEL_SPELL_CATEGORIES);
DB2Storage<SpellCategoryEntry>                  sSpellCategoryStore("SpellCategory.db2", SpellCategoryMeta::Instance(), HOTFIX_SEL_SPELL_CATEGORY);
DB2Storage<SpellClassOptionsEntry>              sSpellClassOptionsStore("SpellClassOptions.db2", SpellClassOptionsMeta::Instance(), HOTFIX_SEL_SPELL_CLASS_OPTIONS);
DB2Storage<SpellCooldownsEntry>                 sSpellCooldownsStore("SpellCooldowns.db2", SpellCooldownsMeta::Instance(), HOTFIX_SEL_SPELL_COOLDOWNS);
DB2Storage<SpellDurationEntry>                  sSpellDurationStore("SpellDuration.db2", SpellDurationMeta::Instance(), HOTFIX_SEL_SPELL_DURATION);
DB2Storage<SpellEffectEntry>                    sSpellEffectStore("SpellEffect.db2", SpellEffectMeta::Instance(), HOTFIX_SEL_SPELL_EFFECT);
DB2Storage<SpellEffectScalingEntry>             sSpellEffectScalingStore("SpellEffectScaling.db2", SpellEffectScalingMeta::Instance(), HOTFIX_SEL_SPELL_EFFECT_SCALING);
DB2Storage<SpellEquippedItemsEntry>             sSpellEquippedItemsStore("SpellEquippedItems.db2", SpellEquippedItemsMeta::Instance(), HOTFIX_SEL_SPELL_EQUIPPED_ITEMS);
DB2Storage<SpellFocusObjectEntry>               sSpellFocusObjectStore("SpellFocusObject.db2", SpellFocusObjectMeta::Instance(), HOTFIX_SEL_SPELL_FOCUS_OBJECT);
DB2Storage<SpellInterruptsEntry>                sSpellInterruptsStore("SpellInterrupts.db2", SpellInterruptsMeta::Instance(), HOTFIX_SEL_SPELL_INTERRUPTS);
DB2Storage<SpellItemEnchantmentEntry>           sSpellItemEnchantmentStore("SpellItemEnchantment.db2", SpellItemEnchantmentMeta::Instance(), HOTFIX_SEL_SPELL_ITEM_ENCHANTMENT);
DB2Storage<SpellItemEnchantmentConditionEntry>  sSpellItemEnchantmentConditionStore("SpellItemEnchantmentCondition.db2", SpellItemEnchantmentConditionMeta::Instance(), HOTFIX_SEL_SPELL_ITEM_ENCHANTMENT_CONDITION);
DB2Storage<SpellLearnSpellEntry>                sSpellLearnSpellStore("SpellLearnSpell.db2", SpellLearnSpellMeta::Instance(), HOTFIX_SEL_SPELL_LEARN_SPELL);
DB2Storage<SpellLevelsEntry>                    sSpellLevelsStore("SpellLevels.db2", SpellLevelsMeta::Instance(), HOTFIX_SEL_SPELL_LEVELS);
DB2Storage<SpellMiscEntry>                      sSpellMiscStore("SpellMisc.db2", SpellMiscMeta::Instance(), HOTFIX_SEL_SPELL_MISC);
DB2Storage<SpellPowerEntry>                     sSpellPowerStore("SpellPower.db2", SpellPowerMeta::Instance(), HOTFIX_SEL_SPELL_POWER);
DB2Storage<SpellPowerDifficultyEntry>           sSpellPowerDifficultyStore("SpellPowerDifficulty.db2", SpellPowerDifficultyMeta::Instance(), HOTFIX_SEL_SPELL_POWER_DIFFICULTY);
DB2Storage<SpellProcsPerMinuteEntry>            sSpellProcsPerMinuteStore("SpellProcsPerMinute.db2", SpellProcsPerMinuteMeta::Instance(), HOTFIX_SEL_SPELL_PROCS_PER_MINUTE);
DB2Storage<SpellProcsPerMinuteModEntry>         sSpellProcsPerMinuteModStore("SpellProcsPerMinuteMod.db2", SpellProcsPerMinuteModMeta::Instance(), HOTFIX_SEL_SPELL_PROCS_PER_MINUTE_MOD);
DB2Storage<SpellRadiusEntry>                    sSpellRadiusStore("SpellRadius.db2", SpellRadiusMeta::Instance(), HOTFIX_SEL_SPELL_RADIUS);
DB2Storage<SpellRangeEntry>                     sSpellRangeStore("SpellRange.db2", SpellRangeMeta::Instance(), HOTFIX_SEL_SPELL_RANGE);
DB2Storage<SpellReagentsEntry>                  sSpellReagentsStore("SpellReagents.db2", SpellReagentsMeta::Instance(), HOTFIX_SEL_SPELL_REAGENTS);
DB2Storage<SpellScalingEntry>                   sSpellScalingStore("SpellScaling.db2", SpellScalingMeta::Instance(), HOTFIX_SEL_SPELL_SCALING);
DB2Storage<SpellShapeshiftEntry>                sSpellShapeshiftStore("SpellShapeshift.db2", SpellShapeshiftMeta::Instance(), HOTFIX_SEL_SPELL_SHAPESHIFT);
DB2Storage<SpellShapeshiftFormEntry>            sSpellShapeshiftFormStore("SpellShapeshiftForm.db2", SpellShapeshiftFormMeta::Instance(), HOTFIX_SEL_SPELL_SHAPESHIFT_FORM);
DB2Storage<SpellTargetRestrictionsEntry>        sSpellTargetRestrictionsStore("SpellTargetRestrictions.db2", SpellTargetRestrictionsMeta::Instance(), HOTFIX_SEL_SPELL_TARGET_RESTRICTIONS);
DB2Storage<SpellTotemsEntry>                    sSpellTotemsStore("SpellTotems.db2", SpellTotemsMeta::Instance(), HOTFIX_SEL_SPELL_TOTEMS);
DB2Storage<SpellXSpellVisualEntry>              sSpellXSpellVisualStore("SpellXSpellVisual.db2", SpellXSpellVisualMeta::Instance(), HOTFIX_SEL_SPELL_X_SPELL_VISUAL);
DB2Storage<SummonPropertiesEntry>               sSummonPropertiesStore("SummonProperties.db2", SummonPropertiesMeta::Instance(), HOTFIX_SEL_SUMMON_PROPERTIES);
DB2Storage<TactKeyEntry>                        sTactKeyStore("TactKey.db2", TactKeyMeta::Instance(), HOTFIX_SEL_TACT_KEY);
DB2Storage<TalentEntry>                         sTalentStore("Talent.db2", TalentMeta::Instance(), HOTFIX_SEL_TALENT);
DB2Storage<TaxiNodesEntry>                      sTaxiNodesStore("TaxiNodes.db2", TaxiNodesMeta::Instance(), HOTFIX_SEL_TAXI_NODES);
DB2Storage<TaxiPathEntry>                       sTaxiPathStore("TaxiPath.db2", TaxiPathMeta::Instance(), HOTFIX_SEL_TAXI_PATH);
DB2Storage<TaxiPathNodeEntry>                   sTaxiPathNodeStore("TaxiPathNode.db2", TaxiPathNodeMeta::Instance(), HOTFIX_SEL_TAXI_PATH_NODE);
DB2Storage<TotemCategoryEntry>                  sTotemCategoryStore("TotemCategory.db2", TotemCategoryMeta::Instance(), HOTFIX_SEL_TOTEM_CATEGORY);
DB2Storage<ToyEntry>                            sToyStore("Toy.db2", ToyMeta::Instance(), HOTFIX_SEL_TOY);
DB2Storage<TransportAnimationEntry>             sTransportAnimationStore("TransportAnimation.db2", TransportAnimationMeta::Instance(), HOTFIX_SEL_TRANSPORT_ANIMATION);
DB2Storage<TransportRotationEntry>              sTransportRotationStore("TransportRotation.db2", TransportRotationMeta::Instance(), HOTFIX_SEL_TRANSPORT_ROTATION);
DB2Storage<UnitPowerBarEntry>                   sUnitPowerBarStore("UnitPowerBar.db2", UnitPowerBarMeta::Instance(), HOTFIX_SEL_UNIT_POWER_BAR);
DB2Storage<VehicleEntry>                        sVehicleStore("Vehicle.db2", VehicleMeta::Instance(), HOTFIX_SEL_VEHICLE);
DB2Storage<VehicleSeatEntry>                    sVehicleSeatStore("VehicleSeat.db2", VehicleSeatMeta::Instance(), HOTFIX_SEL_VEHICLE_SEAT);
DB2Storage<WMOAreaTableEntry>                   sWMOAreaTableStore("WMOAreaTable.db2", WMOAreaTableMeta::Instance(), HOTFIX_SEL_WMO_AREA_TABLE);
DB2Storage<WorldMapAreaEntry>                   sWorldMapAreaStore("WorldMapArea.db2", WorldMapAreaMeta::Instance(), HOTFIX_SEL_WORLD_MAP_AREA);
DB2Storage<WorldMapOverlayEntry>                sWorldMapOverlayStore("WorldMapOverlay.db2", WorldMapOverlayMeta::Instance(), HOTFIX_SEL_WORLD_MAP_OVERLAY);
DB2Storage<WorldMapTransformsEntry>             sWorldMapTransformsStore("WorldMapTransforms.db2", WorldMapTransformsMeta::Instance(), HOTFIX_SEL_WORLD_MAP_TRANSFORMS);
DB2Storage<WorldSafeLocsEntry>                  sWorldSafeLocsStore("WorldSafeLocs.db2", WorldSafeLocsMeta::Instance(), HOTFIX_SEL_WORLD_SAFE_LOCS);

TaxiMask                                        sTaxiNodesMask;
TaxiMask                                        sOldContinentsNodesMask;
TaxiMask                                        sHordeTaxiNodesMask;
TaxiMask                                        sAllianceTaxiNodesMask;
TaxiPathSetBySource                             sTaxiPathSetBySource;
TaxiPathNodesByPath                             sTaxiPathNodesByPath;

typedef std::vector<std::string> DB2StoreProblemList;

uint32 DB2FilesCount = 0;

template<class T, template<class> class DB2>
inline void LoadDB2(uint32& availableDb2Locales, DB2StoreProblemList& errlist, DB2Manager::StorageMap& stores, DB2StorageBase* storage, std::string const& db2Path, uint32 defaultLocale, DB2<T> const& /*hint*/)
{
    // compatibility format and C++ structure sizes
    ASSERT(storage->GetMeta()->GetRecordSize() == sizeof(T),
        "Size of '%s' set by format string (%u) not equal size of C++ structure (" SZFMTD ").",
        storage->GetFileName().c_str(), storage->GetMeta()->GetRecordSize(), sizeof(T));

    ++DB2FilesCount;

    if (storage->Load(db2Path + localeNames[defaultLocale] + '/', defaultLocale))
    {
        storage->LoadFromDB();

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
            stream << storage->GetFileName() << " exists, and has " << storage->GetFieldCount() << " field(s) (expected " << storage->GetMeta()->FieldCount
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

    DB2StoreProblemList bad_db2_files;
    uint32 availableDb2Locales = 0xFF;

#define LOAD_DB2(store) LoadDB2(availableDb2Locales, bad_db2_files, _stores, &store, db2Path, defaultLocale, store)

    LOAD_DB2(sAchievementStore);
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
    LOAD_DB2(sArtifactPowerRankStore);
    LOAD_DB2(sAuctionHouseStore);
    LOAD_DB2(sBankBagSlotPricesStore);
    LOAD_DB2(sBannedAddOnsStore);
    LOAD_DB2(sBarberShopStyleStore);
    LOAD_DB2(sBattlePetBreedQualityStore);
    LOAD_DB2(sBattlePetBreedStateStore);
    LOAD_DB2(sBattlePetSpeciesStore);
    LOAD_DB2(sBattlePetSpeciesStateStore);
    LOAD_DB2(sBattlemasterListStore);
    LOAD_DB2(sBroadcastTextStore);
    LOAD_DB2(sCharSectionsStore);
    LOAD_DB2(sCharStartOutfitStore);
    LOAD_DB2(sCharTitlesStore);
    LOAD_DB2(sChatChannelsStore);
    LOAD_DB2(sChrClassesStore);
    LOAD_DB2(sChrClassesXPowerTypesStore);
    LOAD_DB2(sChrRacesStore);
    LOAD_DB2(sChrSpecializationStore);
    LOAD_DB2(sCinematicSequencesStore);
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
    LOAD_DB2(sItemLimitCategoryStore);
    LOAD_DB2(sItemModifiedAppearanceStore);
    LOAD_DB2(sItemPriceBaseStore);
    LOAD_DB2(sItemRandomPropertiesStore);
    LOAD_DB2(sItemRandomSuffixStore);
    LOAD_DB2(sItemSearchNameStore);
    LOAD_DB2(sItemSetStore);
    LOAD_DB2(sItemSetSpellStore);
    LOAD_DB2(sItemSparseStore);
    LOAD_DB2(sItemSpecStore);
    LOAD_DB2(sItemSpecOverrideStore);
    LOAD_DB2(sItemUpgradeStore);
    LOAD_DB2(sItemXBonusTreeStore);
    LOAD_DB2(sKeyChainStore);
    LOAD_DB2(sLfgDungeonsStore);
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
    LOAD_DB2(sMovieStore);
    LOAD_DB2(sNameGenStore);
    LOAD_DB2(sNamesProfanityStore);
    LOAD_DB2(sNamesReservedStore);
    LOAD_DB2(sNamesReservedLocaleStore);
    LOAD_DB2(sOverrideSpellDataStore);
    LOAD_DB2(sPhaseStore);
    LOAD_DB2(sPhaseXPhaseGroupStore);
    LOAD_DB2(sPlayerConditionStore);
    LOAD_DB2(sPowerDisplayStore);
    LOAD_DB2(sPvpDifficultyStore);
    LOAD_DB2(sQuestFactionRewardStore);
    LOAD_DB2(sQuestMoneyRewardStore);
    LOAD_DB2(sQuestPackageItemStore);
    LOAD_DB2(sQuestSortStore);
    LOAD_DB2(sQuestV2Store);
    LOAD_DB2(sQuestXPStore);
    LOAD_DB2(sRandPropPointsStore);
    LOAD_DB2(sRulesetItemUpgradeStore);
    LOAD_DB2(sScalingStatDistributionStore);
    LOAD_DB2(sSkillLineStore);
    LOAD_DB2(sSkillLineAbilityStore);
    LOAD_DB2(sSkillRaceClassInfoStore);
    LOAD_DB2(sSoundKitStore);
    LOAD_DB2(sSpecializationSpellsStore);
    LOAD_DB2(sSpellStore);
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
    LOAD_DB2(sSpellEffectScalingStore);
    LOAD_DB2(sSpellEquippedItemsStore);
    LOAD_DB2(sSpellFocusObjectStore);
    LOAD_DB2(sSpellInterruptsStore);
    LOAD_DB2(sSpellItemEnchantmentStore);
    LOAD_DB2(sSpellItemEnchantmentConditionStore);
    LOAD_DB2(sSpellLearnSpellStore);
    LOAD_DB2(sSpellLevelsStore);
    LOAD_DB2(sSpellMiscStore);
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
    LOAD_DB2(sTransportAnimationStore);
    LOAD_DB2(sTransportRotationStore);
    LOAD_DB2(sUnitPowerBarStore);
    LOAD_DB2(sVehicleStore);
    LOAD_DB2(sVehicleSeatStore);
    LOAD_DB2(sWMOAreaTableStore);
    LOAD_DB2(sWorldMapAreaStore);
    LOAD_DB2(sWorldMapOverlayStore);
    LOAD_DB2(sWorldMapTransformsStore);
    LOAD_DB2(sWorldSafeLocsStore);

#undef LOAD_DB2

    for (AreaGroupMemberEntry const* areaGroupMember : sAreaGroupMemberStore)
        _areaGroupMembers[areaGroupMember->AreaGroupID].push_back(areaGroupMember->AreaID);

    for (ArtifactPowerEntry const* artifactPower : sArtifactPowerStore)
        _artifactPowers[artifactPower->ArtifactID].push_back(artifactPower);

    for (ArtifactPowerLinkEntry const* artifactPowerLink : sArtifactPowerLinkStore)
    {
        _artifactPowerLinks[artifactPowerLink->FromArtifactPowerID].insert(artifactPowerLink->ToArtifactPowerID);
        _artifactPowerLinks[artifactPowerLink->ToArtifactPowerID].insert(artifactPowerLink->FromArtifactPowerID);
    }

    for (ArtifactPowerRankEntry const* artifactPowerRank : sArtifactPowerRankStore)
        _artifactPowerRanks[std::pair<uint32, uint8>{ artifactPowerRank->ArtifactPowerID, artifactPowerRank->Rank }] = artifactPowerRank;

    std::unordered_map<uint32, std::set<std::pair<uint8, uint8>>> addedSections;
    for (CharSectionsEntry const* charSection : sCharSectionsStore)
    {
        if (!charSection->Race || !((1 << (charSection->Race - 1)) & RACEMASK_ALL_PLAYABLE)) //ignore Nonplayable races
            continue;

        // Not all sections are used for low-res models but we need to get all sections for validation since its viewer dependent
        uint8 baseSection = charSection->GenType;
        switch (baseSection)
        {
            case SECTION_TYPE_SKIN_LOW_RES:
            case SECTION_TYPE_FACE_LOW_RES:
            case SECTION_TYPE_FACIAL_HAIR_LOW_RES:
            case SECTION_TYPE_HAIR_LOW_RES:
            case SECTION_TYPE_UNDERWEAR_LOW_RES:
                baseSection = baseSection + SECTION_TYPE_SKIN;
                break;
            case SECTION_TYPE_SKIN:
            case SECTION_TYPE_FACE:
            case SECTION_TYPE_FACIAL_HAIR:
            case SECTION_TYPE_HAIR:
            case SECTION_TYPE_UNDERWEAR:
                break;
            case SECTION_TYPE_CUSTOM_DISPLAY_1_LOW_RES:
            case SECTION_TYPE_CUSTOM_DISPLAY_2_LOW_RES:
            case SECTION_TYPE_CUSTOM_DISPLAY_3_LOW_RES:
                ++baseSection;
                break;
            case SECTION_TYPE_CUSTOM_DISPLAY_1:
            case SECTION_TYPE_CUSTOM_DISPLAY_2:
            case SECTION_TYPE_CUSTOM_DISPLAY_3:
                break;
            default:
                break;
        }

        uint32 sectionKey = baseSection | (charSection->Gender << 8) | (charSection->Race << 16);
        std::pair<uint8, uint8> sectionCombination{ charSection->Type, charSection->Color };
        if (addedSections[sectionKey].count(sectionCombination))
            continue;

        addedSections[sectionKey].insert(sectionCombination);
        _charSections.insert({ sectionKey, charSection });
    }

    for (CharStartOutfitEntry const* outfit : sCharStartOutfitStore)
        _charStartOutfits[outfit->RaceID | (outfit->ClassID << 8) | (outfit->GenderID << 16)] = outfit;

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
    }

    for (CurvePointEntry const* curvePoint : sCurvePointStore)
        if (sCurveStore.LookupEntry(curvePoint->CurveID))
            _curvePoints[curvePoint->CurveID].push_back(curvePoint);

    for (auto itr = _curvePoints.begin(); itr != _curvePoints.end(); ++itr)
        std::sort(itr->second.begin(), itr->second.end(), [](CurvePointEntry const* point1, CurvePointEntry const* point2) { return point1->Index < point2->Index; });

    ASSERT(MAX_DIFFICULTY >= sDifficultyStore.GetNumRows(),
        "MAX_DIFFICULTY is not large enough to contain all difficulties! (current value %d, required %d)",
        MAX_DIFFICULTY, sDifficultyStore.GetNumRows());

    for (EmotesTextSoundEntry const* emoteTextSound : sEmotesTextSoundStore)
        _emoteTextSounds[EmotesTextSoundContainer::key_type(emoteTextSound->EmotesTextId, emoteTextSound->RaceId, emoteTextSound->SexId, emoteTextSound->ClassId)] = emoteTextSound;

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
        _itemBonusLists[bonus->BonusListID].push_back(bonus);

    for (ItemBonusListLevelDeltaEntry const* itemBonusListLevelDelta : sItemBonusListLevelDeltaStore)
        _itemLevelDeltaToBonusListContainer[itemBonusListLevelDelta->Delta] = itemBonusListLevelDelta->ID;

    for (ItemBonusTreeNodeEntry const* bonusTreeNode : sItemBonusTreeNodeStore)
    {
        uint32 bonusTreeId = bonusTreeNode->BonusTreeID;
        while (bonusTreeNode)
        {
            _itemBonusTrees[bonusTreeId].insert(bonusTreeNode);
            bonusTreeNode = sItemBonusTreeNodeStore.LookupEntry(bonusTreeNode->SubTreeID);
        }
    }

    for (ItemChildEquipmentEntry const* itemChildEquipment : sItemChildEquipmentStore)
    {
        ASSERT(_itemChildEquipment.find(itemChildEquipment->ItemID) == _itemChildEquipment.end(), "Item must have max 1 child item.");
        _itemChildEquipment[itemChildEquipment->ItemID] = itemChildEquipment;
    }

    for (ItemCurrencyCostEntry const* itemCurrencyCost : sItemCurrencyCostStore)
        _itemsWithCurrencyCost.insert(itemCurrencyCost->ItemId);

    for (ItemModifiedAppearanceEntry const* appearanceMod : sItemModifiedAppearanceStore)
    {
        ASSERT(appearanceMod->ItemID <= 0xFFFFFF);
        _itemModifiedAppearancesByItem[appearanceMod->ItemID | (appearanceMod->AppearanceModID << 24)] = appearanceMod;
        auto defaultAppearance = _itemDefaultAppearancesByItem.find(appearanceMod->ItemID);
        if (defaultAppearance == _itemDefaultAppearancesByItem.end() || defaultAppearance->second->Index > appearanceMod->Index)
            _itemDefaultAppearancesByItem[appearanceMod->ItemID] = appearanceMod;
    }

    for (ItemSetSpellEntry const* itemSetSpell : sItemSetSpellStore)
        _itemSetSpells[itemSetSpell->ItemSetID].push_back(itemSetSpell);

    for (ItemSpecOverrideEntry const* itemSpecOverride : sItemSpecOverrideStore)
        _itemSpecOverrides[itemSpecOverride->ItemID].push_back(itemSpecOverride);

    for (ItemXBonusTreeEntry const* itemBonusTreeAssignment : sItemXBonusTreeStore)
        _itemToBonusTree.insert({ itemBonusTreeAssignment->ItemID, itemBonusTreeAssignment->BonusTreeID });

    for (MapDifficultyEntry const* entry : sMapDifficultyStore)
        _mapDifficulties[entry->MapID][entry->DifficultyID] = entry;
    _mapDifficulties[0][0] = _mapDifficulties[1][0]; // map 0 is missing from MapDifficulty.dbc so we cheat a bit

    for (MountEntry const* mount : sMountStore)
        _mountsBySpellId[mount->SpellId] = mount;

    for (MountTypeXCapabilityEntry const* mountTypeCapability : sMountTypeXCapabilityStore)
        _mountCapabilitiesByType[mountTypeCapability->MountTypeID].insert(mountTypeCapability);

    for (NameGenEntry const* nameGen : sNameGenStore)
        _nameGenData[nameGen->Race][nameGen->Sex].push_back(nameGen);

    for (NamesProfanityEntry const* namesProfanity : sNamesProfanityStore)
    {
        ASSERT(namesProfanity->Language < TOTAL_LOCALES || namesProfanity->Language == -1);
        std::wstring name;
        ASSERT(Utf8toWStr(namesProfanity->Name, name));
        if (namesProfanity->Language != -1)
            _nameValidators[namesProfanity->Language].emplace_back(name, std::regex::icase | std::regex::optimize);
        else
        {
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
            {
                if (i == LOCALE_none)
                    continue;

                _nameValidators[i].emplace_back(name, std::regex::icase | std::regex::optimize);
            }
        }
    }

    for (NamesReservedEntry const* namesReserved : sNamesReservedStore)
    {
        std::wstring name;
        ASSERT(Utf8toWStr(namesReserved->Name, name));
        _nameValidators[TOTAL_LOCALES].emplace_back(name, std::regex::icase | std::regex::optimize);
    }

    for (NamesReservedLocaleEntry const* namesReserved : sNamesReservedLocaleStore)
    {
        ASSERT(!(namesReserved->LocaleMask & ~((1 << TOTAL_LOCALES) - 1)));
        std::wstring name;
        ASSERT(Utf8toWStr(namesReserved->Name, name));
        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (i == LOCALE_none)
                continue;

            if (namesReserved->LocaleMask & (1 << i))
                _nameValidators[i].emplace_back(name, std::regex::icase | std::regex::optimize);
        }
    }

    for (PhaseXPhaseGroupEntry const* group : sPhaseXPhaseGroupStore)
        if (PhaseEntry const* phase = sPhaseStore.LookupEntry(group->PhaseID))
            _phasesByGroup[group->PhaseGroupID].insert(phase->ID);

    for (PvPDifficultyEntry const* entry : sPvpDifficultyStore)
    {
        ASSERT(entry->BracketID < MAX_BATTLEGROUND_BRACKETS, "PvpDifficulty bracket (%d) exceeded max allowed value (%d)", entry->BracketID, MAX_BATTLEGROUND_BRACKETS);
    }

    for (QuestPackageItemEntry const* questPackageItem : sQuestPackageItemStore)
        _questPackages[questPackageItem->QuestPackageID].push_back(questPackageItem);

    for (RulesetItemUpgradeEntry const* rulesetItemUpgrade : sRulesetItemUpgradeStore)
        _rulesetItemUpgrade[rulesetItemUpgrade->ItemID] = rulesetItemUpgrade->ItemUpgradeID;

    for (SkillRaceClassInfoEntry const* entry : sSkillRaceClassInfoStore)
        if (sSkillLineStore.LookupEntry(entry->SkillID))
            _skillRaceClassInfoBySkill.insert(SkillRaceClassInfoContainer::value_type(entry->SkillID, entry));

    for (SpecializationSpellsEntry const* specSpells : sSpecializationSpellsStore)
        _specializationSpellsBySpec[specSpells->SpecID].push_back(specSpells);

    for (SpellPowerEntry const* power : sSpellPowerStore)
    {
        if (SpellPowerDifficultyEntry const* powerDifficulty = sSpellPowerDifficultyStore.LookupEntry(power->ID))
        {
            std::vector<SpellPowerEntry const*>& powers = _spellPowerDifficulties[power->SpellID][powerDifficulty->DifficultyID];
            if (powers.size() <= powerDifficulty->PowerIndex)
                powers.resize(powerDifficulty->PowerIndex + 1);

            powers[powerDifficulty->PowerIndex] = power;
        }
        else
        {
            std::vector<SpellPowerEntry const*>& powers = _spellPowers[power->SpellID];
            if (powers.size() <= power->PowerIndex)
                powers.resize(power->PowerIndex + 1);

            powers[power->PowerIndex] = power;
        }
    }

    for (SpellProcsPerMinuteModEntry const* ppmMod : sSpellProcsPerMinuteModStore)
        _spellProcsPerMinuteMods[ppmMod->SpellProcsPerMinuteID].push_back(ppmMod);

    for (TalentEntry const* talentInfo : sTalentStore)
    {
        ASSERT(talentInfo->ClassID < MAX_CLASSES);
        ASSERT(talentInfo->TierID < MAX_TALENT_TIERS, "MAX_TALENT_TIERS must be at least %u", talentInfo->TierID);
        ASSERT(talentInfo->ColumnIndex < MAX_TALENT_COLUMNS, "MAX_TALENT_COLUMNS must be at least %u", talentInfo->ColumnIndex);

        _talentsByPosition[talentInfo->ClassID][talentInfo->TierID][talentInfo->ColumnIndex].push_back(talentInfo);
    }

    for (TaxiPathEntry const* entry : sTaxiPathStore)
        sTaxiPathSetBySource[entry->From][entry->To] = TaxiPathBySourceAndDestination(entry->ID, entry->Cost);

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
            uint8  field = (uint8)((node->ID - 1) / 8);
            uint32 submask = 1 << ((node->ID - 1) % 8);

            sTaxiNodesMask[field] |= submask;
            if (node->Flags & TAXI_NODE_FLAG_HORDE)
                sHordeTaxiNodesMask[field] |= submask;
            if (node->Flags & TAXI_NODE_FLAG_ALLIANCE)
                sAllianceTaxiNodesMask[field] |= submask;

            uint32 nodeMap;
            DeterminaAlternateMapPosition(node->MapID, node->Pos.X, node->Pos.Y, node->Pos.Z, &nodeMap);
            if (nodeMap < 2)
                sOldContinentsNodesMask[field] |= submask;
        }
    }

    for (TransportAnimationEntry const* anim : sTransportAnimationStore)
        sTransportMgr->AddPathNodeToTransport(anim->TransportID, anim->TimeIndex, anim);

    for (TransportRotationEntry const* rot : sTransportRotationStore)
        sTransportMgr->AddPathRotationToTransport(rot->TransportID, rot->TimeIndex, rot);

    for (ToyEntry const* toy : sToyStore)
        _toys.insert(toy->ItemID);

    for (WMOAreaTableEntry const* entry : sWMOAreaTableStore)
        _wmoAreaTableLookup[WMOAreaTableKey(entry->WMOID, entry->NameSet, entry->WMOGroupID)] = entry;

    for (WorldMapAreaEntry const* worldMapArea : sWorldMapAreaStore)
        _worldMapAreaByAreaID[worldMapArea->AreaID] = worldMapArea;

    // error checks
    if (bad_db2_files.size() >= DB2FilesCount)
    {
        TC_LOG_ERROR("misc", "\nIncorrect DataDir value in worldserver.conf or ALL required *.db2 files (%d) not found by path: %sdbc/%s/", DB2FilesCount, dataPath.c_str(), localeNames[defaultLocale]);
        exit(1);
    }
    else if (!bad_db2_files.empty())
    {
        std::string str;
        for (auto i = bad_db2_files.begin(); i != bad_db2_files.end(); ++i)
            str += *i + "\n";

        TC_LOG_ERROR("misc", "\nSome required *.db2 files (%u from %d) not found or not compatible:\n%s", (uint32)bad_db2_files.size(), DB2FilesCount, str.c_str());
        exit(1);
    }

    // Check loaded DB2 files proper version
    if (!sAreaTableStore.LookupEntry(8478) ||                // last area (areaflag) added in 7.0.3 (22293)
        !sCharTitlesStore.LookupEntry(486) ||                // last char title added in 7.0.3 (22293)
        !sGemPropertiesStore.LookupEntry(3363) ||            // last gem property added in 7.0.3 (22293)
        !sItemStore.LookupEntry(142074) ||                   // last item added in 7.0.3 (22293)
        !sItemExtendedCostStore.LookupEntry(6121) ||         // last item extended cost added in 7.0.3 (22293)
        !sMapStore.LookupEntry(1670) ||                      // last map added in 7.0.3 (22293)
        !sSpellStore.LookupEntry(229118))                    // last spell added in 7.0.3 (22293)
    {
        TC_LOG_ERROR("misc", "You have _outdated_ DB2 files. Please extract correct versions from current using client.");
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d DB2 data stores in %u ms", DB2FilesCount, GetMSTimeDiffToNow(oldMSTime));
}

DB2StorageBase const* DB2Manager::GetStorage(uint32 type) const
{
    StorageMap::const_iterator itr = _stores.find(type);
    if (itr != _stores.end())
        return itr->second;

    return nullptr;
}

void DB2Manager::LoadHotfixData()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = HotfixDatabase.Query("SELECT TableHash, RecordID, `Timestamp`, Deleted FROM hotfix_data");

    if (!result)
    {
        TC_LOG_INFO("misc", ">> Loaded 0 hotfix info entries.");
        return;
    }

    uint32 count = 0;

    _hotfixData.reserve(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        HotfixNotify info;
        info.TableHash = fields[0].GetUInt32();
        info.Entry = fields[1].GetUInt32();
        info.Timestamp = fields[2].GetUInt32();
        _hotfixData.push_back(info);

        if (fields[3].GetBool())
        {
            auto itr = _stores.find(info.TableHash);
            if (itr != _stores.end())
                itr->second->EraseRecord(info.Entry);
        }

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("misc", ">> Loaded %u hotfix info entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

time_t DB2Manager::GetHotfixDate(uint32 entry, uint32 type) const
{
    time_t ret = 0;
    for (HotfixNotify const& hotfix : _hotfixData)
        if (hotfix.Entry == entry && hotfix.TableHash == type)
            if (time_t(hotfix.Timestamp) > ret)
                ret = time_t(hotfix.Timestamp);

    return ret ? ret : time(NULL);
}

std::vector<uint32> DB2Manager::GetAreasForGroup(uint32 areaGroupId) const
{
    auto itr = _areaGroupMembers.find(areaGroupId);
    if (itr != _areaGroupMembers.end())
        return itr->second;

    return std::vector<uint32>();
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
    if (gender == GENDER_FEMALE && (forceGender || broadcastText->FemaleText->Str[DEFAULT_LOCALE][0] != '\0'))
    {
        if (broadcastText->FemaleText->Str[locale][0] != '\0')
            return broadcastText->FemaleText->Str[locale];

        return broadcastText->FemaleText->Str[DEFAULT_LOCALE];
    }

    if (broadcastText->MaleText->Str[locale][0] != '\0')
        return broadcastText->MaleText->Str[locale];

    return broadcastText->MaleText->Str[DEFAULT_LOCALE];
}

CharSectionsEntry const* DB2Manager::GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color) const
{
    auto eqr = _charSections.equal_range(uint32(genType) | uint32(gender << 8) | uint32(race << 16));
    for (auto itr = eqr.first; itr != eqr.second; ++itr)
        if (itr->second->Type == type && itr->second->Color == color)
            return itr->second;

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

uint32 DB2Manager::GetPowerIndexByClass(uint32 powerType, uint32 classId) const
{
    return _powersByClass[classId][powerType];
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
            while (pointIndex < points.size() && points[pointIndex]->X <= x)
                ++pointIndex;
            if (!pointIndex)
                return points[0]->Y;
            if (pointIndex >= points.size())
                return points.back()->Y;
            float xDiff = points[pointIndex]->X - points[pointIndex - 1]->X;
            if (xDiff == 0.0)
                return points[pointIndex]->Y;
            return (((x - points[pointIndex - 1]->X) / xDiff) * (points[pointIndex]->Y - points[pointIndex - 1]->Y)) + points[pointIndex - 1]->Y;
        }
        case CurveInterpolationMode::Cosine:
        {
            std::size_t pointIndex = 0;
            while (pointIndex < points.size() && points[pointIndex]->X <= x)
                ++pointIndex;
            if (!pointIndex)
                return points[0]->Y;
            if (pointIndex >= points.size())
                return points.back()->Y;
            float xDiff = points[pointIndex]->X - points[pointIndex - 1]->X;
            if (xDiff == 0.0)
                return points[pointIndex]->Y;
            return ((points[pointIndex]->Y - points[pointIndex - 1]->Y) * (1.0f - std::cos((x - points[pointIndex - 1]->X) / xDiff * float(M_PI))) * 0.5f) + points[pointIndex - 1]->Y;
        }
        case CurveInterpolationMode::CatmullRom:
        {
            std::size_t pointIndex = 1;
            while (pointIndex < points.size() && points[pointIndex]->X <= x)
                ++pointIndex;
            if (pointIndex == 1)
                return points[1]->Y;
            if (pointIndex >= points.size() - 1)
                return points[points.size() - 2]->Y;
            float xDiff = points[pointIndex]->X - points[pointIndex - 1]->X;
            if (xDiff == 0.0)
                return points[pointIndex]->Y;

            float mu = (x - points[pointIndex - 1]->X) / xDiff;
            float a0 = -0.5f * points[pointIndex - 2]->Y + 1.5f * points[pointIndex - 1]->Y - 1.5f * points[pointIndex]->Y + 0.5f * points[pointIndex + 1]->Y;
            float a1 = points[pointIndex - 2]->Y - 2.5f * points[pointIndex - 1]->Y + 2.0f * points[pointIndex]->Y - 0.5f * points[pointIndex + 1]->Y;
            float a2 = -0.5f * points[pointIndex - 2]->Y + 0.5f * points[pointIndex]->Y;
            float a3 = points[pointIndex - 1]->Y;

            return a0 * mu * mu * mu + a1 * mu * mu + a2 * mu + a3;
        }
        case CurveInterpolationMode::Bezier3:
        {
            float xDiff = points[2]->X - points[0]->X;
            if (xDiff == 0.0)
                return points[1]->Y;
            float mu = (x - points[0]->X) / xDiff;
            return ((1.0f - mu) * (1.0f - mu) * points[0]->Y) + (1.0f - mu) * 2.0f * mu * points[1]->Y + mu * mu * points[2]->Y;
        }
        case CurveInterpolationMode::Bezier4:
        {
            float xDiff = points[3]->X - points[0]->X;
            if (xDiff == 0.0)
                return points[1]->Y;
            float mu = (x - points[0]->X) / xDiff;
            return (1.0f - mu) * (1.0f - mu) * (1.0f - mu) * points[0]->Y
                + 3.0f * mu * (1.0f - mu) * (1.0f - mu) * points[1]->Y
                + 3.0f * mu * mu * (1.0f - mu) * points[2]->Y
                + mu * mu * mu * points[3]->Y;
        }
        case CurveInterpolationMode::Bezier:
        {
            float xDiff = points.back()->X - points[0]->X;
            if (xDiff == 0.0f)
                return points.back()->Y;

            std::vector<float> tmp(points.size());
            for (std::size_t i = 0; i < points.size(); ++i)
                tmp[i] = points[i]->Y;

            float mu = (x - points[0]->X) / xDiff;
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
            return points[0]->Y;
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

    itr = _emoteTextSounds.find(EmotesTextSoundContainer::key_type(emote, race, gender, 0));
    if (itr != _emoteTextSounds.end())
        return itr->second;

    return nullptr;
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

std::set<uint32> DB2Manager::GetItemBonusTree(uint32 itemId, uint32 itemBonusTreeMod) const
{
    std::set<uint32> bonusListIDs;
    auto itemIdRange = _itemToBonusTree.equal_range(itemId);
    if (itemIdRange.first == itemIdRange.second)
        return bonusListIDs;

    for (auto itemTreeItr = itemIdRange.first; itemTreeItr != itemIdRange.second; ++itemTreeItr)
    {
        auto treeItr = _itemBonusTrees.find(itemTreeItr->second);
        if (treeItr == _itemBonusTrees.end())
            continue;

        for (ItemBonusTreeNodeEntry const* bonusTreeNode : treeItr->second)
            if (bonusTreeNode->BonusTreeModID == itemBonusTreeMod)
                bonusListIDs.insert(bonusTreeNode->BonusListID);
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

uint32 DB2Manager::GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const
{
    if (ItemModifiedAppearanceEntry const* modifiedAppearance = GetItemModifiedAppearance(itemId, appearanceModId))
        if (ItemAppearanceEntry const* itemAppearance = sItemAppearanceStore.LookupEntry(modifiedAppearance->AppearanceID))
            return itemAppearance->DisplayID;

    return 0;
}

ItemModifiedAppearanceEntry const* DB2Manager::GetItemModifiedAppearance(uint32 itemId, uint32 appearanceModId) const
{
    auto itr = _itemModifiedAppearancesByItem.find(itemId | (appearanceModId << 24));
    if (itr != _itemModifiedAppearancesByItem.end())
        return itr->second;

    // Fall back to unmodified appearance
    itr = _itemDefaultAppearancesByItem.find(itemId);
    if (itr != _itemDefaultAppearancesByItem.end())
        return itr->second;

    return nullptr;
}

ItemModifiedAppearanceEntry const* DB2Manager::GetDefaultItemModifiedAppearance(uint32 itemId) const
{
    auto itr = _itemDefaultAppearancesByItem.find(itemId);
    if (itr != _itemDefaultAppearancesByItem.end())
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

LfgDungeonsEntry const* DB2Manager::GetLfgDungeon(uint32 mapId, Difficulty difficulty)
{
    for (LfgDungeonsEntry const* dungeon : sLfgDungeonsStore)
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

        if (light->MapID == mapId && light->Pos.X == 0.0f && light->Pos.Y == 0.0f && light->Pos.Z == 0.0f)
            return uint32(i);
    }

    return 0;
}

uint32 DB2Manager::GetLiquidFlags(uint32 liquidType)
{
    if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquidType))
        return 1 << liq->Type;

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

std::string DB2Manager::GetNameGenEntry(uint8 race, uint8 gender, LocaleConstant locale) const
{
    ASSERT(gender < GENDER_NONE);
    auto ritr = _nameGenData.find(race);
    if (ritr == _nameGenData.end())
        return "";

    if (ritr->second[gender].empty())
        return "";

    LocalizedString* data = Trinity::Containers::SelectRandomContainerElement(ritr->second[gender])->Name;
    if (*data->Str[locale] != '\0')
        return data->Str[locale];

    return data->Str[sWorld->GetDefaultDbcLocale()];
}

ResponseCodes DB2Manager::ValidateName(std::wstring const& name, LocaleConstant locale) const
{
    for (std::wregex const& regex : _nameValidators[locale])
        if (std::regex_search(name, regex))
            return CHAR_NAME_PROFANE;

    // regexes at TOTAL_LOCALES are loaded from NamesReserved which is not locale specific
    for (std::wregex const& regex : _nameValidators[TOTAL_LOCALES])
        if (std::regex_search(name, regex))
            return CHAR_NAME_RESERVED;

    return CHAR_NAME_SUCCESS;
}

PvPDifficultyEntry const* DB2Manager::GetBattlegroundBracketByLevel(uint32 mapid, uint32 level)
{
    PvPDifficultyEntry const* maxEntry = NULL;              // used for level > max listed level case
    for (uint32 i = 0; i < sPvpDifficultyStore.GetNumRows(); ++i)
    {
        if (PvPDifficultyEntry const* entry = sPvpDifficultyStore.LookupEntry(i))
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
    }

    return maxEntry;
}

PvPDifficultyEntry const* DB2Manager::GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id)
{
    for (uint32 i = 0; i < sPvpDifficultyStore.GetNumRows(); ++i)
        if (PvPDifficultyEntry const* entry = sPvpDifficultyStore.LookupEntry(i))
            if (entry->MapID == mapid && entry->GetBracketId() == id)
                return entry;

    return nullptr;
}

std::vector<QuestPackageItemEntry const*> const* DB2Manager::GetQuestPackageItems(uint32 questPackageID) const
{
    auto itr = _questPackages.find(questPackageID);
    if (itr != _questPackages.end())
        return &itr->second;

    return nullptr;
}

uint32 DB2Manager::GetQuestUniqueBitFlag(uint32 questId)
{
    QuestV2Entry const* v2 = sQuestV2Store.LookupEntry(questId);
    if (!v2)
        return 0;

    return v2->UniqueBitFlag;
}

std::set<uint32> DB2Manager::GetPhasesForGroup(uint32 group) const
{
    auto itr = _phasesByGroup.find(group);
    if (itr != _phasesByGroup.end())
        return itr->second;

    return std::set<uint32>();
}

uint32 DB2Manager::GetRulesetItemUpgrade(uint32 itemId) const
{
    auto itr = _rulesetItemUpgrade.find(itemId);
    if (itr != _rulesetItemUpgrade.end())
        return itr->second;

    return 0;
}

SkillRaceClassInfoEntry const* DB2Manager::GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_)
{
    auto bounds = _skillRaceClassInfoBySkill.equal_range(skill);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
    {
        if (itr->second->RaceMask && !(itr->second->RaceMask & (1 << (race - 1))))
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
                    if (!powers[difficultyPower->PowerIndex])
                        powers[difficultyPower->PowerIndex] = difficultyPower;
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
            if (!powers[power->PowerIndex])
                powers[power->PowerIndex] = power;
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

    if (itemEntry->CategoryType != reqEntry->CategoryType)
        return false;

    return (itemEntry->CategoryMask & reqEntry->CategoryMask) == reqEntry->CategoryMask;
}

bool DB2Manager::IsToyItem(uint32 toy) const
{
    return _toys.count(toy) > 0;
}

WMOAreaTableEntry const* DB2Manager::GetWMOAreaTable(int32 rootId, int32 adtId, int32 groupId) const
{
    auto i = _wmoAreaTableLookup.find(WMOAreaTableKey(int16(rootId), int8(adtId), groupId));
    if (i != _wmoAreaTableLookup.end())
        return i->second;

    return nullptr;
}

uint32 DB2Manager::GetVirtualMapForMapAndZone(uint32 mapId, uint32 zoneId) const
{
    if (mapId != 530 && mapId != 571 && mapId != 732)   // speed for most cases
        return mapId;

    auto itr = _worldMapAreaByAreaID.find(zoneId);
    if (itr != _worldMapAreaByAreaID.end())
        return itr->second->DisplayMapID >= 0 ? itr->second->DisplayMapID : itr->second->MapID;

    return mapId;
}

void DB2Manager::Zone2MapCoordinates(uint32 areaId, float& x, float& y) const
{
    auto itr = _worldMapAreaByAreaID.find(areaId);
    if (itr == _worldMapAreaByAreaID.end())
        return;

    std::swap(x, y);                                         // at client map coords swapped
    x = x*((itr->second->LocBottom - itr->second->LocTop) / 100) + itr->second->LocTop;
    y = y*((itr->second->LocRight - itr->second->LocLeft) / 100) + itr->second->LocLeft;        // client y coord from top to down
}

void DB2Manager::Map2ZoneCoordinates(uint32 areaId, float& x, float& y) const
{
    auto itr = _worldMapAreaByAreaID.find(areaId);
    if (itr == _worldMapAreaByAreaID.end())
        return;

    x = (x - itr->second->LocTop) / ((itr->second->LocBottom - itr->second->LocTop) / 100);
    y = (y - itr->second->LocLeft) / ((itr->second->LocRight - itr->second->LocLeft) / 100);    // client y coord from top to down
    std::swap(x, y);                                         // client have map coords swapped
}

void DB2Manager::DeterminaAlternateMapPosition(uint32 mapId, float x, float y, float z, uint32* newMapId /*= nullptr*/, DBCPosition2D* newPos /*= nullptr*/)
{
    ASSERT(newMapId || newPos);
    WorldMapTransformsEntry const* transformation = nullptr;
    for (WorldMapTransformsEntry const* transform : sWorldMapTransformsStore)
    {
        if (transform->MapID != mapId)
            continue;

        if (transform->RegionMin.X > x || transform->RegionMax.X < x)
            continue;
        if (transform->RegionMin.Y > y || transform->RegionMax.Y < y)
            continue;
        if (transform->RegionMin.Z > z || transform->RegionMax.Z < z)
            continue;

        transformation = transform;
        break;
    }

    if (!transformation)
    {
        if (newMapId)
            *newMapId = mapId;

        if (newPos)
        {
            newPos->X = x;
            newPos->Y = y;
        }
        return;
    }

    if (newMapId)
        *newMapId = transformation->NewMapID;

    if (!newPos)
        return;

    if (transformation->RegionScale > 0.0f && transformation->RegionScale < 1.0f)
    {
        x = (x - transformation->RegionMin.X) * transformation->RegionScale + transformation->RegionMin.X;
        y = (y - transformation->RegionMin.Y) * transformation->RegionScale + transformation->RegionMin.Y;
    }

    newPos->X = x + transformation->RegionOffset.X;
    newPos->Y = y + transformation->RegionOffset.Y;
}

bool DB2Manager::ChrClassesXPowerTypesEntryComparator::Compare(ChrClassesXPowerTypesEntry const* left, ChrClassesXPowerTypesEntry const* right)
{
    if (left->ClassID != right->ClassID)
        return left->ClassID < right->ClassID;
    return left->PowerType < right->PowerType;
}

bool DB2Manager::MountTypeXCapabilityEntryComparator::Compare(MountTypeXCapabilityEntry const* left, MountTypeXCapabilityEntry const* right)
{
    if (left->MountTypeID == right->MountTypeID)
        return left->OrderIndex < right->OrderIndex;
    return left->MountTypeID < right->MountTypeID;
}
