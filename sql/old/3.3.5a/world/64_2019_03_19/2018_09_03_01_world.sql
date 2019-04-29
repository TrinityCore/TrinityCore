-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=177964;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,177964,1,0,29,1,12876,50,0,1,0,'','Execute sai if not near 12876 alive'),
(22,1,177964,1,0,29,1,12876,50,1,1,0,'','Execute sai if not near 12876 dead');
