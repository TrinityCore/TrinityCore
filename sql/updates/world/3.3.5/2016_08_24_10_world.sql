--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=56753;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `COMMENT`) VALUES
(17, 0, 56753, 0, 0, 31, 1, 3, 30120, 0, 0, 0, 0, "", "Spell 'Throw Snowball' can only target 'Seething Revenant'");
