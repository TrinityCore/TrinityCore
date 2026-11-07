DROP TABLE IF EXISTS `creature_static_flags_override`;
CREATE TABLE `creature_static_flags_override` (  
  `SpawnId` BIGINT UNSIGNED NOT NULL,
  `DifficultyId` TINYINT UNSIGNED NOT NULL DEFAULT 0,
  `StaticFlags1` INT UNSIGNED,
  `StaticFlags2` INT UNSIGNED,
  `StaticFlags3` INT UNSIGNED,
  `StaticFlags4` INT UNSIGNED,
  `StaticFlags5` INT UNSIGNED,
  `StaticFlags6` INT UNSIGNED,
  `StaticFlags7` INT UNSIGNED,
  `StaticFlags8` INT UNSIGNED,
  PRIMARY KEY (`SpawnId`, `DifficultyId`) 
);
