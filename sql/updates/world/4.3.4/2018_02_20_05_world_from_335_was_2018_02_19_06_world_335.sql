/*
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (2177,2178,2179);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2177,2933,0,0,8,0,4321,0,0,0,0,0,"","Show gossip text 2933 if quest 'Making Sense of It' is rewarded"), -- Northern Crystal Pylon
(14,2178,2933,0,0,8,0,4321,0,0,0,0,0,"","Show gossip text 2933 if quest 'Making Sense of It' is rewarded"), -- Eastern Crystal Pylon
(14,2179,2933,0,0,8,0,4321,0,0,0,0,0,"","Show gossip text 2933 if quest 'Making Sense of It' is rewarded"); -- Western Crystal Pylon
*/
