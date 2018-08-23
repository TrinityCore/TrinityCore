ALTER TABLE `character_garrison` ADD COLUMN `type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`, DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`, `type`); 
ALTER TABLE `character_garrison_blueprints` ADD COLUMN `garrison_type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`, DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`, `garrison_type`, `buildingId`); 
ALTER TABLE `character_garrison_buildings` ADD COLUMN `garrison_type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`, DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`, `garrison_type`, `plotInstanceId`); 
ALTER TABLE `character_garrison_followers` ADD COLUMN `garrison_type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`;

DROP TABLE IF EXISTS `character_garrison_missions`;
CREATE TABLE `character_garrison_missions` (
  `dbId` BIGINT (20) UNSIGNED NOT NULL,
  `guid` BIGINT (20) UNSIGNED NOT NULL,
  `garrison_type` TINYINT (3) UNSIGNED NOT NULL,
  `missionId` INT UNSIGNED NOT NULL,
  `offerTime` INT (10) NOT NULL,
  `startTime` INT (10) NOT NULL,
  `status` TINYINT (3) UNSIGNED NOT NULL,
  PRIMARY KEY (`dbId`)
);

DROP TABLE IF EXISTS `character_garrison_mission_rewards`;
CREATE TABLE `character_garrison_mission_rewards`(
    `dbId` INT(10) UNSIGNED NOT NULL,
    `type` TINYINT(3) UNSIGNED NOT NULL,
    `itemId` INT(10) NOT NULL DEFAULT 0,
    `itemQuantity` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `currencyId` INT(10) NOT NULL DEFAULT 0,
    `currencyQuantity` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `FollowerXP` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `BonusAbilityId` INT(10) UNSIGNED NOT NULL DEFAULT 0
);
