--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 42325;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,42325,0,0,31,1,3,4351,0,0,0,0,'',"Group 0: Spell 'Capture Raptor' targets creature 'Bloodfen Raptor'"),
(17,0,42325,0,1,31,1,3,4352,0,0,0,0,'',"Group 1: Spell 'Capture Raptor' targets creature 'Bloodfen Screecher'");
