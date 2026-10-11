ALTER TABLE `area_table` MODIFY `PvpCombatWorldStateID` int NOT NULL DEFAULT 0 AFTER `MountFlags`;

ALTER TABLE `broadcast_text` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `EmotesID`;

ALTER TABLE `chr_specialization` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Role`;

ALTER TABLE `content_tuning` ADD `PrimaryStatScalingModPlayerDataElementCharacterID` int NOT NULL DEFAULT 0 AFTER `DamagePrimaryStatCurveID`;
ALTER TABLE `content_tuning` ADD `PrimaryStatScalingModPlayerDataElementCharacterMultiplier` float NOT NULL DEFAULT 0 AFTER `PrimaryStatScalingModPlayerDataElementCharacterID`;

ALTER TABLE `curve` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `curve_point` MODIFY `OrderIndex` int UNSIGNED NOT NULL DEFAULT 0 AFTER `CurveID`;

ALTER TABLE `item` MODIFY `ItemGroupSoundsID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `IconFileDataID`;

ALTER TABLE `item_bonus_tree_node` ADD `ItemCreationContextGroupID` int NOT NULL DEFAULT 0 AFTER `MaxMythicPlusLevel`;
ALTER TABLE `item_bonus_tree_node` ADD `Flags` int NOT NULL DEFAULT 0 AFTER `ItemCreationContextGroupID`;

--
-- Table structure for table `item_creation_context`
--
DROP TABLE IF EXISTS `item_creation_context`;
CREATE TABLE `item_creation_context` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemContext` tinyint unsigned NOT NULL DEFAULT '0',
  `ItemCreationContextGroupID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `item_offset_curve`
--
DROP TABLE IF EXISTS `item_offset_curve`;
CREATE TABLE `item_offset_curve` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `CurveID` int NOT NULL DEFAULT '0',
  `Offset` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `item_scaling_config`
--
DROP TABLE IF EXISTS `item_scaling_config`;
CREATE TABLE `item_scaling_config` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `ItemOffsetCurveID` int NOT NULL DEFAULT '0',
  `ItemLevel` int NOT NULL DEFAULT '0',
  `RequiredLevel` int NOT NULL DEFAULT '0',
  `Unknown1125` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_sparse` ADD `ItemLevelOffsetCurveID` int NOT NULL DEFAULT 0 AFTER `PlayerLevelToItemLevelCurveID`;
ALTER TABLE `item_sparse` ADD `ItemLevelOffsetItemLevel` int NOT NULL DEFAULT 0 AFTER `ItemLevelOffsetCurveID`;

ALTER TABLE `player_condition` MODIFY `Achievement1` int UNSIGNED NOT NULL DEFAULT 0 AFTER `AuraStacks4`;
ALTER TABLE `player_condition` MODIFY `Achievement2` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Achievement1`;
ALTER TABLE `player_condition` MODIFY `Achievement3` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Achievement2`;
ALTER TABLE `player_condition` MODIFY `Achievement4` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Achievement3`;

ALTER TABLE `player_data_element_account` ADD `Unknown1125` int NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `player_data_element_character` ADD `Unknown1125` int NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `player_data_flag_account` ADD `Unknown1125` int NOT NULL DEFAULT 0 AFTER `Unknown1107`;

ALTER TABLE `player_data_flag_character` ADD `Unknown1125` int NOT NULL DEFAULT 0 AFTER `Unknown1107`;

ALTER TABLE `scene_script` MODIFY `FirstSceneScriptID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;
ALTER TABLE `scene_script` MODIFY `NextSceneScriptID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `FirstSceneScriptID`;

ALTER TABLE `spell_categories` MODIFY `DefenseType` int NOT NULL DEFAULT 0 AFTER `Category`;
ALTER TABLE `spell_categories` MODIFY `PreventionType` int NOT NULL DEFAULT 0 AFTER `Mechanic`;

ALTER TABLE `spell_interrupts` MODIFY `InterruptFlags` int NOT NULL DEFAULT 0 AFTER `DifficultyID`;

ALTER TABLE `trait_cost` ADD `CurveID` int NOT NULL DEFAULT 0 AFTER `TraitCurrencyID`;

ALTER TABLE `trait_currency` ADD `PlayerDataElementAccountID` int NOT NULL DEFAULT 0 AFTER `Icon`;
ALTER TABLE `trait_currency` ADD `PlayerDataElementCharacterID` int NOT NULL DEFAULT 0 AFTER `PlayerDataElementAccountID`;

--
-- Table structure for table `trait_system`
--
DROP TABLE IF EXISTS `trait_system`;
CREATE TABLE `trait_system` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `WidgetSetID` int NOT NULL DEFAULT '0',
  `TraitChangeSpell` int NOT NULL DEFAULT '0',
  `ItemID` int NOT NULL DEFAULT '0',
  `VariationType` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `ui_map_assignment` ADD `Unknown1125` int NOT NULL DEFAULT 0 AFTER `WmoGroupID`;
