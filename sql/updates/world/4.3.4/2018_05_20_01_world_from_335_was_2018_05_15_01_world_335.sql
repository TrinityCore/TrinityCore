/*
-- 
-- Quest "Tome of Divinity (1641)"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=1641;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,1641,0,0,14,0,2998,0,0,0,0,0,"","Quest 'Tome of Divinity (1641)' can only be taken if quest 'Tome of Divinity (2998)' is not taken"),
(19,0,1641,0,0,14,0,3681,0,0,0,0,0,"","Quest 'Tome of Divinity (1641)' can only be taken if quest 'Tome of Divinity (3681)' is not taken");
*/
