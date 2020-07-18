--
DELETE FROM `conditions` WHERE `SourceEntry`=25063;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 25063, 0, 0, 31, 0, 4, 0, 0, 1, 0, 0, "", "Dawnblade Hawkrider's SAI id 1 does not execute if invoker is a player");
