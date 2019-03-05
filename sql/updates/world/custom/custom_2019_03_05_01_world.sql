DELETE FROM `conditions` WHERE `SourceEntry` IN (75365, 75378) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 75365, 0, 0, 31, 0, 3, 40406, 0, 0, 0, '', 'Consume - Target Tumultous Earthstorm');
