DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=1790;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,1790,0,0,8,0,1786,0,0,1,0,0,'','Show quest ''The Symbol of Life'' only if quest ''The Tome of Divinity'' is not rewarded'),
(19,0,1790,0,0,28,0,1786,0,0,1,0,0,'','Show quest ''The Symbol of Life'' only if quest ''The Tome of Divinity'' is not completed');
