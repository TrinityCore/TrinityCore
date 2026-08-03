ALTER TABLE `character_loadout`
  ADD `RaceMask_1` int NOT NULL DEFAULT 0 AFTER `ItemContext`,
  ADD `RaceMask_2` int NOT NULL DEFAULT 0 AFTER `RaceMask_1`;

UPDATE `character_loadout` SET 
  `RaceMask_1` = IF((`RaceMask` >>  0) & 0x80000000, CAST(((`RaceMask` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >>  0) & 0xFFFFFFFF),
  `RaceMask_2` = IF((`RaceMask` >> 32) & 0x80000000, CAST(((`RaceMask` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >> 32) & 0xFFFFFFFF);

ALTER TABLE `chr_customization_req`
  ADD `RaceMask_1` int NOT NULL DEFAULT 0 AFTER `ItemModifiedAppearanceID`,
  ADD `RaceMask_2` int NOT NULL DEFAULT 0 AFTER `RaceMask_1`;

UPDATE `chr_customization_req` SET 
  `RaceMask_1` = IF((`RaceMask` >>  0) & 0x80000000, CAST(((`RaceMask` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >>  0) & 0xFFFFFFFF),
  `RaceMask_2` = IF((`RaceMask` >> 32) & 0x80000000, CAST(((`RaceMask` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >> 32) & 0xFFFFFFFF);

ALTER TABLE `emotes`
  ADD `RaceMask_1` int NOT NULL DEFAULT 0 AFTER `ClassMask`,
  ADD `RaceMask_2` int NOT NULL DEFAULT 0 AFTER `RaceMask_1`;

UPDATE `emotes` SET 
  `RaceMask_1` = IF((`RaceMask` >>  0) & 0x80000000, CAST(((`RaceMask` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >>  0) & 0xFFFFFFFF),
  `RaceMask_2` = IF((`RaceMask` >> 32) & 0x80000000, CAST(((`RaceMask` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >> 32) & 0xFFFFFFFF);

ALTER TABLE `faction`
  ADD `ReputationRaceMask1_1` int NOT NULL DEFAULT 0 AFTER `ParentFactionCap2`,
  ADD `ReputationRaceMask1_2` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask1_1`,
  ADD `ReputationRaceMask2_1` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask1_2`,
  ADD `ReputationRaceMask2_2` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask2_1`,
  ADD `ReputationRaceMask3_1` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask2_2`,
  ADD `ReputationRaceMask3_2` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask3_1`,
  ADD `ReputationRaceMask4_1` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask3_2`,
  ADD `ReputationRaceMask4_2` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask4_1`;

UPDATE `faction` SET 
  `ReputationRaceMask1_1` = IF((`ReputationRaceMask1` >>  0) & 0x80000000, CAST(((`ReputationRaceMask1` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask1` >>  0) & 0xFFFFFFFF),
  `ReputationRaceMask1_2` = IF((`ReputationRaceMask1` >> 32) & 0x80000000, CAST(((`ReputationRaceMask1` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask1` >> 32) & 0xFFFFFFFF),
  `ReputationRaceMask2_1` = IF((`ReputationRaceMask2` >>  0) & 0x80000000, CAST(((`ReputationRaceMask2` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask2` >>  0) & 0xFFFFFFFF),
  `ReputationRaceMask2_2` = IF((`ReputationRaceMask2` >> 32) & 0x80000000, CAST(((`ReputationRaceMask2` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask2` >> 32) & 0xFFFFFFFF),
  `ReputationRaceMask3_1` = IF((`ReputationRaceMask3` >>  0) & 0x80000000, CAST(((`ReputationRaceMask3` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask3` >>  0) & 0xFFFFFFFF),
  `ReputationRaceMask3_2` = IF((`ReputationRaceMask3` >> 32) & 0x80000000, CAST(((`ReputationRaceMask3` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask3` >> 32) & 0xFFFFFFFF),
  `ReputationRaceMask4_1` = IF((`ReputationRaceMask4` >>  0) & 0x80000000, CAST(((`ReputationRaceMask4` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask4` >>  0) & 0xFFFFFFFF),
  `ReputationRaceMask4_2` = IF((`ReputationRaceMask4` >> 32) & 0x80000000, CAST(((`ReputationRaceMask4` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`ReputationRaceMask4` >> 32) & 0xFFFFFFFF);

ALTER TABLE `item_extended_cost` ADD `Money` bigint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_search_name`
  ADD `AllowableRace_1` int NOT NULL DEFAULT 0 AFTER `Flags5`,
  ADD `AllowableRace_2` int NOT NULL DEFAULT 0 AFTER `AllowableRace_1`;

UPDATE `item_search_name` SET 
  `AllowableRace_1` = IF((`AllowableRace` >>  0) & 0x80000000, CAST(((`AllowableRace` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`AllowableRace` >>  0) & 0xFFFFFFFF),
  `AllowableRace_2` = IF((`AllowableRace` >> 32) & 0x80000000, CAST(((`AllowableRace` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`AllowableRace` >> 32) & 0xFFFFFFFF);

ALTER TABLE `item_sparse`
  ADD `AllowableRace_1` int NOT NULL DEFAULT 0 AFTER `RequiredAbility`,
  ADD `AllowableRace_2` int NOT NULL DEFAULT 0 AFTER `AllowableRace_1`;

UPDATE `item_sparse` SET 
  `AllowableRace_1` = IF((`AllowableRace` >>  0) & 0x80000000, CAST(((`AllowableRace` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`AllowableRace` >>  0) & 0xFFFFFFFF),
  `AllowableRace_2` = IF((`AllowableRace` >> 32) & 0x80000000, CAST(((`AllowableRace` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`AllowableRace` >> 32) & 0xFFFFFFFF);

ALTER TABLE `movie` ADD `Summary` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

--
-- Table structure for table `movie_locale`
--
DROP TABLE IF EXISTS `movie_locale`;
CREATE TABLE `movie_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Summary_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB);

ALTER TABLE `path_node` MODIFY `PathID` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `path_property` MODIFY `PathID` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `player_condition`
  ADD `RaceMask_1` int NOT NULL DEFAULT 0 AFTER `MovementFlags2`,
  ADD `RaceMask_2` int NOT NULL DEFAULT 0 AFTER `RaceMask_1`;

UPDATE `player_condition` SET 
  `RaceMask_1` = IF((`RaceMask` >>  0) & 0x80000000, CAST(((`RaceMask` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >>  0) & 0xFFFFFFFF),
  `RaceMask_2` = IF((`RaceMask` >> 32) & 0x80000000, CAST(((`RaceMask` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >> 32) & 0xFFFFFFFF);

ALTER TABLE `scenario` ADD `UiScenarioDisplayInfoID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `UiTextureKitID`;

ALTER TABLE `skill_line_ability`
  ADD `RaceMask_1` int NOT NULL DEFAULT 0 AFTER `SkillupSkillLineID`,
  ADD `RaceMask_2` int NOT NULL DEFAULT 0 AFTER `RaceMask_1`;

UPDATE `skill_line_ability` SET 
  `RaceMask_1` = IF((`RaceMask` >>  0) & 0x80000000, CAST(((`RaceMask` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >>  0) & 0xFFFFFFFF),
  `RaceMask_2` = IF((`RaceMask` >> 32) & 0x80000000, CAST(((`RaceMask` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >> 32) & 0xFFFFFFFF);

ALTER TABLE `skill_race_class_info`
  ADD `RaceMask_1` int NOT NULL DEFAULT 0 AFTER `SkillTierID`,
  ADD `RaceMask_2` int NOT NULL DEFAULT 0 AFTER `RaceMask_1`;

UPDATE `skill_race_class_info` SET 
  `RaceMask_1` = IF((`RaceMask` >>  0) & 0x80000000, CAST(((`RaceMask` >>  0) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >>  0) & 0xFFFFFFFF),
  `RaceMask_2` = IF((`RaceMask` >> 32) & 0x80000000, CAST(((`RaceMask` >> 32) & 0xFFFFFFFF) | 0xFFFFFFFF00000000 AS SIGNED), (`RaceMask` >> 32) & 0xFFFFFFFF);

ALTER TABLE `taxi_path_node` MODIFY COLUMN `PathID` int unsigned NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `transmog_outfit_entry` ADD `OutfitIndex` int NOT NULL DEFAULT 0 AFTER `OverrideCostModifier`;
