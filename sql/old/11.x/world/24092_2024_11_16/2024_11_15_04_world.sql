DELETE FROM `terrain_swap_defaults` WHERE `MapId`=870 AND `TerrainSwapMap`=1076;
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(870, 1076, 'The Jade Forest - Jade Forest Horde Starting Area');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `SourceEntry`=1076;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25,0,1076,0,0,6,0,67,0,0,'',0,0,0,'','Apply terrain swap 1076 if player is Horde'),
(25,0,1076,0,0,47,0,31769,(2 | 64),0,'',1,0,0,'','Apply terrain swap 1076 if quest 31769 is not complete | rewarded');
