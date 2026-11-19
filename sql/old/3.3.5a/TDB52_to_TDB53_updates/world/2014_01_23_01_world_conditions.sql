--
DELETE FROM `conditions` WHERE `SourceEntry` = 40817;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(17,0,40817,0,0,23,0,3785,0,0,0,0,0,'Banishing Crystal requires Forge Camp: Wrath'),
(17,0,40817,0,1,23,0,3784,0,0,0,0,0,'Banishing Crystal requires Forge Camp: Terror');
