-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (50790,50791,50802,50803,50825,50826) AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 50790, 0, 0, 31, 0, 3, 22515, 0, 0, 0, 0, "", ""),
(13, 1, 50791, 0, 0, 31, 0, 3, 22515, 0, 0, 0, 0, "", ""),
(13, 2, 50790, 0, 0, 31, 0, 5, 192163, 0, 0, 0, 0, "", ""),
(13, 2, 50791, 0, 0, 31, 0, 5, 192164, 0, 0, 0, 0, "", ""),
(13, 1, 50802, 0, 0, 31, 0, 3, 22515, 0, 0, 0, 0, "", ""),
(13, 1, 50803, 0, 0, 31, 0, 3, 22515, 0, 0, 0, 0, "", ""),
(13, 2, 50802, 0, 0, 31, 0, 5, 192163, 0, 0, 0, 0, "", ""),
(13, 2, 50803, 0, 0, 31, 0, 5, 192164, 0, 0, 0, 0, "", ""),
(13, 1, 50825, 0, 0, 31, 0, 3, 22515, 0, 0, 0, 0, "", ""),
(13, 1, 50826, 0, 0, 31, 0, 3, 22515, 0, 0, 0, 0, "", ""),
(13, 2, 50825, 0, 0, 31, 0, 5, 192163, 0, 0, 0, 0, "", ""),
(13, 2, 50826, 0, 0, 31, 0, 5, 192164, 0, 0, 0, 0, "", "");
