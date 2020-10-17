
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

DROP TABLE IF EXISTS `world_quest`;
CREATE TABLE `world_quest` (
  `id` INT (10) UNSIGNED NOT NULL,
  `rewardid` INT(10) UNSIGNED NOT NULL,
  `starttime` INT (10) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`)
);

ALTER TABLE `character_queststatus` ADD COLUMN `explored` TINYINT(3) UNSIGNED DEFAULT 0 NOT NULL AFTER `timer`;
