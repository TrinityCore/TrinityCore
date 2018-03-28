DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 25 AND `SourceEntry`= 736;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`, `Comment`) VALUES 
(25, 736, 6, 67, 0, 'Terrainwap: Dragonmaw Port visible only for Horde'),
(25, 736, 8, 26830, 1, 'Terrainwap: Dragonmaw Port inactive when rewarded quest 26830');

DELETE FROM `terrain_swap_defaults` WHERE `TerrainSwapMap`= 736;
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(0, 736, 'Twilight Highlands - Dragonmaw Port');

