ALTER TABLE `terrain_worldmap`
  DROP PRIMARY KEY,
  ADD `UiMapPhaseId` int(10) unsigned NOT NULL AFTER `TerrainSwapMap`;

DELETE FROM `terrain_worldmap` WHERE `TerrainSwapMap`=638;
UPDATE `terrain_worldmap` SET `UiMapPhaseId`=52 WHERE `TerrainSwapMap`=655;
UPDATE `terrain_worldmap` SET `UiMapPhaseId`=54 WHERE `TerrainSwapMap`=656;
UPDATE `terrain_worldmap` SET `UiMapPhaseId`=165 WHERE `TerrainSwapMap`=719;
UPDATE `terrain_worldmap` SET `UiMapPhaseId`=2801 WHERE `TerrainSwapMap`=545;

ALTER TABLE `terrain_worldmap`
  ADD PRIMARY KEY(`TerrainSwapMap`,`UiMapPhaseId`),
  DROP `WorldMapArea`;
