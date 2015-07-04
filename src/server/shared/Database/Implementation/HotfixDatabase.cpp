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

#include "HotfixDatabase.h"

// Force locale statments to appear exactly in locale declaration order, right after normal data fetch statement
#define PREPARE_LOCALE_STMT(stmtBase, sql, con) \
    static_assert(stmtBase + 1 == stmtBase##_LOCALE, "Invalid prepared statement index for " #stmtBase "_LOCALE"); \
    PrepareStatement(stmtBase##_LOCALE, sql, con);

void HotfixDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_HOTFIXDATABASE_STATEMENTS);

    // AreaGroup.db2
    PrepareStatement(HOTFIX_SEL_AREA_GROUP, "SELECT ID FROM area_group ORDER BY ID DESC", CONNECTION_SYNCH);

    // AreaGroupMember.db2
    PrepareStatement(HOTFIX_SEL_AREA_GROUP_MEMBER, "SELECT ID, AreaGroupID, AreaID FROM area_group_member ORDER BY ID DESC", CONNECTION_SYNCH);

    // BroadcastText.db2
    PrepareStatement(HOTFIX_SEL_BROADCAST_TEXT, "SELECT ID, Language, MaleText, FemaleText, EmoteID1, EmoteID2, EmoteID3, "
        "EmoteDelay1, EmoteDelay2, EmoteDelay3, SoundID, UnkEmoteID, Type FROM broadcast_text ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_BROADCAST_TEXT, "SELECT ID, MaleText_lang, FemaleText_lang FROM broadcast_text_locale WHERE locale = ?", CONNECTION_SYNCH);

    // CurrencyTypes.db2
    PrepareStatement(HOTFIX_SEL_CURRENCY_TYPES, "SELECT ID, CategoryID, Name, InventoryIcon1, InventoryIcon2, SpellWeight, SpellCategory, "
        "MaxQty, MaxEarnablePerWeek, Flags, Quality, Description FROM currency_types ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_CURRENCY_TYPES, "SELECT ID, Name_lang, InventoryIcon1_lang, InventoryIcon2_lang, "
        "Description_lang FROM currency_types_locale WHERE locale = ?", CONNECTION_SYNCH);

    // CurvePoint.db2
    PrepareStatement(HOTFIX_SEL_CURVE_POINT, "SELECT ID, CurveID, `Index`, X, Y FROM curve_point ORDER BY ID DESC", CONNECTION_SYNCH);

    // GameObjects.db2
    PrepareStatement(HOTFIX_SEL_GAMEOBJECTS, "SELECT ID, MapID, DisplayID, PositionX, PositionY, PositionZ, RotationX, RotationY, RotationZ, RotationW, Size, "
        "PhaseUseFlags, PhaseID, PhaseGroupID, Type, Data0, Data1, Data2, Data3, Data4, Data5, Data6, Data7, Name FROM gameobjects ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GAMEOBJECTS, "SELECT ID, Name_lang FROM gameobjects_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GameTables.db2
    PrepareStatement(HOTFIX_SEL_GAME_TABLES, "SELECT ID, Name, NumRows, NumColumns FROM game_tables ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GAME_TABLES, "SELECT ID, Name_lang FROM game_tables_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrAbility.db2
    PrepareStatement(HOTFIX_SEL_GARR_ABILITY, "SELECT ID, Flags, Name, Description, IconFileDataID, OtherFactionGarrAbilityID, "
        "GarrAbilityCategoryID FROM garr_ability ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_ABILITY, "SELECT ID, Name_lang, Description_lang FROM garr_ability_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrBuilding.db2
    PrepareStatement(HOTFIX_SEL_GARR_BUILDING, "SELECT ID, HordeGameObjectID, AllianceGameObjectID, Unknown, Type, Level, NameAlliance, NameHorde, Description, "
        "Tooltip, BuildDuration, CostCurrencyID, CostCurrencyAmount, HordeTexPrefixKitID, AllianceTexPrefixKitID, IconFileDataID, BonusAmount, Flags, "
        "AllianceActivationScenePackageID, HordeActivationScenePackageID, MaxShipments, FollowerRequiredGarrAbilityID, FollowerGarrAbilityEffectID, CostMoney "
        "FROM garr_building ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_BUILDING, "SELECT ID, NameAlliance_lang, NameHorde_lang, Description_lang, Tooltip_lang "
        "FROM garr_building_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrBuildingPlotInst.db2
    PrepareStatement(HOTFIX_SEL_GARR_BUILDING_PLOT_INST, "SELECT ID, GarrBuildingID, UiTextureAtlasMemberID, GarrSiteLevelPlotInstID, "
        "LandmarkOffsetX, LandmarkOffsetY FROM garr_building_plot_inst ORDER BY ID DESC", CONNECTION_SYNCH);

    // GarrClassSpec.db2
    PrepareStatement(HOTFIX_SEL_GARR_CLASS_SPEC, "SELECT ID, NameMale, NameFemale, NameGenderless, ClassAtlasID, GarrFollItemSetID "
        "FROM garr_class_spec ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_CLASS_SPEC, "SELECT ID, NameMale_lang, NameFemale_lang, NameGenderless_lang FROM garr_class_spec_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrFollower.db2
    PrepareStatement(HOTFIX_SEL_GARR_FOLLOWER, "SELECT ID, HordeCreatureID, AllianceCreatureID, HordeUiAnimRaceInfoID, AllianceUiAnimRaceInfoID, Quality, "
        "HordeGarrClassSpecID, AllianceGarrClassSpecID, HordeGarrFollItemSetID, AllianceGarrFollItemSetID, Level, ItemLevelWeapon, ItemLevelArmor, Unknown1, Flags, "
        "HordeSourceText, AllianceSourceText, Unknown2, Unknown3, HordePortraitIconID, AlliancePortraitIconID FROM garr_follower ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_GARR_FOLLOWER, "SELECT ID, HordeSourceText_lang, AllianceSourceText_lang FROM garr_follower_locale WHERE locale = ?", CONNECTION_SYNCH);

    // GarrFollowerXAbility.db2
    PrepareStatement(HOTFIX_SEL_GARR_FOLLOWER_X_ABILITY, "SELECT ID, GarrFollowerID, GarrAbilityID, FactionIndex FROM garr_follower_x_ability ORDER BY ID DESC", CONNECTION_SYNCH);

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
    PrepareStatement(HOTFIX_SEL_GARR_SITE_LEVEL_PLOT_INST, "SELECT ID, GarrSiteLevelID, GarrPlotInstanceID, LandmarkX, LandmarkY, "
        "Unknown FROM garr_site_level_plot_inst  ORDER BY ID DESC", CONNECTION_SYNCH);

    // Holidays.db2
    PrepareStatement(HOTFIX_SEL_HOLIDAYS, "SELECT ID, Duration1, Duration2, Duration3, Duration4, Duration5, Duration6, Duration7, Duration8, Duration9, Duration10, "
        "Date1, Date2, Date3, Date4, Date5, Date6, Date7, Date8, Date9, Date10, Date11, Date12, Date13, Date14, Date15, Date16, Region, Looping, "
        "CalendarFlags1, CalendarFlags2, CalendarFlags3, CalendarFlags4, CalendarFlags5, CalendarFlags6, CalendarFlags7, CalendarFlags8, CalendarFlags9, CalendarFlags10, "
        "HolidayNameID, HolidayDescriptionID, TextureFilename, Priority, CalendarFilterType, Flags FROM holidays ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_HOLIDAYS, "SELECT ID, TextureFilename_lang FROM holidays_locale WHERE locale = ?", CONNECTION_SYNCH);

    // ItemAppearance.db2
    PrepareStatement(HOTFIX_SEL_ITEM_APPEARANCE, "SELECT ID, DisplayID, IconFileDataID FROM item_appearance ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemBonus.db2
    PrepareStatement(HOTFIX_SEL_ITEM_BONUS, "SELECT ID, BonusListID, Type, Value1, Value2, `Index` FROM item_bonus ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemBonusTreeNode.db2
    PrepareStatement(HOTFIX_SEL_ITEM_BONUS_TREE_NODE, "SELECT ID, BonusTreeID, BonusTreeModID, SubTreeID, BonusListID FROM item_bonus_tree_node ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemCurrencyCost.db2
    PrepareStatement(HOTFIX_SEL_ITEM_CURRENCY_COST, "SELECT ID, ItemID FROM item_currency_cost ORDER BY ItemID DESC", CONNECTION_SYNCH);

    // ItemEffect.db2
    PrepareStatement(HOTFIX_SEL_ITEM_EFFECT, "SELECT ID, ItemID, OrderIndex, SpellID, `Trigger`, Charges, Cooldown, "
        "Category, CategoryCooldown FROM item_effect ORDER BY ID DESC", CONNECTION_SYNCH);

    // Item.db2
    PrepareStatement(HOTFIX_SEL_ITEM, "SELECT ID, Class, SubClass, SoundOverrideSubclass, Material, InventoryType, Sheath, "
        "FileDataID, GroupSoundsID FROM item ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemExtendedCost.db2
    PrepareStatement(HOTFIX_SEL_ITEM_EXTENDED_COST, "SELECT ID, RequiredArenaSlot, RequiredItem1, RequiredItem2, RequiredItem3, RequiredItem4, RequiredItem5, "
        "RequiredItemCount1, RequiredItemCount2, RequiredItemCount3, RequiredItemCount4, RequiredItemCount5, RequiredPersonalArenaRating, ItemPurchaseGroup, "
        "RequiredCurrency1, RequiredCurrency2, RequiredCurrency3, RequiredCurrency4, RequiredCurrency5, "
        "RequiredCurrencyCount1, RequiredCurrencyCount2, RequiredCurrencyCount3, RequiredCurrencyCount4, RequiredCurrencyCount5, "
        "RequiredFactionId, RequiredFactionStanding, RequirementFlags, RequiredAchievement, RequiredMoney FROM item_extended_cost ORDER BY ID DESC", CONNECTION_SYNCH);

    // ItemModifiedAppearance.db2
    PrepareStatement(HOTFIX_SEL_ITEM_MODIFIED_APPEARANCE, "SELECT ID, ItemID, AppearanceModID, AppearanceID, "
        "IconFileDataID, `Index` FROM item_modified_appearance ORDER BY ID DESC", CONNECTION_SYNCH);

    // Item-sparse.db2
    PrepareStatement(HOTFIX_SEL_ITEM_SPARSE, "SELECT ID, Quality, Flags1, Flags2, Flags3, Unk1, Unk2, BuyCount, BuyPrice, SellPrice, InventoryType, "
        "AllowableClass, AllowableRace, ItemLevel, RequiredLevel, RequiredSkill, RequiredSkillRank, RequiredSpell, RequiredHonorRank, RequiredCityRank, "
        "RequiredReputationFaction, RequiredReputationRank, MaxCount, Stackable, ContainerSlots, "
        "ItemStatType1, ItemStatType2, ItemStatType3, ItemStatType4, ItemStatType5, ItemStatType6, ItemStatType7, ItemStatType8, ItemStatType9, ItemStatType10, "
        "ItemStatValue1, ItemStatValue2, ItemStatValue3, ItemStatValue4, ItemStatValue5, ItemStatValue6, ItemStatValue7, ItemStatValue8, ItemStatValue9, ItemStatValue10, "
        "ItemStatAllocation1, ItemStatAllocation2, ItemStatAllocation3, ItemStatAllocation4, ItemStatAllocation5, "
        "ItemStatAllocation6, ItemStatAllocation7, ItemStatAllocation8, ItemStatAllocation9, ItemStatAllocation10, "
        "ItemStatSocketCostMultiplier1, ItemStatSocketCostMultiplier2, ItemStatSocketCostMultiplier3, ItemStatSocketCostMultiplier4, ItemStatSocketCostMultiplier5, "
        "ItemStatSocketCostMultiplier6, ItemStatSocketCostMultiplier7, ItemStatSocketCostMultiplier8, ItemStatSocketCostMultiplier9, ItemStatSocketCostMultiplier10, "
        "ScalingStatDistribution, DamageType, Delay, RangedModRange, Bonding, Name, Name2, Name3, Name4, Description, PageText, LanguageID, PageMaterial, "
        "StartQuest, LockID, Material, Sheath, RandomProperty, RandomSuffix, ItemSet, Area, Map, BagFamily, TotemCategory, "
        "SocketColor1, SocketColor2, SocketColor3, SocketBonus, GemProperties, ArmorDamageModifier, Duration, ItemLimitCategory, "
        "HolidayID, StatScalingFactor, CurrencySubstitutionID, CurrencySubstitutionCount, ItemNameDescriptionID FROM item_sparse ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_ITEM_SPARSE, "SELECT ID, Name_lang, Name2_lang, Name3_lang, Name4_lang, Description_lang FROM item_sparse_locale WHERE locale = ?", CONNECTION_SYNCH);

    // ItemXBonusTree.db2
    PrepareStatement(HOTFIX_SEL_ITEM_X_BONUS_TREE, "SELECT ID, ItemID, BonusTreeID FROM item_x_bonus_tree ORDER BY ID DESC", CONNECTION_SYNCH);

    // KeyChain.db2
    PrepareStatement(HOTFIX_SEL_KEY_CHAIN, "SELECT Id, Key1, Key2, Key3, Key4, Key5, Key6, Key7, Key8, Key9, Key10, Key11, Key12, Key13, Key14, Key15, Key16, "
        "Key17, Key18, Key19, Key20, Key21, Key22, Key23, Key24, Key25, Key26, Key27, Key28, Key29, Key30, Key31, Key32 FROM key_chain ORDER BY Id DESC", CONNECTION_SYNCH);

    // Mount.db2
    PrepareStatement(HOTFIX_SEL_MOUNT, "SELECT Id, MountTypeId, DisplayId, Flags, Name, Description, SourceDescription, "
        "Source, SpellId, PlayerConditionId FROM mount ORDER BY Id DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_MOUNT, "SELECT ID, Name_lang, Description_lang, SourceDescription_lang FROM mount_locale WHERE locale = ?", CONNECTION_SYNCH);

    // OverrideSpellData.db2
    PrepareStatement(HOTFIX_SEL_OVERRIDE_SPELL_DATA, "SELECT ID, SpellID1, SpellID2, SpellID3, SpellID4, SpellID5, "
        "SpellID6, SpellID7, SpellID8, SpellID9, SpellID10, Flags, PlayerActionbarFileDataID FROM override_spell_data ORDER BY ID DESC", CONNECTION_SYNCH);

    // PhaseGroup.db2
    PrepareStatement(HOTFIX_SEL_PHASE_GROUP, "SELECT ID, PhaseID, PhaseGroupID FROM phase_group ORDER BY ID DESC", CONNECTION_SYNCH);

    // QuestPackageItem.db2
    PrepareStatement(HOTFIX_SEL_QUEST_PACKAGE_ITEM, "SELECT ID, QuestPackageID, ItemID, ItemCount, FilterType FROM quest_package_item ORDER BY ID DESC", CONNECTION_SYNCH);

    // SoundEntries.db2
    PrepareStatement(HOTFIX_SEL_SOUND_ENTRIES, "SELECT ID, SoundType, Name, FileDataID1, FileDataID2, FileDataID3, FileDataID4, FileDataID5, "
        "FileDataID6, FileDataID7, FileDataID8, FileDataID9, FileDataID10, FileDataID11, FileDataID12, FileDataID13, FileDataID14, FileDataID15, "
        "FileDataID16, FileDataID17, FileDataID18, FileDataID19, FileDataID20, Freq1, Freq2, Freq3, Freq4, Freq5, Freq6, Freq7, Freq8, Freq9, Freq10, "
        "Freq11, Freq12, Freq13, Freq14, Freq15, Freq16, Freq17, Freq18, Freq19, Freq20, VolumeFloat, Flags, MinDistance, DistanceCutoff, "
        "EAXDef, SoundEntriesAdvancedID, VolumeVariationPlus, VolumeVariationMinus, PitchVariationPlus, "
        "PitchVariationMinus, PitchAdjust, DialogType, BusOverwriteID FROM sound_entries ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_SOUND_ENTRIES, "SELECT ID, Name_lang FROM sound_entries_locale WHERE locale = ?", CONNECTION_SYNCH);

    // SpellAuraRestrictions.db2
    PrepareStatement(HOTFIX_SEL_SPELL_AURA_RESTRICTIONS, "SELECT ID, CasterAuraState, TargetAuraState, ExcludeCasterAuraState, ExcludeTargetAuraState, "
        "CasterAuraSpell, TargetAuraSpell, ExcludeCasterAuraSpell, ExcludeTargetAuraSpell FROM spell_aura_restrictions ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellCastingRequirements.db2
    PrepareStatement(HOTFIX_SEL_SPELL_CASTING_REQUIREMENTS, "SELECT ID, FacingCasterFlags, MinFactionID, MinReputation, "
        "RequiredAreasID, RequiredAuraVision, RequiresSpellFocus FROM spell_casting_requirements ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellClassOptions.db2
    PrepareStatement(HOTFIX_SEL_SPELL_CLASS_OPTIONS, "SELECT ID, ModalNextSpell, SpellClassMask1, SpellClassMask2, SpellClassMask3, SpellClassMask4, "
        "SpellClassSet FROM spell_class_options ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellLearnSpell.db2
    PrepareStatement(HOTFIX_SEL_SPELL_LEARN_SPELL, "SELECT ID, LearnSpellID, SpellID, OverridesSpellID FROM spell_learn_spell ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellMisc.db2
    PrepareStatement(HOTFIX_SEL_SPELL_MISC, "SELECT ID, Attributes, AttributesEx, AttributesExB, AttributesExC, AttributesExD, AttributesExE, "
        "AttributesExF, AttributesExG, AttributesExH, AttributesExI, AttributesExJ, AttributesExK, AttributesExL, AttributesExM, "
        "CastingTimeIndex, DurationIndex, RangeIndex, Speed, SpellVisualID1, SpellVisualID2, SpellIconID, ActiveIconID, "
        "SchoolMask, MultistrikeSpeedMod FROM spell_misc ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellPower.db2
    PrepareStatement(HOTFIX_SEL_SPELL_POWER, "SELECT ID, SpellID, PowerIndex, PowerType, ManaCost, ManaCostPerLevel, ManaCostPerSecond, ManaCostAdditional, "
        "PowerDisplayID, UnitPowerBarID, ManaCostPercentage, ManaCostPercentagePerSecond, RequiredAura, HealthCostPercentage FROM spell_power ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellPowerDifficulty.db2
    PrepareStatement(HOTFIX_SEL_SPELL_POWER_DIFFICULTY, "SELECT SpellPowerID, DifficultyID, PowerIndex FROM spell_power_difficulty ORDER BY SpellPowerID DESC", CONNECTION_SYNCH);

    // SpellReagents.db2
    PrepareStatement(HOTFIX_SEL_SPELL_REAGENTS, "SELECT ID, Reagent1, Reagent2, Reagent3, Reagent4, Reagent5, Reagent6, Reagent7, Reagent8, "
        "ReagentCount1, ReagentCount2, ReagentCount3, ReagentCount4, ReagentCount5, ReagentCount6, ReagentCount7, ReagentCount8, "
        "CurrencyID, CurrencyCount FROM spell_reagents ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellRuneCost.db2
    PrepareStatement(HOTFIX_SEL_SPELL_RUNE_COST, "SELECT ID, Blood, Unholy, Frost, Chromatic, RunicPower FROM spell_rune_cost ORDER BY ID DESC", CONNECTION_SYNCH);

    // SpellTotems.db2
    PrepareStatement(HOTFIX_SEL_SPELL_TOTEMS, "SELECT ID, RequiredTotemCategoryID1, RequiredTotemCategoryID2, Totem1, Totem2 FROM spell_totems ORDER BY ID DESC", CONNECTION_SYNCH);

    // TaxiNodes.db2
    PrepareStatement(HOTFIX_SEL_TAXI_NODES, "SELECT ID, MapID, PosX, PosY, PosZ, Name, MountCreatureID1, MountCreatureID2, ConditionID, "
        "LearnableIndex, Flags, MapOffsetX, MapOffsetY FROM taxi_nodes ORDER BY ID DESC", CONNECTION_SYNCH);
    PREPARE_LOCALE_STMT(HOTFIX_SEL_TAXI_NODES, "SELECT ID, Name_lang FROM taxi_nodes_locale WHERE locale = ?", CONNECTION_SYNCH);

    // TaxiPath.db2
    PrepareStatement(HOTFIX_SEL_TAXI_PATH, "SELECT ID, `From`, `To`, Cost FROM taxi_path ORDER BY ID DESC", CONNECTION_SYNCH);

    // TaxiPathNode.db2
    PrepareStatement(HOTFIX_SEL_TAXI_PATH_NODE, "SELECT ID, PathID, NodeIndex, MapID, LocX, LocY, LocZ, Flags, Delay, "
        "ArrivalEventID, DepartureEventID FROM taxi_path_node ORDER BY ID DESC", CONNECTION_SYNCH);
}
