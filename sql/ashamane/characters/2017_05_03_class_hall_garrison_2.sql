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
