DELETE FROM `terrain_swap_defaults` WHERE `TerrainSwapMap` IN (1817, 1815);
INSERT INTO `terrain_swap_defaults` VALUES
(1, 1815, 'Silithus'),
(1, 1817, 'Silithus: The Wound');

DELETE FROM `terrain_worldmap` WHERE `TerrainSwapMap` IN (1817, 1815);
INSERT INTO `terrain_worldmap` VALUES
(1817, 9491, 'Silithus: The Wound'),
(1815, 0, 'Silithus');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 25 AND `SourceEntry` = 1817;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25, 0, 1817, 0, 0, 27, 0, 110, 3, 0, 0, 0, 0, '', 'TerrainSwap 1817 only when player has level 110');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 25 AND `SourceEntry` = 1815;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25, 0, 1815, 0, 0, 27, 0, 110, 3, 0, 1, 0, 0, '', 'TerrainSwap 1815 only when player has not level 110');

