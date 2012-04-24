-- setup alternate conditions for spell 46488
DELETE FROM `conditions` WHERE `SourceEntry` = 46488 AND `ElseGroup` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46488,0,1,31,1,3,26817,0,0,0,'',''),
(13,1,46488,0,1,36,1,0,0,0,1,0,'','');
