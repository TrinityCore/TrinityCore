DROP TABLE IF EXISTS `character_world_quest`;
CREATE TABLE `character_world_quest` (
  `guid` BIGINT (20) UNSIGNED NOT NULL,
  `questId` INT (10) UNSIGNED NOT NULL,
  `lastupdate` INT (10) UNSIGNED NOT NULL,
  `timer` INT (10) UNSIGNED NOT NULL,
  `variableID` INT (10) UNSIGNED NOT NULL,
  `value` INT (10) NOT NULL,
  PRIMARY KEY (`guid`, `questId`)
);
