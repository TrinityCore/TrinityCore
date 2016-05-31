DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62973,62991);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,62973,0,0, 1,0,62972,0,0,0,0,'','Foam Sword Attack'),
(13,3,62973,0,0,31,0,4,0,0,0,0,'','Foam Sword Attack'),
(13,3,62973,0,0,33,0,1,0,0,1,0,'','Foam Sword Attack'),
(13,3,62991,0,0, 1,0,62972,0,0,0,0,'','Bonked!'),
(13,3,62991,0,0,31,0,4,0,0,0,0,'','Bonked!'),
(13,3,62991,0,0,33,0,1,0,0,1,0,'','Bonked!');
