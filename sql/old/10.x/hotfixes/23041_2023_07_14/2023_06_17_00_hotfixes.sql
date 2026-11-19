--
-- Table structure for table `challenge_mode_item_bonus_override`
--
DROP TABLE IF EXISTS `challenge_mode_item_bonus_override`;
CREATE TABLE `challenge_mode_item_bonus_override` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusTreeGroupID` int(11) NOT NULL DEFAULT '0',
  `DstItemBonusTreeID` int(11) NOT NULL DEFAULT '0',
  `Type` tinyint(4) NOT NULL DEFAULT '0',
  `Value` int(11) NOT NULL DEFAULT '0',
  `MythicPlusSeasonID` int(11) NOT NULL DEFAULT '0',
  `PvPSeasonID` int(11) NOT NULL DEFAULT '0',
  `SrcItemBonusTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `conditional_content_tuning`
--
DROP TABLE IF EXISTS `conditional_content_tuning`;
CREATE TABLE `conditional_content_tuning` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `RedirectContentTuningID` int(11) NOT NULL DEFAULT '0',
  `RedirectFlag` int(11) NOT NULL DEFAULT '0',
  `ParentContentTuningID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `content_tuning_x_label`
--
DROP TABLE IF EXISTS `content_tuning_x_label`;
CREATE TABLE `content_tuning_x_label` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LabelID` int(11) NOT NULL DEFAULT '0',
  `ContentTuningID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `item_bonus_list_group_entry`
--
DROP TABLE IF EXISTS `item_bonus_list_group_entry`;
CREATE TABLE `item_bonus_list_group_entry` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListGroupID` int(11) NOT NULL DEFAULT '0',
  `ItemBonusListID` int(11) NOT NULL DEFAULT '0',
  `ItemLevelSelectorID` int(11) NOT NULL DEFAULT '0',
  `SequenceValue` int(11) NOT NULL DEFAULT '0',
  `ItemExtendedCostID` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `ItemLogicalCostGroupID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `item_bonus_tree`
--
DROP TABLE IF EXISTS `item_bonus_tree`;
CREATE TABLE `item_bonus_tree` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `InventoryTypeSlotMask` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_bonus_tree_node` CHANGE `Unknown1010_1` `MinMythicPlusLevel` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `item_bonus_tree_node` CHANGE `Unknown1010_2` `MaxMythicPlusLevel` int(11) NOT NULL DEFAULT '0';

--
-- Table structure for table `item_context_picker_entry`
--
DROP TABLE IF EXISTS `item_context_picker_entry`;
CREATE TABLE `item_context_picker_entry` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemCreationContext` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PVal` int(11) NOT NULL DEFAULT '0',
  `LabelID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemContextPickerID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `mythic_plus_season`
--
DROP TABLE IF EXISTS `mythic_plus_season`;
CREATE TABLE `mythic_plus_season` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MilestoneSeason` int(11) NOT NULL DEFAULT '0',
  `ExpansionLevel` int(11) NOT NULL DEFAULT '0',
  `HeroicLFGDungeonMinGear` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `pvp_season`
--
DROP TABLE IF EXISTS `pvp_season`;
CREATE TABLE `pvp_season` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MilestoneSeason` int(11) NOT NULL DEFAULT '0',
  `AllianceAchievementID` int(11) NOT NULL DEFAULT '0',
  `HordeAchievementID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

