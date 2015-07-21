DELETE FROM `terrain_map_info` WHERE `MapId` IN (656, 655);
INSERT INTO `terrain_map_info` (MapId, TerrainSwapMap, Comment) VALUES 
(655, 677, 'Gilneas_terrain1'),
(656, 679, 'Gilneas_terrain2');

DELETE FROM `terrain_phase_info` WHERE `Id` IN (182, 186);
INSERT INTO `terrain_phase_info` (Id, TerrainSwapMap, Comment) VALUES 
(182, 655, 'Quest Zone-Specific 07'),
(186, 656, 'Quest Zone-Specific 11');
DELETE FROM `disables` WHERE `entry` IN (10068, 10069) AND `sourceType` = 4;
