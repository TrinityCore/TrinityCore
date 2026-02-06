ALTER TABLE `area_trigger` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `AreaTriggerActionSetID`;

ALTER TABLE `artifact` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ChrSpecializationID`;

ALTER TABLE `artifact_appearance` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `UiAltItemAppearanceID`;

ALTER TABLE `artifact_appearance_set` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ForgeAttachmentOverride`;

ALTER TABLE `artifact_power` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Label`;

ALTER TABLE `battle_pet_ability` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `BattlePetVisualID`;

ALTER TABLE `battlemaster_list` ADD `InstanceType` tinyint NOT NULL DEFAULT 0 AFTER `LongDescription`;

ALTER TABLE `cfg_categories` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ExistingCharsetMask`;

ALTER TABLE `crafting_quality` ADD `CraftingQualityAtlasSetID` int NOT NULL DEFAULT 0 AFTER `QualityTier`;

ALTER TABLE `currency_types`
  ADD `RecraftReagentCountPercentage` float NOT NULL DEFAULT 0 AFTER `OrderIndex`,
  ADD `OrderSource` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `RecraftReagentCountPercentage`,
  ADD `MCRCurrencyID` int NOT NULL DEFAULT 0 AFTER `OrderSource`;

ALTER TABLE `difficulty`
  MODIFY `FallbackDifficultyID` smallint NOT NULL DEFAULT 0 AFTER `OldEnumValue`,
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `MaxPlayers`,
  MODIFY `ToggleDifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ItemContext`;

ALTER TABLE `dungeon_encounter` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `MapID`;

ALTER TABLE `garr_plot`
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `AllianceConstructObjID`,
  DROP `UiCategoryID`;

ALTER TABLE `holidays`
  MODIFY `CalendarFilterType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Priority`,
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `CalendarFilterType`;

ALTER TABLE `item`
  ADD `Unknown1200` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `ModifiedCraftingReagentItemID`,
  CHANGE `Unknown1127` `ItemSquishEraID` int NOT NULL DEFAULT 0 AFTER `CraftingQualityID`,
  ADD `RecraftReagentCountPercentage` float NOT NULL DEFAULT 0 AFTER `ItemSquishEraID`,
  ADD `OrderSource` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `RecraftReagentCountPercentage`;

ALTER TABLE `item_child_equipment` MODIFY `ChildItemEquipSlot` int NOT NULL DEFAULT 0 AFTER `ChildItemID`;

ALTER TABLE `item_context_picker_entry` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `LabelID`;

ALTER TABLE `item_effect` MODIFY `TriggerType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `LegacySlotIndex`;

ALTER TABLE `item_limit_category` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Quantity`;

ALTER TABLE `item_scaling_config` CHANGE `Unknown1125` `ItemSquishEraID` int NOT NULL DEFAULT 0 AFTER `RequiredLevel`;

ALTER TABLE `item_set` MODIFY `SetFlags` int NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `item_sparse` CHANGE `Unknown1127` `ItemSquishEraID` int NOT NULL DEFAULT 0 AFTER `ItemLevelOffsetItemLevel`;

--
-- Table structure for table `item_squish_era`
--
DROP TABLE IF EXISTS `item_squish_era`;
CREATE TABLE `item_squish_era` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Patch` int NOT NULL DEFAULT '0',
  `CurveID` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `lfg_dungeons` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `MapID`;

ALTER TABLE `liquid_type`
  ADD `Color3` int NOT NULL DEFAULT 0 AFTER `Color2`,
  ADD `Float19` float NOT NULL DEFAULT 0 AFTER `Float18`,
  ADD `Float20` float NOT NULL DEFAULT 0 AFTER `Float19`,
  ADD `Float21` float NOT NULL DEFAULT 0 AFTER `Float20`,
  ADD `Float22` float NOT NULL DEFAULT 0 AFTER `Float21`,
  ADD `Float23` float NOT NULL DEFAULT 0 AFTER `Float22`,
  ADD `Float24` float NOT NULL DEFAULT 0 AFTER `Float23`,
  ADD `Float25` float NOT NULL DEFAULT 0 AFTER `Float24`,
  ADD `Float26` float NOT NULL DEFAULT 0 AFTER `Float25`,
  ADD `Float27` float NOT NULL DEFAULT 0 AFTER `Float26`,
  ADD `Float28` float NOT NULL DEFAULT 0 AFTER `Float27`,
  ADD `Float29` float NOT NULL DEFAULT 0 AFTER `Float28`,
  ADD `Float30` float NOT NULL DEFAULT 0 AFTER `Float29`,
  ADD `Float31` float NOT NULL DEFAULT 0 AFTER `Float30`,
  ADD `Float32` float NOT NULL DEFAULT 0 AFTER `Float31`,
  ADD `Float33` float NOT NULL DEFAULT 0 AFTER `Float32`,
  ADD `Float34` float NOT NULL DEFAULT 0 AFTER `Float33`,
  ADD `Float35` float NOT NULL DEFAULT 0 AFTER `Float34`,
  ADD `Float36` float NOT NULL DEFAULT 0 AFTER `Float35`,
  ADD `Float37` float NOT NULL DEFAULT 0 AFTER `Float36`,
  ADD `Float38` float NOT NULL DEFAULT 0 AFTER `Float37`;

ALTER TABLE `map_difficulty` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `override_spell_data` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `PlayerActionBarFileDataID`;

ALTER TABLE `player_condition` MODIFY `PowerTypeValue` tinyint NOT NULL DEFAULT 0 AFTER `PowerTypeComp`;

ALTER TABLE `scenario` MODIFY `Type` int NOT NULL DEFAULT 0 AFTER `AreaTableID`;

ALTER TABLE `scenario` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `scenario_step` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `OrderIndex`;

ALTER TABLE `scene_script_package` ADD `Flags` int NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `spell_aura_options` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_aura_restrictions`
  MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `CasterAuraType` smallint NOT NULL DEFAULT 0 AFTER `ExcludeTargetAuraSpell`,
  MODIFY `TargetAuraType` smallint NOT NULL DEFAULT 0 AFTER `CasterAuraType`,
  MODIFY `ExcludeCasterAuraType` smallint NOT NULL DEFAULT 0 AFTER `TargetAuraType`,
  MODIFY `ExcludeTargetAuraType` smallint NOT NULL DEFAULT 0 AFTER `ExcludeCasterAuraType`;

ALTER TABLE `spell_categories`
  ADD `DiminishType` int NOT NULL DEFAULT 0 AFTER `DefenseType`,
  MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `DefenseType` tinyint NOT NULL DEFAULT 0 AFTER `Category`;

ALTER TABLE `spell_cooldowns` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_duration` ADD `DurationPerResource` int NOT NULL DEFAULT 0 AFTER `MaxDuration`;

ALTER TABLE `spell_effect`
  ADD `TargetNodeGraph` int NOT NULL DEFAULT 0 AFTER `ScalingClass`,
  MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `EffectAura`;

ALTER TABLE `spell_interrupts` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_levels` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_misc`
  ADD `Attributes17` int NOT NULL DEFAULT 0 AFTER `Attributes16`,
  MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `Attributes17`;

ALTER TABLE `spell_power_difficulty` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_procs_per_minute` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `BaseProcRate`;

ALTER TABLE `spell_procs_per_minute_mod` MODIFY `Type` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_range` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `DisplayNameShort`;

ALTER TABLE `spell_reagents_currency`
  MODIFY `CurrencyTypesID` int NOT NULL DEFAULT 0 AFTER `SpellID`,
  MODIFY `CurrencyCount` int NOT NULL DEFAULT 0 AFTER `CurrencyTypesID`,
  ADD `OverrideRecraftCurrencyCount` int NOT NULL DEFAULT 0 AFTER `CurrencyCount`,
  ADD `OrderSource` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `OverrideRecraftCurrencyCount`;

ALTER TABLE `spell_scaling` DROP `ScalesFromItemLevel`;

ALTER TABLE `spell_target_restrictions` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_visual_effect_name`
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Alpha`,
  MODIFY `Type` int NOT NULL DEFAULT 0 AFTER `EffectRadius`;

ALTER TABLE `spell_visual_missile` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `FollowGroundApproach`;

ALTER TABLE `spell_x_spell_visual` MODIFY `DifficultyID` smallint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_edge` MODIFY `Type` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `RightTraitNodeID`;

ALTER TABLE `ui_map` DROP `VisibilityPlayerConditionID2`;

DROP TABLE IF EXISTS `pvp_item`;
