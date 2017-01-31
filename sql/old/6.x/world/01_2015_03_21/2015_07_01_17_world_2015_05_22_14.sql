--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=6994;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`Scriptname`,`Comment`) VALUES
(1,641,6994,0,0,2,0,51315,1,1,1,0 ,'' , 'whitestone oak lumber drop only if the player doesn''t have it already');
