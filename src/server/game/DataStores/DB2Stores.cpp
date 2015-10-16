/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "DBCStores.h"
#include "DB2fmt.h"
#include "Log.h"
#include "TransportMgr.h"
#include "World.h"

DB2Storage<AchievementEntry>                    sAchievementStore("Achievement.db2", AchievementFormat, HOTFIX_SEL_ACHIEVEMENT);
DB2Storage<AreaGroupEntry>                      sAreaGroupStore("AreaGroup.db2", AreaGroupFormat, HOTFIX_SEL_AREA_GROUP);
DB2Storage<AreaGroupMemberEntry>                sAreaGroupMemberStore("AreaGroupMember.db2", AreaGroupMemberFormat, HOTFIX_SEL_AREA_GROUP_MEMBER);
DB2Storage<AuctionHouseEntry>                   sAuctionHouseStore("AuctionHouse.db2", AuctionHouseFormat, HOTFIX_SEL_AUCTION_HOUSE);
DB2Storage<BarberShopStyleEntry>                sBarberShopStyleStore("BarberShopStyle.db2", BarberShopStyleFormat, HOTFIX_SEL_BARBER_SHOP_STYLE);
DB2Storage<BattlePetBreedQualityEntry>          sBattlePetBreedQualityStore("BattlePetBreedQuality.db2", BattlePetBreedQualityFormat, HOTFIX_SEL_BATTLE_PET_BREED_QUALITY);
DB2Storage<BattlePetBreedStateEntry>            sBattlePetBreedStateStore("BattlePetBreedState.db2", BattlePetBreedStateFormat, HOTFIX_SEL_BATTLE_PET_BREED_STATE);
DB2Storage<BattlePetSpeciesEntry>               sBattlePetSpeciesStore("BattlePetSpecies.db2", BattlePetSpeciesFormat, HOTFIX_SEL_BATTLE_PET_SPECIES);
DB2Storage<BattlePetSpeciesStateEntry>          sBattlePetSpeciesStateStore("BattlePetSpeciesState.db2", BattlePetSpeciesStateFormat, HOTFIX_SEL_BATTLE_PET_SPECIES_STATE);
DB2Storage<BroadcastTextEntry>                  sBroadcastTextStore("BroadcastText.db2", BroadcastTextFormat, HOTFIX_SEL_BROADCAST_TEXT);
DB2Storage<CharStartOutfitEntry>                sCharStartOutfitStore("CharStartOutfit.db2", CharStartOutfitFormat, HOTFIX_SEL_CHAR_START_OUTFIT);
DB2Storage<ChrClassesXPowerTypesEntry>          sChrClassesXPowerTypesStore("ChrClassesXPowerTypes.db2", ChrClassesXPowerTypesFormat, HOTFIX_SEL_CHR_CLASSES_X_POWER_TYPES);
DB2Storage<CinematicSequencesEntry>             sCinematicSequencesStore("CinematicSequences.db2", CinematicSequencesFormat, HOTFIX_SEL_CINEMATIC_SEQUENCES);
DB2Storage<CreatureDisplayInfoEntry>            sCreatureDisplayInfoStore("CreatureDisplayInfo.db2", CreatureDisplayInfoFormat, HOTFIX_SEL_CREATURE_DISPLAY_INFO);
DB2Storage<CreatureTypeEntry>                   sCreatureTypeStore("CreatureType.db2", CreatureTypeFormat, HOTFIX_SEL_CREATURE_TYPE);
DB2Storage<CriteriaEntry>                       sCriteriaStore("Criteria.db2", CriteriaFormat, HOTFIX_SEL_CRITERIA);
DB2Storage<CriteriaTreeEntry>                   sCriteriaTreeStore("CriteriaTree.db2", CriteriaTreeFormat, HOTFIX_SEL_CRITERIA_TREE);
DB2Storage<CurrencyTypesEntry>                  sCurrencyTypesStore("CurrencyTypes.db2", CurrencyTypesFormat, HOTFIX_SEL_CURRENCY_TYPES);
DB2Storage<CurvePointEntry>                     sCurvePointStore("CurvePoint.db2", CurvePointFormat, HOTFIX_SEL_CURVE_POINT);
DB2Storage<DestructibleModelDataEntry>          sDestructibleModelDataStore("DestructibleModelData.db2", DestructibleModelDataFormat, HOTFIX_SEL_DESTRUCTIBLE_MODEL_DATA);
DB2Storage<DurabilityQualityEntry>              sDurabilityQualityStore("DurabilityQuality.db2", DurabilityQualityFormat, HOTFIX_SEL_DURABILITY_QUALITY);
DB2Storage<GameObjectsEntry>                    sGameObjectsStore("GameObjects.db2", GameObjectsFormat, HOTFIX_SEL_GAMEOBJECTS);
DB2Storage<GameTablesEntry>                     sGameTablesStore("GameTables.db2", GameTablesFormat, HOTFIX_SEL_GAME_TABLES);
DB2Storage<GarrAbilityEntry>                    sGarrAbilityStore("GarrAbility.db2", GarrAbilityFormat, HOTFIX_SEL_GARR_ABILITY);
DB2Storage<GarrBuildingEntry>                   sGarrBuildingStore("GarrBuilding.db2", GarrBuildingFormat, HOTFIX_SEL_GARR_BUILDING);
DB2Storage<GarrBuildingPlotInstEntry>           sGarrBuildingPlotInstStore("GarrBuildingPlotInst.db2", GarrBuildingPlotInstFormat, HOTFIX_SEL_GARR_BUILDING_PLOT_INST);
DB2Storage<GarrClassSpecEntry>                  sGarrClassSpecStore("GarrClassSpec.db2", GarrClassSpecFormat, HOTFIX_SEL_GARR_CLASS_SPEC);
DB2Storage<GarrFollowerEntry>                   sGarrFollowerStore("GarrFollower.db2", GarrFollowerFormat, HOTFIX_SEL_GARR_FOLLOWER);
DB2Storage<GarrFollowerXAbilityEntry>           sGarrFollowerXAbilityStore("GarrFollowerXAbility.db2", GarrFollowerXAbilityFormat, HOTFIX_SEL_GARR_FOLLOWER_X_ABILITY);
DB2Storage<GarrPlotBuildingEntry>               sGarrPlotBuildingStore("GarrPlotBuilding.db2", GarrPlotBuildingFormat, HOTFIX_SEL_GARR_PLOT_BUILDING);
DB2Storage<GarrPlotEntry>                       sGarrPlotStore("GarrPlot.db2", GarrPlotFormat, HOTFIX_SEL_GARR_PLOT);
DB2Storage<GarrPlotInstanceEntry>               sGarrPlotInstanceStore("GarrPlotInstance.db2", GarrPlotInstanceFormat, HOTFIX_SEL_GARR_PLOT_INSTANCE);
DB2Storage<GarrSiteLevelEntry>                  sGarrSiteLevelStore("GarrSiteLevel.db2", GarrSiteLevelFormat, HOTFIX_SEL_GARR_SITE_LEVEL);
DB2Storage<GarrSiteLevelPlotInstEntry>          sGarrSiteLevelPlotInstStore("GarrSiteLevelPlotInst.db2", GarrSiteLevelPlotInstFormat, HOTFIX_SEL_GARR_SITE_LEVEL_PLOT_INST);
DB2Storage<GlyphSlotEntry>                      sGlyphSlotStore("GlyphSlot.db2", GlyphSlotFormat, HOTFIX_SEL_GLYPH_SLOT);
DB2Storage<GuildPerkSpellsEntry>                sGuildPerkSpellsStore("GuildPerkSpells.db2", GuildPerkSpellsFormat, HOTFIX_SEL_GUILD_PERK_SPELLS);
DB2Storage<HeirloomEntry>                       sHeirloomStore("Heirloom.db2", HeirloomFormat, HOTFIX_SEL_HEIRLOOM);
DB2Storage<HolidaysEntry>                       sHolidaysStore("Holidays.db2", HolidaysEntryFormat, HOTFIX_SEL_HOLIDAYS);
DB2Storage<ImportPriceArmorEntry>               sImportPriceArmorStore("ImportPriceArmor.db2", ImportPriceArmorFormat, HOTFIX_SEL_IMPORT_PRICE_ARMOR);
DB2Storage<ImportPriceQualityEntry>             sImportPriceQualityStore("ImportPriceQuality.db2", ImportPriceQualityFormat, HOTFIX_SEL_IMPORT_PRICE_QUALITY);
DB2Storage<ImportPriceShieldEntry>              sImportPriceShieldStore("ImportPriceShield.db2", ImportPriceShieldFormat, HOTFIX_SEL_IMPORT_PRICE_SHIELD);
DB2Storage<ImportPriceWeaponEntry>              sImportPriceWeaponStore("ImportPriceWeapon.db2", ImportPriceWeaponFormat, HOTFIX_SEL_IMPORT_PRICE_WEAPON);
DB2Storage<ItemAppearanceEntry>                 sItemAppearanceStore("ItemAppearance.db2", ItemAppearanceFormat, HOTFIX_SEL_ITEM_APPEARANCE);
DB2Storage<ItemBonusEntry>                      sItemBonusStore("ItemBonus.db2", ItemBonusFormat, HOTFIX_SEL_ITEM_BONUS);
DB2Storage<ItemBonusTreeNodeEntry>              sItemBonusTreeNodeStore("ItemBonusTreeNode.db2", ItemBonusTreeNodeFormat, HOTFIX_SEL_ITEM_BONUS_TREE_NODE);
DB2Storage<ItemClassEntry>                      sItemClassStore("ItemClass.db2", ItemClassFormat, HOTFIX_SEL_ITEM_CLASS);
DB2Storage<ItemCurrencyCostEntry>               sItemCurrencyCostStore("ItemCurrencyCost.db2", ItemCurrencyCostFormat, HOTFIX_SEL_ITEM_CURRENCY_COST);
DB2Storage<ItemDisenchantLootEntry>             sItemDisenchantLootStore("ItemDisenchantLoot.db2", ItemDisenchantLootFormat, HOTFIX_SEL_ITEM_DISENCHANT_LOOT);
DB2Storage<ItemEffectEntry>                     sItemEffectStore("ItemEffect.db2", ItemEffectFormat, HOTFIX_SEL_ITEM_EFFECT);
DB2Storage<ItemEntry>                           sItemStore("Item.db2", ItemFormat, HOTFIX_SEL_ITEM);
DB2Storage<ItemExtendedCostEntry>               sItemExtendedCostStore("ItemExtendedCost.db2", ItemExtendedCostFormat, HOTFIX_SEL_ITEM_EXTENDED_COST);
DB2Storage<ItemLimitCategoryEntry>              sItemLimitCategoryStore("ItemLimitCategory.db2", ItemLimitCategoryFormat, HOTFIX_SEL_ITEM_LIMIT_CATEGORY);
DB2Storage<ItemModifiedAppearanceEntry>         sItemModifiedAppearanceStore("ItemModifiedAppearance.db2", ItemModifiedAppearanceFormat, HOTFIX_SEL_ITEM_MODIFIED_APPEARANCE);
DB2Storage<ItemPriceBaseEntry>                  sItemPriceBaseStore("ItemPriceBase.db2", ItemPriceBaseFormat, HOTFIX_SEL_ITEM_PRICE_BASE);
DB2Storage<ItemRandomPropertiesEntry>           sItemRandomPropertiesStore("ItemRandomProperties.db2", ItemRandomPropertiesFormat, HOTFIX_SEL_ITEM_RANDOM_PROPERTIES);
DB2Storage<ItemRandomSuffixEntry>               sItemRandomSuffixStore("ItemRandomSuffix.db2", ItemRandomSuffixFormat, HOTFIX_SEL_ITEM_RANDOM_SUFFIX);
DB2Storage<ItemSparseEntry>                     sItemSparseStore("Item-sparse.db2", ItemSparseFormat, HOTFIX_SEL_ITEM_SPARSE);
DB2Storage<ItemSpecEntry>                       sItemSpecStore("ItemSpec.db2", ItemSpecFormat, HOTFIX_SEL_ITEM_SPEC);
DB2Storage<ItemSpecOverrideEntry>               sItemSpecOverrideStore("ItemSpecOverride.db2", ItemSpecOverrideFormat, HOTFIX_SEL_ITEM_SPEC_OVERRIDE);
DB2Storage<ItemToBattlePetSpeciesEntry>         sItemToBattlePetSpeciesStore("ItemToBattlePetSpecies.db2", ItemToBattlePetSpeciesFormat, HOTFIX_SEL_ITEM_TO_BATTLE_PET_SPECIES);
DB2Storage<ItemXBonusTreeEntry>                 sItemXBonusTreeStore("ItemXBonusTree.db2", ItemXBonusTreeFormat, HOTFIX_SEL_ITEM_X_BONUS_TREE);
DB2Storage<KeyChainEntry>                       sKeyChainStore("KeyChain.db2", KeyChainFormat, HOTFIX_SEL_KEY_CHAIN);
DB2Storage<MailTemplateEntry>                   sMailTemplateStore("MailTemplate.db2", MailTemplateFormat, HOTFIX_SEL_MAIL_TEMPLATE);
DB2Storage<ModifierTreeEntry>                   sModifierTreeStore("ModifierTree.db2", ModifierTreeFormat, HOTFIX_SEL_MODIFIER_TREE);
DB2Storage<MountCapabilityEntry>                sMountCapabilityStore("MountCapability.db2", MountCapabilityFormat, HOTFIX_SEL_MOUNT_CAPABILITY);
DB2Storage<MountEntry>                          sMountStore("Mount.db2", MountFormat, HOTFIX_SEL_MOUNT);
DB2Storage<MountTypeXCapabilityEntry>           sMountTypeXCapabilityStore("MountTypeXCapability.db2", MountTypeXCapabilityFormat, HOTFIX_SEL_MOUNT_TYPE_X_CAPABILITY);
DB2Storage<NameGenEntry>                        sNameGenStore("NameGen.db2", NameGenFormat, HOTFIX_SEL_NAME_GEN);
DB2Storage<NamesProfanityEntry>                 sNamesProfanityStore("NamesProfanity.db2", NamesProfanityFormat, HOTFIX_SEL_NAMES_PROFANITY);
DB2Storage<NamesReservedEntry>                  sNamesReservedStore("NamesReserved.db2", NamesReservedFormat, HOTFIX_SEL_NAMES_RESERVED);
DB2Storage<NamesReservedLocaleEntry>            sNamesReservedLocaleStore("NamesReservedLocale.db2", NamesReservedLocaleFormat, HOTFIX_SEL_NAMES_RESERVED_LOCALE);
DB2Storage<OverrideSpellDataEntry>              sOverrideSpellDataStore("OverrideSpellData.db2", OverrideSpellDataFormat, HOTFIX_SEL_OVERRIDE_SPELL_DATA);
DB2Storage<PhaseXPhaseGroupEntry>               sPhaseXPhaseGroupStore("PhaseXPhaseGroup.db2", PhaseXPhaseGroupFormat, HOTFIX_SEL_PHASE_X_PHASE_GROUP);
DB2Storage<QuestMoneyRewardEntry>               sQuestMoneyRewardStore("QuestMoneyReward.db2", QuestMoneyRewardFormat, HOTFIX_SEL_QUEST_MONEY_REWARD);
DB2Storage<QuestPackageItemEntry>               sQuestPackageItemStore("QuestPackageItem.db2", QuestPackageItemfmt, HOTFIX_SEL_QUEST_PACKAGE_ITEM);
DB2Storage<QuestSortEntry>                      sQuestSortStore("QuestSort.db2", QuestSortFormat, HOTFIX_SEL_QUEST_SORT);
DB2Storage<QuestV2Entry>                        sQuestV2Store("QuestV2.db2", QuestV2Format, HOTFIX_SEL_QUEST_V2);
DB2Storage<QuestXPEntry>                        sQuestXPStore("QuestXP.db2", QuestXPFormat, HOTFIX_SEL_QUEST_XP);
DB2Storage<ScalingStatDistributionEntry>        sScalingStatDistributionStore("ScalingStatDistribution.db2", ScalingStatDistributionFormat, HOTFIX_SEL_SCALING_STAT_DISTRIBUTION);
DB2Storage<SoundEntriesEntry>                   sSoundEntriesStore("SoundEntries.db2", SoundEntriesFormat, HOTFIX_SEL_SOUND_ENTRIES);
DB2Storage<SpecializationSpellsEntry>           sSpecializationSpellsStore("SpecializationSpells.db2", SpecializationSpellsFormat, HOTFIX_SEL_SPECIALIZATION_SPELLS);
DB2Storage<SpellAuraRestrictionsEntry>          sSpellAuraRestrictionsStore("SpellAuraRestrictions.db2", SpellAuraRestrictionsFormat, HOTFIX_SEL_SPELL_AURA_RESTRICTIONS);
DB2Storage<SpellCastTimesEntry>                 sSpellCastTimesStore("SpellCastTimes.db2", SpellCastTimesFormat, HOTFIX_SEL_SPELL_CAST_TIMES);
DB2Storage<SpellCastingRequirementsEntry>       sSpellCastingRequirementsStore("SpellCastingRequirements.db2", SpellCastingRequirementsFormat, HOTFIX_SEL_SPELL_CASTING_REQUIREMENTS);
DB2Storage<SpellClassOptionsEntry>              sSpellClassOptionsStore("SpellClassOptions.db2", SpellClassOptionsFormat, HOTFIX_SEL_SPELL_CLASS_OPTIONS);
DB2Storage<SpellDurationEntry>                  sSpellDurationStore("SpellDuration.db2", SpellDurationFormat, HOTFIX_SEL_SPELL_DURATION);
DB2Storage<SpellItemEnchantmentConditionEntry>  sSpellItemEnchantmentConditionStore("SpellItemEnchantmentCondition.db2", SpellItemEnchantmentConditionFormat, HOTFIX_SEL_SPELL_ITEM_ENCHANTMENT_CONDITION);
DB2Storage<SpellLearnSpellEntry>                sSpellLearnSpellStore("SpellLearnSpell.db2", SpellLearnSpellFormat, HOTFIX_SEL_SPELL_LEARN_SPELL);
DB2Storage<SpellMiscEntry>                      sSpellMiscStore("SpellMisc.db2", SpellMiscFormat, HOTFIX_SEL_SPELL_MISC);
DB2Storage<SpellPowerDifficultyEntry>           sSpellPowerDifficultyStore("SpellPowerDifficulty.db2", SpellPowerDifficultyFormat, HOTFIX_SEL_SPELL_POWER_DIFFICULTY);
DB2Storage<SpellPowerEntry>                     sSpellPowerStore("SpellPower.db2", SpellPowerFormat, HOTFIX_SEL_SPELL_POWER);
DB2Storage<SpellRadiusEntry>                    sSpellRadiusStore("SpellRadius.db2", SpellRadiusFormat, HOTFIX_SEL_SPELL_RADIUS);
DB2Storage<SpellRangeEntry>                     sSpellRangeStore("SpellRange.db2", SpellRangeFormat, HOTFIX_SEL_SPELL_RANGE);
DB2Storage<SpellReagentsEntry>                  sSpellReagentsStore("SpellReagents.db2", SpellReagentsFormat, HOTFIX_SEL_SPELL_REAGENTS);
DB2Storage<SpellRuneCostEntry>                  sSpellRuneCostStore("SpellRuneCost.db2", SpellRuneCostFormat, HOTFIX_SEL_SPELL_RUNE_COST);
DB2Storage<SpellTotemsEntry>                    sSpellTotemsStore("SpellTotems.db2", SpellTotemsFormat, HOTFIX_SEL_SPELL_TOTEMS);
DB2Storage<SpellXSpellVisualEntry>              sSpellXSpellVisualStore("SpellXSpellVisual.db2", SpellXSpellVisualFormat, HOTFIX_SEL_SPELL_X_SPELL_VISUAL);
DB2Storage<TaxiNodesEntry>                      sTaxiNodesStore("TaxiNodes.db2", TaxiNodesFormat, HOTFIX_SEL_TAXI_NODES);
DB2Storage<TaxiPathEntry>                       sTaxiPathStore("TaxiPath.db2", TaxiPathFormat, HOTFIX_SEL_TAXI_PATH);
DB2Storage<TaxiPathNodeEntry>                   sTaxiPathNodeStore("TaxiPathNode.db2", TaxiPathNodeFormat, HOTFIX_SEL_TAXI_PATH_NODE);
DB2Storage<TotemCategoryEntry>                  sTotemCategoryStore("TotemCategory.db2", TotemCategoryFormat, HOTFIX_SEL_TOTEM_CATEGORY);
DB2Storage<ToyEntry>                            sToyStore("Toy.db2", ToyFormat, HOTFIX_SEL_TOY);
DB2Storage<TransportAnimationEntry>             sTransportAnimationStore("TransportAnimation.db2", TransportAnimationFormat, HOTFIX_SEL_TRANSPORT_ANIMATION);
DB2Storage<TransportRotationEntry>              sTransportRotationStore("TransportRotation.db2", TransportRotationFormat, HOTFIX_SEL_TRANSPORT_ROTATION);
DB2Storage<UnitPowerBarEntry>                   sUnitPowerBarStore("UnitPowerBar.db2", UnitPowerBarFormat, HOTFIX_SEL_UNIT_POWER_BAR);
DB2Storage<WorldMapOverlayEntry>                sWorldMapOverlayStore("WorldMapOverlay.db2", WorldMapOverlayFormat, HOTFIX_SEL_WORLD_MAP_OVERLAY);

TaxiMask                                        sTaxiNodesMask;
TaxiMask                                        sOldContinentsNodesMask;
TaxiMask                                        sHordeTaxiNodesMask;
TaxiMask                                        sAllianceTaxiNodesMask;
TaxiPathSetBySource                             sTaxiPathSetBySource;
TaxiPathNodesByPath                             sTaxiPathNodesByPath;

typedef std::list<std::string> DB2StoreProblemList;

uint32 DB2FilesCount = 0;

template<class T>
inline void LoadDB2(uint32& availableDb2Locales, DB2StoreProblemList& errlist, DB2Manager::StorageMap& stores, DB2Storage<T>* storage, std::string const& db2Path, uint32 defaultLocale)
{
    // compatibility format and C++ structure sizes
    ASSERT(DB2FileLoader::GetFormatRecordSize(storage->GetFormat()) == sizeof(T),
        "Size of '%s' set by format string (%u) not equal size of C++ structure (" SZFMTD ").",
        storage->GetFileName().c_str(), DB2FileLoader::GetFormatRecordSize(storage->GetFormat()), sizeof(T));

    ++DB2FilesCount;

    if (storage->Load(db2Path + localeNames[defaultLocale] + '/', defaultLocale))
    {
        storage->LoadFromDB();

        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (defaultLocale == i)
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
        if (FILE* f = fopen((db2Path + storage->GetFileName()).c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << storage->GetFileName() << " exists, and has " << storage->GetFieldCount() << " field(s) (expected " << strlen(storage->GetFormat())
                << "). Extracted file might be from wrong client version.";
            std::string buf = stream.str();
            errlist.push_back(buf);
            fclose(f);
        }
        else
            errlist.push_back(storage->GetFileName());
    }

    stores[storage->GetHash()] = storage;
}

void DB2Manager::LoadStores(std::string const& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string db2Path = dataPath + "dbc/";

    DB2StoreProblemList bad_db2_files;
    uint32 availableDb2Locales = 0xFF;

#define LOAD_DB2(store) LoadDB2(availableDb2Locales, bad_db2_files, _stores, &store, db2Path, defaultLocale)

    LOAD_DB2(sAchievementStore);
    LOAD_DB2(sAreaGroupMemberStore);
    LOAD_DB2(sAreaGroupStore);
    LOAD_DB2(sBattlePetBreedQualityStore);
    LOAD_DB2(sBattlePetBreedStateStore);
    LOAD_DB2(sAuctionHouseStore);
    LOAD_DB2(sBarberShopStyleStore);
    LOAD_DB2(sBattlePetSpeciesStore);
    LOAD_DB2(sBattlePetSpeciesStateStore);
    LOAD_DB2(sBroadcastTextStore);
    LOAD_DB2(sCharStartOutfitStore);
    LOAD_DB2(sChrClassesXPowerTypesStore);
    LOAD_DB2(sCinematicSequencesStore);
    LOAD_DB2(sCreatureDisplayInfoStore);
    LOAD_DB2(sCreatureTypeStore);
    LOAD_DB2(sCriteriaStore);
    LOAD_DB2(sCriteriaTreeStore);
    LOAD_DB2(sCurrencyTypesStore);
    LOAD_DB2(sCurvePointStore);
    LOAD_DB2(sDestructibleModelDataStore);
    LOAD_DB2(sDurabilityQualityStore);
    LOAD_DB2(sGameObjectsStore);
    LOAD_DB2(sGameTablesStore);
    LOAD_DB2(sGarrAbilityStore);
    LOAD_DB2(sGarrBuildingPlotInstStore);
    LOAD_DB2(sGarrBuildingStore);
    LOAD_DB2(sGarrClassSpecStore);
    LOAD_DB2(sGarrFollowerStore);
    LOAD_DB2(sGarrFollowerXAbilityStore);
    LOAD_DB2(sGarrPlotBuildingStore);
    LOAD_DB2(sGarrPlotInstanceStore);
    LOAD_DB2(sGarrPlotStore);
    LOAD_DB2(sGarrSiteLevelPlotInstStore);
    LOAD_DB2(sGarrSiteLevelStore);
    LOAD_DB2(sGlyphSlotStore);
    LOAD_DB2(sGuildPerkSpellsStore);
    LOAD_DB2(sHeirloomStore);
    LOAD_DB2(sHolidaysStore);
    LOAD_DB2(sImportPriceArmorStore);
    LOAD_DB2(sImportPriceQualityStore);
    LOAD_DB2(sImportPriceShieldStore);
    LOAD_DB2(sImportPriceWeaponStore);
    LOAD_DB2(sItemAppearanceStore);
    LOAD_DB2(sItemBonusStore);
    LOAD_DB2(sItemBonusTreeNodeStore);
    LOAD_DB2(sItemClassStore);
    LOAD_DB2(sItemCurrencyCostStore);
    LOAD_DB2(sItemDisenchantLootStore);
    LOAD_DB2(sItemEffectStore);
    LOAD_DB2(sItemExtendedCostStore);
    LOAD_DB2(sItemLimitCategoryStore);
    LOAD_DB2(sItemModifiedAppearanceStore);
    LOAD_DB2(sItemPriceBaseStore);
    LOAD_DB2(sItemRandomPropertiesStore);
    LOAD_DB2(sItemRandomSuffixStore);
    LOAD_DB2(sItemSparseStore);
    LOAD_DB2(sItemSpecOverrideStore);
    LOAD_DB2(sItemSpecStore);
    LOAD_DB2(sItemStore);
    LOAD_DB2(sItemToBattlePetSpeciesStore);
    LOAD_DB2(sItemXBonusTreeStore);
    LOAD_DB2(sKeyChainStore);
    LOAD_DB2(sMailTemplateStore);
    LOAD_DB2(sModifierTreeStore);
    LOAD_DB2(sMountCapabilityStore);
    LOAD_DB2(sMountStore);
    LOAD_DB2(sMountTypeXCapabilityStore);
    LOAD_DB2(sNameGenStore);
    LOAD_DB2(sNamesProfanityStore);
    LOAD_DB2(sNamesReservedStore);
    LOAD_DB2(sNamesReservedLocaleStore);
    LOAD_DB2(sOverrideSpellDataStore);
    LOAD_DB2(sPhaseXPhaseGroupStore);
    LOAD_DB2(sQuestMoneyRewardStore);
    LOAD_DB2(sQuestPackageItemStore);
    LOAD_DB2(sQuestSortStore);
    LOAD_DB2(sQuestV2Store);
    LOAD_DB2(sQuestXPStore);
    LOAD_DB2(sScalingStatDistributionStore);
    LOAD_DB2(sSoundEntriesStore);
    LOAD_DB2(sSpecializationSpellsStore);
    LOAD_DB2(sSpellAuraRestrictionsStore);
    LOAD_DB2(sSpellCastTimesStore);
    LOAD_DB2(sSpellCastingRequirementsStore);
    LOAD_DB2(sSpellClassOptionsStore);
    LOAD_DB2(sSpellDurationStore);
    LOAD_DB2(sSpellItemEnchantmentConditionStore);
    LOAD_DB2(sSpellLearnSpellStore);
    LOAD_DB2(sSpellMiscStore);
    LOAD_DB2(sSpellPowerDifficultyStore);
    LOAD_DB2(sSpellPowerStore);
    LOAD_DB2(sSpellRadiusStore);
    LOAD_DB2(sSpellRangeStore);
    LOAD_DB2(sSpellReagentsStore);
    LOAD_DB2(sSpellRuneCostStore);
    LOAD_DB2(sSpellTotemsStore);
    LOAD_DB2(sSpellXSpellVisualStore);
    LOAD_DB2(sTaxiNodesStore);
    LOAD_DB2(sTaxiPathNodeStore);
    LOAD_DB2(sTaxiPathStore);
    LOAD_DB2(sTotemCategoryStore);
    LOAD_DB2(sToyStore);
    LOAD_DB2(sTransportAnimationStore);
    LOAD_DB2(sTransportRotationStore);
    LOAD_DB2(sUnitPowerBarStore);
    LOAD_DB2(sWorldMapOverlayStore);

#undef LOAD_DB2

    for (AreaGroupMemberEntry const* areaGroupMember : sAreaGroupMemberStore)
        _areaGroupMembers[areaGroupMember->AreaGroupID].push_back(areaGroupMember->AreaID);

    for (CharStartOutfitEntry const* outfit : sCharStartOutfitStore)
        _charStartOutfits[outfit->RaceID | (outfit->ClassID << 8) | (outfit->GenderID << 16)] = outfit;

    sChrClassesXPowerTypesStore.Sort(&ChrClassesXPowerTypesEntryComparator::Compare);
    for (uint32 i = 0; i < MAX_CLASSES; ++i)
        for (uint32 j = 0; j < MAX_POWERS; ++j)
            _powersByClass[i][j] = MAX_POWERS;

    for (ChrClassesXPowerTypesEntry const* power : sChrClassesXPowerTypesStore)
    {
        uint32 index = 0;
        for (uint32 j = 0; j < MAX_POWERS; ++j)
            if (_powersByClass[power->ClassID][j] != MAX_POWERS)
                ++index;

        _powersByClass[power->ClassID][power->PowerType] = index;
    }

    for (GlyphSlotEntry const* glyphSlot : sGlyphSlotStore)
        if (glyphSlot->Type == GLYPH_SLOT_MAJOR || glyphSlot->Type == GLYPH_SLOT_MINOR)
            _glyphSlots.insert(glyphSlot);

    for (ItemBonusEntry const* bonus : sItemBonusStore)
        _itemBonusLists[bonus->BonusListID].push_back(bonus);

    for (ItemBonusTreeNodeEntry const* bonusTreeNode : sItemBonusTreeNodeStore)
    {
        uint32 bonusTreeId = bonusTreeNode->BonusTreeID;
        while (bonusTreeNode)
        {
            _itemBonusTrees[bonusTreeId].insert(bonusTreeNode);
            bonusTreeNode = sItemBonusTreeNodeStore.LookupEntry(bonusTreeNode->SubTreeID);
        }
    }

    for (ItemModifiedAppearanceEntry const* appearanceMod : sItemModifiedAppearanceStore)
        if (ItemAppearanceEntry const* appearance = sItemAppearanceStore.LookupEntry(appearanceMod->AppearanceID))
            _itemDisplayIDs[appearanceMod->ItemID | (appearanceMod->AppearanceModID << 24)] = appearance->DisplayID;

    for (ItemSpecOverrideEntry const* entry : sItemSpecOverrideStore)
        _itemSpecOverrides[entry->ItemID].push_back(entry);

    for (ItemXBonusTreeEntry const* itemBonusTreeAssignment : sItemXBonusTreeStore)
        _itemToBonusTree.insert({ itemBonusTreeAssignment->ItemID, itemBonusTreeAssignment->BonusTreeID });

    {
        std::set<uint32> scalingCurves;
        for (ScalingStatDistributionEntry const* ssd : sScalingStatDistributionStore)
            scalingCurves.insert(ssd->ItemLevelCurveID);

        for (CurvePointEntry const* curvePoint : sCurvePointStore)
            if (scalingCurves.count(curvePoint->CurveID))
                _heirloomCurvePoints[curvePoint->CurveID][curvePoint->Index] = curvePoint;
    }

    for (MountEntry const* mount : sMountStore)
        _mountsBySpellId[mount->SpellId] = mount;

    for (MountTypeXCapabilityEntry const* mount : sMountTypeXCapabilityStore)
        _mountCapabilitiesByType[mount->MountTypeID].insert(mount);

    for (NameGenEntry const* entry : sNameGenStore)
        _nameGenData[entry->Race][entry->Sex].push_back(entry);

    for (NamesProfanityEntry const* namesProfanity : sNamesProfanityStore)
    {
        ASSERT(namesProfanity->Language < TOTAL_LOCALES || namesProfanity->Language == -1);
        if (namesProfanity->Language != -1)
            _nameValidators[namesProfanity->Language].emplace_back(namesProfanity->Name, boost::regex::perl | boost::regex::icase | boost::regex::optimize);
        else
            for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                _nameValidators[i].emplace_back(namesProfanity->Name, boost::regex::perl | boost::regex::icase | boost::regex::optimize);
    }

    for (NamesReservedEntry const* namesReserved : sNamesReservedStore)
        _nameValidators[TOTAL_LOCALES].emplace_back(namesReserved->Name, boost::regex::perl | boost::regex::icase | boost::regex::optimize);

    for (NamesReservedLocaleEntry const* namesReserved : sNamesReservedLocaleStore)
    {
        ASSERT(!(namesReserved->LocaleMask & ~((1 << TOTAL_LOCALES) - 1)));
        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
            if (namesReserved->LocaleMask & (1 << i))
                _nameValidators[i].emplace_back(namesReserved->Name, boost::regex::perl | boost::regex::icase | boost::regex::optimize);
    }

    for (PhaseXPhaseGroupEntry const* group : sPhaseXPhaseGroupStore)
        if (PhaseEntry const* phase = sPhaseStore.LookupEntry(group->PhaseID))
            _phasesByGroup[group->PhaseGroupID].insert(phase->ID);

    for (QuestPackageItemEntry const* questPackageItem : sQuestPackageItemStore)
        _questPackages[questPackageItem->QuestPackageID].push_back(questPackageItem);

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

    for (TaxiPathEntry const* entry : sTaxiPathStore)
        sTaxiPathSetBySource[entry->From][entry->To] = TaxiPathBySourceAndDestination(entry->ID, entry->Cost);

    uint32 pathCount = sTaxiPathStore.GetNumRows();

    // Calculate path nodes count
    std::vector<uint32> pathLength;
    pathLength.resize(pathCount);                           // 0 and some other indexes not used
    for (TaxiPathNodeEntry const* entry : sTaxiPathNodeStore)
        if (pathLength[entry->PathID] < entry->NodeIndex + 1)
            pathLength[entry->PathID] = entry->NodeIndex + 1;

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
        _toys.push_back(toy->ItemID);

    for (HeirloomEntry const* heirloom : sHeirloomStore)
        _heirlooms[heirloom->ItemID] = heirloom;

    // error checks
    if (bad_db2_files.size() >= DB2FilesCount)
    {
        TC_LOG_ERROR("misc", "\nIncorrect DataDir value in worldserver.conf or ALL required *.db2 files (%d) not found by path: %sdbc/%s/", DB2FilesCount, dataPath.c_str(), localeNames[defaultLocale]);
        exit(1);
    }
    else if (!bad_db2_files.empty())
    {
        std::string str;
        for (std::list<std::string>::iterator i = bad_db2_files.begin(); i != bad_db2_files.end(); ++i)
            str += *i + "\n";

        TC_LOG_ERROR("misc", "\nSome required *.db2 files (%u from %d) not found or not compatible:\n%s", (uint32)bad_db2_files.size(), DB2FilesCount, str.c_str());
        exit(1);
    }

    // Check loaded DB2 files proper version
    if (!sItemStore.LookupEntry(128706)             ||       // last item added in 6.2.0 (20216)
        !sItemExtendedCostStore.LookupEntry(5923)  )        // last item extended cost added in 6.2.0 (20216)
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

CharStartOutfitEntry const* DB2Manager::GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender) const
{
    auto itr = _charStartOutfits.find(race | (class_ << 8) | (gender << 16));
    if (itr == _charStartOutfits.end())
        return nullptr;

    return itr->second;
}

uint32 DB2Manager::GetPowerIndexByClass(uint32 powerType, uint32 classId) const
{
    return _powersByClass[classId][powerType];
}

uint32 DB2Manager::GetHeirloomItemLevel(uint32 curveId, uint32 level) const
{
    // Assuming linear item level scaling for heirlooms
    auto itr = _heirloomCurvePoints.find(curveId);
    if (itr == _heirloomCurvePoints.end())
        return 0;

    auto it2 = itr->second.begin(); // Highest scaling point
    if (level >= it2->second->X)
        return it2->second->Y;

    auto previousItr = it2++;
    for (; it2 != itr->second.end(); ++it2, ++previousItr)
        if (level >= it2->second->X)
            return uint32((previousItr->second->Y - it2->second->Y) / (previousItr->second->X - it2->second->X) * (float(level) - it2->second->X) + it2->second->Y);

    return uint32(previousItr->second->Y);  // Lowest scaling point
}

DB2Manager::ItemBonusList const* DB2Manager::GetItemBonusList(uint32 bonusListId) const
{
    auto itr = _itemBonusLists.find(bonusListId);
    if (itr != _itemBonusLists.end())
        return &itr->second;

    return nullptr;
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

uint32 DB2Manager::GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const
{
    auto itr = _itemDisplayIDs.find(itemId | (appearanceModId << 24));
    if (itr != _itemDisplayIDs.end())
        return itr->second;

    // Fall back to unmodified appearance
    if (appearanceModId)
    {
        itr = _itemDisplayIDs.find(itemId);
        if (itr != _itemDisplayIDs.end())
            return itr->second;
    }

    return 0;
}

std::vector<ItemSpecOverrideEntry const*> const* DB2Manager::GetItemSpecOverrides(uint32 itemId) const
{
    auto itr = _itemSpecOverrides.find(itemId);
    if (itr != _itemSpecOverrides.end())
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

ResponseCodes DB2Manager::ValidateName(std::string const& name, LocaleConstant locale) const
{
    for (boost::regex const& regex : _nameValidators[locale])
        if (boost::regex_search(name, regex))
            return CHAR_NAME_PROFANE;

    // regexes at TOTAL_LOCALES are loaded from NamesReserved which is not locale specific
    for (boost::regex const& regex : _nameValidators[TOTAL_LOCALES])
        if (boost::regex_search(name, regex))
            return CHAR_NAME_RESERVED;

    return CHAR_NAME_SUCCESS;
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

bool DB2Manager::ChrClassesXPowerTypesEntryComparator::Compare(ChrClassesXPowerTypesEntry const* left, ChrClassesXPowerTypesEntry const* right)
{
    if (left->ClassID != right->ClassID)
        return left->ClassID < right->ClassID;
    return left->PowerType < right->PowerType;
}

bool DB2Manager::GlyphSlotEntryComparator::Compare(GlyphSlotEntry const* left, GlyphSlotEntry const* right)
{
    if (left->Tooltip != right->Tooltip)
        return left->Tooltip < right->Tooltip;
    return left->Type > right->Type;
}

bool DB2Manager::MountTypeXCapabilityEntryComparator::Compare(MountTypeXCapabilityEntry const* left, MountTypeXCapabilityEntry const* right)
{
    if (left->MountTypeID == right->MountTypeID)
        return left->OrderIndex < right->OrderIndex;
    return left->ID < right->ID;
}

bool DB2Manager::GetToyItemIdMatch(uint32 toy) const
{
    return std::find(_toys.begin(), _toys.end(), toy) != _toys.end();
}

HeirloomEntry const* DB2Manager::GetHeirloomByItemId(uint32 itemId) const
{
    auto itr = _heirlooms.find(itemId);
    if (itr != _heirlooms.end())
        return itr->second;

    return nullptr;
}
