--
-- Table structure for table `conditional_chr_model`
--
DROP TABLE IF EXISTS `conditional_chr_model`;
CREATE TABLE `conditional_chr_model` (
  `ID` int(11) NOT NULL DEFAULT '0',
  `ChrModelID` int(10) unsigned NOT NULL DEFAULT '0',
  `ChrCustomizationReqID` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `ChrCustomizationCategoryID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


ALTER TABLE `area_table` MODIFY `MountFlags` int NOT NULL DEFAULT 0 AFTER `AmbientMultiplier`;

ALTER TABLE `chr_customization_req` ADD `RaceMask` bigint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `criteria` MODIFY `StartEvent` int NOT NULL DEFAULT 0 AFTER `ModifierTreeId`;
ALTER TABLE `criteria` MODIFY `FailEvent` int NOT NULL DEFAULT 0 AFTER `StartTimer`;
ALTER TABLE `criteria` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `FailAsset`;

ALTER TABLE `criteria_tree` MODIFY `Operator` int NOT NULL DEFAULT 0 AFTER `Amount`;

ALTER TABLE `gameobject_display_info` ADD `AlternateDisplayType` int NOT NULL DEFAULT 0 AFTER `OverrideNameScale`;
ALTER TABLE `gameobject_display_info` ADD `ClientCreatureDisplayInfoID` int NOT NULL DEFAULT 0 AFTER `AlternateDisplayType`;
ALTER TABLE `gameobject_display_info` ADD `ClientItemID` int NOT NULL DEFAULT 0 AFTER `ClientCreatureDisplayInfoID`;

ALTER TABLE `spell_category` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `ui_map` ADD `VisibilityPlayerConditionID2` int NOT NULL DEFAULT 0 AFTER `BountyDisplayLocation`;
