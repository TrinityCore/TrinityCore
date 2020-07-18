-- 
DELETE FROM `conditions` WHERE `SourceEntry`=56189 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56189, 0, 0, 31, 0, 3, 29368, 0, 0, 0, 0, '', 'Horn target Valduran'),
(13, 1, 56189, 0, 0, 29, 0, 29801, 30, 0, 1, 0, 0, '', 'Horn target'),
(13, 1, 56189, 0, 0, 29, 0, 30152, 30, 0, 1, 0, 0, '', 'Horn target');
