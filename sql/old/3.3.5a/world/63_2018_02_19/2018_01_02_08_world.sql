-- Add condition to gossip text of Thassarian
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9840;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 9840, 13609, 0, 0, 8, 0, 12019, 0, 0, 0, 0, 0, "", "Gossip if quest=12019 is completed"), 
(14, 9840, 13608, 0, 0, 8, 0, 12019, 0, 0, 1, 0, 0, "", "Gossip if quest=12019 isn't completed");
