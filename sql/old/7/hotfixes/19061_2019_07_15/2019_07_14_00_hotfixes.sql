--
-- Table structure for table `cfg_regions`
--
ALTER TABLE `cfg_regions`
  DROP `ChallengeTimeOffset1`,
  DROP `ChallengeTimeOffset2`;

--
-- Table structure for table `content_tuning`
--
ALTER TABLE `content_tuning`
  ADD `ExpansionID` int(11) NOT NULL DEFAULT '0' AFTER `Flags`,
  DROP `ExpectedStatModID`,
  DROP `DifficultyESMID`;

--
-- Table structure for table `content_tuning_x_expected`
--
DROP TABLE IF EXISTS `content_tuning_x_expected`;
CREATE TABLE `content_tuning_x_expected` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ExpectedStatModID` int(11) NOT NULL DEFAULT '0',
  `ContentTuningID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `creature_model_data`
--
ALTER TABLE `creature_model_data`
  ADD `Unknown820_1` tinyint(4) NOT NULL DEFAULT '0' AFTER `TamedPetBaseScale`,
  ADD `Unknown820_2` float NOT NULL DEFAULT '0' AFTER `Unknown820_1`,
  ADD `Unknown820_31` float NOT NULL DEFAULT '0' AFTER `Unknown820_2`,
  ADD `Unknown820_32` float NOT NULL DEFAULT '0' AFTER `Unknown820_31`;

--
-- Table structure for table `garr_follower`
--
ALTER TABLE `garr_follower` MODIFY `HordeGarrClassSpecID` int(11) NOT NULL DEFAULT '0' AFTER `AllianceGarrFollRaceID`;
ALTER TABLE `garr_follower` MODIFY `AllianceGarrClassSpecID` int(11) NOT NULL DEFAULT '0' AFTER `HordeGarrClassSpecID`;

--
-- Table structure for table `glyph_properties`
--
ALTER TABLE `glyph_properties` ADD `SpellIconFileDataID` int(11) NOT NULL DEFAULT '0' AFTER `GlyphExclusiveCategoryID`;
ALTER TABLE `glyph_properties` DROP `SpellIconID`;

--
-- Table structure for table `modifier_tree`
--
ALTER TABLE `modifier_tree` MODIFY `Type` int(11) NOT NULL DEFAULT '0' AFTER `Amount`;

--
-- Table structure for table `mount_capability`
--
ALTER TABLE `mount_capability` ADD `PlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `ReqMapID`;

--
-- Table structure for table `rand_prop_points`
--
ALTER TABLE `rand_prop_points` ADD `DamageSecondary` int(11) NOT NULL DEFAULT '0' AFTER `DamageReplaceStat`;

--
-- Table structure for table `spell_misc`
--
ALTER TABLE `spell_misc` ADD `ContentTuningID` int(11) NOT NULL DEFAULT '0' AFTER `ActiveIconFileDataID`;

--
-- Table structure for table `ui_map_link`
--
ALTER TABLE `ui_map_link`
  ADD `OverrideHighlightFileDataID` int(11) NOT NULL DEFAULT '0' AFTER `ChildUiMapID`,
  ADD `OverrideHighlightAtlasID` int(11) NOT NULL DEFAULT '0' AFTER `OverrideHighlightFileDataID`;
