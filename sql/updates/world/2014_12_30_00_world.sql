DROP TABLE IF EXISTS `phase_definitions`;
DROP TABLE IF EXISTS `phase_info`;
DROP TABLE IF EXISTS `terrain_phase_info`;
DROP TABLE IF EXISTS `terrain_map_info`;

CREATE TABLE `terrain_phase_info`(  
  `Id` INT(10) unsigned NOT NULL,
  `TerrainSwapMap` INT(10) unsigned NOT NULL,
  `Comment` VARCHAR(255),
  PRIMARY KEY (`Id`, `TerrainSwapMap`)
);

CREATE TABLE `terrain_map_info`(
  `MapId` INT(10) unsigned NOT NULL,
  `TerrainSwapMap` INT(10) unsigned NOT NULL,
  `Comment` VARCHAR(255),
  PRIMARY KEY (`MapId`, `TerrainSwapMap`)
);

