UPDATE `creature_template` SET `scriptname` = 'npc_baros_alexston' WHERE `entry` = 79243;

-- TerrainSwap
DELETE FROM `terrain_swap_defaults` WHERE (`MapId` = 1116 AND `TerrainSwapMap` = 1158);
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(1116, 1158, ' SMV Alliance Garrison Level 1');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 25 AND `SourceGroup` = 0 AND `SourceEntry` = 1158);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(25, 0, 1158, 0, 0, 47, 0, 34586, 66, 0, 0, 'TerrainSwap to 1158 if Quest: 34586 is completed/rewarded');
