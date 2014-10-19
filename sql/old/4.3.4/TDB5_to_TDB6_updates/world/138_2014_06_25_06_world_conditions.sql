--
DELETE FROM `conditions` WHERE `SourceEntry`=28700 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(17,0,28700,0,0,30,0,181433,15,0,0,0,0,'Disperse Neutralizing Agent (28700) can be used only near the Irradiated Power Crystal (181433)');
