-- 
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=16 AND `SourceEntry`=29709);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16,0,29709,0,0,23,0,4422,0,0,0,0,'','Dismount player when not in intended zone'),
(16,0,29709,0,1,23,0,4535,0,0,0,0,'','Dismount player when not in intended zone'),
(16,0,29709,0,2,23,0,4437,0,0,0,0,'','Dismount player when not in intended zone'),
(16,0,29709,0,3,23,0,4438,0,0,0,0,'','Dismount player when not in intended zone');
