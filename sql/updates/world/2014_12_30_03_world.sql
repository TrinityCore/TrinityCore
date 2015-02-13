DROP TABLE IF EXISTS `terrain_phase_info`;
DROP TABLE IF EXISTS `terrain_map_info`;
DROP TABLE IF EXISTS `terrain_swap_defaults`;
DROP TABLE IF EXISTS `terrain_worldmap`;

CREATE TABLE `terrain_phase_info`(  
  `Id` INT(10) unsigned NOT NULL,
  `TerrainSwapMap` INT(10) unsigned NOT NULL,
  `Comment` VARCHAR(255),
  PRIMARY KEY (`Id`, `TerrainSwapMap`)
);

CREATE TABLE `terrain_swap_defaults`(  
  `MapId` INT(10) unsigned NOT NULL,
  `TerrainSwapMap` INT(10) unsigned NOT NULL,
  `Comment` VARCHAR(255),
  PRIMARY KEY (`MapId`, `TerrainSwapMap`)
);

CREATE TABLE `terrain_worldmap`(  
  `TerrainSwapMap` INT(10) unsigned NOT NULL,
  `WorldMapArea` INT(10) unsigned NOT NULL,
  `Comment` VARCHAR(255),
  PRIMARY KEY (`TerrainSwapMap`, `WorldMapArea`)
);

INSERT INTO `terrain_phase_info` (Id, TerrainSwapMap, Comment) VALUES 
(182, 655, 'Quest Zone-Specific 07'),
(186, 656, 'Quest Zone-Specific 11');

INSERT INTO `terrain_worldmap` (TerrainSwapMap, WorldMapArea, Comment) VALUES 
(638, 545, 'Gilneas'),
(655, 678, 'Gilneas_terrain1'),
(719, 683, 'Hyjal_terrain1'),
(656, 679, 'Gilneas_terrain2');

INSERT INTO `terrain_swap_defaults` (MapId, TerrainSwapMap, Comment) VALUES 
(1, 719, 'Mount Hyjal default terrain'),
(654, 638, 'Gilneas default terrain');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `SourceEntry`=719;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25, 0, 719, 0, 0, 8, 0, 25372, 0, 0, 1, 0, 0, '', 'Hyjal terrain swap if Aessina''s Miracle quest is not rewarded');

