UPDATE `conditions` SET `ElseGroup`=0 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=45614; -- typo fix for previous commit
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=47431;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,47431,0,23,4195,0,0,64,'','Capture Jormungar Spawn can only be used in Ice Heart Cavern');
