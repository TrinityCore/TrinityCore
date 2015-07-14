DELETE FROM  `conditions` where `SourceTypeOrReferenceId`=17 AND `SourceEntry`=72590;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 72590, 0, 0,27, 1, 70, 3, 0, 0, 0, 0, '', 'Minimum Level for Runescroll of Fortitude on players (70)');
