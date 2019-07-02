-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup` IN (25286, 25500);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 25286, 0, 0, 27, 0, 75, 3, 0, 0, 0, 0, "", "Quest 'Words of Delivery' requires level 75 or higher"),
(19, 0, 25500, 0, 0, 27, 0, 74, 4, 0, 0, 0, 0, "", "Quest 'Words of Delivery' requires level 74 or lower");
