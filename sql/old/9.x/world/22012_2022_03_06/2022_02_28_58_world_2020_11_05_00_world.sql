--
DELETE FROM `conditions` WHERE `SourceEntry`= 40647 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 4, 40647, 0, 0, 31, 0, 3, 23089, 0, 0, 0, '', 'Shadow Prison - Target Akama');
