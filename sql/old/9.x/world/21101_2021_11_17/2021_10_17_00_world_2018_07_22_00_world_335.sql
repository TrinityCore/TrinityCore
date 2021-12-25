-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1822;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,1822,2473,0,0,6,0,67,0,0,0,0,0,"","Show gossip text 2473 if player is Horde"),
(14,1822,2474,0,0,6,0,469,0,0,0,0,0,"","Show gossip text 2474 if player is Alliance");
