--
DELETE FROM `conditions` WHERE `SourceEntry`=4170 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 4170, 0, 0, 31, 0, 3, 2775, 0, 0, 0, 0, "", "Cannon Ball can only hit \'Daggerspine Marauder\'");
