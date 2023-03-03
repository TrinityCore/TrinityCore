-- 
DELETE FROM `terrain_swap_defaults` WHERE `TerrainSwapMap` = 1817;
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES 
(1, 1817, 'Silithus: The Wound');

DELETE FROM `terrain_worldmap` WHERE `TerrainSwapMap` = 1817;
INSERT INTO `terrain_worldmap` (`TerrainSwapMap`, `UiMapPhaseId`, `Comment`) VALUES 
(1817, 9491, 'Silithus: The Wound');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 25 AND `SourceEntry` = 1817;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25, 0, 1817, 0, 0, 27, 0, 110, 3, 0, 0, 0, 0, '', 'TerrainSwap 1817 only when player has level 110');
