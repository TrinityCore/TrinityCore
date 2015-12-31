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

#include "HotfixDatabase.h"

// Force locale statments to appear exactly in locale declaration order, right after normal data fetch statement
#define PREPARE_LOCALE_STMT(stmtBase, sql, con) \
    static_assert(stmtBase + 1 == stmtBase##_LOCALE, "Invalid prepared statement index for " #stmtBase "_LOCALE"); \
    PrepareStatement(stmtBase##_LOCALE, sql, con);

void HotfixDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_HOTFIXDATABASE_STATEMENTS);

    // Achievement.db2
    PrepareStatement(HOTFIX_SEL_ACHIEVEMENT, "SELECT ID, Faction, MapID, Supercedes, Title, Description, Category, Points, UIOrder, Flags, IconID, "
        "Reward, MinimumCriteria, SharesCriteria, CriteriaTree FROM achievement ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_ACHIEVEMENT, "SELECT ID, Title_lang, Description_lang, Reward_lang FROM achievement_locale WHERE locale = ?", CONNECTION_SYNCH);

    // AreaGroup.db2
    PrepareStatement(HOTFIX_SEL_AREA_GROUP, "SELECT ID FROM area_group ORDER BY ID DESC", CONNECTION_SYNCH);

    // AreaGroupMember.db2
    PrepareStatement(HOTFIX_SEL_AREA_GROUP_MEMBER, "SELECT ID, AreaGroupID, AreaID FROM area_group_member ORDER BY ID DESC", CONNECTION_SYNCH);

    // AuctionHouse.db2
    PrepareStatement(HOTFIX_SEL_AUCTION_HOUSE, "SELECT ID, FactionID, DepositRate, ConsignmentRate, Name FROM auction_house ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_AUCTION_HOUSE, "SELECT ID, Name_lang FROM auction_house_locale WHERE locale = ?", CONNECTION_SYNCH);

    // BarberShopStyle.db2
    PrepareStatement(HOTFIX_SEL_BARBER_SHOP_STYLE, "SELECT ID, Type, DisplayName, Description, CostModifier, Race, Sex, Data FROM barber_shop_style"
        " ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_BARBER_SHOP_STYLE, "SELECT ID, DisplayName_lang, Description_lang FROM barber_shop_style_locale WHERE locale = ?", CONNECTION_SYNCH);

    // BattlePetBreedQuality.db2
    PrepareStatement(HOTFIX_SEL_BATTLE_PET_BREED_QUALITY, "SELECT ID, Quality, Modifier FROM battle_pet_breed_quality ORDER BY ID DESC", CONNECTION_SYNCH);

    // BattlePetBreedState.db2
    PrepareStatement(HOTFIX_SEL_BATTLE_PET_BREED_STATE, "SELECT ID, BreedID, State, Value FROM battle_pet_breed_state ORDER BY ID DESC", CONNECTION_SYNCH);

    // BattlePetSpecies.db2
    PrepareStatement(HOTFIX_SEL_BATTLE_PET_SPECIES, "SELECT ID, CreatureID, IconFileID, SummonSpellID, PetType, Source, Flags, "
        "SourceText, Description FROM battle_pet_species ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_BATTLE_PET_SPECIES, "SELECT ID, SourceText, Description FROM battle_pet_species_locale WHERE locale = ?", CONNECTION_SYNCH);

    // BattlePetSpeciesState.db2
    PrepareStatement(HOTFIX_SEL_BATTLE_PET_SPECIES_STATE, "SELECT ID, SpeciesID, State, Value FROM battle_pet_species_state ORDER BY ID DESC", CONNECTION_SYNCH);

    // BroadcastText.db2
    PrepareStatement(HOTFIX_SEL_BROADCAST_TEXT, "SELECT ID, Language, MaleText, FemaleText, EmoteID1, EmoteID2, EmoteID3, EmoteDelay1, EmoteDelay2, "
        "EmoteDelay3, SoundID, UnkEmoteID, Type FROM broadcast_text ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_BROADCAST_TEXT, "SELECT ID, MaleText_lang, FemaleText_lang FROM broadcast_text_locale WHERE locale = ?", CONNECTION_SYNCH);

    // CharStartOutfit.db2
    PrepareStatement(HOTFIX_SEL_CHAR_START_OUTFIT, "SELECT ID, RaceID, ClassID, GenderID, OutfitID, ItemID1, ItemID2, ItemID3, ItemID4, ItemID5, "
        "ItemID6, ItemID7, ItemID8, ItemID9, ItemID10, ItemID11, ItemID12, ItemID13, ItemID14, ItemID15, ItemID16, ItemID17, ItemID18, ItemID19, "
        "ItemID20, ItemID21, ItemID22, ItemID23, ItemID24, PetDisplayID, PetFamilyID FROM char_start_outfit ORDER BY ID DESC", CONNECTION_SYNCH);

    // ChrClassesXPowerTypes.db2
    PrepareStatement(HOTFIX_SEL_CHR_CLASSES_X_POWER_TYPES, "SELECT ID, ClassID, PowerType FROM chr_classes_x_power_types ORDER BY ID DESC", CONNECTION_SYNCH);

    // CinematicSequences.db2
    PrepareStatement(HOTFIX_SEL_CINEMATIC_SEQUENCES, "SELECT ID, SoundID, Camera1, Camera2, Camera3, Camera4, Camera5, Camera6, Camera7, Camera8"
        " FROM cinematic_sequences ORDER BY ID DESC", CONNECTION_SYNCH);

    // CreatureDisplayInfo.db2
    PrepareStatement(HOTFIX_SEL_CREATURE_DISPLAY_INFO, "SELECT ID, ModelID, SoundID, ExtendedDisplayInfoID, CreatureModelScale, Unknown620, "
        "CreatureModelAlpha, TextureVariation1, TextureVariation2, TextureVariation3, PortraitTextureName, PortraitCreatureDisplayInfoID, SizeClass, "
        "BloodID, NPCSoundID, ParticleColorID, CreatureGeosetData, ObjectEffectPackageID, AnimReplacementSetID, Flags, Gender, StateSpellVisualKitID"
        " FROM creature_display_info ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_CREATURE_DISPLAY_INFO, "SELECT ID, TextureVariation_lang1, TextureVariation_lang2, TextureVariation_lang3, "
        "PortraitTextureName_lang FROM creature_display_info_locale WHERE locale = ?", CONNECTION_SYNCH);

    // CreatureType.db2
    PrepareStatement(HOTFIX_SEL_CREATURE_TYPE, "SELECT ID, Name, Flags FROM creature_type ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_CREATURE_TYPE, "SELECT ID, Name_lang FROM creature_type_locale WHERE locale = ?", CONNECTION_SYNCH);

    // Criteria.db2
    PrepareStatement(HOTFIX_SEL_CRITERIA, "SELECT ID, Type, Asset, StartEvent, StartAsset, StartTimer, FailEvent, FailAsset, ModifierTreeId, Flags, "
        "EligibilityWorldStateID, EligibilityWorldStateValue FROM criteria ORDER BY ID DESC", CONNECTION_SYNCH);

    // CriteriaTree.db2
    PrepareStatement(HOTFIX_SEL_CRITERIA_TREE, "SELECT ID, CriteriaID, Operator, Parent, Flags, Description, OrderIndex FROM criteria_tree"
        " ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_CRITERIA_TREE, "SELECT ID, Description_lang FROM criteria_tree_locale WHERE locale = ?", CONNECTION_SYNCH);

    // CurrencyTypes.db2
    PrepareStatement(HOTFIX_SEL_CURRENCY_TYPES, "SELECT ID, CategoryID, Name, InventoryIcon1, InventoryIcon2, SpellWeight, SpellCategory, MaxQty, "
        "MaxEarnablePerWeek, Flags, Quality, Description FROM currency_types ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_CURRENCY_TYPES, "SELECT ID, Name_lang, InventoryIcon1_lang, InventoryIcon2_lang, Description_lang"
        " FROM currency_types_locale WHERE locale = ?", CONNECTION_SYNCH);

    // CurvePoint.db2
    PrepareStatement(HOTFIX_SEL_CURVE_POINT, "SELECT ID, CurveID, `Index`, X, Y FROM curve_point ORDER BY ID DESC", CONNECTION_SYNCH);

    // DestructibleModelData.db2
    PrepareStatement(HOTFIX_SEL_DESTRUCTIBLE_MODEL_DATA, "SELECT ID, StateDamagedDisplayID, StateDamagedImpactEffectDoodadSet, StateDamagedAmbientDoodadSet, "
        "StateDamagedNameSet, StateDestroyedDisplayID, StateDestroyedDestructionDoodadSet, StateDestroyedImpactEffectDoodadSet, StateDestroyedAmbientDoodadSet, "
        "StateDestroyedNameSet, StateRebuildingDisplayID, StateRebuildingDestructionDoodadSet, StateRebuildingImpactEffectDoodadSet, "
        "StateRebuildingAmbientDoodadSet, StateRebuildingNameSet, StateSmokeDisplayID, StateSmokeInitDoodadSet, StateSmokeAmbientDoodadSet, StateSmokeNameSet, "
        "EjectDirection, RepairGroundFx, DoNotHighlight, HealEffect, HealEffectSpeed FROM destructible_model_data ORDER BY ID DESC", CONNECTION_SYNCH);

    // DurabilityQuality.db2
    PrepareStatement(HOTFIX_SEL_DURABILITY_QUALITY, "SELECT ID, QualityMod FROM durability_quality ORDER BY ID DESC", CONNECTION_SYNCH);

    // GameObjects.db2
    PrepareStatement(HOTFIX_SEL_GAMEOBJECTS, "SELECT ID, MapID, DisplayID, PositionX, PositionY, PositionZ, RotationX, RotationY, RotationZ, "
        "RotationW, Size, PhaseUseFlags, PhaseID, PhaseGroupID, Type, Data0, Data1, Data2, Data3, Data4, Data5, Data6, Data7, Name FROM gameobjects"
        " ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GAMEOBJECTS, "SELECT ID, Name_lang FROM gameobjects_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GameTables.db2
    PrepareStatement(HOTFIX_SEL_GAME_TABLES, "SELECT ID, Name, NumRows, NumColumns FROM game_tables ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GAME_TABLES, "SELECT ID, Name_lang FROM game_tables_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrAbility.db2
    PrepareStatement(HOTFIX_SEL_GARR_ABILITY, "SELECT ID, Flags, Name, Description, IconFileDataID, OtherFactionGarrAbilityID, GarrAbilityCategoryID, "
        "FollowerTypeID FROM garr_ability ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_ABILITY, "SELECT ID, Name_lang, Description_lang FROM garr_ability_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrBuilding.db2
    PrepareStatement(HOTFIX_SEL_GARR_BUILDING, "SELECT ID, HordeGameObjectID, AllianceGameObjectID, Unknown, Type, Level, NameAlliance, NameHorde, "
        "Description, Tooltip, BuildDuration, CostCurrencyID, CostCurrencyAmount, HordeTexPrefixKitID, AllianceTexPrefixKitID, IconFileDataID, "
        "BonusAmount, Flags, AllianceActivationScenePackageID, HordeActivationScenePackageID, MaxShipments, FollowerRequiredGarrAbilityID, "
        "FollowerGarrAbilityEffectID, CostMoney FROM garr_building ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_BUILDING, "SELECT ID, NameAlliance_lang, NameHorde_lang, Description_lang, Tooltip_lang"
        " FROM garr_building_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrBuildingPlotInst.db2
    PrepareStatement(HOTFIX_SEL_GARR_BUILDING_PLOT_INST, "SELECT ID, GarrBuildingID, UiTextureAtlasMemberID, GarrSiteLevelPlotInstID, "
        "LandmarkOffsetX, LandmarkOffsetY FROM garr_building_plot_inst ORDER BY ID DESC", CONNECTION_SYNCH);

    // GarrClassSpec.db2
    PrepareStatement(HOTFIX_SEL_GARR_CLASS_SPEC, "SELECT ID, NameMale, NameFemale, NameGenderless, ClassAtlasID, GarrFollItemSetID"
        " FROM garr_class_spec ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_CLASS_SPEC, "SELECT ID, NameMale_lang, NameFemale_lang, NameGenderless_lang FROM garr_class_spec_locale"
        " WHERE locale = ?", CONNECTION_SYNCH);

    // GarrFollower.db2
    PrepareStatement(HOTFIX_SEL_GARR_FOLLOWER, "SELECT ID, FollowerTypeID, HordeCreatureID, AllianceCreatureID, HordeUiAnimRaceInfoID, AllianceUiAnimRaceInfoID, "
        "Quality, HordeGarrClassSpecID, AllianceGarrClassSpecID, HordeGarrFollItemSetID, AllianceGarrFollItemSetID, Level, ItemLevelWeapon, "
        "ItemLevelArmor, Unknown1, Flags, HordeSourceText, AllianceSourceText, Unknown2, Unknown3, HordePortraitIconID, AlliancePortraitIconID, "
        "HordeListPortraitTextureKitID, AllianceListPortraitTextureKitID FROM garr_follower ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_FOLLOWER, "SELECT ID, HordeSourceText_lang, AllianceSourceText_lang FROM garr_follower_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrFollowerXAbility.db2
    PrepareStatement(HOTFIX_SEL_GARR_FOLLOWER_X_ABILITY, "SELECT ID, GarrFollowerID, GarrAbilityID, FactionIndex FROM garr_follower_x_ability"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // GarrPlot.db2
    PrepareStatement(HOTFIX_SEL_GARR_PLOT, "SELECT ID, GarrPlotUICategoryID, PlotType, Flags, Name, MinCount, MaxCount, "
        "AllianceConstructionGameObjectID, HordeConstructionGameObjectID FROM garr_plot ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_PLOT, "SELECT ID, Name_lang FROM garr_plot_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrPlotBuilding.db2
    PrepareStatement(HOTFIX_SEL_GARR_PLOT_BUILDING, "SELECT ID, GarrPlotID, GarrBuildingID FROM garr_plot_building ORDER BY ID DESC", CONNECTION_SYNCH);

    // GarrPlotInstance.db2
    PrepareStatement(HOTFIX_SEL_GARR_PLOT_INSTANCE, "SELECT ID, GarrPlotID, Name FROM garr_plot_instance ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_PLOT_INSTANCE, "SELECT ID, Name_lang FROM garr_plot_instance_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrSiteLevel.db2
    PrepareStatement(HOTFIX_SEL_GARR_SITE_LEVEL, "SELECT ID, Level, MapID, SiteID, UITextureKitID, TownHallX, TownHallY, MovieID, Level2, "
        "UpgradeResourceCost, UpgradeMoneyCost FROM garr_site_level ORDER BY ID DESC", CONNECTION_SYNCH);

    // GarrSiteLevelPlotInst.db2
    PrepareStatement(HOTFIX_SEL_GARR_SITE_LEVEL_PLOT_INST, "SELECT ID, GarrSiteLevelID, GarrPlotInstanceID, LandmarkX, LandmarkY, Unknown"
        " FROM garr_site_level_plot_inst ORDER BY ID DESC", CONNECTION_SYNCH);

    // GlyphSlot.db2
    PrepareStatement(HOTFIX_SEL_GLYPH_SLOT, "SELECT ID, Type, Tooltip FROM glyph_slot ORDER BY ID DESC", CONNECTION_SYNCH);

    // GuildPerkSpells.db2
    PrepareStatement(HOTFIX_SEL_GUILD_PERK_SPELLS, "SELECT ID, GuildLevel, SpellID FROM guild_perk_spells ORDER BY ID DESC", CONNECTION_SYNCH);

    // Heirloom.db2
    PrepareStatement(HOTFIX_SEL_HEIRLOOM, "SELECT ID, ItemID, Flags, SourceText, Source, OldItem1, OldItem2, NextDifficultyItemID, UpgradeItemID1, UpgradeItemID2, "
        "ItemBonusListID1, ItemBonusListID2 FROM heirloom ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_HEIRLOOM, "SELECT ID, SourceText_lang FROM heirloom_locale WHERE locale = ?", CONNECTION_SYNCH);

    // Holidays.db2
    PrepareStatement(HOTFIX_SEL_HOLIDAYS, "SELECT ID, Duration1, Duration2, Duration3, Duration4, Duration5, Duration6, Duration7, Duration8, "
        "Duration9, Duration10, Date1, Date2, Date3, Date4, Date5, Date6, Date7, Date8, Date9, Date10, Date11, Date12, Date13, Date14, Date15, "
        "Date16, Region, Looping, CalendarFlags1, CalendarFlags2, CalendarFlags3, CalendarFlags4, CalendarFlags5, CalendarFlags6, CalendarFlags7, "
        "CalendarFlags8, CalendarFlags9, CalendarFlags10, HolidayNameID, HolidayDescriptionID, TextureFilename, Priority, CalendarFilterType, Flags"
        " FROM holidays ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_HOLIDAYS, "SELECT ID, TextureFilename_lang FROM holidays_locale WHERE locale = ?", CONNECTION_SYNCH);

    // ImportPriceArmor.db2
    PrepareStatement(HOTFIX_SEL_IMPORT_PRICE_ARMOR, "SELECT ID, ClothFactor, LeatherFactor, MailFactor, PlateFactor FROM import_price_armor"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // ImportPriceQuality.db2
    PrepareStatement(HOTFIX_SEL_IMPORT_PRICE_QUALITY, "SELECT ID, Factor FROM import_price_quality ORDER BY ID DESC", CONNECTION_SYNCH);

    // ImportPriceShield.db2
    PrepareStatement(HOTFIX_SEL_IMPORT_PRICE_SHIELD, "SELECT ID, Factor FROM import_price_shield ORDER BY ID DESC", CONNECTION_SYNCH);

    // ImportPriceWeapon.db2
    PrepareStatement(HOTFIX_SEL_IMPORT_PRICE_WEAPON, "SELECT ID, Factor FROM import_price_weapon ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemAppearance.db2
    PrepareStatement(HOTFIX_SEL_ITEM_APPEARANCE, "SELECT ID, DisplayID, IconFileDataID FROM item_appearance ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemBonus.db2
    PrepareStatement(HOTFIX_SEL_ITEM_BONUS, "SELECT ID, BonusListID, Type, Value1, Value2, `Index` FROM item_bonus ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemBonusTreeNode.db2
    PrepareStatement(HOTFIX_SEL_ITEM_BONUS_TREE_NODE, "SELECT ID, BonusTreeID, BonusTreeModID, SubTreeID, BonusListID FROM item_bonus_tree_node"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemClass.db2
    PrepareStatement(HOTFIX_SEL_ITEM_CLASS, "SELECT ID, Flags, PriceMod, Name FROM item_class ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_ITEM_CLASS, "SELECT ID, Name_lang FROM item_class_locale WHERE locale = ?", CONNECTION_SYNCH);

    // ItemCurrencyCost.db2
    PrepareStatement(HOTFIX_SEL_ITEM_CURRENCY_COST, "SELECT ID, ItemId FROM item_currency_cost ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemDisenchantLoot.db2
    PrepareStatement(HOTFIX_SEL_ITEM_DISENCHANT_LOOT, "SELECT ID, ItemClass, ItemSubClass, ItemQuality, MinItemLevel, MaxItemLevel, "
        "RequiredDisenchantSkill FROM item_disenchant_loot ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemEffect.db2
    PrepareStatement(HOTFIX_SEL_ITEM_EFFECT, "SELECT ID, ItemID, OrderIndex, SpellID, `Trigger`, Charges, Cooldown, Category, CategoryCooldown, "
        "ChrSpecializationID FROM item_effect ORDER BY ID DESC", CONNECTION_SYNCH);

    // Item.db2
    PrepareStatement(HOTFIX_SEL_ITEM, "SELECT ID, Class, SubClass, SoundOverrideSubclass, Material, InventoryType, Sheath, FileDataID, GroupSoundsID"
        " FROM item ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemExtendedCost.db2
    PrepareStatement(HOTFIX_SEL_ITEM_EXTENDED_COST, "SELECT ID, RequiredArenaSlot, RequiredItem1, RequiredItem2, RequiredItem3, RequiredItem4, "
        "RequiredItem5, RequiredItemCount1, RequiredItemCount2, RequiredItemCount3, RequiredItemCount4, RequiredItemCount5, "
        "RequiredPersonalArenaRating, ItemPurchaseGroup, RequiredCurrency1, RequiredCurrency2, RequiredCurrency3, RequiredCurrency4, "
        "RequiredCurrency5, RequiredCurrencyCount1, RequiredCurrencyCount2, RequiredCurrencyCount3, RequiredCurrencyCount4, RequiredCurrencyCount5, "
        "RequiredFactionId, RequiredFactionStanding, RequirementFlags, RequiredAchievement, RequiredMoney FROM item_extended_cost ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemLimitCategory.db2
    PrepareStatement(HOTFIX_SEL_ITEM_LIMIT_CATEGORY, "SELECT ID, Name, Quantity, Flags FROM item_limit_category ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_ITEM_LIMIT_CATEGORY, "SELECT ID, Name_lang FROM item_limit_category_locale WHERE locale = ?", CONNECTION_SYNCH);

    // ItemModifiedAppearance.db2
    PrepareStatement(HOTFIX_SEL_ITEM_MODIFIED_APPEARANCE, "SELECT ID, ItemID, AppearanceModID, AppearanceID, IconFileDataID, `Index`"
        " FROM item_modified_appearance ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemPriceBase.db2
    PrepareStatement(HOTFIX_SEL_ITEM_PRICE_BASE, "SELECT ID, ItemLevel, ArmorFactor, WeaponFactor FROM item_price_base ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemRandomProperties.db2
    PrepareStatement(HOTFIX_SEL_ITEM_RANDOM_PROPERTIES, "SELECT ID, InternalName, Enchantment1, Enchantment2, Enchantment3, Enchantment4, "
        "Enchantment5, Name FROM item_random_properties ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_ITEM_RANDOM_PROPERTIES, "SELECT ID, InternalName_lang, Name_lang FROM item_random_properties_locale"
        " WHERE locale = ?", CONNECTION_SYNCH);

    // ItemRandomSuffix.db2
    PrepareStatement(HOTFIX_SEL_ITEM_RANDOM_SUFFIX, "SELECT ID, Name, InternalName, Enchantment1, Enchantment2, Enchantment3, Enchantment4, "
        "Enchantment5, AllocationPct1, AllocationPct2, AllocationPct3, AllocationPct4, AllocationPct5 FROM item_random_suffix ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_ITEM_RANDOM_SUFFIX, "SELECT ID, Name_lang, InternalName_lang FROM item_random_suffix_locale WHERE locale = ?", CONNECTION_SYNCH);

    // ItemSparse.db2
    PrepareStatement(HOTFIX_SEL_ITEM_SPARSE, "SELECT ID, Quality, Flags1, Flags2, Flags3, Unk1, Unk2, BuyCount, BuyPrice, SellPrice, InventoryType, "
        "AllowableClass, AllowableRace, ItemLevel, RequiredLevel, RequiredSkill, RequiredSkillRank, RequiredSpell, RequiredHonorRank, "
        "RequiredCityRank, RequiredReputationFaction, RequiredReputationRank, MaxCount, Stackable, ContainerSlots, ItemStatType1, ItemStatType2, "
        "ItemStatType3, ItemStatType4, ItemStatType5, ItemStatType6, ItemStatType7, ItemStatType8, ItemStatType9, ItemStatType10, ItemStatValue1, "
        "ItemStatValue2, ItemStatValue3, ItemStatValue4, ItemStatValue5, ItemStatValue6, ItemStatValue7, ItemStatValue8, ItemStatValue9, "
        "ItemStatValue10, ItemStatAllocation1, ItemStatAllocation2, ItemStatAllocation3, ItemStatAllocation4, ItemStatAllocation5, "
        "ItemStatAllocation6, ItemStatAllocation7, ItemStatAllocation8, ItemStatAllocation9, ItemStatAllocation10, ItemStatSocketCostMultiplier1, "
        "ItemStatSocketCostMultiplier2, ItemStatSocketCostMultiplier3, ItemStatSocketCostMultiplier4, ItemStatSocketCostMultiplier5, "
        "ItemStatSocketCostMultiplier6, ItemStatSocketCostMultiplier7, ItemStatSocketCostMultiplier8, ItemStatSocketCostMultiplier9, "
        "ItemStatSocketCostMultiplier10, ScalingStatDistribution, DamageType, Delay, RangedModRange, Bonding, Name, Name2, Name3, Name4, Description, "
        "PageText, LanguageID, PageMaterial, StartQuest, LockID, Material, Sheath, RandomProperty, RandomSuffix, ItemSet, Area, Map, BagFamily, "
        "TotemCategory, SocketColor1, SocketColor2, SocketColor3, SocketBonus, GemProperties, ArmorDamageModifier, Duration, ItemLimitCategory, "
        "HolidayID, StatScalingFactor, CurrencySubstitutionID, CurrencySubstitutionCount, ItemNameDescriptionID FROM item_sparse ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_ITEM_SPARSE, "SELECT ID, Name_lang, Name2_lang, Name3_lang, Name4_lang, Description_lang FROM item_sparse_locale"
        " WHERE locale = ?", CONNECTION_SYNCH);

    // ItemSpec.db2
    PrepareStatement(HOTFIX_SEL_ITEM_SPEC, "SELECT ID, MinLevel, MaxLevel, ItemType, PrimaryStat, SecondaryStat, SpecID FROM item_spec"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemSpecOverride.db2
    PrepareStatement(HOTFIX_SEL_ITEM_SPEC_OVERRIDE, "SELECT ID, ItemID, SpecID FROM item_spec_override ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemToBattlePetSpecies.db2
    PrepareStatement(HOTFIX_SEL_ITEM_TO_BATTLE_PET_SPECIES, "SELECT ID, BattlePetSpeciesID FROM item_to_battle_pet_species ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemXBonusTree.db2
    PrepareStatement(HOTFIX_SEL_ITEM_X_BONUS_TREE, "SELECT ID, ItemID, BonusTreeID FROM item_x_bonus_tree ORDER BY ID DESC", CONNECTION_SYNCH);

    // KeyChain.db2
    PrepareStatement(HOTFIX_SEL_KEY_CHAIN, "SELECT Id, Key1, Key2, Key3, Key4, Key5, Key6, Key7, Key8, Key9, Key10, Key11, Key12, Key13, Key14, "
        "Key15, Key16, Key17, Key18, Key19, Key20, Key21, Key22, Key23, Key24, Key25, Key26, Key27, Key28, Key29, Key30, Key31, Key32 FROM key_chain"
        " ORDER BY Id DESC", CONNECTION_SYNCH);

    // MailTemplate.db2
    PrepareStatement(HOTFIX_SEL_MAIL_TEMPLATE, "SELECT ID, Body FROM mail_template ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_MAIL_TEMPLATE, "SELECT ID, Body_lang FROM mail_template_locale WHERE locale = ?", CONNECTION_SYNCH);

    // ModifierTree.db2
    PrepareStatement(HOTFIX_SEL_MODIFIER_TREE, "SELECT ID, Type, Asset1, Asset2, Operator, Amount, Parent FROM modifier_tree ORDER BY ID DESC", CONNECTION_SYNCH);

    // Mount.db2
    PrepareStatement(HOTFIX_SEL_MOUNT, "SELECT Id, SpellId, MountTypeId, DisplayId, Flags, Name, Description, SourceDescription, Source, "
        "PlayerConditionId FROM mount ORDER BY Id DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_MOUNT, "SELECT Id, Name_lang, Description_lang, SourceDescription_lang FROM mount_locale WHERE locale = ?", CONNECTION_SYNCH);

    // MountCapability.db2
    PrepareStatement(HOTFIX_SEL_MOUNT_CAPABILITY, "SELECT ID, Flags, RequiredRidingSkill, RequiredArea, RequiredAura, RequiredSpell, SpeedModSpell, "
        "RequiredMap FROM mount_capability ORDER BY ID DESC", CONNECTION_SYNCH);

    // MountTypeXCapability.db2
    PrepareStatement(HOTFIX_SEL_MOUNT_TYPE_X_CAPABILITY, "SELECT ID, MountTypeID, OrderIndex, MountCapabilityID FROM mount_type_x_capability ORDER BY ID DESC", CONNECTION_SYNCH);

    // NameGen.db2
    PrepareStatement(HOTFIX_SEL_NAME_GEN, "SELECT ID, Name, Race, Sex FROM name_gen ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_NAME_GEN, "SELECT ID, Name_lang FROM name_gen_locale WHERE locale = ?", CONNECTION_SYNCH);

    // NamesProfanity.db2
    PrepareStatement(HOTFIX_SEL_NAMES_PROFANITY, "SELECT ID, Name, Language FROM names_profanity ORDER BY ID DESC", CONNECTION_SYNCH);

    // NamesReserved.db2
    PrepareStatement(HOTFIX_SEL_NAMES_RESERVED, "SELECT ID, Name FROM names_reserved ORDER BY ID DESC", CONNECTION_SYNCH);

    // NamesReservedLocale.db2
    PrepareStatement(HOTFIX_SEL_NAMES_RESERVED_LOCALE, "SELECT ID, Name, LocaleMask FROM names_reserved_locale ORDER BY ID DESC", CONNECTION_SYNCH);

    // OverrideSpellData.db2
    PrepareStatement(HOTFIX_SEL_OVERRIDE_SPELL_DATA, "SELECT ID, SpellID1, SpellID2, SpellID3, SpellID4, SpellID5, SpellID6, SpellID7, SpellID8, "
        "SpellID9, SpellID10, Flags, PlayerActionbarFileDataID FROM override_spell_data ORDER BY ID DESC", CONNECTION_SYNCH);

    // PhaseXPhaseGroup.db2
    PrepareStatement(HOTFIX_SEL_PHASE_X_PHASE_GROUP, "SELECT ID, PhaseID, PhaseGroupID FROM phase_group ORDER BY ID DESC", CONNECTION_SYNCH);

    // QuestMoneyReward.db2
    PrepareStatement(HOTFIX_SEL_QUEST_MONEY_REWARD, "SELECT Level, Money1, Money2, Money3, Money4, Money5, Money6, Money7, Money8, Money9, Money10"
        " FROM quest_money_reward ORDER BY Level DESC", CONNECTION_SYNCH);

    // QuestPackageItem.db2
    PrepareStatement(HOTFIX_SEL_QUEST_PACKAGE_ITEM, "SELECT ID, QuestPackageID, ItemID, ItemCount, FilterType FROM quest_package_item ORDER BY ID DESC", CONNECTION_SYNCH);

    // QuestSort.db2
    PrepareStatement(HOTFIX_SEL_QUEST_SORT, "SELECT ID, SortName FROM quest_sort ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_QUEST_SORT, "SELECT ID, SortName_lang FROM quest_sort_locale WHERE locale = ?", CONNECTION_SYNCH);

    // QuestV2.db2
    PrepareStatement(HOTFIX_SEL_QUEST_V2, "SELECT ID, UniqueBitFlag FROM quest_v2 ORDER BY ID DESC", CONNECTION_SYNCH);

    // QuestXP.db2
    PrepareStatement(HOTFIX_SEL_QUEST_XP, "SELECT ID, Exp1, Exp2, Exp3, Exp4, Exp5, Exp6, Exp7, Exp8, Exp9, Exp10 FROM quest_xp ORDER BY ID DESC", CONNECTION_SYNCH);

    // ScalingStatDistribution.db2
    PrepareStatement(HOTFIX_SEL_SCALING_STAT_DISTRIBUTION, "SELECT ID, MinLevel, MaxLevel, ItemLevelCurveID FROM scaling_stat_distribution"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // SoundEntries.db2
    PrepareStatement(HOTFIX_SEL_SOUND_ENTRIES, "SELECT ID, SoundType, Name, FileDataID1, FileDataID2, FileDataID3, FileDataID4, FileDataID5, "
        "FileDataID6, FileDataID7, FileDataID8, FileDataID9, FileDataID10, FileDataID11, FileDataID12, FileDataID13, FileDataID14, FileDataID15, "
        "FileDataID16, FileDataID17, FileDataID18, FileDataID19, FileDataID20, Freq1, Freq2, Freq3, Freq4, Freq5, Freq6, Freq7, Freq8, Freq9, Freq10, "
        "Freq11, Freq12, Freq13, Freq14, Freq15, Freq16, Freq17, Freq18, Freq19, Freq20, VolumeFloat, Flags, MinDistance, DistanceCutoff, EAXDef, "
        "SoundEntriesAdvancedID, VolumeVariationPlus, VolumeVariationMinus, PitchVariationPlus, PitchVariationMinus, PitchAdjust, DialogType, "
        "BusOverwriteID FROM sound_entries ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_SOUND_ENTRIES, "SELECT ID, Name_lang FROM sound_entries_locale WHERE locale = ?", CONNECTION_SYNCH);

    // SpecializationSpells.db2
    PrepareStatement(HOTFIX_SEL_SPECIALIZATION_SPELLS, "SELECT ID, SpecID, OrderIndex, SpellID, OverridesSpellID, Description"
        " FROM specialization_spells ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_SPECIALIZATION_SPELLS, "SELECT ID, Description_lang FROM specialization_spells_locale WHERE locale = ?", CONNECTION_SYNCH);

    // SpellAuraRestrictions.db2
    PrepareStatement(HOTFIX_SEL_SPELL_AURA_RESTRICTIONS, "SELECT ID, CasterAuraState, TargetAuraState, ExcludeCasterAuraState, "
        "ExcludeTargetAuraState, CasterAuraSpell, TargetAuraSpell, ExcludeCasterAuraSpell, ExcludeTargetAuraSpell FROM spell_aura_restrictions"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellCastingRequirements.db2
    PrepareStatement(HOTFIX_SEL_SPELL_CASTING_REQUIREMENTS, "SELECT ID, FacingCasterFlags, MinFactionID, MinReputation, RequiredAreasID, "
        "RequiredAuraVision, RequiresSpellFocus FROM spell_casting_requirements ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellCastTimes.db2
    PrepareStatement(HOTFIX_SEL_SPELL_CAST_TIMES, "SELECT ID, CastTime, CastTimePerLevel, MinCastTime FROM spell_cast_times ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellClassOptions.db2
    PrepareStatement(HOTFIX_SEL_SPELL_CLASS_OPTIONS, "SELECT ID, ModalNextSpell, SpellClassMask1, SpellClassMask2, SpellClassMask3, SpellClassMask4, "
        "SpellClassSet FROM spell_class_options ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellDuration.db2
    PrepareStatement(HOTFIX_SEL_SPELL_DURATION, "SELECT ID, Duration1, Duration2, Duration3 FROM spell_duration ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellItemEnchantmentCondition.db2
    PrepareStatement(HOTFIX_SEL_SPELL_ITEM_ENCHANTMENT_CONDITION, "SELECT ID, LTOperandType1, LTOperandType2, LTOperandType3, LTOperandType4, "
        "LTOperandType5, LTOperand1, LTOperand2, LTOperand3, LTOperand4, LTOperand5, Operator1, Operator2, Operator3, Operator4, Operator5, "
        "RTOperandType1, RTOperandType2, RTOperandType3, RTOperandType4, RTOperandType5, RTOperand1, RTOperand2, RTOperand3, RTOperand4, RTOperand5, "
        "Logic1, Logic2, Logic3, Logic4, Logic5 FROM spell_item_enchantment_condition ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellLearnSpell.db2
    PrepareStatement(HOTFIX_SEL_SPELL_LEARN_SPELL, "SELECT ID, LearnSpellID, SpellID, OverridesSpellID FROM spell_learn_spell ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellMisc.db2
    PrepareStatement(HOTFIX_SEL_SPELL_MISC, "SELECT ID, Attributes, AttributesEx, AttributesExB, AttributesExC, AttributesExD, AttributesExE, "
        "AttributesExF, AttributesExG, AttributesExH, AttributesExI, AttributesExJ, AttributesExK, AttributesExL, AttributesExM, CastingTimeIndex, "
        "DurationIndex, RangeIndex, Speed, SpellIconID, ActiveIconID, SchoolMask, MultistrikeSpeedMod FROM spell_misc"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellPower.db2
    PrepareStatement(HOTFIX_SEL_SPELL_POWER, "SELECT ID, SpellID, PowerIndex, PowerType, ManaCost, ManaCostPerLevel, ManaCostPerSecond, "
        "ManaCostAdditional, PowerDisplayID, UnitPowerBarID, ManaCostPercentage, ManaCostPercentagePerSecond, RequiredAura, HealthCostPercentage"
        " FROM spell_power ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellPowerDifficulty.db2
    PrepareStatement(HOTFIX_SEL_SPELL_POWER_DIFFICULTY, "SELECT SpellPowerID, DifficultyID, PowerIndex FROM spell_power_difficulty"
        " ORDER BY SpellPowerID DESC", CONNECTION_SYNCH);

    // SpellRadius.db2
    PrepareStatement(HOTFIX_SEL_SPELL_RADIUS, "SELECT ID, Radius, RadiusPerLevel, RadiusMin, RadiusMax FROM spell_radius ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellRange.db2
    PrepareStatement(HOTFIX_SEL_SPELL_RANGE, "SELECT ID, MinRangeHostile, MinRangeFriend, MaxRangeHostile, MaxRangeFriend, Flags, DisplayName, "
        "DisplayNameShort FROM spell_range ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_SPELL_RANGE, "SELECT ID, DisplayName_lang, DisplayNameShort_lang FROM spell_range_locale WHERE locale = ?", CONNECTION_SYNCH);

    // SpellReagents.db2
    PrepareStatement(HOTFIX_SEL_SPELL_REAGENTS, "SELECT ID, Reagent1, Reagent2, Reagent3, Reagent4, Reagent5, Reagent6, Reagent7, Reagent8, "
        "ReagentCount1, ReagentCount2, ReagentCount3, ReagentCount4, ReagentCount5, ReagentCount6, ReagentCount7, ReagentCount8 "
        " FROM spell_reagents ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellRuneCost.db2
    PrepareStatement(HOTFIX_SEL_SPELL_RUNE_COST, "SELECT ID, Blood, Unholy, Frost, Chromatic, RunicPower FROM spell_rune_cost"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellTotems.db2
    PrepareStatement(HOTFIX_SEL_SPELL_TOTEMS, "SELECT ID, RequiredTotemCategoryID1, RequiredTotemCategoryID2, Totem1, Totem2 FROM spell_totems"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellXSpellVisual.db2
    PrepareStatement(HOTFIX_SEL_SPELL_X_SPELL_VISUAL, "SELECT ID, SpellID, DifficultyID, SpellVisualID1, SpellVisualID2, Unk620, PlayerConditionID, "
        "Flags FROM spell_x_spell_visual ORDER BY ID DESC", CONNECTION_SYNCH);

    // TaxiNodes.db2
    PrepareStatement(HOTFIX_SEL_TAXI_NODES, "SELECT ID, MapID, PosX, PosY, PosZ, Name, MountCreatureID1, MountCreatureID2, ConditionID, "
        "LearnableIndex, Flags, MapOffsetX, MapOffsetY FROM taxi_nodes ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_TAXI_NODES, "SELECT ID, Name_lang FROM taxi_nodes_locale WHERE locale = ?", CONNECTION_SYNCH);

    // TaxiPath.db2
    PrepareStatement(HOTFIX_SEL_TAXI_PATH, "SELECT ID, `From`, `To`, Cost FROM taxi_path ORDER BY ID DESC", CONNECTION_SYNCH);

    // TaxiPathNode.db2
    PrepareStatement(HOTFIX_SEL_TAXI_PATH_NODE, "SELECT ID, PathID, NodeIndex, MapID, LocX, LocY, LocZ, Flags, Delay, ArrivalEventID, "
        "DepartureEventID FROM taxi_path_node ORDER BY ID DESC", CONNECTION_SYNCH);

    // TotemCategory.db2
    PrepareStatement(HOTFIX_SEL_TOTEM_CATEGORY, "SELECT ID, Name, CategoryType, CategoryMask FROM totem_category ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_TOTEM_CATEGORY, "SELECT ID, Name_lang FROM totem_category_locale WHERE locale = ?", CONNECTION_SYNCH);

    // Toy.db2
    PrepareStatement(HOTFIX_SEL_TOY, "SELECT ID, ItemID, Flags, Description, CategoryFilter FROM toy ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_TOY, "SELECT ID, Description_lang FROM toy_locale WHERE locale = ?", CONNECTION_SYNCH);

    // TransportAnimation.db2
    PrepareStatement(HOTFIX_SEL_TRANSPORT_ANIMATION, "SELECT ID, TransportID, TimeIndex, PosX, PosY, PosZ, SequenceID FROM transport_animation"
        " ORDER BY ID DESC", CONNECTION_SYNCH);

    // TransportRotation.db2
    PrepareStatement(HOTFIX_SEL_TRANSPORT_ROTATION, "SELECT ID, TransportID, TimeIndex, X, Y, Z, W FROM transport_rotation ORDER BY ID DESC", CONNECTION_SYNCH);

    // UnitPowerBar.db2
    PrepareStatement(HOTFIX_SEL_UNIT_POWER_BAR, "SELECT ID, MinPower, MaxPower, StartPower, CenterPower, RegenerationPeace, RegenerationCombat, "
        "BarType, FileDataID1, FileDataID2, FileDataID3, FileDataID4, FileDataID5, FileDataID6, Color1, Color2, Color3, Color4, Color5, Color6, "
        "Flags, Name, Cost, OutOfError, ToolTip, StartInset, EndInset FROM unit_power_bar ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_UNIT_POWER_BAR, "SELECT ID, Name_lang, Cost_lang, OutOfError_lang, ToolTip_lang FROM unit_power_bar_locale"
        " WHERE locale = ?", CONNECTION_SYNCH);

    // WorldMapOverlay.db2
    PrepareStatement(HOTFIX_SEL_WORLD_MAP_OVERLAY, "SELECT ID, MapAreaID, AreaID1, AreaID2, AreaID3, AreaID4, TextureName, TextureWidth, "
        "TextureHeight, OffsetX, OffsetY, HitRectTop, HitRectLeft, HitRectBottom, HitRectRight, PlayerConditionID FROM world_map_overlay"
        " ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_WORLD_MAP_OVERLAY, "SELECT ID, TextureName_lang FROM world_map_overlay_locale WHERE locale = ?", CONNECTION_SYNCH);
}
