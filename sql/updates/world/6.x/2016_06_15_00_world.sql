-- 
DELETE FROM `terrain_swap_defaults` WHERE `MapId`= 0 AND `TerrainSwapMap`= 1190;
INSERT INTO `terrain_swap_defaults` (`MapId`,`TerrainSwapMap`,`Comment`) VALUES
(0, 1190, 'Blasted Land Terrian');

DELETE FROM `terrain_worldmap` WHERE `TerrainSwapMap`= 545 AND `WorldMapArea`= 683;
INSERT INTO `terrain_worldmap` (`TerrainSwapMap`,`WorldMapArea`,`Comment`) VALUES
(545, 683, 'Blasted Land Swap');
