--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=40060 AND `ConditionTypeOrReference`=29;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,40060,0,0,0,29,0,9461,100,0,1,0,0,'','Gor Grimgut cannot be a target for Exhaustion.'),
(15,40060,0,0,1,29,0,9461,100,0,1,0,0,'','Gor Grimgut cannot be a target for Exhaustion.'),
(15,40060,0,0,2,29,0,9461,100,0,1,0,0,'','Gor Grimgut cannot be a target for Exhaustion.');
