DROP TABLE IF EXISTS `character_queststatus_objectives_spawn_tracking`;
CREATE TABLE `character_queststatus_objectives_spawn_tracking` (
  `guid` BIGINT UNSIGNED NOT NULL,
  `quest` INT UNSIGNED NOT NULL,
  `objective` TINYINT UNSIGNED NOT NULL DEFAULT '0',
  `spawnTrackingId` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`guid`,`quest`,`objective`,`spawnTrackingId`)
) ENGINE=INNODB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
