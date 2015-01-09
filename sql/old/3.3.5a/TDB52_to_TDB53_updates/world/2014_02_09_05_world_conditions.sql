DELETE FROM `conditions` WHERE `SourceEntry` = 52446 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(13,1,52446,0,0,31,0,3,28684,0,1,0,0,"Spell Acid Splash cannot hit Krik'thir the Gatewatcher (28684)");
