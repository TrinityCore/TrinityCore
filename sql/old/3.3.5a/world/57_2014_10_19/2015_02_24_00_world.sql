DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` =17 AND `SourceEntry`=56448;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 56448, 0, 0, 31, 1, 3, 30142, 0, 0, 0, 0, '', 'Storm Hammer only targets only The Iron Watcher');
