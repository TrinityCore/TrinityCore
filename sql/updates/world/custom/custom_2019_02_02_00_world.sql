DELETE FROM `conditions` WHERE `SourceEntry`= 86425 AND `SourceTypeOrReferenceId`= 17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(17, 0, 86425, 0, 0, 31, 1, 3, 46393, 0, 0, 0, '', 'Billy Goat Blast - Allow Billy Goat only');
